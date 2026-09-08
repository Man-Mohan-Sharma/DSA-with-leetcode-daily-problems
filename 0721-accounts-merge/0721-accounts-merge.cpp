class DSU{
public:
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        parent.resize(n);
        for(int i = 0; i<n; i++) parent[i] = i;
        size.resize(n,1);
    }
    int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int a, int b){
        int root_a = find(a);
        int root_b = find(b);
        if(root_a == root_b) return;
        if(size[root_a] > size[root_b]){
            parent[root_b] = root_a;
            size[root_a] += size[root_b];
        }
        else{
            parent[root_a] = root_b;
            size[root_b] += size[root_a];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> mp;
        vector<vector<string>> merge(accounts.size());
        DSU dsu = DSU(accounts.size());
        for(int i = 0; i<accounts.size(); i++){
            for(int j = 1; j<accounts[i].size(); j++){
                if(mp.find(accounts[i][j]) != mp.end()){
                    dsu.unite(i,mp[accounts[i][j]]);
                }
                else mp[accounts[i][j]] = i;
            }
        }
        for(auto & i : mp){
            int root = dsu.find(i.second);
            merge[root].push_back(i.first);
        }
        vector<vector<string>> ans;

        for(int i = 0; i < accounts.size(); i++){

            if(merge[i].empty())
                continue;

            sort(merge[i].begin(), merge[i].end());

            vector<string> temp;

            temp.push_back(accounts[i][0]);

            for(auto &email : merge[i]){
                temp.push_back(email);
            }

            ans.push_back(temp);
        }
        return ans;
    }
};