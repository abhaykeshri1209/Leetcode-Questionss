class Solution {
public:

    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
      
        for (int i = 0; i < asteroids.size(); i++) {
             bool destroyed = false;
    int asteroid = asteroids[i];
          while (!st.empty() && st.top() > 0 && asteroid < 0) {

    if (abs(st.top()) < abs(asteroid)) {
        st.pop();                 
    }
    else if (abs(st.top()) == abs(asteroid)) {
        st.pop();               
        destroyed = true;
        break;
    }
    else {
        destroyed = true;        
        break;
    }
}
            
            if (!destroyed) {
                st.push(asteroid);
                 }
        }
        vector<int> ans;

while (!st.empty()) {
    ans.push_back(st.top());
    st.pop();
}

reverse(ans.begin(), ans.end());

return ans;

    }
};