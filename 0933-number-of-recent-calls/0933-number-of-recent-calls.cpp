class RecentCounter {
public:
    priority_queue<int, vector<int> , greater<int>> pq;
    RecentCounter() {
        // priority_queue<int> pq;
        
    }
    
    int ping(int t) {
        // cout<<pq.top()<<" ";
        while(!pq.empty() && pq.top()<t-3000){
            cout<<pq.top();
            pq.pop();
        }
        pq.push(t);
        cout<<pq.top()<<" ";
        return pq.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */