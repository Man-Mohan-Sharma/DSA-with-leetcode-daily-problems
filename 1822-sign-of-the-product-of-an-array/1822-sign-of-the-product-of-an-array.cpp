class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count_negative = 0;
        for(auto& i : nums){
            if(i==0) return 0;
            else if(i<0) count_negative++;
        }
        return (count_negative%2==0)?1:-1;
    }
};