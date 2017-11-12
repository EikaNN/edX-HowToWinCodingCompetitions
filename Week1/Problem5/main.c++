#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef vector<int> VI;

const int CODER = 0;
const int MATHEMATICIAN = 1;
const int TESTER = 2;

inline int square(int n) {
    return n*n;
}

double maximize_efficiency(const VI& andrew, const VI& peter, const VI& paul) {
    
    int roles1 = square(andrew[CODER]) + square(peter[MATHEMATICIAN]) + square(paul[TESTER]);
    int roles2 = square(andrew[CODER]) + square(peter[TESTER]) + square(paul[MATHEMATICIAN]);
    int roles3 = square(andrew[MATHEMATICIAN]) + square(peter[CODER]) + square(paul[TESTER]);
    int roles4 = square(andrew[MATHEMATICIAN]) + square(peter[TESTER]) + square(paul[CODER]);
    int roles5 = square(andrew[TESTER]) + square(peter[CODER]) + square(paul[MATHEMATICIAN]);
    int roles6 = square(andrew[TESTER]) + square(peter[MATHEMATICIAN]) + square(paul[CODER]);

    return sqrt(max( {roles1, roles2, roles3, roles4, roles5, roles6} ));
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fout.setf(ios::fixed);
    fout.precision(6);

    VI andrew(3);
    fin >> andrew[CODER] >> andrew[MATHEMATICIAN] >> andrew[TESTER];
    
    VI peter(3);
    fin >> peter[CODER] >> peter[MATHEMATICIAN] >> peter[TESTER];

    VI paul(3);
    fin >> paul[CODER] >> paul[MATHEMATICIAN] >> paul[TESTER];

    fout << maximize_efficiency(andrew, peter, paul) << endl;

    return 0;
}
