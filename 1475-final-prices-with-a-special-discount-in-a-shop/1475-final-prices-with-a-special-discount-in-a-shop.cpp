class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
       vector<int> answer = prices;
        stack<int>st;

        for(int i=prices.size()-1;i>=0;i--){

        while (!st.empty() && st.top() > prices[i]) {
    st.pop();
}

if(!st.empty()){
answer[i]=answer[i]-st.top();
}

st.push(prices[i]);

        }

       return answer;
        
    }
};

// // int n=prices.size();
//         vector<int>answer;
//         bool flag=true;


//         for(int i=0;i<prices.size();i++){
//             flag=true;
//             for(int j=i+1;j<prices.size();j++){

//                 if(j>i && prices[j]<= prices[i]){
//                  int ans = prices[i] - prices[j];
//                     answer.push_back(ans);
//                     flag=false;
//                     break;
//                 }
               
                   
//             }
//              if(flag){
//                     answer.push_back(prices[i]);
//                     }
//         }
//         return answer;