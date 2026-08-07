class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
 sort(deck.begin(), deck.end());

queue<int> q;
vector<int> ans(deck.size());

for (int i = 0; i < deck.size(); i++) {
    q.push(i);
}

for (int i = 0; i < deck.size(); i++) {

    int index = q.front();
    q.pop();

    ans[index] = deck[i];

    if (!q.empty()) {
        q.push(q.front());
        q.pop();
    }
}

return ans;
    }
};