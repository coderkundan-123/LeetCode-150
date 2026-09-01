class Solution {
public:
// T.C = O(n log n)
// S.C = O(n)
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        for(auto it : mp){
            if(it.second > n/2){
                return it.first;
            }
        }
        return -1;
    }
};

/*************************** Brout force Approch *********************/
class Solution {
public:
    //Brute force Approach 
    //T.C = O(n^2);
    //S.C = O(1);
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(nums[j] == nums[i]){
                    cnt++;
                }
            }

            if(cnt > n/2){
                return nums[i];
            }
        }
        return -1;
    }
};
/**************************** Most Optimal solution *******************/
class Solution {
public:
// T.C = O(n)
// S.C = O(1)
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int ele = 0;
        for(int i=0; i<n; i++){
            if(cnt == 0){
                cnt = 1;
                ele = nums[i];
            }else if(nums[i] == ele){
                cnt++;
            }else {
                cnt--;
            }
        }
        int cnt1 = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == ele)cnt1++;
        }
        if(cnt1 > n/2){
            return ele;
        }
        return -1;
    }
};
