#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
using namespace std;

typedef vector<int> VI;

int maximize_ability(const VI& practice, const VI& theory) {
    
    int max_ability = 0;
    int min_difference = numeric_limits<int>::max();
    bool practice_day = false;
    bool theory_day = false;

    for (int i = 0; i < practice.size(); ++i) {
        if (practice[i] > theory[i]) {
            practice_day = true;
            max_ability += practice[i];
        } else {
            theory_day = true;
            max_ability += theory[i];
        }
        min_difference = min(min_difference, abs(practice[i] - theory[i]));
    }

    if (!practice_day || !theory_day) {
        max_ability -= min_difference;
    }

    return max_ability;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    VI practice(n);
    for (int i = 0; i < n; ++i) fin >> practice[i];

    VI theory(n);
    for (int i = 0; i < n; ++i) fin >> theory[i];

    fout << maximize_ability(practice, theory) << endl;

    return 0;
}
