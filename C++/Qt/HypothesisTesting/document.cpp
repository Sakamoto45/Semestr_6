#include "document.h"

Document::Document()
{
    srand(time(nullptr));
    generator = nullptr;
    p_0 = 0.2;
    k_0 = 10;
    p_1 = 0.2;
    k_1 = 10;
    method = Method::Bernulli;
    sample_size = 1000;
    p_sample_size = 10000;

    resetGenerator();
}

Document::~Document()
{
    if(generator != nullptr) {
        delete generator;
        generator = nullptr;
    }
}

void Document::generateEmpericalDencity()
{
    std::vector<int> sample = generator->GenerateSample(sample_size);
    emperical_density.clear();
    emperical_density.resize(*max_element(sample.begin(), sample.end()) + 1);
    for (auto i : sample) {
        emperical_density[i]++;
    }
    for (auto& i : emperical_density) {
        i = i / sample_size;
    }
}

void Document::resetGenerator()
{
    if(generator != nullptr) {
        delete generator;
        generator = nullptr;
    }
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
