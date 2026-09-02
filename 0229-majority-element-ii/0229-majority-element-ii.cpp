class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> list;

        for(int i = 0; i < n; i++) {

            // duplicate avoid
            if(list.size() > 0 && list[0] == nums[i]) continue;
            if(list.size() > 1 && list[1] == nums[i]) continue;

            int cnt = 0;

            for(int j = 0; j < n; j++) {
                if(nums[j] == nums[i])
                    cnt++;
            }

            if(cnt > n/3)
                list.push_back(nums[i]);

            if(list.size() == 2)
                break;
        }

        return list;
    }
};