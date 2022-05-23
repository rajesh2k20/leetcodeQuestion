// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        
        int sum=0;
        int sum1=0;
        set<int> s;
        for(int i=0; i<n;i++){
            sum+=A[i];
            s.insert(A[i]);
        }
        for(int i=0; i<m;i++){
            sum+=B[i];
            sum1+=B[i];
        }
        
        if(sum%2==0){
            
         for(int i=0;i<m;i++){
             
         int req= (sum/2)-sum1+ B[i];
          
          if(s.count(req)==1){
              return 1;
          }
         }
         
         return -1;
            
            
        }else{
            return -1;
        }
	}
 

};

// { Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}





  // } Driver Code Ends