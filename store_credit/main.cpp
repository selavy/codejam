#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>

std::pair<int, int> solve(const int credit, const std::vector<int>& items) {
    for (int i = 0; i < items.size(); ++i) {
        for (int j = i+1; j < items.size(); ++j) {
            if (items[i] + items[j] == credit) {
                return std::make_pair(i+1, j+1);
            }
        }
    }

    return std::make_pair(0, 0);
}

int main(int argc, char** argv)
{
    /* FILE *fin = freopen("A-small.in", "r", stdin); */
    /* FILE *fout = freopen("A-small.out", "w", stdout); */
    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int credit;
        std::cin >> credit;
        std::vector<int> items;
        int M;
        std::cin >> M;
        int T;
        for (int j = 0; j < M; ++j) {
            std::cin >> T;
            items.push_back(T);
        }
        const auto& s = solve(credit, items);
        std::cout << "Case #" << i+1 << ": " << s.first << " " << s.second << "\n";
    }

    return 0;
}
