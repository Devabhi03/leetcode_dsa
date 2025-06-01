class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        int ans = 0;
        int n = mat1.size();
        int m = mat1[0].size();
        int size = n*m;
        int i=0;
        int j=size-1;
        
        while(i < size && j >= 0){
            int row1=i/n;
            int col1=i%n;
            int row2=j/n;
            int col2=j%n;
            
            
            int temp = mat1[row1][col1] + mat2[row2][col2];
            if(temp == x){
                ans++;
                i++;
                j--;
            }else if(temp < x){
                i++;
            }else{
                j--;
            }
        }
        
        return ans;
    }
};