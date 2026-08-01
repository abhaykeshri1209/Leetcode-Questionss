class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low < high) {
            int mid = (low + high) / 2;

            int day_used = 1;  
            int load = 0;

            for(int w : weights) {
                if(load + w <= mid) {
                    load += w;
                } else {
                    day_used++;
                    load = w;
                }
            }

            if(day_used <= days)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};