//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int find(int val,int l,int r,vector<int>&suff)
    {
        int ind=l-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(suff[mid]<val)
            {
                r=mid-1;
            }
            else{
                ind=mid;
                l=mid+1;
            }
        }
        return ind;
    }
    int maxIndexDiff(int A[], int N) 
    {  
       if(N==1)
         return 0;
       
       vector<int>suff(N);
       suff[N-1]=A[N-1];
       for(int i=N-2;i>=0;i--)
       {
           suff[i]=max(suff[i+1],A[i]);
       }

       int res=0;
       for(int i=0;i<N;i++)
       {
           int x=find(A[i],i+1,N-1,suff);
           res=max(res,x-i);
       }
       return res;
    }
};


//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends