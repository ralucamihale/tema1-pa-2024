#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int putere(int n, int *p, double alimentare, int *c) {
    int min = p[0] - abs(alimentare - c[0]);
    for (int i = 1; i < n; i++) {
        if (p[i] - abs(alimentare - c[i]) < min) {
            min = p[i] - abs(alimentare - c[i]);
        }
    }
    return min;
}



int main() {
    ifstream f("servere.in");
    ofstream g("servere.out");

    int n;
    f >> n;

    int p[n], c[n];
    int minim, maxim;

    for (int i = 0; i < n; i++) {
        f >> p[i];
    }

    f >> c[0];
    minim = c[0];
    maxim = c[0];
    for (int i = 1; i < n; i++) {
        f >> c[i];
        if (c[i] < minim) {
            minim = c[i];
        }
        if (c[i] > maxim) {
            maxim = c[i];
        }
    }

    while (minim <= maxim) {
        int putere_min = putere(n, p, (minim + maxim) / 2 - 1, c);
        int putere_max = putere(n, p, (minim + maxim) / 2 + 1, c);
        int putere_mid = putere(n, p, (minim + maxim) / 2, c);
        if (putere_mid > putere_min && putere_mid > putere_max) {
            g << fixed << setprecision(1) <<
                putere(n, p, (minim + maxim) / 2, c) << "\n";
            return 0;
        } else if (putere_mid > putere_min && putere_mid < putere_max) {
            minim = (minim + maxim) / 2 - 1;
        } else if (putere_mid > putere_max && putere_mid < putere_min) {
            maxim = (minim + maxim) / 2 + 1;
        } else {
            g << fixed << setprecision(1) <<
                putere(n, p, (minim + maxim) / 2, c) + 0.5 << "\n";
            return 0;
        }
    }

    return 0;
}
