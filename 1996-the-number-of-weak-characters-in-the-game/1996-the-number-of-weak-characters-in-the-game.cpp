#include<bits/stdc++.h>

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        
        sort(arr.begin(), arr.end());
        int n= arr.size();
        int suffix[n];
        
        suffix[n-1]=arr[n-1][1];
        
        for(int i=n-2; i>=0;i--){
            
             
            suffix[i]= max(suffix[i+1], arr[i][1]);
        }
        
//         for(int i=0; i<n;i++){
            
//             cout<<suffix[i]<<" ";
//         }
        
//         cout<<endl;
        
        
        int ans=0;
        
         for(int i=n-2; i>=0;i--){
          vector<int> p;
             p.push_back(arr[i][0]);
             p.push_back(1e9);
        int index=  upper_bound(arr.begin()+i+1, arr.end(), p)- (arr.begin()+i+1);
          // cout<<index<<" ";    
        index+=(i+1);
            // cout<<index<<endl;
        if(index>=arr.size()){
           continue; 
        }else{
            
            int maxval=suffix[index];
            if(maxval>arr[i][1]){
                // cout<<i<<endl;
                ans++;
            }
        }
             
             
         }
        
        return ans;
        
    }
};