class Solution {
public:
    void merge(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int gap = (n + m + 1) / 2; 

        while (gap > 0) {
            int i = 0, j = gap;

            while (j < (n + m)) {
                int val1 = (i < n) ? nums1[i] : nums2[i - n];
                int val2 = (j < n) ? nums1[j] : nums2[j - n];

                if (val1 > val2) {
                    if (i < n && j < n) {
                        swap(nums1[i], nums1[j]); 
                    } else if (i < n) {
                        swap(nums1[i],
                             nums2[j - n]); 
                    } else {
                        swap(nums2[i - n], nums2[j - n]); 
                    }
                }
                i++, j++;
            }

            gap = (gap > 1) ? (gap + 1) / 2 : 0; 
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        merge(nums1,nums2);
        nums1.insert(nums1.end(), make_move_iterator(nums2.begin()), make_move_iterator(nums2.end()));
        int n = nums1.size();
        int mid = n / 2;
        double ans = n%2 == 0 ? (nums1[mid] + nums1[mid-1]) / 2.0 : (nums1[mid]);

        return ans;  
    }
};