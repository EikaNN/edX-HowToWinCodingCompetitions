#include <fstream>
#include <map>
using namespace std;

typedef map<int,int> MII;

MII table;

int three_bonacci(int n) {
    if (table.find(n) != table.end()) return table[n];
    
    table[n] = three_bonacci(n-1) + three_bonacci(n-2) - three_bonacci(n-3);
    return table[n];
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int a0, a1, a2, n;
    fin >> a0 >> a1 >> a2 >> n;

    table[0] = a0;
    table[1] = a1;
    table[2] = a2;

    fout << three_bonacci(n) << endl;

    return 0;
}
