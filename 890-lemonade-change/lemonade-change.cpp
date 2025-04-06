class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();

        int fc = 0, tc = 0, ttc = 0;
        // for(auto &a : bills){
        //     if(a == 5){
        //         fc++;
        //     }else{
        //         break;
        //     }
        // }
        for(auto &a : bills){
            if(a == 5){
                fc++;
            }else if(a == 10){
                if(fc == 0) return false;
                fc--;
                tc++;
            }else if(a == 20){
                // if(fc == 0) return false;
                // if(tc == 0) return false;
                if(fc > 0 && tc > 0){
                    fc--;
                    tc--;
                }else if(fc >= 3){
                    fc -= 3;
                }else{
                    return false;
                }
            }
        }

        return true;
    }
};