class Solution {
public:
    int numberOfSpecialChars(string word) {
     unordered_map<char,int> lower;
     unordered_map<char,int> upper;

     for(int i=0;i<word.size();i++){
        char c=word[i];

        if(islower(c)){
            lower[word[i]]=i;
        }
        else{
            char x = tolower(c);
            if(upper.find(x) == upper.end()) {
              upper[x]=i; 
             }
           
        }
     }

        int count=0;

        for(auto it:lower){
            char c=it.first;

            if(upper.find(c)!=upper.end()){
                if(lower[c] < upper[c]){
                    count++;
                }
            }
        }

return count;
        
    }
};