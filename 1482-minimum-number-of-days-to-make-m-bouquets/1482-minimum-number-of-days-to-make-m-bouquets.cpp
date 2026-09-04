class Solution {
private:
    bool func(vector<int>& bloomDay, int m, int k , int mid){
        int count = 0, adj = 0;
        for(auto & i : bloomDay){
            if(i<=mid){
                adj++;
            }
            else adj = 0;
            if(adj == k){
                count++;
                adj = 0;
            }
        }
        return count >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long size = 1LL * m * k;
        if(size > bloomDay.size()) return -1;
        int low = INT_MAX , high = INT_MIN;
        for(auto & i : bloomDay){
            low = min(low, i);
            high = max(high, i);
        }
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(func(bloomDay,m,k,mid)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};