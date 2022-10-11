#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <class T> using multi_ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
       
      map<int, int> m;
        
       for(int i=0; i<nums2.size();i++){
           
           m[nums2[i]]=i;
       }
        
      vector<int> v;
       ordered_set s1;
       ordered_set s2;
      for(int i=0; i<nums1.size();i++){
          
          v.push_back(m[nums1[i]]);
          s2.insert(i);
      }
        
      long long ans=0;
        
      for(int i=0; i<v.size();i++){
          
          s2.erase(v[i]);
          
          long long ans1= s1.order_of_key(v[i]);
          long long  ans2=  s2.size()- (s2.order_of_key(v[i]));
          ans+= 1LL*ans1*ans2;
          
          s1.insert(v[i]);
          
      }
        
        return ans;
        
      
    }
};