class Solution {
public:
    // Move the comparator inside the function and fix its declaration
    static bool compare(const pair<string, int> &a, const pair<string, int> &b) {
        return a.second < b.second; // sort by increasing index sum (not descending)
    }

    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int n = list1.size();
        int m = list2.size();
        map<string, int> mp;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (list1[i] == list2[j]) {
                    mp[list1[i]] = i + j;
                }
            }
        }
        vector<pair<string, int>> v;
        for (auto &a : mp) {
            v.push_back(a);
        }

        sort(v.begin(), v.end(), compare);

        int mi = v[0].second; 

        vector<string> ans;
        for (auto &a : v) {
            if (a.second > mi) {
                break;
            }
            ans.push_back(a.first); 
        }

        return ans;
    }
};
