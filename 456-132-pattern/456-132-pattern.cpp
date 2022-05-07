class Solution {
public:
    bool find132pattern(vector<int>& nums) {
     
     multiset<int> s1;
     multiset<int> s2;
     int n=nums.size();
     for(int i=0; i<nums.size();i++){
         
         s2.insert(nums[i]);
     }
     for(int i=0; i<n;i++){
        
         s1.insert(nums[i]);
         s2.erase(s2.find(nums[i]));
         auto it= s1.begin();
         auto it2= s2.lower_bound(nums[i]);
         if(it2 == s2.begin()){
             continue;
         }
         it2--;
         if(*it < *it2){
              return true;
         }
     }
        return false;
    }
};