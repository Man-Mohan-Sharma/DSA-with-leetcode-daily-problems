class Solution {
public:
    int findGCD(vector<int>& nums) {
        int s = INT_MAX, l = INT_MIN;
        for(auto & i : nums){
            s = min(s,i);
            l = max(l,i);
        }
        return gcd(s,l);
    }
};