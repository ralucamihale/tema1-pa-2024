#include <iostream>
#include <fstream>
using namespace std;

#define MOD 1000000007

long long power(long long base, long long exponent) {
    long long mul = 1;

    base = base % MOD;

    if (base == 0) return 1;

    while (exponent > 0) {
        if (exponent % 2 == 1)
            mul = mul * base  % MOD;
        exponent /= 2;
        base = (base * base) % MOD;
    }
    return mul % MOD;
}


int main() {
    ifstream f("colorare.in");
    ofstream g("colorare.out");

    long long k;
    long long section_nr;
    char type, prev_type = '0';

    long long total = 1;

    f >> k;

    for (int i = 0; i < k; i++) {
        f >> section_nr;
        f >> type;

        long long mul = 1;

        if (prev_type == '0') {
            if (type == 'V') {
                total = (total * 3 * power(2, section_nr - 1)) % MOD;
            } else {
                total = (total * 6 * power(3, section_nr - 1)) % MOD;
            }
        } else if (prev_type == 'V') {
            if (type == 'V') {
                total = (total * power(2, section_nr)) % MOD;
            } else {
                total = (total * 2 * power(3, section_nr - 1)) % MOD;
            }
        } else {
            if (type == 'V') {
                total = (total * power(2, section_nr - 1)) % MOD;
            } else {
                total = (total * power(3, section_nr)) % MOD;
            }
        }

        prev_type = type;
    }

    g << total;
    return 0;
}
