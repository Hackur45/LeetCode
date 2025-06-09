class Solution {
public:
    long long helper(long long a, long long b) {
        long long x = 0, y = a, z = a + 1;
        while (y <= b) {
            x += min(b + 1, z) - y;
            y *= 10;
            z *= 10;
        }
        return x;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;

        while (k > 0) {
            long long cnt = helper(curr, n);
            if (cnt <= k) {
                curr += 1;
                k -= cnt;
            } else {
                curr *= 10;
                k -= 1;
            }
        }

        return curr;
    }
};
