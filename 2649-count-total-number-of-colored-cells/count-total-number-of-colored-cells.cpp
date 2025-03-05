class Solution {
public:
    long long coloredCells(long long n) {
        return 1 + 2 * (n-1) * n;
    }
};