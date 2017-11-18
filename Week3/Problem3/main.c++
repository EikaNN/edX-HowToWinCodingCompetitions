#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Medicine {
    int lives, units;
};

typedef vector<Medicine> VM;

bool compare(const Medicine& a, const Medicine& b) {
    return a.lives > b.lives;
}

int save_lives(VM& medicines, int w) {
    
    // Sort medicines in decreasing order of lives
    sort(medicines.begin(), medicines.end(), compare);

    int total_units = 0;
    int total_lives = 0;
    for (int i = 0; i < medicines.size(); ++i) {
        if (medicines[i].units + total_units <= w) {
            total_lives += medicines[i].lives * medicines[i].units;
            total_units += medicines[i].units;
        } else {
            total_lives += medicines[i].lives * (w-total_units);
            break;
        }
    }
    return total_lives;
}


int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    VM medicines(n);
    for (int i = 0; i < n; ++i) {
        fin >> medicines[i].lives >> medicines[i].units;
    }

    int w;
    fin >> w;

    fout << save_lives(medicines, w) << endl;

    return 0;
}
