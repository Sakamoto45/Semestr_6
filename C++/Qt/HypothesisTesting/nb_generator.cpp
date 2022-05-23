#include "nb_generator.h"

NB_Generator::NB_Generator(int sample_size, std::mt19937& rand_gen):
    rand_gen_{rand_gen},
    sample_{nullptr},
    sample_size_{sample_size}
//    frequency_is_relevant_{false}
{}

NB_Generator::~NB_Generator()
{}

int* NB_Generator::GenerateSample()
{
//    frequency_is_relevant_ = false;
    delete[] sample_;
    sample_ = new int[sample_size_];
    for (int i = 0; i < sample_size_; ++i) {
        sample_[i] = Generate();
    }
    return sample_;
}

//std::vector<int> NB_Generator::GenerateFrequency()
//{
//    int max_elem = 0;
//    for (int i = 0; i < sample_size_; ++i) {
//        if (sample_[i] > max_elem) {
//            max_elem = sample_[i];
//        }
//    }

//    frequency_.clear();
//    frequency_.resize(max_elem + 1);

//    for (int i = 0; i < sample_size_; ++i) {
//        frequency_[sample_[i]]++;
//    }
//    frequency_is_relevant_ = true;
//    return frequency_;
//}

int *NB_Generator::get_sample() const
{
    return sample_;
}

//std::vector<int> NB_Generator::get_frequency()
//{
//    if (!frequency_is_relevant_) {
//        GenerateFrequency();
//    }
//    return frequency_;
//}

int NB_Generator::get_sample_size() const
{
    return sample_size_;
}
