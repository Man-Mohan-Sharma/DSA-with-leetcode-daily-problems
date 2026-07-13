class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string num = "123456789";
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i = 2; i<=9; i++){
            for(int j = 0; j<9; j++){
                int temp = stoi(num.substr(j,i));
                if(mp.contains(temp)) continue;
                else if(temp<low) continue;
                else if(temp>high) break;
                else{
                    ans.push_back(temp);
                    mp[temp]++;
                }
            }
        }
        return ans;
    }
};