class Solution {
public:
    bool check(int l1, int r1, int l2, int r2){
        
        if(l1>r2 || l2>r1){
            return false;
        }else{
            return true;
        }
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        
      sort(intervals.begin(), intervals.end());
        stack<pair<int, int>> s;
        
        s.push({intervals[0][0], intervals[0][1]});
        
        for(int i=1; i<intervals.size();i++){
            
          
           bool isoverlap=check(s.top().first, s.top().second, intervals[i][0], intervals[i][1]);
            
            if(isoverlap==true){
                
                
                
                int newl= min(s.top().first, intervals[i][0]);
                int newr= max(s.top().second, intervals[i][1]);
                
                // cout<<newl<<" "<<newr<<endl;
                
                s.pop();
                s.push({newl, newr});
                
            }else{
                
                s.push({intervals[i][0], intervals[i][1]});
                
            }
             
        }
        
        vector<vector<int>> ans;
        
        while(s.size()>0){
            
            ans.push_back({s.top().first, s.top().second});
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};