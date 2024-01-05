class DataStream {
public:
    int val;
    int n;
    int temp;
    vector<int>q;
    bool flag=true;
    DataStream(int value, int k) {
        n=k;
        val=value;
        temp=n-1;
    }
    
    bool consec(int num) {
        // cout<<num<<" ";
        q.push_back(num);
        // cout<<"yes";
        // for(auto it: q)cout<<it;
        // cout<<" ";
        // cout<<"*"<<temp<<"*"<<" ";
        // cout<<q.size()<<" ";
        if(q.size()<n){
           if(num==val && !flag){
               cout<<"in"<<" ";
               temp--;
           }
            
            else if(num!=val){
                temp=n-1;
                flag=false;
                cout<<num<<" ";
            }
           cout<<"*"<<temp<<flag<<"*"<<" ";

            return false;
        }
        if(num!=val){
            temp=n-1;
            flag=false;
            return false;
        }
        if(!flag && temp>0){
            temp--;
            return false;
        }
        temp=n-1;
        flag=true;
        if(num==val && flag)return true;
        if(flag)return true;
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */