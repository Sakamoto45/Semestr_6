#include "document.h"

Document::Document() :
    generator{nullptr},
    distribution_0{nullptr},
    distribution_1{nullptr},
    p_sample_size_{10000},
    method{Method::Bernulli}
{
    srand(time(nullptr));


    set_distribution_0(0.2, 10);
    set_distribution_1(0.2, 10, 1000);

//    set_generator(1000);
}

Document::~Document()
{
    delete generator;
    delete distribution_0;
    delete distribution_1;
}

void Document::set_generator(int sample_size)
{
    delete generator;

    switch (method) {
    case Method::Bernulli:
        generator = new NB_Bernoulli(distribution_1, sample_size);
        break;
    case Method::Table:
        generator = new NB_Table(distribution_1, sample_size);
        break;
    }
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

void Document::GenerateEmpericalFrequency()
{
    generator->GenerateSample();
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

std::vector<double> Document::get_emperical_frequency() const
{
    return generator->get_frequency();
}

//std::vector<double> Document::get_theoretical_density() const
//{
//    return distribution_0->get_density();
//}
