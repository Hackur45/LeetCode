class Solution {
public:
    void find(unordered_map<char, int>& mp, int& count) {
        for (auto& [key, val] : mp) {
            if (val > 0) {
                val--;
                count++;
                find(mp, count);
                val++;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> mp;
        for (int i = 0; i < tiles.size(); i++) {
            mp[tiles[i]]++;
        }
        int count = 0;
        find(mp, count);
        return count;
    }
};