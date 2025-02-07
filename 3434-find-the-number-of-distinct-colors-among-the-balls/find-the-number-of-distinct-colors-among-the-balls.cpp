#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void boostCode() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }

    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        boostCode();
        vector<int> result;
        unordered_map<int, int> colored;  
        unordered_map<int, int> colorCount; 
        
        for (auto& query : queries) {
            int x = query[0]; 
            int y = query[1]; 
            
            if (colored.find(x) != colored.end()) {
                int prevColor = colored[x];
                if (--colorCount[prevColor] == 0) {
                    colorCount.erase(prevColor);
                }
            }
            
            colored[x] = y;
            colorCount[y]++;
            
            result.push_back(colorCount.size());
        }

        return result;
    }
};

