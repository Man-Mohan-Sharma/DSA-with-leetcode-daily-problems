class Solution {
    struct Node{
        vector<int> arr;
        long long score = INT_MIN;
    };

private:
    int find(vector<vector<int>>& intervals, int low, int high, int target){
        int ans = intervals.size();
        while(low<=high){
            int mid = low+(high-low)/2;
            if(intervals[mid][0]>target){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }

    Node solve(vector<vector<int>>& intervals, int i, int k,vector<int>& nextterm,vector<vector<Node>>& dp){
        if(i >= intervals.size() || k == 4) {
            Node base;
            base.score = 0;
            return base;
        }
        if(dp[i][k].score!=INT_MIN) return dp[i][k];
        Node skip = solve(intervals,i+1,k,nextterm,dp);
        Node taken = solve(intervals,nextterm[i],k+1,nextterm,dp);
        int idx = intervals[i][3];
        long long score = intervals[i][2];
        taken.arr.push_back(idx);
        taken.score+=score;
        sort(taken.arr.begin(),taken.arr.end());
        Node result;
        if(skip.score>taken.score) result = skip;
        else if(taken.score>skip.score) result = taken;
        else{
            result = (skip.arr < taken.arr)?skip:taken;
        }
        return  dp[i][k] = result;
    }

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        for(int i = 0; i<intervals.size(); i++) intervals[i].push_back(i);
        int n = intervals.size();
        vector<vector<Node>> dp(n,vector<Node>(4,Node()));
        sort(intervals.begin(),intervals.end());
        vector<int> nextterm(n);
        for(int i = 0; i<n; i++){
            nextterm[i] = find(intervals,i+1,n-1,intervals[i][1]);
        }
        Node result = solve(intervals,0,0,nextterm,dp);
        return result.arr;
    }
};