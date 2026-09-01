class Solution {
public:
    //T.C = O(n);
    //S.C = O(1);
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        for(auto ele : nums){
            if(i == 0 || i == 1 || nums[i-2] != ele){
                nums[i] = ele;
                i += 1;
            }
        }
        return i;
    }
};