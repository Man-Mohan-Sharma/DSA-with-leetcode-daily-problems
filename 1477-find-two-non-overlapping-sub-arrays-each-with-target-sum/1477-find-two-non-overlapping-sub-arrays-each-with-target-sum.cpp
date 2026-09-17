class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> prefix(n,1e9), suffix(n,1e9);
        int i = 0, j = 0;
        int current = 0, len = 1e9;
        while(j<n){
            current+=arr[j];
            while(i<=j && current > target) current-=arr[i++];
            if(current == target){
               len = min(len,j-i+1);
            }
            prefix[j] = len;
            j++;
        }
        i = n-1, j = n-1, current = 0, len = 1e9;

        while(j >= 0) {
            suffix[j] = len;
            current += arr[j];

            while(i >= j && current > target)
                current -= arr[i--];

            if(current == target)
                len = min(len, i-j+1);

            j--;
        }
        int ans = INT_MAX;
        for(i = 0; i<n; i++){
            if(suffix[i]!=1e9 && prefix[i]!=1e9) ans = min(ans,suffix[i]+prefix[i]);
        }
        return (ans==INT_MAX)?-1:ans;
    }
};