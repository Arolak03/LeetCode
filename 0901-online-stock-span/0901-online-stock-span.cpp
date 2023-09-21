class StockSpanner {
public:
    
    vector<int> ans;
    vector<int> prices;
    unordered_map<int, int>mpp;
    stack<int> s;
    stack<pair<int, int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        // stack<int> s;
        // int count=0;
        // prices.push_back(price);
        // // for(int i=0;i<prices.size();i++){
        // //     s.push(prices[i]);
        // // }
        // //     while(!s.empty() && s.top()<=price){
        // //         count++;
        // //         s.pop();  
        // //     }
        // //     if(s.empty() && count==0){
        // //         count=1;
        // //     }
        // // else if(!s.empty() && count==0)count=1;
        // // while(!s.empty())s.pop();
        // int count=1;
        // for(int i=prices.size()-2;i>=0;i--){
        //     if(prices[i]<=price)count++;
        //     else break;
        // }
        // return count;
        
        int count=1;
        while(!st.empty() && st.top().first<=price){
            count+=st.top().second;
            st.pop();
        }
        st.push({price,count});
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */