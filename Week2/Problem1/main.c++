#include <fstream>
#include <stack>
using namespace std;

typedef stack<int> SI;

const char PUSH = '+';

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    SI stack;
    for (int i = 0; i < n; ++i) {

        char operation;
        fin >> operation;

        if (operation == PUSH) {
            int x;
            fin >> x;
            stack.push(x);
        } else {
            fout << stack.top() << "\n";
            stack.pop();
        }
    }

    return 0;
}
