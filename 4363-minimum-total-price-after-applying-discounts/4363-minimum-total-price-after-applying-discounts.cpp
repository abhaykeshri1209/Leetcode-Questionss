class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end(), greater<int>());
        sort(discounts.begin(), discounts.end(), greater<int>());
        double total = 0;
    for(int i = 0; i < prices.size(); i++) {

    if (i < discounts.size()) {
                double finalPrice =
                    prices[i] * (100.0 - discounts[i]) / 100.0;

                total += finalPrice;
            }
            else {
                total += prices[i];
            }
  
    }
    
        return total;
    }
};