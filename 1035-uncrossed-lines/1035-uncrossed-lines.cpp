struct comp { bool operator() (const pair <int , int> &lhs, const pair <int , int> &rhs) const { 
    return lhs.first == rhs.first? lhs.second > rhs.second: lhs.first < rhs.first; } 
 };
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
      int n=nums1.size();
     vector<set<pair<int, int>, comp>> dp(n);
     map<int, vector<int>> m;
     for(int i=0; i<nums2.size();i++){
         
         m[nums2[i]].push_back(i);
     }
     int ans=0;
     for(int i=0; i<n;i++){
         
         vector<int> v= m[nums1[i]];
         set<pair<int, int>, comp> s1;
         for(int j=0; j<v.size();j++){
               // s1.insert({v[j], 1});
               int maxval=1;
             for(int k=0; k<i;k++){
                 
                auto  index= dp[k].upper_bound({v[j]-1, -1e9});
             
                 
                 if(index== dp[k].begin()){
                     continue;
                     
                 }else{
                    
                      index--;
                      
                     maxval= max(maxval, index->second+1);
                 }
                 
             }
             s1.insert({v[j], maxval});
             ans=max(ans, maxval);
         }
         dp[i]=s1;
     }
        
//       for(int i=0; i<n;i++){
          
//           set<pair<int, int>, comp> s=dp[i];
//           cout<<nums1[i]<<" ";
//           for(auto  x: s){
              
//               cout<<x.first<<" "<<x.second<<" ";
//           }
//           cout<<endl;
//       }
        return ans;
    }
};