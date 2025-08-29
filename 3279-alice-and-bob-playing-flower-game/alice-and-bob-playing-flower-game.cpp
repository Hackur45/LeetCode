class Solution {
public:
    long long flowerGame(int n, int m) {
        int e_n = 0;
        int e_m = 0;



        for(int i=1;i<=n;i++){
            if(i % 2 == 0) e_n++;
        }

        for(int  i=1;i<=m;i++){
            if(i % 2 == 0) e_m++;
        }

        return (1LL*e_n * (m-e_m)) + (1LL*e_m * (n-e_n));
    }
};