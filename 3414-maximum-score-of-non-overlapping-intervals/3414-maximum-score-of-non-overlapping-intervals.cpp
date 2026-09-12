class Solution {
    struct Node {
        vector<int> arr;
        long long score = LLONG_MIN;
    };

private:
    int findNext(vector<vector<int>>& intervals,
                 int low,
                 int high,
                 int target) {

        int ans = intervals.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (intervals[mid][0] > target) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }

    Node solve(vector<vector<int>>& intervals,
               int i,
               int k,
               vector<int>& nextterm,
               vector<vector<Node>>& dp) {

        if (i >= intervals.size() || k == 4) {
            Node base;
            base.score = 0;
            return base;
        }

        if (dp[i][k].score != LLONG_MIN)
            return dp[i][k];

        // Don't take
        Node skip = solve(
            intervals,
            i + 1,
            k,
            nextterm,
            dp
        );

        // Take
        Node taken = solve(
            intervals,
            nextterm[i],
            k + 1,
            nextterm,
            dp
        );

        int originalIndex = intervals[i][3];
        long long weight = intervals[i][2];

        taken.score += weight;
        taken.arr.push_back(originalIndex);

        // Important for lexicographical comparison
        sort(taken.arr.begin(), taken.arr.end());

        Node result;

        if (taken.score > skip.score) {
            result = taken;
        }
        else if (skip.score > taken.score) {
            result = skip;
        }
        else {
            // vector comparison is lexicographical
            result = (taken.arr < skip.arr) ? taken : skip;
        }

        return dp[i][k] = result;
    }

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // Store original index
        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }

        // Sort according to starting point
        sort(intervals.begin(), intervals.end());

        vector<int> nextterm(n);

        for (int i = 0; i < n; i++) {
            nextterm[i] = findNext(
                intervals,
                i + 1,
                n - 1,
                intervals[i][1]
            );
        }

        vector<vector<Node>> dp(
            n,
            vector<Node>(4)
        );

        Node result = solve(intervals,0,0,nextterm,dp);

        return result.arr;
    }
};