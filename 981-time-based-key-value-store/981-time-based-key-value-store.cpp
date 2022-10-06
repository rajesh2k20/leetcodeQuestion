class TimeMap {
public:
    
    vector<map<int, string>> arr;// timestamp and value, for any index .
    map<string, int> m1; // key and index.
    int size=0;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
      
        if(m1.count(key)==1){
            
          int index=m1[key];
            
          arr[index][timestamp]=value;
          
        }else{
            map<int,string> d;
            d[timestamp]=value;
            arr.push_back(d);
            m1[key]=size;
            size++;
           
            
        }
    }
    
    string get(string key, int timestamp) {
        
        
        if(m1.count(key)==0){
            return "";
        }else{
            
            int index= m1[key];
            
            if(arr[index].size()==0){
                return "";
            }
            
            auto it=  arr[index].upper_bound(timestamp);
            
            
            
            if(it==arr[index].begin()){
                return "";
            }else{
                it--;
                
                return it->second;
            }
        }
        
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */