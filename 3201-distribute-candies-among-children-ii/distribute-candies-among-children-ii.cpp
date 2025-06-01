class Solution {
public:
    long long f(long long x) {
        if (x < 0) return 0;
        return x * (x - 1) / 2;
    }

    //Damm Combinatorics
    long long distributeCandies(int n, int limit) {
        return f(n + 2) - 3 * f(n - limit + 1) + 3 * f(n - 2 * (limit + 1) + 2) - f(n - 3 * (limit + 1) + 2);
    }
};
