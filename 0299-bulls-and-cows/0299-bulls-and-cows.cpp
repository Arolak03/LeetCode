class Solution {
public:
    string getHint(string secret, string guess) {
        //bulls -> correct digit att correct place 
        //cow --. correct digit wrong place
        int cows=0;
        int bulls=0;
        unordered_map<int, int>mpp;
        // dig and index
        
        for(int i=0;i<secret.length();i++){
            if(secret[i]==guess[i]){
                bulls++;
                secret[i]='*';
                guess[i]='*';
            }
        }
        // for(int i=0;i<secret.length();i++)cout<<secret[i]<<" "<<guess[i];
        for(int i=0;i<secret.length();i++){
            if(secret[i]!='*')mpp[secret[i]-'0']++;
        }
        
        unordered_map<int, int> mpp2;
        for(int i=0;i<guess.length();i++){
            if(guess[i]!='*')mpp2[guess[i]-'0']++;
        }
        // for(auto it: mpp2)cout<<it.first<<it.second<<" ";
        for(int i=0;i<secret.size();i++){
            if(mpp2.find(secret[i]-'0')!=mpp.end()){
                // cout<<"in";
                if(mpp2[secret[i]-'0']==mpp[secret[i]-'0']){
                    // cout<<secret[i]<<" ";
                    cows+=mpp2[secret[i]-'0'];
                    mpp[secret[i]-'0']=-1;
                    // cout<<"in";
                }
                else if(mpp[secret[i]-'0']!=-1){
                    // cout<<secret[i];
                    cout<<min(mpp[secret[i]-'0'],mpp2[secret[i]-'0']);
                    cows=cows+(min(mpp[secret[i]-'0'],mpp2[secret[i]-'0']));
                    mpp[secret[i]-'0']=0;
                }
            }
        
        }
        
        
        string ans="";
        
        return to_string(bulls)+'A'+to_string(cows)+'B';
        
    }
};