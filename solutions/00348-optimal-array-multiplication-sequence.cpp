#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

const int MAX_N = 15;

void print_optimal_parens(int s[][MAX_N], int i, int j);

int main() {
    int i, j, k, l, N, k_opt;
    long min, mults;
    int r[MAX_N], c[MAX_N];
    long m[MAX_N][MAX_N];
    int s[MAX_N][MAX_N];
    int case_no = 1;

    while (std::cin >> N) {
        if (N == 0) break;

        for (i = 0; i < N; ++i) {
            std::cin >> r[i] >> c[i];
            m[i][i] = 0;
        }

        for (l = 1; l < N; ++l) {
            for (i = 0, j = i+l; j < N; ++i, ++j) {
                min = std::numeric_limits<int>::max();
                for (k = i; k < j; ++k) {
                    mults = m[i][k] + m[k+1][j] + r[i]*c[j]*c[k];
                    if (mults < min) {
                        min = mults;
                        k_opt = k;
                    }
                }
                m[i][j] = min;
                s[i][j] = k_opt;
            }
        }

        std::cout << "Case " << case_no++ << ": ";
        print_optimal_parens(s, 0, N-1);
        std::cout << std::endl;
    }

    return 0;
}

void print_optimal_parens(int s[][MAX_N], int i, int j) {
    if (i == j) {
        std::cout << "A" << i+1;
    } else {
        int k = s[i][j];
        std::cout << "(";
        print_optimal_parens(s, i, k);
        std::cout << " x ";
        print_optimal_parens(s, k+1, j);
        std::cout << ")";
    }
}
