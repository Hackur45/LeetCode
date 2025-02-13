class Solution {
public:
    bool wordPattern(string pattern, string s) {
        ___b();
        vector<string> words;
        stringstream ss(s);
        string word;
        while(ss >> word){
            words.push_back(word);
        }

        int n = pattern.size();

        if(n != words.size()) return false;

        unordered_map<char,string> mp;
        unordered_map<string,char> imp;

        for(int i=0;i<n;i++){
            char ch = pattern[i];
            string word = words[i];

            
            if(mp.find(ch) == mp.end()){
                //insert the new mapping
                if(imp.find(word) == imp.end()){
                    mp[ch] = word;
                    imp[word] = ch;
                }else{
                    return false;
                }
            }else{
                //check one to one mapping ---> if bijection then rejection
                if(mp[ch] != word) return false;
                if(imp[word] != ch) return false;
            }
        }
        return true;
    }

private:
    void ___b(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
};