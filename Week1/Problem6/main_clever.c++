#include <fstream>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fout.setf(ios::fixed);
    fout.precision(6);

    double a, b, c;
    fin >> a >> b >> c;

    // Using midpoint theorem of a triangle, there is a trivial solution 
    fout << (a/2 + b/2 + c/2)/3 << endl;

    return 0;
}
