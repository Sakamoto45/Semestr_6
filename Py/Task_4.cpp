#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

vector<int> fisher_yates_shuffle(int n, mt19937& generator) {
    vector<int> shuffle(n);
    for (int i = 0; i < n; ++i) {
        shuffle[i] = i;
    }
    for (int i = n - 1; i >= 0; --i) {
        uniform_int_distribution<int> distribution(0, i);
        int j = distribution(generator);
        if (i != j) {
            swap(shuffle[i], shuffle[j]);
        }
    }
    return shuffle;
}

void print(vector<int> shuffle) {
    for (auto it : shuffle) {
        cout << it << " ";
    }
    cout << endl;
}

void position_distribution_test(int sample_size, int shuffle_length, mt19937& generator) {
    // stats[i][j] count i-th elem on j-th position
    vector<vector<int>> stats(shuffle_length, vector<int>(shuffle_length, 0));
    vector<int> shuffle;
    for (int rep = 0; rep < sample_size; ++rep) {
        shuffle = fisher_yates_shuffle(shuffle_length, generator);
        for (int j = 0; j < shuffle_length; ++j) {
            stats[shuffle[j]][j]++;
        }
    }

    ofstream output;
    output.open("position_distribution_test.txt");
    for (auto line : stats) {
        for (auto elem : line) {
            output << (double) elem/* / sample_size */<< " ";
        }
        output << endl;
    }
    output.close();
}

vector<int> count_cycles_by_length(vector<int>& shuffle) {
    vector<bool> visited(shuffle.size(), false);
    // result[i] counts cycles of length i+1
    vector<int> result(shuffle.size());
    
    for (int start = 0; start < shuffle.size(); ++start) {
        if (visited[start]) {
            continue;
        }
        int next = shuffle[start];
        int cycle_length = 1;
        while (next != start) {
            visited[next] = true;
            next = shuffle[next];
            cycle_length++;
        }
        result[cycle_length - 1]++;
    }
    // print(result);
    return result;
}

void cycle_length_test(int sample_size, int shuffle_length, mt19937& generator) {
    // stats[i][j] count shuffles with j cycles of length i + 1
    vector<vector<int>> stats(shuffle_length);
    for (int i = 0; i < shuffle_length; ++i) {
        stats[i] = vector<int>(shuffle_length / (i + 1) + 1);
    }
    vector<int> shuffle;
    for (int rep = 0; rep < sample_size; ++rep) {
        shuffle = fisher_yates_shuffle(shuffle_length, generator);
        vector<int> count = count_cycles_by_length(shuffle);
        for (int i = 0; i < shuffle_length; ++i) {
            stats[i][count[i]]++;
        }
    }

    ofstream output;
    output.open("cycle_length_test.txt");
    for (auto line : stats) {
        for (auto elem : line) {
            output << (double) elem/* / sample_size */<< " ";
        }
        output << endl;
    }
    output.close();
}

int main() {
    mt19937 generator(time(nullptr));

    position_distribution_test(1000000, 10, generator);
    cycle_length_test(1000000, 10, generator);
    int x;

    return 0;
}

