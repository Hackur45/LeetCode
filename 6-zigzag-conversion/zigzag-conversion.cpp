#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        if (numRows == 1 || numRows >= len) {
            return s;
        }

        int n = numRows - 1;
        int cycle = numRows + (numRows - 2);
        int loop = (len + cycle - 1) / cycle * (numRows - 1);

        int k = 0;
        vector<vector<char>> mat(numRows, vector<char>(loop, ' '));

        int col = 0;
        while (k < len) {
            for (int j = 0; j <= n && k < len; j++) {
                mat[j][col] = s[k++];
            }
            for (int j = n - 1; j > 0 && k < len; j--) {
                mat[j][++col] = s[k++];
            }
            col++;
        }

        string ans;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < loop; j++) {
                if (mat[i][j] != ' ')
                    ans += mat[i][j];
            }
        }
        return ans;
    }
};
