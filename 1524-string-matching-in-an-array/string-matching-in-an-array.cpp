class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        boostCode();
        int n = words.size();
        set<string> a;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j != i && words[j].find(words[i]) != string::npos){
                    a.insert(words[i]);
                    break;
                }
            }            
        }

        return vector<string>(a.begin(),a.end());
    }

private:
    void boostCode(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
};