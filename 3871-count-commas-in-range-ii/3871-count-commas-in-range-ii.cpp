class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) return 0;
        long long startrange = 1000;
        long long endrange = startrange*1000 -1;
        int comma = 1;
        long long ans = 0;
        while(startrange<=n){
            long long number = min(n,endrange)-startrange+1;
            ans+= 1LL * number * comma;
            if(endrange > n) break;
            comma++;
            startrange *= 1000;
            endrange = startrange*1000 -1;
        }
        return ans;
    }
};