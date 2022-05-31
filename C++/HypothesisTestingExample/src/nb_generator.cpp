#include "nb_generator.h"

NB_Generator::NB_Generator(int sample_size, std::mt19937& rand_gen):
    rand_gen_{rand_gen},
    sample_{nullptr},
    sample_size_{sample_size}
{}

NB_Generator::~NB_Generator()
{
    delete[] sample_;
}

int* NB_Generator::GenerateSample()
{
    delete[] sample_;
    sample_ = new int[sample_size_];
    for (int i = 0; i < sample_size_; ++i) {
        sample_[i] = Generate();
    }
    return sample_;
}

int *NB_Generator::get_sample() const
{
    return sample_;
}

int NB_Generator::get_sample_size() const
{
    return sample_size_;
}
