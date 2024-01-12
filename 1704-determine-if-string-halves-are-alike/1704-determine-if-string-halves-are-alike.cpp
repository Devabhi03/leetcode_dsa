class Solution {
public:
    bool halvesAreAlike(string s) {
        
        int n = s.length();
        vector<char> s1;
        vector<char>s2;

        for(int i = 0 ; i <n/2; i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' 
            ||s[i]=='A'||s[i]=='E'||s[i]=='I'||s  [i]=='O'||s[i]=='U')
                          s1.push_back( tolower(s[i]));
        }
        for(int i = n/2 ; i <n; i++){
           
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'
             ||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
                    s2.push_back( tolower(s[i]));
        }

        if(s1.size() == s2.size()){
            return true;
        }

        return false;

    }
};