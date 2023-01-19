class MedianFinder {
public:
    priority_queue<long> small, large;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if (small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
       //  priority_queue<long> t1,t2;
       //  t1 = small;
       //  t2 = large;
       //  while(t1.size()>0)cout<<t1.top()<<" ", t1.pop();
       //  cout<<"#\n";
       // while(t2.size()>0)cout<<t2.top()<<" ", t2.pop();
       //  cout<<"$\n";
       //  cout<<num<<endl;
        
    }

    double findMedian() {
        return small.size() > large.size()
               ? small.top()
               : (small.top() - large.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */