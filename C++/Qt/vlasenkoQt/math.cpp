#include <iostream>
#include <iomanip>
#include "math.h"


int Distribution::geom1() {
    int k{};
    PRNG prng;
    initGenerator(prng);
//    double s = p, t = s, q = 1 - p, a = getRandomDouble(prng, 0, 1);
    double s = p, t = s, q = 1 - p, a = rand() / (double)RAND_MAX;
    while(a >= s) {
        t *= q;
        ++k;
        s +=t;
    }
    return k;
}

int Distribution::geom2() {
    int k{};
    PRNG prng;
    initGenerator(prng);
    double q = 1 - p;
//    while(getRandomDouble(prng, 0, 1) < q)
    while(rand() / (double)RAND_MAX < q)
        k++;
    return k;
}

std::map<int, int> *Distribution::geomGroupedSample(int n, std::string method) {
    // Создаем словарь, ключ - значение выборки, значение - частота.
    auto *gSample = new std::map<int, int>; // Работа с указателями, чтобы не копировать результат функции в глобальную область
//    std::map<int, int> gSample;
    if (method == "inverseFunction")
        for (int i = 0; i < n; ++i)
            ++(*gSample)[geom1()];
    if (method == "bernoulli")
        for (int i = 0; i < n; ++i)
            ++(*gSample)[geom2()];

    return gSample;
}

std::pair<double, int> Distribution::chiSquare(int n, std::map<int, int> &geomGroupedSample, double hypotheticalProp) {
    double p_k = hypotheticalProp, F = p_k; // Вероятность k неуспехов, функция распределения.
    std::pair<double, int> result{0, -1}; // Критерий и степень свободы.

    // Переменные для объединения частот и вероятностей состояний.
    int tmpFrequency{};
    double tmpP_k{};
    for(int i = 0; i <= geomGroupedSample.rbegin()->first; ++i) {
        tmpP_k += p_k;
        if(geomGroupedSample.find(i) != geomGroupedSample.end())
            tmpFrequency += geomGroupedSample[i];

        // Объединяем конец и добавляем его к последнему состоянию,
        // если его теоретическая частота меньше или равна 5.
        if((1 - F) * n <= 5) {
            tmpP_k += 1 - F;
            for(++i; i <= geomGroupedSample.rbegin()->first; ++i)
                if(geomGroupedSample.find(i) != geomGroupedSample.end())
                    tmpFrequency += geomGroupedSample[i];
        }
        if (tmpP_k * n > 5) {
            // Увеличиваем степень свободы и считаем критерий.
            ++result.second;
            result.first += pow(tmpFrequency - n * tmpP_k, 2) / (n * tmpP_k);
            tmpP_k = 0;
            tmpFrequency = 0;
        }
        p_k *= 1 - p;
        F += p_k;
    }

    return result;
}

double Distribution::pValue(double criteria, int degreeOfFreedom) {
    auto chiSquare = Probdist();
    return 1 - chiSquare.pChi(criteria, degreeOfFreedom);
}

std::vector<double> Distribution::pValueSample(int sizeOfGeomSample, double realProb, double hypotheticalProp,
                                               std::string &method, int sizeOfPValueSample) {
    std::vector<double> result;
    auto dist = Distribution(realProb);
    for(int i = 0; i < sizeOfPValueSample; ++i) {
        std::map<int, int> *geomGroupedSample = dist.geomGroupedSample(sizeOfGeomSample, method);
        std::pair<double, int> chiSquare = dist.chiSquare(sizeOfGeomSample, *geomGroupedSample, hypotheticalProp);
        result.push_back(dist.pValue(chiSquare.first, chiSquare.second));
        (*geomGroupedSample).clear();
    }

    return result;
}
