#pragma once
#include "random.h"
#include <map>
#include "probdist.h"


class Distribution{
public:
    explicit Distribution(double p): p(p) {};
    // Создание сгруппированной выборки геометрического распределения.
    std::map<int, int> *geomGroupedSample(int n, std::string method);
    // Вычисление критерия.
    std::pair<double, int> chiSquare(int n, std::map<int, int> &geomGroupedSample, double hypotheticalProp);
    // Вычисление p-value.
    double pValue(double criteria, int degreeOfFreedom);
    // Создание выборки p-value.
    std::vector<double> pValueSample(int sizeOfGeomSample, double realProb, double hypotheticalProp,
                                     std::string &method, int sizeOfPValueSample);

//private:
    double p;

    // Моделирование случайной величины методом обратной функции.
    int geom1();
    // Моделирование случайной величины методом Бернулли.
    int geom2();
};
