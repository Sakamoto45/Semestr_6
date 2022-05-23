#ifndef NB_GENERATOR_H
#define NB_GENERATOR_H

#include <vector>
#include <cstdlib>
#include <random>

class NB_Generator
{
protected:
    int* sample_;
    int sample_size_;
    std::vector<double> frequency_;
    bool frequency_is_relevant_;
//    std::vector<double> density_;

public:
    NB_Generator(int sample_size);
    virtual ~NB_Generator();

    virtual int Generate()=0;
    int* GenerateSample();
    std::vector<double> GenerateFrequency();
    int* get_sample() const;
    std::vector<double> get_frequency();
    int get_sample_size() const;
};

#endif // NB_GENERATOR_H
