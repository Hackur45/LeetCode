class Solution {
public:
    bool isvowel(char a){
        return a == 'a' || a == 'A' || a == 'e' || a == 'E' || a == 'i' || a == 'I' ||a == 'o' || a == 'O' || a == 'u' ||a == 'U';
    }
    string toGoatLatin(string sentence) {
        int n = sentence.length();
        stringstream s(sentence);
        vector<string> words;

        string word;
        while(s >> word){
            words.push_back(word);
        }
        string ext = "";
        for(auto &w :words){
            ext += 'a';
            if(isvowel(w[0])){
                w += "ma" + ext;
            }else{
                int l = w.length();
                char a = w[0];
                w = w.substr(1,l) + w[0] + "ma" + ext; 
            }
        }

        string ans = "";
        for(auto &w : words){
            ans += w + " ";
        }

        return ans.substr(0,ans.length()-1);
    } 
};