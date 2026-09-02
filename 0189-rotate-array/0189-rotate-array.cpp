class Solution {
public:
    // T.C = O(n);
    // S.C = O(1);
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        if(k == 0)return;

        k = k%n;

        auto reverse = [&](int i, int j){
            while(i < j){
                swap(nums[i++], nums[j--]);
            }
        };

        reverse(0, n-1);
        reverse(0, k-1);
        reverse(k, n-1);
    }
};