class dsu{
public:
    vector<int> parent;
    vector<int> size;
    dsu(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i = 1; i<n; i++) parent[i] = i;
    }

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b){
        int root_a = find(a);
        int root_b = find(b);
        if(root_a == root_b) return ;
        else if(size[root_a]<size[root_b]){
            parent[root_a] = root_b;
            size[root_b]+=size[root_a];
        }
        else{
            parent[root_b] = root_a;
            size[root_a]+=size[root_b];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        dsu obj(edges.size()+1);
        int u,v;
        for(auto & i : edges){
            if(obj.find(i[0])==obj.find(i[1])){
                u = i[0];
                v = i[1];
            }
            obj.unite(i[0],i[1]);
        }
        return {u,v};
    }
};