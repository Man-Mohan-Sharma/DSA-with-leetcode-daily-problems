class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x = max(x1,min(xCenter,x2));
        int y = max(y1,min(yCenter,y2));

        long long dist_x = x-xCenter, dist_y = y-yCenter;
        return dist_x*dist_x + dist_y*dist_y <= (1LL)*radius*radius;
    }
};