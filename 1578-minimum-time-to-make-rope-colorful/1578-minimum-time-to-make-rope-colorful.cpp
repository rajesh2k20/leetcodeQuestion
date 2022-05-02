class Solution {
public:
    int minCost(string colors, vector<int>& arr) {
       
      stack<pair<char, int>> s;
      int ans=0;
      for(int i=0; i<colors.size();i++){
          // total+=arr[i];
          if(s.size()==0){
              s.push({colors[i], arr[i]});
          }else{
              
              if(s.top().first==colors[i]){
                  if(s.top().second<arr[i]){
                      ans+= s.top().second;
                      s.pop();
                      s.push({colors[i], arr[i]});
                  }else{
                      ans+=arr[i];
                  }
              }else{
                s.push({colors[i], arr[i]});  
              }
          }
      }
      return ans;
    }
};