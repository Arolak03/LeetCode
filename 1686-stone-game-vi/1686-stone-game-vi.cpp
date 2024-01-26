class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        priority_queue<pair<int, int>>pq;
        for(int i=0;i<a.size();i++){
            pq.push({a[i]+b[i],i});
        }
        int p=1;
        int x=0;
        int y=0;
        while(!pq.empty()){
            if(p){
                x+=a[pq.top().second];
                pq.pop();
            }
            else{
                y+=b[pq.top().second];
                pq.pop();
            }
            p=1-p;
        }
        if(x>y)return 1;
        else if(x<y)return -1;
        else return 0;
    }
};