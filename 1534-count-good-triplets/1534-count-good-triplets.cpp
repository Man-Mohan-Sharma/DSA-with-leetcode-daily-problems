class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        vector<int> freq(1001,0);
        int ans = 0;
        for(int j = 1; j<arr.size(); j++){
            freq[arr[j-1]]++;
            vector<int> prefix(1001,0);
            prefix[0] = freq[0];
            for(int i = 1; i<1001; i++) prefix[i] = prefix[i-1]+freq[i];
            for(int k = j+1; k<arr.size(); k++){
                if(abs(arr[j]-arr[k])>b) continue;
                int l = max(0,max(arr[j]-a,arr[k]-c));
                int r = min(1000,min(arr[j]+a,arr[k]+c));
                if(l>r) continue;
                ans+= prefix[r];
                if(l>0) ans-=prefix[l-1];
            }
        }
        return ans;
    }
};