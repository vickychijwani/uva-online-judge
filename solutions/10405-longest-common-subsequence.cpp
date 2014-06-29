#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

const int MAX_LEN = 1000;

int main() {
    std::string x, y;
    int i, j, m, n, max;
    int L[MAX_LEN+1][MAX_LEN+1];

    while (std::getline(std::cin, x) && std::getline(std::cin, y)) {
        m = x.length(), n = y.length();

        for (i = 0; i <= m; ++i) {
            for (j = 0; j <= n; ++j) {
                L[i][j] = 0;
            }
        }

        for (i = 1; i <= m; ++i) {
            for (j = 1; j <= n; ++j) {
                max = std::max(L[i][j-1], L[i-1][j]);
                if (x.at(i-1) == y.at(j-1) && L[i-1][j-1] + 1 > max) {
                    max = L[i-1][j-1] + 1;
                }
                L[i][j] = max;
            }
        }

        std::cout << L[m][n] << std::endl;
    }

    return 0;
}
