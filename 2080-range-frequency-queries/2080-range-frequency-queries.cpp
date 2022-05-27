class RangeFreqQuery {
public:
    map<int, vector<int>> m;
    RangeFreqQuery(vector<int>& arr) {
        
        for(int i=0;i<arr.size();i++){
            
            m[arr[i]].push_back(i);
        }
        
    }
    
    int query(int l, int r, int value) {
        
        
        if(m.count(value)==0){
            return 0;
        }
        
        int index2= upper_bound(m[value].begin(), m[value].end(),r)- m[value].begin();
        int index1= lower_bound(m[value].begin(), m[value].end(), l)-m[value].begin();
        return index2-index1;
        
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */