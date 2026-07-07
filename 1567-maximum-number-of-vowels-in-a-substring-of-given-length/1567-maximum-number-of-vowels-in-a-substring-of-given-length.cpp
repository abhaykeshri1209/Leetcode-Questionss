class Solution {
public:

 bool isVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' ||
            ch == 'o' || ch == 'u') {
            return true;
        }

        return false;
    }
    int maxVowels(string s, int k) {
        int left=0;
        int count=0;

        for(int right=0;right<k;right++){
            if(isVowel(s[right]))
            count++;
            
        }
        int ans=count;
        
      for (int right = k; right < s.size(); right++) {

    if (isVowel(s[right])) {
        count++;
    }

    if (isVowel(s[left])) {
        count--;
    }

    left++;

    ans = max(ans, count);
}
return ans;
    }
};