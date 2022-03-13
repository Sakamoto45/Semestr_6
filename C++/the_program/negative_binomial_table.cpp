#include "negative_binomial_table.h"

NegativeBinomialTable::NegativeBinomialTable(double p, int k) {
    double q = 1 - p;
    double l = pow(p, k);
    table_.push_back(l);
    // for (int j = 0; table_.back() < 1 - EPS; ++j) {
    for (int j = 0; j < 300; ++j) {
        l *= (k + j) * q / (j + 1);
        table_.push_back(table_.back() + l);
    }
    table_.push_back(1);

    // for (auto i : table_) {cout << i << " ";}
    // cout << table_.size()<<endl;
}

NegativeBinomialTable::~NegativeBinomialTable() {
}

int NegativeBinomialTable::Generate() {
    double value = rand() / (double)RAND_MAX;
    int result = 0;
    while (value > table_[result]) {
        ++result;
    }
    return result;
}