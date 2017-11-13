#include <fstream>
#include <stack>
using namespace std;

inline char get_opening(char bracket) {
    return bracket == ']' ? '[' : '(';
}

inline bool is_opening(char bracket) {
    return bracket == '(' or bracket == '[';
}

bool is_correct(const string& sequence) {
    stack<char> stack;
    for (char bracket : sequence) {
        
        if (is_opening(bracket)) {
            stack.push(bracket);
        }
        
        else {
            if (stack.empty() || stack.top() != get_opening(bracket)) return false;
            stack.pop();
        }
    }
    return stack.empty();
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    for (int i = 0; i < n; ++i) {
        string sequence;
        fin >> sequence;
        fout << (is_correct(sequence) ? "YES" : "NO") << "\n";
    }

    return 0;
}
