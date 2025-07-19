class Solution {
   public:
  int fact(int num){
      if(num==0){
          return 1;
      }
      
      return num*fact(num-1);
  }
    int vowelCount(string& s) {
        // code here
        map<char,int>freq;
        int cnt=0;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch=='a'|| ch=='i'|| ch=='e' || ch=='o' || ch=='u'){
                if(freq[ch]==0){
                    cnt++;
                }
                freq[ch]++;
            }
        }
       if(cnt==0){
           return 0;
       }
      int total=fact(cnt);
      for(const auto temp:freq){
          total=total*temp.second;
      }
      return total;
        
    }
};