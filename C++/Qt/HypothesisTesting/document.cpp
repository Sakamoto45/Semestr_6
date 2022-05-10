#include "document.h"

Document::Document() :
    generator{nullptr},
    p_0{0.2}, k_0{10}, p_1{0.2}, k_1{10},
    method{Method::Bernulli},
    sample_size{1000}, p_sample_size{10000}
{
    srand(time(nullptr));
    resetGenerator();
}

Document::~Document()
{
    delete generator;
}

void Document::generateEmpericalDencity()
{
    int* sample = generator->GenerateSample(sample_size);
    emperical_density.clear();

    int max_elem = 0;
    for (int i = 0; i < sample_size; ++i) {
        if (sample[i] > max_elem) {
            max_elem = sample[i];
        }
    }

    emperical_density.resize(max_elem + 1);
    for (int i = 0; i < sample_size; ++i) {
        emperical_density[sample[i]]++;
    }
    for (auto& i : emperical_density) {
        i = i / sample_size;
    }
    delete[] sample;
}

void Document::resetGenerator()
{
    delete generator;

    switch (method) {
    case Method::Bernulli:
        generator = new NegativeBinomialBernoulli(p_1, k_1);
        break;
    case Method::Table:
        generator = new NegativeBinomialTable(p_1, k_1);
        break;
    default:
        break;
    }
}
