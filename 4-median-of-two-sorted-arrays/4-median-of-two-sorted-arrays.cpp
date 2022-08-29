class Solution {
public:
    bool check(vector<int> & arr1, vector<int> & arr2, int mid, int k){
        
        int index1= lower_bound(arr1.begin(), arr1.end(), mid)-arr1.begin();
        int index2= lower_bound(arr2.begin(), arr2.end(), mid)-arr2.begin();
        
        if(index1+index2<k){
            return true;
        }
        
        return false;
        
    }
    int bs(vector<int> & arr1, vector<int> & arr2, int k){
        
        int low=-1e6;
        int high=1e6;
        int ans=0;
        while(low<=high){
            
            int mid= (low+high)/2;
            // cout<<mid<<endl;
            if(check(arr1, arr2, mid,k )==true){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int size= nums1.size()+nums2.size();
        
        if(size%2==0){
            
            int k1= (size)/2;
            int k2=k1+1;
            
            int val1=bs(nums1, nums2, k1);
            int val2= bs(nums1,nums2, k2);
            // cout<<val1<<" "<<val2<<endl;
            return ((double)val1+(double)val2)/2.0;
            
        }else{
            
            int k1= (size+1)/2;
            int val1=bs(nums1, nums2, k1);
            return (double)val1;
        }
        
    }
};