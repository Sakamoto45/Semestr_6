#include "nb_distribution.h"

NB_Distribution::NB_Distribution(double p, int k):
    p_{p}, k_{k}, residual_{1}
{}

NB_Distribution::~NB_Distribution()
{}

double NB_Distribution::get_p() const
{
    return p_;
}

int NB_Distribution::get_k() const
{
    return k_;
}

std::vector<double> NB_Distribution::get_probabilities()
{
    if (probabilities_.empty() ) {
        ExtendProbabilities();
    }
    return probabilities_;
}

std::string NB_Distribution::get_name() const
{
    return "Negative Binomial distribution";
}

int NB_Distribution::get_probabilities_size() const
{
    return probabilities_.size();
}

void NB_Distribution::ExtendProbabilities(int len)
{
    double q = 1 - p_;

    if (probabilities_.empty()) {
        probabilities_.push_back(pow(p_, k_));
        residual_ = 1 - probabilities_.back();
    }

    int new_len = len + probabilities_.size();
    for (int j = probabilities_.size(); (j < new_len || len == 0) && residual_ > EPS; ++j) {
        probabilities_.push_back(probabilities_.back() * (k_ + j - 1) * q / j);
        residual_ -= probabilities_.back();
    }
    if (residual_ < EPS && residual_ != 0) {
        probabilities_.push_back(residual_);
        residual_ = 0;
    }
}
