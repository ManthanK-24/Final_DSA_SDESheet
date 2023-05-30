class MyHashSet {
public:
    unordered_map<int,int> ump;
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(ump[key]==0)
        ump[key]++;
        // cout<<key<<"key "<<ump[key]<<"cnt\n";
    }
    
    void remove(int key) {
        // cout<<key<<"key "<<ump[key]<<"#cnt\n";
        if(ump[key]>0)
        {
        ump[key]--;
        if(ump[key]==0)ump.erase(key);
        }
        // cout<<key<<"key "<<ump[key]<<"$cnt\n";
    }
    
    bool contains(int key) {
        // cout<<key<<"key "<<ump[key]<<"*cnt\n";
        return ump[key]>0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */