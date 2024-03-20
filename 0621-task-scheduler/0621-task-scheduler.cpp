class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mpp;
        for(int i=0;i<tasks.size();i++){
            mpp[tasks[i]]++;
        }
        priority_queue<int> pq;
        for(auto it: mpp){
            pq.push(it.second);
        }
        int ans=0;
        while(!pq.empty()){
            int cycle=n+1;
            int taskcount=0;
            vector<int> store;
            while(cycle-- && !pq.empty()){
                if(pq.top()>1){
                    //not just one leftauto 
                    store.push_back(pq.top()-1);
                }
                pq.pop();
                taskcount++;
            }
            //fill pq waps
            for(auto it: store)pq.push(it);
            //pq empty h store m kuch nhi h koi bcha nhi h wrna cycles ==0 to n+1 add krdo
            ans+= pq.empty()? taskcount: n+1; 
            
        }
        return ans;
    }
};