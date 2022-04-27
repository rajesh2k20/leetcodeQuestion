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
    bool gcdSort(vector<int>& nums) {
      dsu  d(1e5+3);
      vector<int> arr(nums.size());
      for(int i=0; i<nums.size();i++){
          arr[i]=nums[i];
          for(int j=2; 1LL*j*j<=nums[i];j++){
              
             if(nums[i]%j==0){
                 
                int div2= nums[i]/j;
                d.un(nums[i], j);
                d.un(nums[i], div2);
             }
          }
      }
     sort(arr.begin(), arr.end());
     for(int i=0; i<arr.size();i++){
         
         if(arr[i]!=nums[i]){
             if(d.find(arr[i],nums[i])==false){
                 // cout<<d.root(nums[i]);
                 // cout<<d.root(arr[i]);
                 return false;
             }
         }
     }
        return true;
        
      
    }
};