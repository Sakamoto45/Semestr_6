#include "sample.h"

//NegativeBinomial::NegativeBinomial()
//{

//}

int* Sample::GenerateSample(int sample_size)
{
    int* sample = new int[sample_size];
    for (int i = 0; i < sample_size; ++i) {

        sample[i] = Generate();
    }
    return sample;
}
