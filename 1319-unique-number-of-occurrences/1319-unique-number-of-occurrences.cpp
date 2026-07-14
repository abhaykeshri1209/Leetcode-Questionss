class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq;

for(int num:arr)
{
    freq[num]++;
}    
    
      unordered_set<int> st;
     
    for (auto it : freq) {
            if (st.count(it.second)) {  
                return false;
            }
            st.insert(it.second);
        }

        return true;


    }
};