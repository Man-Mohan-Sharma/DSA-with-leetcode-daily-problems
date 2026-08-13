class Solution {
public:
    struct node{
        int maxlen = 0;
        int prefixlen = 0;
        int sufixlen = 0;
        char prefix = 0;
        char sufix = 0;
    };
    vector<node> segmentTree;

    node merge(node& l  , node& r, int left, int right){
        node result;
        result.prefix = l.prefix;
        result.sufix = r.sufix;
        result.prefixlen = l.prefixlen;
        if(l.prefixlen==left && l.sufix == r.prefix){
            result.prefixlen = l.prefixlen+r.prefixlen;
        }
        result.sufixlen = r.sufixlen;
        if(r.sufixlen == right && r.prefix == l.sufix){
            result.sufixlen = l.sufixlen+r.prefixlen;
        }
        result.maxlen = max(l.maxlen,r.maxlen);

        if(l.sufix == r.prefix) result.maxlen = max(result.maxlen, l.sufixlen+r.prefixlen);
        return result;
    }

    void buildSegmentTree(int i, int l, int r, string& s){
        if(l==r){
            segmentTree[i] = {1,1,1,s[l],s[l]};
            return;
        }
        int mid = l+(r-l)/2;
        buildSegmentTree(2*i+1,l,mid,s);
        buildSegmentTree(2*i+2,mid+1,r,s);
        segmentTree[i] = merge(segmentTree[2*i+1],segmentTree[2*i+2],mid-l+1, r-mid);
    }

    void update(int i, int l, int r, int target, char ch){
        if(r==l){
            segmentTree[i] = {1,1,1,ch,ch};
            return;
            }
        int mid = l+(r-l)/2;
        if(target<=mid) update(2*i+1,l,mid,target,ch);
        else update(2*i+2,mid+1,r,target,ch);
        segmentTree[i] = merge(segmentTree[2*i+1],segmentTree[2*i+2],mid-l+1, r-mid);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        segmentTree.resize(4*n,node());
        buildSegmentTree(0,0,n-1,s);
        int k = queryIndices.size();
        vector<int> result(k);
        for(int i = 0; i<k; i++){
            int ind = queryIndices[i];
            char ch = queryCharacters[i];
            update(0,0,n-1,ind,ch);
            result[i] = segmentTree[0].maxlen;
        }
        return result;
    }
};