class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        
        
        int val=0;
        
        for(int i=0; i<arr2.size();i++){
            
            val^= arr2[i];
        }
        
        int ans=0;
        
        for(int i=0; i<arr1.size();i++){
            
            ans^= val & arr1[i];
        }
        return ans;
        
    }
};