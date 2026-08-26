class DSU{
public:
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i = 0; i<n; i++) parent[i] = i;
    }
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b){
        int root_a = find(a);
        int root_b = find(b);
        if(root_a == root_b) return;
        else if(size[root_a]<size[root_b]){
            parent[root_a]  = root_b;
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
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DSU dsu = DSU(n);
        for(auto & i : edges) dsu.unite(i[0],i[1]);
        return dsu.find(source)==dsu.find(destination);
    }
};