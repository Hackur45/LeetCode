class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(s1 == s2){
            return true;
        }

        if(s1.length() != s2.length()) return false;
        map<int,int> mpA;
        map<int,int> mpB; 

        int n = s1.length();
        int dif = 0;
        for(int i=0;i<n;i++){
            if(s1[i] != s2[i]){
                dif++;
            }
            if(dif > 2) return false;

            mpA[s1[i] - 'a']++;
            mpB[s2[i] - 'a']++;
        }

        for(int i=0;i<26;i++){
            if(mpA[i] != mpB[i]) return false;
        }

        return true;
    }
};