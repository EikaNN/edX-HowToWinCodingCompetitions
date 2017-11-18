#include <fstream>
#include <vector>
using namespace std;

typedef vector<int> VI;

void merge(VI& v, int left, int mid, int right) {
    int n = right - left;
    VI aux(n);
    int i = left;
    int j = mid;
    int k = 0;
    while (i < mid and j < right) {
        if (v[i] <= v[j]) {
            aux[k] = v[i];
            ++i;
        }
        else {
            aux[k] = v[j];
            ++j;
        }
        ++k;
    }
    while (i < mid) {
        aux[k] = v[i];
        ++i;
        ++k;
    }
    while (j < right) {
        aux[k] = v[j];
        ++j;
        ++k;
    }
    for (int l = 0; l < n; ++l) v[left+l] = aux[l];
}

void mergesort(VI& v, int left, int right, ofstream& fout) {

    // v has only one element, thus it is already sorted
    if (left+1 == right) return;

    int mid = (left+right)/2;
    mergesort(v, left, mid, fout);
    mergesort(v, mid, right, fout);
    merge(v, left, mid, right);
    fout << left+1 << " " << right << " " << v[left] << " " << v[right-1] << "\n";
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    VI v(n);
    for (int i = 0; i < n; ++i) fin >> v[i];

    mergesort(v, 0, v.size(), fout);

    for (int x : v) fout << x << " ";
    fout << endl;

    return 0;
}
