class Solution {
public:
    void helper(string & ans, vector<int> & arr, int n, int k){
        
        if(n==0){
            return ;
        }
        
        int val=1;
        for(int i=1;i<=n-1;i++){
            val*=i;
        }
        int count=1;
        for(int i=0; i<arr.size();i++){
            
            if(arr[i]==1){
                continue;
            }
            int curr= val*count;
            if(k>curr){
                count++;
            }else{
                ans+=(char)((i+1)+'0');
                
                arr[i]=1;
                helper(ans,arr, n-1, k-val*(count-1) );
            }
            
        }
    }
    string getPermutation(int n, int k) {
        
        string ans;
        vector<int> arr(n,0);
        helper(ans, arr,n, k);
        return ans;
        
    }
};