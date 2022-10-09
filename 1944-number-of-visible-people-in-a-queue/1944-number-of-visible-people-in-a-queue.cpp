class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& arr) {
       
        
      stack<int> s;
       int n=arr.size();
      s.push(arr[n-1]);
     
        vector<int> ans(n,0);
       for(int i=n-2; i>=0; i--){
           
           
           int count=0;
           
           while(s.size()>0 and s.top()< arr[i]){
               
             count++;
               s.pop();
           }
           
           ans[i]=(s.size()>0 ? 1: 0 )+count;
           s.push(arr[i]);
       }
        
        return ans;
    }
};