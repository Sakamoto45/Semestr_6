#include "negativebinomialtable.h"

void NegativeBinomialTable::ExtendTable(int len = 100)
{
    double q = 1 - p_;
    static double l = pow(p_, k_);

    if (table_.empty()) table_.push_back(l);

    len += table_.size();
    for (int j = table_.size(); j < len; ++j) {
        l *= (k_ + j - 1) * q / j;
        table_.push_back(table_.back() + l);
    }
}

NegativeBinomialTable::NegativeBinomialTable(double p, int k) :
    Sample(p, k)
{
    ExtendTable();
}

NegativeBinomialTable::~NegativeBinomialTable()
{}

int NegativeBinomialTable::Generate()
{
    double value = rand() / (double)RAND_MAX;
    int result = 0;
    while (value > table_[result]) {
        ++result;
        if (result == (int)table_.size()) ExtendTable(10);
    }
    return result;
}
