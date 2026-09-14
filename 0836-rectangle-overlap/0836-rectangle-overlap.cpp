class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = min(rec1[0],rec2[0]), y1 = min(rec1[1],rec2[1]), x2 = max(rec1[2],rec2[2]), y2 = max(rec1[3],rec2[3]);

        long long rec1_hori = abs(rec1[2]-rec1[0]), rec1_verti = abs(rec1[3]-rec1[1]);
        long long rec2_hori = abs(rec2[2]-rec2[0]), rec2_verti = abs(rec2[3]-rec2[1]);
        long long hori = abs(x2-x1) , verti = abs(y2-y1);
        if(rec1_hori+rec2_hori > hori && rec1_verti+rec2_verti > verti) return true;
        else return false;
    }
};