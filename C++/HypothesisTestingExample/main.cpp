#include "nb_bernoulli.h"
#include "nb_table.h"
#include "nb_inverse.h"
#include "chisquare.h"

#include <ctime>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    std::mt19937 rand_gen(time(nullptr));
    
    vector<double> density;
    // How to get negative binomial distribution
    NB_Distribution distribution_0(0.3, 10);
    density = distribution_0.get_density();
    
    // How to get first k probabilities of negative binomial distribution
    int k = 10;
    NB_Distribution distribution_1(0.2, 10);
    distribution_1.ExtendDensity(k);
    density = distribution_1.get_density();
    cout << density.size() << endl; // 10
    // To get full density call ExtendDensity() without args
    distribution_1.ExtendDensity();
    density = distribution_1.get_density();
    cout << density.size() << endl; // 144 

    // How to generate sample
    NB_Generator *generator;
    enum class Method{
        Bernulli,
        Table,
        Inverse
    } method;
    // choose method
    method = Method::Bernulli;
    switch (method)
    {
    case Method::Bernulli:
        generator = new NB_Bernoulli(&distribution_1, 100, rand_gen);
        break;
    case Method::Table:
        generator = new NB_Table(&distribution_1, 100, rand_gen);
        break;
    case Method::Inverse:
        generator = new NB_Inverse(&distribution_1, 100, rand_gen);
        break;
    }
    generator->GenerateSample();
    // get sample
    // shallow copy
    int *sample = generator->get_sample();
    // use sample
    for (int i = 0; i < generator->get_sample_size(); ++i) {
        cout << sample[i] << " ";
    }
    cout << endl;

    // How to use chi square test
    // create object
    ChiSquare chi_square(distribution_0, *generator);
    // call needed getters
    cout << "degree of freedom = " << chi_square.get_degree_of_freedom() << endl;
    cout << "test statistic = " << chi_square.get_test_stat() << endl;
    cout << "p-value = " << chi_square.get_p_value() << endl;
    // reuse object
    chi_square.set_data(distribution_1, *generator);
    generator->GenerateSample();
    cout << "p-value = " << chi_square.get_p_value() << endl;

    delete generator;
    return 0;
}