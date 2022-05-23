#ifndef NB_GENERATOR_H
#define NB_GENERATOR_H

#include <vector>
#include <cstdlib>
#include <random>

class NB_Generator
{
protected:
    std::mt19937& rand_gen_;
    int* sample_;
    int sample_size_;
//    std::vector<int> frequency_;
//    bool frequency_is_relevant_;
//    std::vector<double> density_;

public:
    NB_Generator(int sample_size, std::mt19937& rand_gen);
    virtual ~NB_Generator();

    virtual int Generate()=0;
    int* GenerateSample();
//    std::vector<int> GenerateFrequency();
    int* get_sample() const;
//    std::vector<int> get_frequency();
    int get_sample_size() const;
};

#endif // NB_GENERATOR_H
