#ifndef NB_GENERATOR_H
#define NB_GENERATOR_H

#include <vector>
#include <cstdlib>
#include <random>

class NB_Generator
{
public:
    NB_Generator(int sample_size, std::mt19937& rand_gen);
    virtual ~NB_Generator();

    virtual int Generate()=0;
    int* GenerateSample();
    int* get_sample() const;
    int get_sample_size() const;

protected:
    std::mt19937& rand_gen_;
    int* sample_;
    int sample_size_;
};

#endif // NB_GENERATOR_H
