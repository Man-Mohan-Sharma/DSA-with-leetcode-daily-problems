class Solution {
private:
    set<pair<int,int>> visited;

   int find(const vector<pair<int,int>>& v1,
         const unordered_set<long long>& s,
         int n, int m) {

    int count = 0;

    for(auto& i : v1) {

        if(i.first < 0 || i.first >= n ||
           i.second < 0 || i.second >= m)
            continue;

        long long key = 1LL * i.first * m + i.second;

        if(s.count(key))
            count++;
    }

    return count;
}

    vector<pair<int,int>> right(const vector<pair<int,int>>& v1,int n, int m){
        vector<pair<int,int>> ans;

        for(auto& i : v1){
            int nj = i.second + 1;
            ans.push_back({i.first,nj});
        }

        return ans;
    }

    vector<pair<int,int>> left(const vector<pair<int,int>>& v1, int n, int m){
        vector<pair<int,int>> ans;

        for(auto& i : v1){
            int nj = i.second - 1;
            ans.push_back({i.first,nj});
        }

        return ans;
    }

    vector<pair<int,int>> up(const vector<pair<int,int>>& v1, int n, int m){
        vector<pair<int,int>> ans;

        for(auto& i : v1){
            int ni = i.first - 1;
            ans.push_back({ni,i.second});
        }

        return ans;
    }

    vector<pair<int,int>> down(const vector<pair<int,int>>& v1, int n, int m){
        vector<pair<int,int>> ans;

        for(auto& i : v1){
            int ni = i.first + 1;
            ans.push_back({ni,i.second});
        }

        return ans;
    }

    int solve(const vector<pair<int,int>>& v1,
              const unordered_set<long long>& s,
              int n,
              int m,
              int x,
              int y){

        // This translation has already been visited
        if(visited.count({x,y}))
            return 0;

        // Maximum useful translation
        if(x <= -n || x >= n || y <= -m || y >= m)
            return 0;

        visited.insert({x,y});

        int count = find(v1,s,n,m);

        int temp1 = solve(right(v1,n,m),s,n,m,x,y+1);
        count = max(count,temp1);

        int temp2 = solve(left(v1,n,m),s,n,m,x,y-1);
        count = max(count,temp2);

        int temp3 = solve(up(v1,n,m),s,n,m,x-1,y);
        count = max(count,temp3);

        int temp4 = solve(down(v1,n,m),s,n,m,x+1,y);
        count = max(count,temp4);

        return count;
    }

public:
    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2) {

        vector<pair<int,int>> v1;
        unordered_set<long long> s;

        int n = img1.size();
        int m = img1[0].size();

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){

                if(img1[i][j] == 1)
                    v1.push_back({i,j});

                if(img2[i][j] == 1){
                    long long key = 1LL * i * m + j;
                    s.insert(key);
                }
            }
        }

        visited.clear();

        return solve(v1,s,n,m,0,0);
    }
};