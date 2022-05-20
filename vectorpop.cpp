class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = 0;
        for(int i = 0; i<nums1.size()&&j<n;){
            if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                nums1.pop_back();
                nums1.insert(nums1.begin()+i,nums2[j]);
                j++;
            }
        }
        while(j<n){
            nums1.pop_back();
            nums1.insert(nums1.begin()+m+j,nums2[j]);
            j++;
        }
    }
};

