#include <fstream>
#include <stack>
#include <cmath>
using namespace std;

struct Node {
    int value, minimum;
};

typedef stack<Node> QN;

const char PUSH = '+';
const char POP = '-';
const int MAX = pow(10, 9) + 1;

void push_tracking_minimum(QN& stack, int x) {
    int minimum = stack.empty() ? MAX : stack.top().minimum;
    if (x < minimum) stack.push(Node{x, x});
    else stack.push(Node{x, minimum});
}

void move_inbox_to_outbox(QN& inbox, QN& outbox) {
    while(not inbox.empty()) {
        push_tracking_minimum(outbox, inbox.top().value);
        inbox.pop();
    }
}

int getMin(const QN& stack) {
    if (stack.empty()) return MAX;
    return stack.top().minimum;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    QN inbox;
    QN outbox;

    for (int i = 0; i < n; ++i) {

        char operation;
        fin >> operation;

        if (operation == PUSH) {
            int x;
            fin >> x;
            push_tracking_minimum(inbox, x);
        } else if (operation == POP) {
            if (outbox.empty()) move_inbox_to_outbox(inbox, outbox);
            outbox.pop();
        } else {
            fout << min(getMin(inbox), getMin(outbox)) << "\n";
        }
    }

    return 0;
}
