class Solution {
public:
    bool smallex(int i, vector<int> &ans, vector<bool> &isused, int n) {
        if (i == ans.size()) return true;
        if (ans[i] != 0) return smallex(i + 1, ans, isused, n);

        for (int j = n; j >= 1; j--) {
            if (isused[j]) continue;

            isused[j] = true;
            ans[i] = j;

            int second_index = (j > 1) ? i + j : -1;
            bool placed = false;
            
            if (j == 1 || (second_index < ans.size() && ans[second_index] == 0)) {
                if (j > 1) {
                    ans[second_index] = j;
                    placed = true;
                }

                if (smallex(i + 1, ans, isused, n)) return true;

                if (placed) ans[second_index] = 0; 
            }

            ans[i] = 0; 
            isused[j] = false;
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * n - 1, 0);
        vector<bool> isused(n + 1, false);
        smallex(0, ans, isused, n);
        return ans;
    }
};
