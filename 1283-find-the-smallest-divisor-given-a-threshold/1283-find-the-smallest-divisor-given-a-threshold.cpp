class Solution {
private:
    int divisor(vector<int>& nums,int k){
        int total = 0;
        for(auto& i : nums) total+= ceil(double(i)/double(k));
        return total;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long sum = 0;
        for(auto& i : nums) sum+=i;
        long long low = 1, high = sum;
        int ans = sum;
        while(low<=high){
            long long mid = low+(high-low)/2;
            int x = divisor(nums,mid);
            if(x<=threshold){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};