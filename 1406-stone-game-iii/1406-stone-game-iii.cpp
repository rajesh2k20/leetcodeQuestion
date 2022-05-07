int dp[100000];
class Solution {
public:
    
    int helper(int index, vector<int> & arr){
        
       if(arr.size()==index){
           
           return 0;
       }
       if(dp[index] != -1){
           return dp[index];
       }
       int ans=-1e9;
       int limit= min(index+3, (int)arr.size());
        // cout<<limit<<endl;
       for(int i= index; i<limit;i++){
            
         ans= max( arr[index]- helper(i+1, arr), ans); 
          
       }
       return dp[index]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        
        int n= stoneValue.size();
       vector<int> arr(n,0);
        memset(dp, -1, sizeof(dp));
        for(int i=n-1; i>=0;i--){
            
            if(i==n-1){
                arr[i]=stoneValue[i];
                continue;
            }
            
            arr[i]= arr[i+1]+ stoneValue[i];
        }
        
        int ans= helper(0, arr);
        int ans2= arr[0]-ans;
        // cout<<ans<<" "<<ans2<<endl;
        if(ans>ans2){
             return "Alice";
        }else if(ans<ans2){
            return "Bob";
        }else{
             return "Tie";
        }
    }
};