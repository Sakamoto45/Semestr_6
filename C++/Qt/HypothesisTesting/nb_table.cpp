#include "nb_table.h"

NB_Table::NB_Table(NB_Distribution *distribution, int sample_size):
    NB_Generator(sample_size)
{
    table_ = distribution->get_density();
    for (int i = 1; i < table_.size(); ++i) {
        table_[i] += table_[i - 1];
    }
}

NB_Table::~NB_Table()
{}

int NB_Table::Generate()
{
    double value = rand() / (double)RAND_MAX;
    int result = 0;
    while (value > table_[result]) {
        ++result;
    }
    return result;
}
