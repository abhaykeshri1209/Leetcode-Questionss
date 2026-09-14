class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {

       int overlap1=max(rec1[0], rec2[0]) < min(rec1[2], rec2[2]);
       int overlap2=max(rec1[1], rec2[1]) < min(rec1[3], rec2[3]);

       return overlap1 && overlap2;
        
    }
};