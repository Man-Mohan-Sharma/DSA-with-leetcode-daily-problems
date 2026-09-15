class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0, ele1 = INT_MIN, ele2 = INT_MIN;
        for(auto& i : nums){
            if(count1==0 && i!=ele2){
                count1++;
                ele1 = i;
            }
            else if(count2==0 && i!=ele1){
                count2++;
                ele2 = i;
            }
            else if(ele1 == i) count1++;
            else if(ele2 == i) count2++;
            else{
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        int freq = nums.size()/3 + 1;
        count1 = 0, count2 = 0;
        for(auto& i : nums){
            if(i==ele1) count1++;
            if(i==ele2) count2++;
        }
        if(count1>=freq) ans.push_back(ele1);
        if(count2>=freq) ans.push_back(ele2);
        return ans;
    }
};