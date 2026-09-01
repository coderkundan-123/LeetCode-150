/*********************************** first Approach cpp solution hai ***********************/
/* T.C = O(n+m) + O(n+m)
    S.C = O(n+m) */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nums3[m+n];
        int left = 0;
        int right = 0;
        int idx = 0;
        while(left < m  && right < n){
            if(nums1[left] <= nums2[right]){
                nums3[idx] = nums1[left];
                left++, idx++;
            }else{
                nums3[idx] = nums2[right];
                right++, idx++;
            }
        }

        while(left < m){
            nums3[idx++] = nums1[left++];
        }
        while(right < n){
            nums3[idx++] = nums2[right++];
        }

        //int idx = 0;
        for(int i=0; i<m+n; i++){
           nums1[i] = nums3[i];
        }

    }
};
