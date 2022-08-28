class Solution {
public:
    bool check(int val, string & str){
        
        string str1= to_string(val);
        sort(str1.begin(), str1.end());
        // cout<<str1<<" "<<str<<endl;
        return str1==str;
    }
    bool reorderedPowerOf2(int n) {
        
        string str= to_string(n);
        sort(str.begin(), str.end());
        long long  val=1;
        
        while(val<=1e18){
            
            if(check(val, str)==true){
                return true;
            }
            val*=2;
        }
        return false;
        
    }
};