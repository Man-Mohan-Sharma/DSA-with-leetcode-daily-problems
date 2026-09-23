class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> ans(37,0);
        for(int i = 1; i<=n; i++){
            int digit = 0, j = i;
            while(j>0){
                digit+=j%10;
                j/=10;
            }
            
            ans[digit]++;
    
        }
        int count = 1, maxx = ans[0];
        for(int i = 1; i<37; i++){
            if(ans[i]==maxx) count++;
            else if(ans[i]>maxx){
                count = 1;
                maxx = ans[i];
            }
        }
        return count;
    }
};