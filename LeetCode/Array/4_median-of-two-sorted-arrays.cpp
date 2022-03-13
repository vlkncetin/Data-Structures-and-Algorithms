class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int s1=nums1.size();
        int s2=nums2.size();
        
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(),nums1.end());
        
        if((s1+s2)%2==1)
            return (double)nums1[(s1+s2)/2];
        
        return ((double)nums1[(s1+s2)/2]+(double)nums1[(s1+s2)/2-1])/2;
    }
};