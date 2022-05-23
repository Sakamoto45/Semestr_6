#include "nb_bernoulli.h"

NB_Bernoulli::NB_Bernoulli(NB_Distribution* distribution, int sample_size):
    NB_Generator(sample_size),
    k_{distribution->get_k()},
    p_{distribution->get_p()}
{}

NB_Bernoulli::~NB_Bernoulli()
{}

int NB_Bernoulli::Generate() {
    int i = 0;
    int j = 0;
    while (i < k_) {
        if (rand() / (double)RAND_MAX > p_) {
            ++j;
        } else {
            ++i;
        }
    }
    return j;
}
