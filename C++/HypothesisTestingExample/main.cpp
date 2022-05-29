#include "document.h"
#include <iostream>

using namespace std;

int main() {
    Document doc = Document();

    doc.set_distribution_1(0.2, 10, 10000);
    doc.set_method(Document::Method::Table);
    doc.GenerateSampleHistogram();
    cout << "\nSample frequency vs Theoretical frequency";
    cout<< "\n " << doc.get_distribution_name()
        << "\n p = " << doc.get_p1()
        << "\n k = " << doc.get_k1()
        << "\n sample size = " << doc.get_sample_size()
        << "\n test statistic = " << doc.get_test_stat()
        << "\n degree of freedom = " << doc.get_degree_of_freedom()
        << "\n p-value = " << doc.get_p_value()
        << endl;

    const std::vector<int>& empirical_frequency = doc.get_empirical_frequency();
    const std::vector<double>& theoretical_frequency = doc.get_theoretical_frequency();
    cout << "i\tempir\ttheor\n";
    for (int i = 0; i < theoretical_frequency.size(); ++i) {
        cout << i << "\t" << empirical_frequency[i] << "\t" << theoretical_frequency[i] << "\n";
    }




    doc.set_distribution_0(0.2, 10);
    doc.set_distribution_1(0.2, 10, 100);
    doc.set_p_sample_size(10000);
    doc.GeneratePvalueDistribution();
    cout << "\nP-value distribution";
    cout<< "\n p0 = " << doc.get_p0()
        << "\n k0 = " << doc.get_k0()
        << "\n p1 = " << doc.get_p1()
        << "\n k1 = " << doc.get_k1()
        << "\n sample size = " << doc.get_sample_size()
        << "\n p sample size = " << doc.get_p_sample_size()
        << endl;

    const std::vector<double>& distribution = doc.get_p_distribution();
    cout << "sig-lev\tp-level\n";
    for (int i = 0; i < distribution.size(); ++i) {
        cout << i / 100.0 << "\t" << distribution[i] << "\n";
    }




    doc.set_distribution_0(0.2, 10);
    doc.set_distribution_1(0.2, 10, 100);
    doc.set_significance_level(0.1);
    doc.GeneratePowerRelation();
    cout << "\nPower relation to sample size";
    cout<< "\n p0 = " << doc.get_p0()
        << "\n k0 = " << doc.get_k0()
        << "\n p1 = " << doc.get_p1()
        << "\n k1 = " << doc.get_k1()
        << "\n significance level = " << doc.get_significance_level()
        << endl;
    
    const std::vector<double>& power = doc.get_power_relation();
    cout << "size\tpower\n";
    for (int i = 0; i < power.size(); ++i) {
        cout << (i + 1) * 100 << "\t" << power[i] << "\n";
    }

    return 0;
}