class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
      
      vector<pair<int, int>> arr;
        
        for(int i=0; i<n;i++){
            
            arr.push_back({efficiency[i], speed[i]});
        }
        
        sort(arr.begin(), arr.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        long long  ans=0;
        long long  sum=0;
        
        int mod=1e9+7;
        for(int i=n-1; i>=0; i--){
           
            long long  currans=  (1LL*arr[i].second+sum);
            // currans%=mod;
            currans*=1LL*arr[i].first;
            // currans%=mod;
            ans= max(ans, currans);
            // cout<<currans<<endl;
            // ans%=mod;
            if(pq.size()<k-1){
                pq.push(arr[i].second);
               sum= (sum+ 1LL*arr[i].second);
            }else{
                
                if(pq.size()>0){
                    
                if(pq.top()<arr[i].second){
                    
                  long long  val= pq.top();
                    pq.pop();
                    // sum= (sum-val+mod)%mod;
                    // sum= (sum+ 1LL*arr[i].second)%mod;
                    sum-=val;
                    sum+=arr[i].second;
                    pq.push(arr[i].second);
                }
                }
            }
              
        }
        
         long long  currans=  (1LL*arr[0].second+sum);
            // currans%=mod;
            currans*=1LL*arr[0].first;
            // currans%=mod;
            ans= max(ans, currans);
        return ans%mod;
        
        
        
    }
};