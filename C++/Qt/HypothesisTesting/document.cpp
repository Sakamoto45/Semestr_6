#include "document.h"

Document::Document() :
    rand_gen(time(nullptr)),
    generator{nullptr},
    distribution_0{nullptr},
    distribution_1{nullptr},
    p_sample_size_{10000},
    chi_square{nullptr},
    method{Method::Bernulli}
{
    set_distribution_0(0.2, 10);
    set_distribution_1(0.2, 10, 1000);
    chi_square = new ChiSquare(*distribution_0,
                               generator->get_sample(),
                               generator->get_sample_size());
}

Document::~Document()
{
    delete generator;
    delete distribution_0;
    delete distribution_1;
    delete chi_square;
}

void Document::set_chi_square(int distribution_id)
{
    chi_square->set_data(distribution_id ? *distribution_1 : *distribution_0,
                         generator->get_sample(),
                         generator->get_sample_size());
}

void Document::set_generator(int sample_size)
{
    delete generator;

    switch (method) {
    case Method::Bernulli:
        generator = new NB_Bernoulli(distribution_1, sample_size, rand_gen);
        break;
    case Method::Table:
        generator = new NB_Table(distribution_1, sample_size, rand_gen);
        break;
    }
    generator->GenerateSample();
}

void Document::set_distribution_0(double p, int k)
{
    if (!distribution_0 || p != distribution_0->get_p() || k != distribution_0->get_p()) {
        delete distribution_0;
        distribution_0 = new NB_Distribution(p, k);
    }
}

void Document::set_distribution_1(double p, int k, int sample_size)
{
    if (!distribution_1 || p != distribution_1->get_p() || k != distribution_1->get_p()) {
        delete distribution_1;
        distribution_1 = new NB_Distribution(p, k);
    }
    set_generator(sample_size);
}

void Document::set_p_sample_size(int p_sample_size)
{
    p_sample_size_ = p_sample_size;
}

void Document::GenerateSampleHistogram()
{
    generator->GenerateSample();
    set_chi_square(1);
}

void Document::GeneratePvalueDistribution()
{

}

void Document::GeneratePowerRelation()
{

}

double Document::get_p0() const
{
    return distribution_0->get_p();
}

int Document::get_k0() const
{
    return distribution_0->get_k();
}

double Document::get_p1() const
{
    return distribution_1->get_p();
}

int Document::get_k1() const
{
    return distribution_1->get_k();
}

int Document::get_sample_size() const
{
    return generator->get_sample_size();
}

int Document::get_p_sample_size() const
{
    return p_sample_size_;
}

std::string Document::get_distribution_name() const
{
    return distribution_0->get_name();
}

std::vector<int> Document::get_emperical_frequency() const
{
    return chi_square->get_emperical_frequency();
}

std::vector<double> Document::get_theoretical_frequency() const
{
    return chi_square->get_theoretical_frequency();
}

double Document::get_test_stat()
{
    return chi_square->get_test_stat();
}

int Document::get_degree_of_freedom()
{
    return chi_square->get_degree_of_freedom();
}

double Document::get_p_value()
{
    return chi_square->get_p_value();
}

//std::vector<double> Document::get_theoretical_density() const
//{
//    return distribution_0->get_density();
//}
