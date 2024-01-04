class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& a) {
        sort(a.begin(), a.end());
        vector<string> ans;
        int temp=0;
        for(int i=0;i<a.size();i++){
            while(i<a.size() && a[i][0]==a[temp][0]){
                i++;
            }
            int count=i-temp;
            if(count<3){
                temp=i;
                i--;
                continue;
            }
            // cout<<i<<temp<<" ";
            
            for(int j=temp;j<i;j++){
                int start=j;
                int threshold=stoi(a[j][1])+100;
                while(j<i && stoi(a[j][1])<threshold){
                    j++;
                }
                cout<<a[temp][0]<<j<<start<<" ";
                if(j-start>=3){
                    // cout<<a[temp][0]<<" ";
                    ans.push_back(a[temp][0]);
                    break;
                }
                j=start;
                
            }
            temp=i;
        }
        return ans;
    }
};