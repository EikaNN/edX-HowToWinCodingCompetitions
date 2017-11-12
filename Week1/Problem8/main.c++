#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;

const int MAX = pow(10, 7);

void sieve(VB& is_prime, VI& prime_factors) {
    is_prime = VB(MAX+1, true);
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i*i <= MAX; ++i) {
        if (is_prime[i]) {
            // Store prime numbers up to sqrt(MAX)
            prime_factors.push_back(i);
            for (int j = 2*i; j <= MAX; j += i) is_prime[j] = false;
        }
    }
}

int number_of_divisors(int n, const VB& is_prime, const VI& prime_factors) {
    int divisors = 1;

    for (int prime : prime_factors) {
        
        if (is_prime[n] or prime*prime > n) break;

        int exponent = 0;
        while (n%prime == 0) {
            ++exponent;
            n /= prime;
        }
        divisors *= exponent + 1;      
    }

    // The number is prime
    // => Then it has one divisor which is itself, thus one factor with exponent 1
    // OR
    // The number has a prime factor which is not in prime_factors
    // => Then only one can exist and its exponent is 1
    if (n != 1) divisors *= 1 + 1;

    return divisors;
}

int maximal_tests(int k, const VB& is_prime, const VI& prime_factors) {
    int max_divisors = 0;
    int max_value = 0;

    // We can start from ceil(k/2 + 1) and only check even numbers
    int start = (k/2)%2 == 0 ? k/2 + 2 : k/2 + 1;
    for (int i = start; i <= k; i += 2) {
        int divisors = number_of_divisors(i, is_prime, prime_factors);
        if (divisors > max_divisors) {
            max_divisors = divisors;
            max_value = i;
        }
    }
    return k - max_value + 1;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int k;
    fin >> k;

    VB is_prime;
    VI prime_factors;
    sieve(is_prime, prime_factors);
    
    fout << maximal_tests(k, is_prime, prime_factors) << endl;
    
    return 0;
}
