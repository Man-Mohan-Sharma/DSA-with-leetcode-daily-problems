class Solution {
public:
    int countCommas(int n) {
        if(n<1000) return 0;
        int ans = 0;
        while(n>=1000){
            int temp = n-1000;
            n = n/1000;
            ans+=temp+1;
        }
        return ans;
    }
};