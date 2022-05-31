#include "nb_inverse.h"

NB_Inverse::NB_Inverse(NB_Distribution *distribution, int sample_size, std::mt19937 &rand_gen):
    NB_Generator(sample_size, rand_gen),
    distribution_{distribution}
{}

NB_Inverse::~NB_Inverse()
{}

int NB_Inverse::Generate()
{
//    std::vector<double> density = distribution_->get_density();

    int i = 0;
    if (distribution_->get_size() < 1) {
        distribution_->ExtendProbabilities(1);
    }
    double t = distribution_->get_probabilities()[0];
    double value = rand_gen_() / (double)rand_gen_.max();
    while (value > t) {
        ++i;
        if (distribution_->get_size() < i + 1) {
            distribution_->ExtendProbabilities(1);
        }
        t += distribution_->get_probabilities()[i];
    }
    return i;

}
