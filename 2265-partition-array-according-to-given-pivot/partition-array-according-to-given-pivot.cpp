class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);

        int li = 0;
        int gi = n - 1;

        for(int i=0,j = n -1; i < n, j >= 0; i++,j--){
            if(nums[i] < pivot){
                ans[li] = nums[i];
                li++;
            }

            if(nums[j] > pivot){
                ans[gi] = nums[j];
                gi--;
            }
        }

        while(li <= gi){
            ans[li] = pivot;
            li++;
        }

        return ans;
    }
};