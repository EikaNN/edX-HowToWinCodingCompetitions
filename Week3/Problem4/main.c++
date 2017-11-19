#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> VI;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    VI v(n);
    v[0] = 1;
    if (n > 1) v[1] = 2;

    for (int i = 2; i < n; ++i) {
        v[i] = i+1;
        swap(v[i/2], v[i]);
    }

    for (int i = 0; i < n; ++i) fout << v[i] << " ";
    fout << endl;
    
    return 0;
}
