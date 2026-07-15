class Solution {
public:
static bool comparator(pair<char, int>& a, pair<char, int>& b) {
    return a.second > b.second;
}
    string frequencySort(string s) {
        unordered_map<char, int> m;

        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
          vector<pair<char,int>>v;


          for (auto it : m) {
        v.push_back(it);
       }

       sort(v.begin(), v.end(), comparator);
      string ans;

       for (auto it : v) {
        for (int i = 0; i < it.second; i++) {
        ans += it.first;
      }
}  

return ans;
      
    }
};