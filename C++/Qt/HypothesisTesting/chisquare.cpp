#include "chisquare.h"



ChiSquare::ChiSquare(const NB_Distribution& distribution, const int *sample, int sample_size)
{
    set_data(distribution, sample, sample_size);
}

void ChiSquare::set_data(const NB_Distribution& distribution, const int *sample, int sample_size)
{
    grouped_is_relevant_ = false;
    stats_are_relevant_ = false;
    int max_elem = 0;
    for (int i = 0; i < sample_size; ++i) {
        if (sample[i] > max_elem) {
            max_elem = sample[i];
        }
    }
    emperical_frequency_.clear();
    emperical_frequency_.resize(max_elem + 1);
    for (int i = 0; i < sample_size; ++i) {
        emperical_frequency_[sample[i]]++;
    }

    theoretical_frequency_ = distribution.get_density();
    for (int i = 0; i < theoretical_frequency_.size(); ++i) {
        theoretical_frequency_[i] *= sample_size;
    }

    int max_size = std::max(emperical_frequency_.size(),
                            theoretical_frequency_.size());
    emperical_frequency_.resize(max_size);
    theoretical_frequency_.resize(max_size);
}

std::vector<double> ChiSquare::get_theoretical_frequency() const
{
    return theoretical_frequency_;
}

std::vector<int> ChiSquare::get_emperical_frequency() const
{
    return emperical_frequency_;
}

std::vector<double> ChiSquare::get_theoretical_frequency_grouped()
{
    if (!grouped_is_relevant_) group();
    return theoretical_frequency_grouped_;
}

std::vector<int> ChiSquare::get_emperical_frequency_grouped()
{
    if (!grouped_is_relevant_) group();
    return emperical_frequency_grouped_;
}

double ChiSquare::get_test_stat()
{
    if (!stats_are_relevant_) calc_p_value();
    return test_stat_;
}

int ChiSquare::get_degree_of_freedom()
{
    if (!stats_are_relevant_) calc_p_value();
    return degree_of_freedom_;
}

double ChiSquare::get_p_value()
{
    if (!stats_are_relevant_) calc_p_value();
    return p_value_;
}

void ChiSquare::group()
{
    int size = theoretical_frequency_.size();
    theoretical_frequency_grouped_ = {theoretical_frequency_[0]};
    emperical_frequency_grouped_ = {emperical_frequency_[0]};
    for (int i = 1; i < size; ++i) {
        if (theoretical_frequency_grouped_.back() < 5) {
            theoretical_frequency_grouped_.back() += theoretical_frequency_[i];
            emperical_frequency_grouped_.back() += emperical_frequency_[i];
        } else {
            theoretical_frequency_grouped_.push_back(theoretical_frequency_[i]);
            emperical_frequency_grouped_.push_back(emperical_frequency_[i]);
        }
    }
    if (theoretical_frequency_grouped_.back() < 5) {
        double tmp1 = theoretical_frequency_grouped_.back();
        theoretical_frequency_grouped_.pop_back();
        theoretical_frequency_grouped_.back() += tmp1;
        int tmp2 = emperical_frequency_grouped_.back();
        emperical_frequency_grouped_.pop_back();
        emperical_frequency_grouped_.back() += tmp2;
    }
    grouped_is_relevant_ = true;
}

void ChiSquare::calc_p_value()
{
    if (!grouped_is_relevant_) group();

    int size = theoretical_frequency_grouped_.size();
    test_stat_ = 0;
    for (int i = 0; i < size; ++i) {
        double tmp = theoretical_frequency_grouped_[i] - emperical_frequency_grouped_[i];
        test_stat_ += tmp * tmp / theoretical_frequency_grouped_[i];
    }
    degree_of_freedom_ = size - 1;
    p_value_ = pChi(test_stat_, degree_of_freedom_);
    stats_are_relevant_ = true;
}

