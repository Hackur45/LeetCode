#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";  
        int n = s.length();

        for (int i = 0; i < n; i++) {
            int countOnes = 0;
            string temp = "";

            for (int j = i; j < n; j++) {
                temp += s[j];
                if (s[j] == '1') {
                    countOnes++;
                }

                if (countOnes == k) {
                    if (ans.empty() || temp.length() < ans.length() || (temp.length() == ans.length() && temp < ans)) {
                        ans = temp;
                    }
                }
            }
        }

        return ans;
    }
};
