class Solution {
public:
    int dayOfYear(string date) {
        int ans=0;
        unordered_map<int, int> mpp;
        
        mpp[1]=31;
        mpp[2]=28;
        mpp[3]=31;
        mpp[4]=30;
        mpp[5]=31;
        mpp[6]=30;
        mpp[7]=31;
        mpp[8]=31;
        mpp[9]=30;
        mpp[10]=31;
        mpp[11]=30;
        mpp[12]=31;
    
        // cout<<mpp[2];
    
        // cout<<mpp[2]<<endl;
        string d="";
        for(int i=8;i<=9;i++)d+=date[i];
        int day=stoi(d);
        string m="";
        for(int i=5;i<=6;i++)m+=date[i];
        int month=stoi(m);
        for(auto it: mpp){
            if(it.first<month){
                ans+=it.second;
            }
        }
        ans+=day;
        
        string year="";
        for(int i=0;i<4;i++)year+=date[i];
        
        int y=stoi(year);
        return (y%4==0 && month>2 && y%100!=0) || (y%100==0 && y%400==0 && month>2) ? ans+1: ans;
        
    }
};