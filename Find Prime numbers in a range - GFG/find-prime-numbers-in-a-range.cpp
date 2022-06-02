// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
const int limit=1e6;
vector<int> prime(limit+1, 1);
vector<int> plist;
void sieve(){

   prime[0]=0;
   prime[1]=0;
   for(int i=2;i*i<=limit;i++){

      if(prime[i]==1){

        for(int j=i*i; j<=limit;j+=i){
           
           prime[j]=0;
        }
      }
   }


   for(int i=2;i<=limit;i++){

      if(prime[i]==1){
         plist.push_back(i);
      }
   }


}
void solve(int l, int r, vector<int> & ans){


   

    

   

    vector<int> arr(r-l+1,1);
    
    if(l==1){
        
        arr[0]=0;
    }

    for(int i=0; plist[i]*plist[i]<=r;i++){

        int curr=plist[i];

        int val= (l/curr)*curr;

        if(val<l){
            val+=curr;
        }

      for(int j=val; j<=r;j+=curr){

          int index= j-l;

          arr[index]=0;
      }

      if(val==curr){
         arr[val-l]=1;
      }

    }


    for(int i=0; i<arr.size();i++){

        if(arr[i]==1){
            ans.push_back(i+l);
        }
    }
    
    
}
bool check=true;
class Solution {
  public:
 
    vector<int> primeRange(int M, int N) {
        if(check==true){
            sieve();
            check=false;
        }
        vector<int> ans;
        solve(M,N, ans);
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}  // } Driver Code Ends