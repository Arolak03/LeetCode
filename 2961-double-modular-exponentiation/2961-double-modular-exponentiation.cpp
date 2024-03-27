class Solution {
public:
int helper(int a,int b,int c){
    int ans=1;
    while(b>0){
        ans=(ans*a)%c;
        b--;
    }
    return ans;
}
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        int n=variables.size();
        int temp=0;
        int ans=0;
        vector<int> good;
        for(int i=0;i<n;i++){
            int a=variables[i][0];
            int b=variables[i][1];
            int c=variables[i][2];
            int m=variables[i][3];
            int ab=helper(a,b,10);
            int temp=helper(ab,c,m);
            cout<<temp<<endl;
            if(temp==target){
                good.push_back(i);
            }
        }
        return good;
    }
};