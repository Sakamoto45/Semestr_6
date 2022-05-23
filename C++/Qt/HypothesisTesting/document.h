#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "nb_bernoulli.h"
#include "nb_table.h"
#include "chisquare.h"

#include <ctime>
#include <algorithm>


class Document
{
private:
    std::mt19937 rand_gen;
    NB_Generator *generator;
    NB_Distribution *distribution_0;
    NB_Distribution *distribution_1;
    int p_sample_size_;
    ChiSquare *chi_square;



public:
    Document();
    ~Document();

    void set_chi_square(int distribution_id);
    void set_generator(int sample_size);
    void set_distribution_0(double p, int k);
    void set_distribution_1(double p, int k, int sample_size);
    void set_p_sample_size(int p_sample_size);


    void GenerateSampleHistogram();
    void GeneratePvalueDistribution();
    void GeneratePowerRelation();

    double get_p0() const;
    int get_k0() const;
    double get_p1() const;
    int get_k1() const;
    int get_sample_size() const;
    int get_p_sample_size() const;
    std::string get_distribution_name() const;
    std::vector<int> get_emperical_frequency() const;
    std::vector<double> get_theoretical_frequency() const;
    double get_test_stat();
    int get_degree_of_freedom();
    double get_p_value();

    enum class Method{
        Bernulli,
        Table
    } method;
};

#endif // DOCUMENT_H
