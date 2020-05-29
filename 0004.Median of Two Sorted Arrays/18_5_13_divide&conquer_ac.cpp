# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

void recursion(){

}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();

        if(len1 > len2)
            return findMedianSortedArrays(nums2, nums1);

        int L1, L2, R1, R2, lo = 0, hi = len1 * 2;
        while(lo <= hi){
            int c1 = (lo + hi) / 2;
            int c2 = len1 + len2 - c1;

            L1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
            R1 = (c1 == len1 * 2) ? INT_MAX : nums1[c1 / 2];
            L2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
            R2 = (c2 == len2 * 2) ? INT_MAX : nums2[c2 / 2];

            if(L1 > R2)
                hi = c1 - 1;
            else if(L2 > R1)
                lo = c1 + 1;
            else
                break;
        }
        return (max(L1, L2) + min(R1, R2)) / 2.0;
    }
};

int main(){

    return 0;
}