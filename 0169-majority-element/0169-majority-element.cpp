class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, pre = -1;
        for(auto& i : nums){
            if(count == 0){
                count++;
                pre = i;
            }
            else if(pre == i) count++;
            else count--;
            }
            return pre;
        }
};