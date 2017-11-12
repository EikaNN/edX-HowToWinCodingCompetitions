#include <fstream>
#include <queue>
using namespace std;

typedef queue<int> QI;

const char PUSH = '+';

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    QI queue;
    for (int i = 0; i < n; ++i) {

        char operation;
        fin >> operation;

        if (operation == PUSH) {
            int x;
            fin >> x;
            queue.push(x);
        } else {
            fout << queue.front() << "\n";
            queue.pop();
        }
    }

    return 0;
}
