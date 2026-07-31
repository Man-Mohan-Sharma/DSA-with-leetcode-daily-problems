class Solution {

static bool op(const int a, const int b){
        return a>b;
    }
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(auto & i : word) freq[i-'a']++;
        sort(freq.begin(),freq.end(),op);
        int count = 1, ans = 0;
        for(int i : freq){
            if(count<=8){
                count++;
                ans+= i*1;
            }
            else if(count<=16){
                count++;
                ans+=i*2;
            }
            else if(count<=24){
                count++;
                ans+=i*3;
            }
            else{
                count++;
                ans+=i*4;
            }
        }
        return ans;
    }
};