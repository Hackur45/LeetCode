class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> q;
        unordered_set<int> seen, have;
        vector<bool> open(status.begin(), status.end());
        int total = 0;

        for (int b : initialBoxes) {
            have.insert(b);
            if (open[b]) q.push(b);
        }

        while (!q.empty()) {
            int b = q.front(); q.pop();
            if (seen.count(b)) continue;
            seen.insert(b);
            total += candies[b];

            for (int k : keys[b]) {
                open[k] = true;
                if (have.count(k)) q.push(k);
            }

            for (int c : containedBoxes[b]) {
                have.insert(c);
                if (open[c]) q.push(c);
            }
        }

        return total;
    }
};
