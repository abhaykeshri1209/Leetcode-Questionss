class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
      vector<vector<pair<int, double>>> adj(n);
      
      for (int i = 0; i < edges.size(); i++) {
         int u = edges[i][0]; 
         int v = edges[i][1];
          adj[u].push_back({v, succProb[i]}); 
          adj[v].push_back({u, succProb[i]});
           }

       vector<double> prob(n, 0.0); 
       prob[start_node] = 1.0;

       priority_queue<pair<double, int>> pq;

       pq.push({1.0, start_node});

       while(!pq.empty()){
        double currentProb = pq.top().first; 
        int node = pq.top().second;
         pq.pop();
         if (node == end_node)
          return currentProb;
        

        for( auto neighbour:adj[node]){
           int adjNode = neighbour.first;
            double edgeProb = neighbour.second; 

           double newProb = currentProb * edgeProb;

           if(newProb> prob[adjNode]){
            prob[adjNode]=newProb;
            pq.push({newProb, adjNode});
           }

        }


       }
return 0;

    }
};