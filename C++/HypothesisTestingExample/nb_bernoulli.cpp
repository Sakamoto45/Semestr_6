#include "nb_bernoulli.h"

NB_Bernoulli::NB_Bernoulli(NB_Distribution* distribution, int sample_size, std::mt19937& rand_gen):
    NB_Generator(sample_size, rand_gen),
    k_{distribution->get_k()},
    p_{distribution->get_p()}
{}

NB_Bernoulli::~NB_Bernoulli()
{}

int NB_Bernoulli::Generate() {
    int i = 0;
    int j = 0;
    while (i < k_) {
        if (rand_gen_() / (double)rand_gen_.max() > p_) {
            ++j;
        } else {
            ++i;
        }
    }
    return j;
}
