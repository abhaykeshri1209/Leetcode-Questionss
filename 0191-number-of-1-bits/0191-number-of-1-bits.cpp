class Solution {
public:
    int hammingWeight(int n) {
 vector<int> binary;

while (n > 0) {
    binary.push_back(n % 2);
    n /= 2;
}

reverse(binary.begin(), binary.end());
int count=0;

     for (int i = 0; i < binary.size(); i++){
         if(binary[i]==1){
            count++;
         }
     }
return count;
    }
};