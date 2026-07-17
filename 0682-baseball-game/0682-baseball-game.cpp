class Solution {
public:
bool isDigit(string s) {
    if (s.empty()) return false;

    int i = 0;

    if (s[0] == '-') {
        if (s.size() == 1)
            return false;
        i = 1;
    }

    for (; i < s.size(); i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }

    return true;
}

    int calPoints(vector<string>& operations) {
        stack<int>st;
       for (string &op : operations){

           if (isDigit(op)){
            int ans=stoi(op);
            st.push(ans);
           }
            
          else if(op=="C"){
             st.pop();
          }

           else if(op=="D"){
          int score=  st.top();
          score=score*2;
          st.push(score);

           }
             
           else if(op =="+"){
            int first = st.top();
            st.pop();

            int second = st.top();
            st.push(first);
            int sum = first + second;
            st.push(sum);

           }

        }
     int sum = 0;

stack<int> temp = st;  

while (!temp.empty()) {
    sum += temp.top();
    temp.pop();
}

return sum;

    }
};