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

/***************************** Approach 2 hai ***********************/
class Solution {
public:
    //Approach - 2 hai Optimal
    //T.C = O(min(n,m)) + sorting  = 2 O(nlongm) hoag
    // S.C = O(1) hai
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = 0;
        while(i >= 0 && j < n){
            if(nums1[i] > nums2[j]){
                swap(nums1[i], nums2[j]);
                i--,j++;
            }else{
                break;
            }
        }

        sort(nums1.begin(), nums1.begin() + m);
        sort(nums2.begin(), nums2.begin() + n);

        // copy kar do nums2 ko nums1 me dalna hai A/c 
        for(int k=0; k<n; k++){
            nums1[m+k] = nums2[k];
        }
    }
};

/********************** Approach 3 hai *************************/
// T.C = O(n+m)
// s.c = 0(1) 

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        while(j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};
