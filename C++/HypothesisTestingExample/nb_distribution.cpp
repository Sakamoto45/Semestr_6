#include "nb_distribution.h"

NB_Distribution::NB_Distribution(double p, int k):
    p_{p}, k_{k}
{
    double q = 1 - p_;
    density_.push_back(pow(p_, k_));
    double residual = 1 - density_.back();
    for (int j = 1; residual > EPS; ++j) {
        density_.push_back(density_.back() * (k_ + j - 1) * q / j);
        residual -= density_.back();
    }
    density_.push_back(residual);
}

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

std::vector<double> NB_Distribution::get_density() const
{
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
