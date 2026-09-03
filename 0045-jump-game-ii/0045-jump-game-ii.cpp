class Solution {
public:
    vector<int> t;
    int solve(vector<int>& nums, int n, int idx){
        if(idx >= n-1) return 0;
        if(t[idx] != -1)
            return t[idx];
        int mini = INT_MAX;
        for(int i=1; i<= nums[idx] && idx+i < n; i++){
           int ans =  solve(nums,n, idx+i);

           if(ans != INT_MAX){
              mini = min(mini, 1+ans);
           }
        }
        return t[idx] =  mini;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        t.assign(n, -1);
        return solve(nums, n,0);
    }
};