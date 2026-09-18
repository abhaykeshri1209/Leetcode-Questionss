class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
         vector<vector<int>> dislike(n + 1);

     
        for(auto it : dislikes) {
            int a = it[0];
            int b = it[1];

            dislike[a].push_back(b);
            dislike[b].push_back(a);
        }



     vector<int> color(n + 1, -1);
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                queue<int>q;
                q.push(i);
                color[i]=0;


                while(!q.empty()){
                    int node=q.front();
                    q.pop();

                   for(auto it : dislike[node]){
                        if(color[it]==-1){
                            color[it] =!color[node];
                            q.push(it);
                        }
                        else if(color[it]==color[node]){
                            return false;
                        }
                    }
                }
            }
           

        } return true;
    }
};