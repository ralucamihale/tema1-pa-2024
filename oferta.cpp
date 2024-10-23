#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;


int main() {
    ifstream f("oferta.in");
    ofstream g("oferta.out");
    int n, k;
    double pret[10001] = {0};

    f >> n;
    f >> k;


    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        f >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        pret[i] = pret[i - 1] + a[i];

        if (i >= 2) {
            double pret_crt = min(a[i], a[i - 1]) / 2.0 + max(a[i], a[i - 1]);
            pret[i] = min(pret[i], pret[i - 2] + pret_crt);
        }

        if (i >= 3) {
            double pret_crt = a[i] + a[i - 1] + a[i - 2] -
                            min(a[i], min(a[i - 1], a[i - 2]));
            pret[i] = min(pret[i], pret[i - 3] + pret_crt);
        }
    }

    g << fixed << setprecision(1) << pret[n];

    return 0;
}
