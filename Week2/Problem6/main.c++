#include <fstream>
#include <vector>
using namespace std;

struct Snowman {
    int clone, snowball;
};

typedef vector<Snowman> VS;
typedef vector<long long int> VLLI;

long long int total_mass(VS& snowmen) {

    VLLI masses(snowmen.size(), 0);
    for (int i = 0; i < snowmen.size(); ++i) {
        Snowman snowman = snowmen[i];
        Snowman clone = snowmen[snowman.clone];
        if (snowman.snowball == 0) {
            masses[i] = masses[snowman.clone] - clone.snowball;
            snowmen[i] = snowmen[clone.clone];
        } else {
            masses[i] = masses[snowman.clone] + snowman.snowball;
        }
    }

    long long int total_mass = 0;
    for (long long int mass : masses) total_mass += mass;
    return total_mass;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    VS snowmen(n+1, Snowman{0, 0});

    for (int i = 1; i <= n; ++i) {

        int t, m;
        fin >> t >> m;

        snowmen[i] = Snowman{t, m};
    }

    fout << total_mass(snowmen) << endl;

    return 0;
}
