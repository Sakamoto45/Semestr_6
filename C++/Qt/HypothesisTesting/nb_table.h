#ifndef NB_TABLE_H
#define NB_TABLE_H

#include "nb_generator.h"

class NB_Table : public NB_Generator
{
private:
    std::vector<double> table_;
    void ExtendTable(int len);

public:
    NB_Table(double p, int k);
    ~NB_Table() override;
    int Generate() override;
};

#endif // NB_TABLE_H
