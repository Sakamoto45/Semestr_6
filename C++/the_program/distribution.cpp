#include "distribution.h"

Distribution::Distribution(/* args */) {}

Distribution::~Distribution() {}

int Distribution::Generate() {
    return 0;
}

vector<int> Distribution::GetSample(int sample_size) {
    vector<int> result;
    for (int i = 0; i < sample_size; ++i) {
        result.push_back(Generate());
    }
    return result;
}
