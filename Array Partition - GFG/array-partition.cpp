// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
int dp[1000000];
class Solution{
    public:
    bool helper(int index, int k, int m, vector<int> & arr){
        
        
        if(index==arr.size()){
            
            return true;
        }
        
        if(dp[index] !=-1){
            
            return dp[index];
        }
        
        int size= arr.size()-index+1;
        if(size>=k){
            
            for(int i= index+k-1;i<arr.size();i++){
                
                if(arr[i]-arr[index]<=m){
                    
                bool curr= helper(i+1, k, m, arr);
                 if(curr==true){
                     return dp[index]=true;
                 }
                }
            }
            
        }else{
            return dp[index]=false;
        }
        
        return dp[index]=false;
    }
    bool partitionArray(int N, int K, int M, vector<int> &arr){
       
       
       sort(arr.begin(), arr.end());
       
       memset(dp, -1, sizeof(dp));
       
       return helper(0, K, M, arr);
       
    }
};

// { Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, K, M;
        cin >> N >> K >> M;
        vector<int> A(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        Solution obj;
        bool ans = obj.partitionArray(N, K, M, A);
        if(ans){
            cout << "YES\n";
        }
        else{
            cout<< "NO\n";
        }
    }
}
  // } Driver Code Ends