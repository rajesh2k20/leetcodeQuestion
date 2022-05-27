class store{
   
   public:
 
       int sum=0;
 
       store (int s=0){
           sum=s;
       }
 
};
 
class store2{
 
public:
 
    int val=0;
 
    store2(int v=0){
 
        val=v;
    }
 
};
 
class segment{
 
    vector<int> arr;
    vector<store> tree;
    vector<store2> lazy;
    int size;
 
   
private:
    store merge(store f1, store f2){
 
        return store(max(f1.sum, f2.sum));
    }
    
    void build(int l, int r, int p){
       
       if(l==r){
 
             tree[p]= store(arr[l]);
           return ;
       }
       int mid= (l+r)/2;
 
       build(l, mid, 2*p);
       build(mid+1, r, 2*p+1);
 
       tree[p]= merge(tree[2*p], tree[2*p+1]);
    }
 
    void AEU(int l, int r, int p){
 
       
 
       tree[p].sum=(lazy[p].val);
 
       if(l!=r){
 
          lazy[2*p].val=lazy[p].val;
          lazy[2*p+1].val=lazy[p].val;
       }
 
       lazy[p].val=0;
    }
 
    void update(int l, int r, int ul,int ur, int v, int p){
 
        
      if(lazy[p].val!=0){
 
          AEU(l,r,p);
      }
 
      if(l>=ul and r<=ur){
          lazy[p].val=v;
          AEU(l,r,p);
          return ;
      }
 
      if(ul>r || l> ur){
 
        return ;
      }
 
      int mid=(l+r)/2;
 
      update(l,mid, ul, ur, v,2*p);
      update(mid+1, r, ul, ur, v, 2*p+1);
      tree[p]= merge(tree[2*p], tree[2*p+1]);
 
        
        
    }
 
    store query(int l, int r, int s, int e, int p){
 
 
      if(lazy[p].val!=0){
 
          AEU(l,r,p);
      }
 
      if(e<l || s>r){
           return store();
      }
 
      if(l>=s and r<=e){
           return tree[p];
      }
 
        int mid= (l+r)/2;
        store ans1=query(l, mid, s, e, 2*p);
        store ans2=query(mid+1, r, s, e, 2*p+1);
 
        return merge(ans1, ans2);
 
    }
 
public:
     segment(vector<int> a, int n){
        arr=a;
        tree.resize(4*n+1, 0);
        lazy.resize(4*n+1, 0);
        size=n;
        build(1, size, 1);
    }
    
 
 
    store query(int s, int e){
 
        return query(1, size, s, e, 1);
    }
 
     void update(int ul, int ur, int val){
 
        update(1,size, ul, ur, val, 1);
    }
 
};
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
       
       vector<int> arr;
        for(int i=0; i<positions.size();i++){
            
            arr.push_back(positions[i][0]);
            arr.push_back(positions[i][0]+positions[i][1]);
        }
        sort(arr.begin(), arr.end());
        int val=1;
        
        map<int, int> m;
        
        for(int i=0; i<arr.size();i++){
            
            m[arr[i]]=val;
            val++;
        }
        
        vector<int> v(val+1,0);
        segment st(v, val);
        
        vector<int> ans;
        
        for(int i=0; i<positions.size();i++){
            
            int l= positions[i][0];
            int r= l+positions[i][1];
            // cout<<m[l]<<" "<<m[r]<<endl;
            int maxval= st.query(m[l]+1, m[r]).sum;
            // cout<<maxval+positions[i][1]<<endl;
            // int nl= 
            st.update(m[l]+1, m[r],maxval+positions[i][1]);
            int val1= st.query(1, val).sum;
            ans.push_back(val1);
        }
        
        return ans;
        
        
        
        
    }
};