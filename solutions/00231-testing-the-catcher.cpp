#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

int main() {
    short h;
    int i, j, n, longest, case_no = 1, interceptions, max_interceptions;
    std::vector<short> heights, lds;  // lds == longest decreasing subsequence

    while (true) {
        heights.clear();
        lds.clear();
        while (true) {
            std::cin >> h;
            if (h == -1 && heights.empty()) goto exit;
            if (h == -1) break;
            heights.push_back(h);
        }

        n = heights.size();
        for (i = 0; i < n; ++i) {
            longest = 0;
            for (j = 0; j < i; ++j) {
                if (lds.at(j) > longest && heights.at(j) >= heights.at(i)) {
                    longest = lds.at(j);
                }
            }
            lds.push_back(longest+1);
        }

        max_interceptions = 1;
        for (i = 0; i < n; ++i) {
            interceptions = lds.at(i);
            if (interceptions > max_interceptions) {
                max_interceptions = interceptions;
            }
        }

        if (case_no > 1) {
            std::cout << std::endl;
        }
        std::cout << "Test #" << case_no++ << ":" << std::endl;
        std::cout << "  maximum possible interceptions: "
                  << max_interceptions << std::endl;
    }

exit:
    return 0;
}
