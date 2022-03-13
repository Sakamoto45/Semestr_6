#include "chi_square_test.h"
#include <ctime>

// using namespace std;

int main() {
    srand(time(nullptr));  

    cout << "Negative binomial distribution\n";

    double p0 = 0.1;
    int k0 = 10;
    ChiSquareTest::Method method = ChiSquareTest::Method::None;
    double p1 = 0.11;
    int k1 = 10;
    int sample_size;
    int p_sample_size;



    // input
    cout << "Input args for zero hypothesis (p0, k0): ";
    cin >> p0 >> k0;
    cout << "Select generation method:\n 1) Table\n 2) Bernoulli\n";
    int tmp;
    while (method == ChiSquareTest::Method::None) {
        cin >> tmp;
        switch (tmp) {
        case 1:
            method = ChiSquareTest::Method::Table;
            break;
        case 2:
            method = ChiSquareTest::Method::Bernoulli;
            break;
        default:
            break;
        }  
    }
    cout << "Input args for alternative hypothesis (p1, k1): ";
    cin >> p1 >> k1;
    while (sample_size < 100) {
        cout << "Input sample size (>=100): ";
        cin >> sample_size;
    }
    while (p_sample_size < 10000) {
        cout << "Input p-value sample size (>=10000): ";
        cin >> p_sample_size;
    }







    




    ChiSquareTest MyChi{};
    {
        Distribution* generator = MyChi.GetGenerator(p0, k0, method);
        vector<double> theoretical_distribution = MyChi.GetTheoreticalDistribution(p0, k0);
        vector<int> sample = generator->GetSample(sample_size);
        pair<double, int> chi_squared = MyChi.CalculateChiSquared(theoretical_distribution, sample);
        cout << "chi_squared, DoF, p-value\n";
        cout << chi_squared.first << " " << chi_squared.second << " " << MyChi.p_value(chi_squared) << endl;
        delete generator;
    }
    

    
    
    cout << "\nType 1 error\n";
    MyChi.PrintDistributionAsTable(
        MyChi.GeneratePvalueSample(p0, k0, p0, k0, method, sample_size, p_sample_size));
    
    cout << "\nPower\n";
    MyChi.PrintDistributionAsTable(
        MyChi.GeneratePvalueSample(p0, k0, p1, k1, method, sample_size, p_sample_size));

    
    

    return 0;
}