// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
int dp[1001][1001];
class Solution{
  public:
    int helper(int i, int j, string & str){
        
        if(i>=j){
            return 0;
        }
        
        
        if(dp[i][j] !=-1){
            return dp[i][j];
        }
        
       if(str[i]==str[j]){
           
           return  dp[i][j]=helper(i+1, j-1, str);
       }else{
           
           return dp[i][j]= min(helper(i,j-1, str), helper(i+1, j, str))+1;
       }
    }
    int countMin(string str){
       memset(dp, -1, sizeof(dp));
       return helper(0, str.size()-1, str);
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}

  // } Driver Code Ends