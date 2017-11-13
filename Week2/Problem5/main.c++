#include <fstream>
#include <stack>
using namespace std;

const char ADDITION = '+';
const char SUBTRACTION = '-';
const char MULTIPLICATION = '*';

inline int char_to_digit(char c) {
    return c - '0';
}

inline bool is_operator(char c) {
    return c == ADDITION or c == SUBTRACTION or c == MULTIPLICATION;
}

void evaluate(stack<int>& stack, char operation) {
    int operand2 = stack.top();
    stack.pop();
    int operand1 = stack.top();
    stack.pop();

    switch(operation) {
        case ADDITION:
            stack.push(operand1 + operand2);
            break;
        case SUBTRACTION:
            stack.push(operand1 - operand2);
            break;
        case MULTIPLICATION:
            stack.push(operand1*operand2);
            break;
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    stack<int> stack;

    for (int i = 0; i < n; ++i) {
        char c;
        fin >> c;
        if (is_operator(c)) evaluate(stack, c);
        else stack.push(char_to_digit(c));
    }

    fout << stack.top() << endl;

    return 0;
}
