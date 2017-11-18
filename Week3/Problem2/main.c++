#include <fstream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef long long int LLI;

void merge(VI& v, int left, int mid, int right, LLI& inversions) {
    int n = right - left;
    VI aux(n);
    int i = left;
    int j = mid;
    int k = 0;
    while (i < mid and j < right) {
        if (v[i] <= v[j]) aux[k++] = v[i++];
        else {
            // All the remaining elements from [i,mid) are inversions of v[j]
            inversions += mid - i;
            aux[k++] = v[j++];
        }
    }
    while (i < mid) aux[k++] = v[i++];
    while (j < right) aux[k++] = v[j++];

    for (int i = 0; i < n; ++i) v[left+i] = aux[i];
}

void mergesort(VI& v, int left, int right, LLI& inversions) {
    
    if (left+1 == right) return;

    int mid = (left+right)/2;
    mergesort(v, left, mid, inversions);
    mergesort(v, mid, right, inversions);
    merge(v, left, mid, right, inversions);
}

LLI count_inversions(VI& v) {
    LLI inversions = 0;
    mergesort(v, 0, v.size(), inversions);
    return inversions;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    VI v(n);
    for (int i = 0; i < n; ++i) fin >> v[i];

    fout << count_inversions(v) << endl;

    return 0;
}
