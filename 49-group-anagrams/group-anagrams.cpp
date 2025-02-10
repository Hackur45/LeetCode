#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<string>> mp; 
        
        for (auto &str : strs) {
            map<char, int> lc; 
            for (auto &a : str) {
                lc[a]++;
            }
            mp[lc].push_back(str);
        }

        vector<vector<string>> ans; 

        for (auto &[key, val] : mp) {
            ans.push_back(val);
        }

        return ans;
    }
};
