#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "nb_bernoulli.h"
#include "nb_table.h"
#include <ctime>
#include <algorithm>


class Document
{
private:
    NB_Generator *generator;



public:
    Document();
    ~Document();

    void generateEmpericalDencity();
    void resetGenerator();


    std::vector<double> emperical_density;
//    std::vector<double> theoretical_density;

    double p_0;
    int k_0;
    double p_1;
    int k_1;
    enum class Method{
        Bernulli,
        Table,
        None
    } method;
    int sample_size;
    int p_sample_size;



};

#endif // DOCUMENT_H
