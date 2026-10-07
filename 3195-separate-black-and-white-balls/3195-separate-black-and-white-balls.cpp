class Solution {
public:
    long long minimumSteps(string s) {
        long long ones = 0;
long long steps = 0;

for (char c : s) {
    if (c == '1')
        ones++;
    else
        steps += ones;
}
return steps;
    }
};