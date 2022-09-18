class Solution {
public:
    int dp[1001][1001];
    int helper(int index1, int index2,string & str1, string & str2){
        
        if(index1== str1.size() || index2==str2.size()){
            
            return 0;
        }
        
        if(dp[index1][index2] !=-1){
            
            return dp[index1][index2];
        }
        if(str1[index1]==str2[index2]){
            
            return dp[index1][index2]=1+ helper(index1+1, index2+1, str1, str2);
        }else{
            
            return dp[index1][index2]=max(helper(index1,index2+1, str1, str2), helper(index1+1, index2, str1, str2));
            
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        int n=text1.size();
        int m= text2.size();
        
        for(int i=0; i<n;i++){
            
            for(int j=0; j<m;j++){
                
                dp[i][j]=-1;
            }
        }
        
        
       return helper(0,0, text1, text2);
        
    }
};