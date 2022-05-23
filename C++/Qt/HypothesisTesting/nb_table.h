#ifndef NB_TABLE_H
#define NB_TABLE_H

#include "nb_generator.h"
#include "nb_distribution.h"

class NB_Table : public NB_Generator
{
private:
    std::vector<double> table_;

public:
    NB_Table(NB_Distribution *distribution, int sample_size);
    ~NB_Table() override;
    int Generate() override;
};

#endif // NB_TABLE_H
