class Solution {
public:
    void reverseString(vector<char>& s) {
        // reverse(s.begin(),s.end());

       stack<char>st;
for(int i=0;i<s.size();i++){
    st.push(s[i]);
}
int i=0;
while(!st.empty()){
   s[i]= st.top();
   i++;
    st.pop();
}
    
    }
};

//using stack 
// stack<char>st;
// for(int i=0;i<s.size();i++){
//     st.push(s[i]);
// }
// int i=0;
// while(!st.empty()){
//    s[i]= st.top();
//    i++;
//     st.pop();
// }