class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
          int n = numCourses;
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

          for(auto prerequisite : prerequisites) {
            int a =prerequisite[0];
            int b = prerequisite[1];
         adj[b].push_back(a);
          indegree[a]++;
        }

         queue<int>q;
         for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
         }

         vector<int> ans;

          while(!q.empty()){

            int node=q.front();
            q.pop();
            ans.push_back(node);

             for(auto neighbour : adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0) {
              q.push(neighbour);
              }
             }
         }

         if(ans.size() != numCourses){
             return {};
         }
   
         return ans;

    }
};