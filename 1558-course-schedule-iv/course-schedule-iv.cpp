class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        vector<vector<bool>> reach(n, vector<bool>(n, false));


        for (auto& p : prerequisites) {
            reach[p[0]][p[1]] = true;
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (reach[i][k] && reach[k][j]) {
                        reach[i][j] = true;
                    }
                }
            }
        }

        vector<bool> ans;
        for (auto& query : queries) {
            ans.push_back(reach[query[0]][query[1]]);
        }

        return ans;
    }
};
