class Solution {
public:
    bool isPowerOfTwo(int n) {
        cout<<((n)>>1)<<endl;
        return (n > 0) && ((n & (n-1)) == 0);
    }
};