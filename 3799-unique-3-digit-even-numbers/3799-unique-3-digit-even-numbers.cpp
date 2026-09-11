class Solution {
public:
    int totalNumbers(vector<int>& digits) {

       
        set<int> ans;


        for(int i = 0; i < digits.size(); i++) {       

    for(int j = 0; j < digits.size(); j++) {   

        for(int k = 0; k < digits.size(); k++) { 

           if(i != j && j != k && i != k){

                if(digits[i] != 0 && digits[k] % 2 == 0){
                  int number = digits[i] + digits[j] * 10 + digits[k] * 100;
                 ans.insert(number);
                }
            }
        }
    }
}
return ans.size();
        
    }
};