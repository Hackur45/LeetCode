class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        float ld = 0;
        int area = 0;

        for(auto &dim : dimensions){
            int l = max(dim[0],dim[1]);
            int b = l == dim[0] ? dim[1] : dim[0];

            float diag = sqrt((l*l + b*b));
            int area_n = l * b;
            if(diag > ld || (diag == ld && area_n > area)){
                ld = diag;
                area = area_n;
            }
        }

        return area;
    }
};