#include <fstream>
#include <queue>
using namespace std;

struct Stack {
    int height, count;
};

typedef vector<Stack> VS;
typedef vector<int> VI;
typedef priority_queue<int, VI, greater<int> > PQI;

void aggregate(PQI& stacks, VS& aggregated_stacks) {
    while (!stacks.empty()) {
        int count = 0;
        int height = stacks.top();
        while (!stacks.empty() and stacks.top() == height) {
            ++count;
            stacks.pop();
        }
        aggregated_stacks.push_back(Stack{height,count});
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    PQI stacks;

    int a;
    fin >> a;
    stacks.push(1);

    for (int i = 1; i < n; ++i) {
        fin >> a;
        if (a == 0) {
            int smallest_height = stacks.top();
            stacks.pop();
            stacks.push(++smallest_height);
        }
        else stacks.push(1);
    }

    VS aggregated_stacks;
    aggregate(stacks, aggregated_stacks);

    fout << aggregated_stacks.size() << endl;
    for (Stack stack: aggregated_stacks) {
        fout << stack.height << " " << stack.count << endl;
    }

    return 0;
}
