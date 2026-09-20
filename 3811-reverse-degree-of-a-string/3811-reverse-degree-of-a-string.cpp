class Solution {
public:
    int reverseDegree(string s) {
        int position =1;
        int product=0;
        for(int i=0;i<s.size();i++){
         int rev = 26 - (s[i] - 'a');
         product+=rev*position;
         position++;


        }
        return product;
    }
};