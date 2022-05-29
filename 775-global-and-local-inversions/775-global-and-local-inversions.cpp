class BIT{
    vector<int> tree;
    int size;
    public:
    BIT(int n){
        tree.resize(n+1,0);
        size=n+1;
    }
    
    int querySum(int r){
        
        int sum=0;
        
        while(r>0){
            
          sum+=tree[r];
            r -= r&(-r);
        }
        return sum;
    }
    
    void update(int index, int val){
        
        while(index<size){
            
            tree[index]+=val;
            index+= (index & (-index));
        }
        
    }
    
    int range(int l, int r){
        
        int val= querySum(r) ;
        int val2=querySum(l);
        // cout<<val<<" "<<val2<<endl;
        return val-val2;
    }
    
    
    
};
class Solution {
public:
    
    bool isIdealPermutation(vector<int>& nums) {
        
        BIT bt(nums.size()+1);
        
        long long  ans=0;
        long long ans1=0;
        
        for(int i=0; i<nums.size();i++){
            
             int val= bt.range(nums[i]+1,nums.size()+1 );
            // cout<<val<<endl;
            ans+=val;
            bt.update(nums[i]+1, 1);
            if(i==nums.size()-1){
                continue;
            }
            if(nums[i]>nums[i+1]){
                ans1++;
            }
            
        }
        // cout<<ans<<endl;
        
        if(ans1==ans){
            return true;
        }else{
            return false;
        }
        
        
        
        
        
        
    }
};