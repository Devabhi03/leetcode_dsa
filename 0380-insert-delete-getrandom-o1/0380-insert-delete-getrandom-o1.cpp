class RandomizedSet {
public:
        unordered_map<int,int>mpp;
        vector<int> ans;
    RandomizedSet() {
    }
    bool find(int val){
        return mpp.find(val) != mpp.end();
    }
    bool insert(int val) {
       if(find(val)) return false;
       ans.push_back(val);
       mpp[val] = ans.size()-1;
       return true;
    }
    
    bool remove(int val) {
       if(!find(val)) return false;

       int last_val = ans[ans.size()-1];
       int val_index = mpp[val];
       ans[val_index] = last_val; 
       mpp[last_val] = val_index;
       ans.pop_back();
       mpp.erase(val);
       return true;
    }
    
    int getRandom() {
        return ans[rand()%ans.size()];
    }
};