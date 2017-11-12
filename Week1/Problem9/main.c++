#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> VI;

const int MAX_SECONDS = 300*60;

int maximum_problems(const VI& problem_times) {
    int n = problem_times.size();
    int total_time = 0;
    for (int i = 0; i < n; ++i) {
        if (total_time + problem_times[i] > MAX_SECONDS) return i;
        if (i == n-1) return n;
        total_time += problem_times[i];
    }
    return 0;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    VI problem_times(n);
    for (int i = 0; i < n; ++i) fin >> problem_times[i];
    sort(problem_times.begin(), problem_times.end());
    
    fout << maximum_problems(problem_times) << endl;
    
    return 0;
}
