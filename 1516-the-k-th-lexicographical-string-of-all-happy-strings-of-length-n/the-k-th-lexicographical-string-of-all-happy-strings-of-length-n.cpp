class Solution {
public:
    pair<char, char> otherThanLast(char c) {
        if (c == 'a') return {'b', 'c'};
        if (c == 'b') return {'a', 'c'};
        return {'a', 'b'};
    }

    void findNsizeStrings(vector<string>& v, string &s, int n, int k) {
        if (s.length() == n) { 
            v.push_back(s);
            return;
        }

        if (v.size() == k) return; 

        pair<char, char> p = otherThanLast(s.back());

        s.push_back(p.first);
        findNsizeStrings(v, s, n, k);
        s.pop_back();

        if (v.size() == k) return;

        s.push_back(p.second);
        findNsizeStrings(v, s, n, k);
        s.pop_back();
    }

    string getHappyString(int n, int k) {
        vector<string> v;
        v.reserve(k); 
        string s;

        for (char c : {'a', 'b', 'c'}) {
            s = c;
            findNsizeStrings(v, s, n, k);
            if (v.size() == k) return v.back();
        }

        return "";
    }
};
