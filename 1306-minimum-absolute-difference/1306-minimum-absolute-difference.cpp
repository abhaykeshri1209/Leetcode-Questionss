class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;

        int mini=INT_MAX;

        for(int i=0;i<arr.size()-1;i++){

            int small=arr[i+1]-arr[i];

           mini = min(mini, small);
           
        }
        for(int i = 0; i < arr.size()-1; i++){

    int small = arr[i+1] - arr[i];

    if(small == mini){
       ans.push_back({arr[i], arr[i+1]});
    }
}

return ans;
        
    }
};