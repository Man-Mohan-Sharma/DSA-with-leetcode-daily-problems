class Solution {
public:
    int maxProduct(int n) {
        int pre = 0, maxi = 0;
        while(n>0){
            int rem = n%10;
            if(maxi<=rem){
                pre = maxi;
                maxi = rem;
            }
            else if(rem>=pre && rem<=maxi) pre = rem;
            n/=10;
        }
        return maxi*pre;
    }
};