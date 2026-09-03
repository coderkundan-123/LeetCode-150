class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int h = 0;
        sort(rbegin(citations), rend(citations));
        for(int i=0; i<n; i++){
            if(citations[i] >= i+1){
                h = i+1;
            }else{
                break;
            }
        }

        return h;
    }
};