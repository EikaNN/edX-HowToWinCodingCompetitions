#include <fstream>
#include <deque>
using namespace std;

typedef deque<int> DI;

const string ADD = "add";
const string TAKE = "take";

inline bool is_rebalance_needed(const DI& left, const DI& right) {
    if (right.size() > left.size()) return right.size() - left.size() > 1;
    return left.size() > right.size();
}

inline void move_right_to_left(DI& left, DI& right) {
    int pivot = right.front();
    right.pop_front();
    left.push_back(pivot);
}

inline void move_left_to_right(DI& left, DI& right) {
    int pivot = left.back();
    left.pop_back();
    right.push_front(pivot);
}

void add_action(int x, DI& left, DI& right) {
    right.push_back(x);

    if (is_rebalance_needed(left, right)) {
        move_right_to_left(left, right);
    }
}

void take_action(DI& left, DI& right) {
    right.pop_back();

    if (is_rebalance_needed(left, right)) {
        move_left_to_right(left, right);
    }
}

void mum_action(DI& left, DI& right) {
    left.swap(right);

    if (is_rebalance_needed(left, right)) {
        move_left_to_right(left, right);
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    DI left;
    DI right;
    for (int i = 0; i < n; ++i) {
        string action;
        fin >> action;
        if (action == ADD) {
            int x;
            fin >> x;
            add_action(x, left, right);
        } else if (action == TAKE) {
            take_action(left, right);
        } else {
            mum_action(left, right);
        }
    }

    fout << left.size() + right.size() << endl;
    for (int lightsaber : left)  fout << lightsaber << " ";
    for (int lightsaber : right) fout << lightsaber << " ";
    fout << endl;

    return 0;
}
