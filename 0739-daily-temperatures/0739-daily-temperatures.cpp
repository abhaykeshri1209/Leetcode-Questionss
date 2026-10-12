class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
         vector<int> answer(n, 0);
        stack<int>st;
        
        for(int i=n-1;i>=0;i--){
            while( !st.empty() && temperatures[st.top()] <= temperatures[i] ){
                st.pop();
            }

            if(!st.empty()){
                int days= st.top()-i;
              answer[i]=days;

            }
            st.push(i);
        }

return answer;

        
    }
};

//my approach and getting tle of both approach 
//   vector<int>ans; 
//         for(int i=0;i<temperatures.size();i++){
//             bool found=false;
//             for(int j=i+1;j<temperatures.size();j++){
//                 if(temperatures[j]>temperatures[i]){
//                     int value=j-i;
//                     ans.push_back(value);
//                     found =true;
//                     break;

//                 } 
//                 if(!found){
//                     ans.push_back(0);
//                 }
                    
//                 }
//             }


//         return ans;
        
//     }
// };