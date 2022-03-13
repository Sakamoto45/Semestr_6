#include "chi_square_test.h"

// lower incomplete gamma function (s, x) for x 
double ChiSquareTest::ligf(double s, double x, int n) {
    double result = 0;
    double tmp = 1.0 / x;
    for (int i = 0; i < n; ++i) {
        tmp *= x / (s + i);
        result += tmp;
    }
    return result * pow(x, s) * exp(-x);
}

// calculate gamma function of n/2, for natural n
double ChiSquareTest::gamma_half(int n) {
    double result = (n % 2) ? sqrt(M_PI) : 1;
    for (int i = n - 2; i > 0; i -= 2) {
        result *= (0.5 * i);
    }
    return result;
}

// calculate p-value for chi-squared distribution 
double ChiSquareTest::p_value(pair<double, int> chi_squared) {
    double critical_value = chi_squared.first;
    int dergees_of_freedom = chi_squared.second;
    if(critical_value < 0 || dergees_of_freedom < 1) {
        return 0;
    }
    
    if(dergees_of_freedom == 2) {
	return exp(-0.5 * critical_value);
    }

    return 1.0 - ligf(0.5 * dergees_of_freedom, 0.5 * critical_value) / gamma_half(dergees_of_freedom);
}

ChiSquareTest::ChiSquareTest() {}

ChiSquareTest::~ChiSquareTest() {}

Distribution* ChiSquareTest::GetGenerator(double p, int k, Method method) {
    switch (method) {
    case Method::Table:
        return new NegativeBinomialTable(p, k);
    case Method::Bernoulli:
        return new NegativeBinomialBernoulli(p, k);
    }
    return nullptr;
}

// returns vector of theoretical probabilities of distribution res[i] = P(i)
vector<double> ChiSquareTest::GetTheoreticalDistribution(double p, int k) {
    vector<double> result;
    double q = 1 - p;
    result.push_back(pow(p, k));
    for (int j = 0; j < 300; ++j) {
        result.push_back(result.back() * (k + j) * q / (j + 1));
    }
    return result;
}

// returns pair(critical value, degree of freedom)
pair<double, int> ChiSquareTest::CalculateChiSquared(vector<double> theoretical_distribution, vector<int> sample) {
    int n = sample.size();
    sort(sample.rbegin(), sample.rend());

    vector<double> theoretical_distribution_grouped = {0};
    vector<int> sample_grouped = {0};

    for (int i = 0; i < theoretical_distribution.size(); ++i) {
        if (theoretical_distribution_grouped.back() * n < 5) {
            theoretical_distribution_grouped.back() += theoretical_distribution[i];
        } else {
            theoretical_distribution_grouped.push_back(theoretical_distribution[i]);
            sample_grouped.push_back(0);
        }
        while (sample.back() == i) {
            sample.pop_back();
            sample_grouped.back()++;
        }
    }
    if (theoretical_distribution_grouped.back() * n < 5) {
        double tmp1 = theoretical_distribution_grouped.back();
        theoretical_distribution_grouped.pop_back();
        theoretical_distribution_grouped.back() += tmp1;
        int tmp2 = sample_grouped.back();
        sample_grouped.pop_back();
        sample_grouped.back() += tmp2;
    }

    double result = 0;

    for (int i = 0; i < theoretical_distribution_grouped.size(); ++i) {
        result += pow((double)sample_grouped[i] / n - theoretical_distribution_grouped[i], 2) / theoretical_distribution_grouped[i];
    }

    return make_pair(result * n, theoretical_distribution_grouped.size() - 1);
}

vector<double> ChiSquareTest::GeneratePvalueSample(double p0, int k0, double p1, int k1, Method method, int sample_size, int p_sample_size) {
    vector<double> theoretical_distribution = GetTheoreticalDistribution(p0, k0);
    Distribution* generator = GetGenerator(p1, k1, method);
    vector<double> result(p_sample_size);

    for (int i = 0; i < p_sample_size; ++i) {
        result[i] = p_value(CalculateChiSquared(theoretical_distribution, generator->GetSample(sample_size)));
    }
    return result;
}

void ChiSquareTest::PrintDistributionAsTable(vector<double> distribution) {
    vector<int> density(20);
    
    for (auto i : distribution) {
        density[floor(i*20)]++;
    }

    vector<int> cumulative;
    cumulative.push_back(0);
    for (auto i : density) {
        cumulative.push_back(cumulative.back() + i);
    }

    for (int i = 0; i < 21; ++i) {
        cout << i*0.05 << "\t" << cumulative[i] / (double)distribution.size() << endl;
    }
}