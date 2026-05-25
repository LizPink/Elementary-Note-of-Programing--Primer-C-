#include <iostream>
#include <vector>
#include <algorithm>

int lowerBound(const std::vector<int>& points, int target) {
    int left = 0;
    int right = static_cast<int>(points.size());

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (points[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int upperBound(const std::vector<int>& points, int target) {
    int left = 0;
    int right = static_cast<int>(points.size());

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (points[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 0;
    int m = 0;
    std::cin >> n >> m;

    std::vector<int> points(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> points[i];
    }

    std::sort(points.begin(), points.end());

    for (int i = 0; i < m; ++i) {
        int a = 0;
        int b = 0;
        std::cin >> a >> b;

        int left = lowerBound(points, a);
        int right = upperBound(points, b);

        std::cout << right - left << '\n';
    }

    return 0;
}