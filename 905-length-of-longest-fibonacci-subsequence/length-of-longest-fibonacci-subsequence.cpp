class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index; 
        unordered_map<int, int> dp;     

        for (int i = 0; i < n; i++) {
            index[arr[i]] = i; 
        }

        int maxLength = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int k = index.find(arr[i] - arr[j]) != index.end() ? index[arr[i] - arr[j]] : -1;
                if (k >= 0 && k < j) {
                    int len = dp[k * n + j] + 1;
                    dp[j * n + i] = len;  
                    maxLength = max(maxLength, len);
                } else {
                    dp[j * n + i] = 2;
                }
            }
        }

        return maxLength >= 3 ? maxLength : 0;  
    }
};
