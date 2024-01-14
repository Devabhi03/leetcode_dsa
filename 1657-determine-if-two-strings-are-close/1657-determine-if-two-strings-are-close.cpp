class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        vector<int> v1(26) ,v2(26),v11(26,0),v22(26,0);

        for(auto it : word1)v1[it-'a']++,v11[it-'a']=1;
        for(auto it : word2)v2[it-'a']++,v22[it-'a']=1;

        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());

        return v1==v2 && v11==v22;


    }
};;