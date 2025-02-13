class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;  // No transactions possible

        int profit = 0;
        int i = 0;

        while (i < n - 1) {
            while (i < n - 1 && prices[i] >= prices[i + 1]) 
                i++;

            if (i == n - 1) break;
            int buy = prices[i]; 
            i++; 
            while (i < n && prices[i] >= prices[i - 1]) 
                i++;

            int sell = prices[i - 1]; 
            profit += sell - buy;
        }

        return profit;
    }
};
