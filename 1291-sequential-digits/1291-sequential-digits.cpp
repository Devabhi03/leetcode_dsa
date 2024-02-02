class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> ans;
        for(int i= 2; i<=s.length() ;i++) {
            for(int j=0;j<=s.length()-i;j++){
                string temp = s.substr(j,i);
                int poss = stoi(temp);

                if(low <= poss && poss<= high)
                    ans.push_back(poss);
            }
        }
        return ans;
    }
};