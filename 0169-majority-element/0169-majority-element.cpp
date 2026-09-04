class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, pre = -1;
        for(auto& i : nums){
            if(count == 0){
                pre = i;
                count++;
            }
            else if(count >0){
                if(pre==i)  count++;
                else count--;
            }
            else count = 0;
        }
        return pre;
    }
};