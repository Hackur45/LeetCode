class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string t = s;
        int n = s.length();
        char a = '\0';

        for (auto &ch : s) {
            if (ch != '9') {
                a = ch;
                break;
            }
        }

        if (a != '\0') {
            for (auto &ch : s) {
                if (ch == a)
                    ch = '9';
            }
        }

        if (t[0] != '1') {
            char k = t[0];
            for (auto &ch : t) {
                if (ch == k) {
                    ch = '1';
                }
            }
        } else {
            char k = '\0';
            for (int i = 1; i < t.size(); ++i) {
                if (t[i] != '0' && t[i] != '1') {
                    k = t[i];
                    break;
                }
            }
            if (k != '\0') {
                for (auto &ch : t) {
                    if (ch == k) {
                        ch = '0';
                    }
                }
            }
        }

        return stoi(s) - stoi(t);
    }
};
