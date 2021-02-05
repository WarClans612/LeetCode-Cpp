#include<algorithm>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> &A = (nums1.size()>nums2.size()) ? nums2 : nums1;
        vector<int> &B = (nums1.size()>nums2.size()) ? nums1 : nums2;
        int m = A.size();
        int n = B.size();
        if (m == 0)
        {
            return (n%2==1) ? B[n/2] : static_cast<double>(B[n/2] + B[n/2 -1]) / 2.0;
        }
        
        int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
        while(iMin <= iMax) {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            if (i < iMax && B[j-1] > A[i]) {
                iMin = i + 1;
            }
            else if (i > iMin && A[i-1] > B[j]) {
                iMax = i - 1;
            }
            else {
                int maxLeft = 0;
                if (i == 0) maxLeft = B[j-1];
                else if (j == 0) maxLeft = A[i-1];
                else maxLeft = std::max(A[i-1], B[j-1]);
                if ( (m+n)%2 == 1 ) return static_cast<double>(maxLeft);
                
                int minRight = 0;
                if (i == m) minRight = B[j];
                else if (j == n) minRight = A[i];
                else minRight = std::min(B[j], A[i]);
                
                return static_cast<double>(maxLeft + minRight) / 2.0;
            }
        }
        return static_cast<double>(0.0);
    }
};
