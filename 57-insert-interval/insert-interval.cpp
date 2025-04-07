class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int i = 0;
        vector<vector<int>> ans;
        
        while(i < n && intervals[i][1] <newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        int minL = newInterval[0];
        int maxR = newInterval[1];
        while(i < n && intervals[i][0] <= maxR){
            minL = min(minL,intervals[i][0]);
            maxR = max(maxR,intervals[i][1]);
            i++;
        }
        ans.push_back({minL,maxR});

        while(i < n){
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;        
    }
};