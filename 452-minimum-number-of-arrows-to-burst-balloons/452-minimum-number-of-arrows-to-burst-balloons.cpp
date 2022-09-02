class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& arr) {
       
        set<pair<int, int>> s;
        
        sort(arr.begin(), arr.end());
        
        s.insert({arr[0][1], arr[0][0]});
        
        
        for(int i=1; i<arr.size();i++){
            
            int val=arr[i][0];
            
            auto it= s.lower_bound({val,(int)-1e9});
            
            if(it != s.end()){
                
                int l= it->second;
                int r= it->first;
                
               if(arr[i][1]<l  || (arr[i][0]> r)){
                   s.insert({arr[i][1], arr[i][0]});
            }
               else{
                    int nl= max(l, arr[i][0]);
                int nr= min(r, arr[i][1]);
                
                s.erase(it);
               s.insert({nr,nl});
               }
                
            }else{
                
                s.insert({arr[i][1], arr[i][0]});
            }
        }
        
        return s.size();
        
        
    }
};