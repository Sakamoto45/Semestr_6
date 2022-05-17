#include "nb_generator.h"

NB_Generator::NB_Generator(NB_Distribution *distribution): distribution_{distribution} {}

int* NB_Generator::GenerateSample(int sample_size)
{
    delete[] sample_;
    sample_ = new int[sample_size];
    for (int i = 0; i < sample_size; ++i) {
        sample_[i] = Generate();
    }
    return sample_;
}

int *NB_Generator::GetSample()
{
    return sample_;
}
