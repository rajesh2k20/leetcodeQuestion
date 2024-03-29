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
	bool find(int a,int b){

		int roota=root(a);
		int rootb=root(b);
		return roota==rootb;
	}

};
class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
       
     dsu d(n+10);
     for(int i=threshold+1; i<=n;i++){
        
          for(int j=1; 1LL*j*j<=1LL*i;j++){
              
             if(i%j==0){
                 
                int div2= i/j;
                
               if(j>threshold){
                    d.un(i, j);
               }
               if(div2>threshold){
                    d.un(i, div2);
               }
             }
          }
      }
      vector<bool> ans;
      for(int i=0; i<queries.size();i++){
           bool val=d.find(queries[i][0], queries[i][1]);
          // cout<<val<<endl;
          ans.push_back(val);
      }
     return ans;
    }
};