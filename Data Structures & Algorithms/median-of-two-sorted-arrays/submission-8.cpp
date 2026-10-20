class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int totalSize = m + n;
        
        // Fix 1: Resize nums1 so it has room to hold all m + n elements safely
        nums1.resize(totalSize);
        
        // Set up pointers starting from the back of both original arrays
        int idx = totalSize - 1;
        int i = m - 1;
        int j = n - 1;
        
        // Fix 2: Clean up merge logic to track correct array indices
        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) {
                nums1[idx] = nums1[i]; // Corrected source vector
                i--;
            } else {
                nums1[idx] = nums2[j];
                j--;
            }
            idx--;
        }
        
        // If elements remain in nums2, copy them over
        while (j >= 0) {
            nums1[idx] = nums2[j];
            idx--;
            j--;
        }
        
        // Calculate the median
        if (totalSize % 2 == 0) {
            return (nums1[totalSize / 2 - 1] + nums1[totalSize / 2]) / 2.0;
        } else {
            return nums1[totalSize / 2];
        }
    }
};
