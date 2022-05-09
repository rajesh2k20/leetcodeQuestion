class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& arr) {
     
     int maxval=arr[0];
     int ans=-1e9;
     int n=arr.size();
     for(int i=1; i<n;i++){
       
        int val= (arr[i]-i)+maxval;
         ans=max(ans, val);
        maxval=max(maxval, arr[i]+i);
     }
        return ans;
    }
};