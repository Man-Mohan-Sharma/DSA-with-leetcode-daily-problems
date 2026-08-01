class Solution {
private:
    long long game(vector<int>& nums, int i , int j){
        if(i>j) return 0;
        if(i==j) return nums[i];
        long long taken_i = nums[i]+ min(game(nums,i+1,j-1),game(nums,i+2,j));
        long long taken_j = nums[j] + min(game(nums,i+1,j-1),game(nums,i,j-2));
        return max(taken_i, taken_j);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        long long sum = 0;
        for(auto i : nums) sum+=i;
        long long player_1 = game(nums,0,nums.size()-1);
        return player_1 >= sum-player_1;
    }
};