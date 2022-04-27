class dsu{

	public :
	 int *par;
	 int *height;
	 dsu(int n){
	 	par=new int[n+1];
	 	height=new int[n+1];
	 	for(int i=0;i<=n;i++){
	 		par[i]=i;
	 		height[i]=1;
	 	}
	 }

	int root(int a){

		if(a==par[a]){
			return a;
		}
		par[a]=root(par[a]);
		return par[a];
	}

	void un(int a,int b){

		int roota=root(a);
		int rootb=root(b);
		if(roota==rootb){
			return;
		}
		else{
			int heighta=height[a];
			int heightb=height[b];
			if(heighta>heightb){
				par[rootb]=roota;


			}else if(heightb>heighta){
              par[roota]=rootb;
			}else{
				par[roota]=rootb;
				height[roota]++;
			}
		}

	}
	int find(int a,int b){

		int roota=root(a);
		int rootb=root(b);
		return roota==rootb;
	}

};
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
       
     dsu  d(1e5+3);
     
      for(int i=0; i<nums.size();i++){
          
          for(int j=2; 1LL*j*j<=nums[i];j++){
              
             if(nums[i]%j==0){
                 
                int div2= nums[i]/j;
                d.un(nums[i], j);
                if(div2>1){
                  d.un(nums[i], div2);
                }
             }
          }
      }
        
     map<int, int> m;
     for(int i=0; i<nums.size();i++){
          
         int r= d.root(nums[i]);
         m[r]++;
     }
     int maxval=1;
     for(auto x: m){
         maxval=max(maxval, x.second);
     }
        
     return maxval;
      
    }
};