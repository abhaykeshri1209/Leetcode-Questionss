class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {

        unordered_set<string> st(bank.begin(), bank.end());

        // If endGene is not present, transformation is impossible
        if (st.find(endGene) == st.end()) {
            return -1;
        }

        queue<pair<string, int>> q;
        q.push({startGene, 0});

        st.erase(startGene);

        string genes = "ACGT";

        while (!q.empty()) {

            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (word == endGene) {
                return steps;
            }

            for (int i = 0; i < word.size(); i++) {

                char original = word[i];

                for (char ch : genes) {

                    if (ch == original)
                        continue;

                    word[i] = ch;

                    if (st.find(word) != st.end()) {

                        st.erase(word);

                        q.push({word, steps + 1});
                    }
                }

                word[i] = original;
            }
        }

        return -1;
    }
};