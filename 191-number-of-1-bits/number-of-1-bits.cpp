class Solution {
public:
    int hammingWeight(int n) {
        long long int  ans = 0;

        while(n != 0){
            if(1 & n){
                ans++;
            }
            n= (n >> 1);
        }

        return ans;
    }
};