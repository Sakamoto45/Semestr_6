#include "negativebinomialbernoulli.h"

NegativeBinomialBernoulli::NegativeBinomialBernoulli(double p, int k) :
    Sample(p, k) {}

NegativeBinomialBernoulli::~NegativeBinomialBernoulli()
{}

int NegativeBinomialBernoulli::Generate() {
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
