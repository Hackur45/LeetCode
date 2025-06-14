class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string t = s;
        int n = s.length();
        string dummy = s;
        int l = 0;
        for(auto &a  : s){
            if(a != '9'){
                break;
            }
            l++;
        }

        if(l < n){
            char a = s[l];
            for(int i=0;i<n;i++){
                if(s[i] == a){
                    s[i] = '9'; 
                }
            }
        }

        char b = t[0];
        for(int i=0;i<n;i++){
            if(t[i] == b){
                t[i] = '0';
            }
        }

        return stoi(s) - stoi(t);
    }
};