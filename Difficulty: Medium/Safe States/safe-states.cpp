class Solution {
  private:
    bool solve(int node, vector<vector<int>> &adj,vector<int> &vis,vector<int> &pathVis,vector<int> &check){
        vis[node]=1;
        pathVis[node]=1;
        check[node]=0;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                if(solve(it,adj,vis,pathVis,check)==true){
                    //check[node]=0;
                    return true;
                }
            }
            else if(pathVis[it]){
                //check[node]=0;
                return true;
            }
        }
        
        pathVis[node]=0;
        check[node]=1;
        return false;
        
    }
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // code here
        
        vector<vector<int>> adj(V);
        
        for(auto it: edges){
            int u=it[0];
            int v=it[1];
            
            adj[u].push_back(v);
            
        }
        
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        vector<int> check(V,0);
        vector<int> ans;
        
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bool temp=solve(i,adj,vis,pathVis,check);
            }
        }
        
        for(int i=0;i<V;i++){
            if(check[i]==1){
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
};