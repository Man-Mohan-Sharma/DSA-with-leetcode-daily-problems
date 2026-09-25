class Solution {
private:
    long long find(vector<int>& piles, int k){
        long long  total = 0;
        for(auto& i : piles){
            total+= (i+k-1)/k;
        }
        return total;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int low = 1, high = piles[piles.size()-1];
        int ans = high;
        while(low<=high){
            long long mid = low+(high-low)/2;
            if(find(piles,mid)<=h){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};