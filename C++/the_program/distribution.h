#pragma once

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

class Distribution {
private:
    /* data */
public:
    Distribution(/* args */);
    ~Distribution();
    // virtual void SetArgs();
    virtual int Generate();
    vector<int> GetSample(int sample_size);
};