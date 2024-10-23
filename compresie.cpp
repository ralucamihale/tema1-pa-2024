#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream f("compresie.in");
    ofstream g("compresie.out");

    int n, m;
    int length = 0;
    int sumA = 0, sumB = 0;

    f >> n;
    int A[n];
    for (int i = 0; i < n; i++) {
        f >> A[i];
        sumA += A[i];
    }

    f >> m;
    int B[m];
    for (int i = 0; i < m; i++) {
        f >> B[i];
        sumB += B[i];
    }

    if (sumA != sumB) {
        g << -1;
    } else {
        int i = 0, j = 0;
        sumA = A[0];
        sumB = B[0];

        while (i < n && j < m) {
            if (sumA == sumB) {
                length++;
                i++;
                j++;
                sumA = A[i];
                sumB = B[j];
            } else if (sumA < sumB) {
                i++;
                sumA += A[i];
            } else {
                j++;
                sumB += B[j];
            }
        }

        g << length;
    }

    return 0;
}
