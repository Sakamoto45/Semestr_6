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

std::vector<double> NB_Distribution::get_density()
{
    if (density_.empty() ) {
        ExtendDensity();
    }
    return density_;
}

std::string NB_Distribution::get_name() const
{
    return "Negative Binomial distribution";
}

int NB_Distribution::get_size() const
{
    return density_.size();
}

void NB_Distribution::ExtendDensity(int len)
{
    double q = 1 - p_;

    if (density_.empty()) {
        density_.push_back(pow(p_, k_));
        residual_ = 1 - density_.back();
    }

    int new_len = len + density_.size();
    for (int j = density_.size(); (j < new_len || len == 0) && residual_ > EPS; ++j) {
        density_.push_back(density_.back() * (k_ + j - 1) * q / j);
        residual_ -= density_.back();
    }
    if (residual_ < EPS && residual_ != 0) {
        density_.push_back(residual_);
        residual_ = 0;
    }
}
