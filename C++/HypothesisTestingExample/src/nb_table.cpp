#include "nb_table.h"

NB_Table::NB_Table(NB_Distribution *distribution, int sample_size, std::mt19937& rand_gen):
    NB_Generator(sample_size, rand_gen)
{
    distribution->ExtendProbabilities();
    table_ = distribution->get_probabilities();
    for (int i = 1; i < table_.size(); ++i) {
        table_[i] += table_[i - 1];
    }
}

NB_Table::~NB_Table()
{}

int NB_Table::Generate()
{
    double value = rand_gen_() / (double)rand_gen_.max();
    int result = 0;
    while (value > table_[result]) {
        ++result;
    }
    return result;
}
