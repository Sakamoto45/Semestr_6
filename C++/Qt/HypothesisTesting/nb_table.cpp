#include "nb_table.h"

void NB_Table::ExtendTable(int len = 100)
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

NB_Table::NB_Table(double p, int k) :
    NB_Generator(p, k)
{
    ExtendTable();
}

NB_Table::~NB_Table()
{}

int NB_Table::Generate()
{
    double value = rand() / (double)RAND_MAX;
    int result = 0;
    while (value > table_[result]) {
        ++result;
        if (result == (int)table_.size()) ExtendTable(10);
    }
    return result;
}
