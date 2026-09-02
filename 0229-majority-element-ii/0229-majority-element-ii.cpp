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

/*********************** most Optimal Solution in cpp **************************/
class Solution {
public:
        /*  ⏱️ Time Complexity

        There are 3 main operations:

        First for loop → O(n)
        Second for loop → O(n)
        sort(li.begin(), li.end())

        Important point: li can contain at most 2 elements, because elements occurring more than n/3 can be at most 2.

        So sorting li is:

        O(2 log 2) = O(1)

        Therefore:

        Total T.C = O(n) + O(n) + O(1) = O(n)
            S.C = O(1) 

        */
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        int ele1 = 0, ele2 = 0;

        for(int i=0; i<n; i++){ // O(n)
            if(cnt1 == 0 && nums[i] != ele2){
                cnt1++, ele1 = nums[i];
            }else if(cnt2 == 0 && nums[i] != ele1){
                cnt2++, ele2 = nums[i];
            }else if(ele1 == nums[i]){
                cnt1++;
            }else if(ele2 == nums[i]){
                cnt2++;
            }else{
                cnt1--,cnt2--;
            }
        }

        vector<int> li;
        cnt1 = 0, cnt2=0;
        for(int i=0; i<n; i++){ //O(n)
            if(ele1 == nums[i])cnt1++;
            if(ele2 == nums[i])cnt2++;
        }
        int mini = (int)(n/3) + 1;
        if(cnt1 >= mini)li.push_back(ele1);
        if(cnt2 >= mini)li.push_back(ele2);
        sort(li.begin(), li.end());

        return li;
    }
};
