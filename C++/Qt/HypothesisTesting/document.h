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
    std::vector<double> p_distribution_;
    double significance_level_;
    std::vector<double> power_relation_;


public:
    Document();
    ~Document();

    void set_chi_square(int distribution_id);
    void set_generator(int sample_size);
    void set_distribution_0(double p, int k);
    void set_distribution_1(double p, int k, int sample_size);
    void set_p_sample_size(int p_sample_size);
    void set_significance_level(double significance_level);


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
    std::vector<double> get_p_distribution();
    double get_significance_level() const;
    const std::vector<double>& get_power_relation() const;


    enum class Method{
        Bernulli,
        Table
    } method;
};

#endif // DOCUMENT_H
