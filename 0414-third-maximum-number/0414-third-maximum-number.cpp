class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long maxx = -1e14, maxx2 = -1e14, maxx3 = -1e14;
        for(auto& i : nums){
            if(i>maxx){
                maxx3 = maxx2;
                maxx2 = maxx;
                maxx = i;
            }
            else if(i>maxx2 && i!=maxx){
                maxx3 = maxx2;
                maxx2 = i;
            }
            else if(i>maxx3 && i!=maxx && i!=maxx2) maxx3 = i;
            else continue;
        }
        return maxx3==-1e14?maxx:maxx3;
    }
};