class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> winners,loosers;
        vector<vector<int>>sol(2,vector<int>(0));
        for(auto match :  matches){
            winners[match[0]]++;
            loosers[match[1]]++;
        }

        for(auto winner : winners){
            // cout<<winner.first<<" : "<<winner.second<<endl;
            int player = winner.first;
            if(loosers.find(player) == loosers.end())
                sol[0].push_back(player);
        }
        
        for(auto looser : loosers){
            // cout<<looser.first<<" : "<<looser.second<<endl;
            int player = looser.first;
            if(looser.second ==  1)
                sol[1].push_back(player);
        }
        return sol;
    }
};