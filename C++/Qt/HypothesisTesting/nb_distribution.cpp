#include "nb_distribution.h"

NB_Distribution::NB_Distribution(double p, int k):
    p_{p}, k_{k}
{

}

double NB_Distribution::GetP()
{
    return p_;
}

int NB_Distribution::GetK()
{
    return k_;
}

std::vector<double> NB_Distribution::GetDensity()
{
    return density_;
}
