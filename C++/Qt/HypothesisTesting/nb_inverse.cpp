#include "nb_inverse.h"

NB_Inverse::NB_Inverse(NB_Distribution *distribution, int sample_size, std::mt19937 &rand_gen):
    NB_Generator(sample_size, rand_gen),
    k_{distribution->get_k()},
    p_{distribution->get_p()}
{}

NB_Inverse::~NB_Inverse()
{}

int NB_Inverse::Generate()
{
    int j = 0;
    double q = 1 - p_;
    double l = pow(p_, k_);
    double t = l;
    double value = rand_gen_() / (double)rand_gen_.max();
    while (value > t) {
        l *= (k_ + j) * q / (j + 1);
        t += l;
        j++;
    }
    return j;
}
