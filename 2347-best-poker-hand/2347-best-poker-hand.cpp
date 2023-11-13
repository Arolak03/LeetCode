class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        // sort(ranks.begin(),ranks.end());
        // unordered_map<int, unordered_map<<int, char>>> mpp;
        // for(int i=0;i<5;i++){
        //     mpp[i] = {ranks[i],suits[i]};
        // }
        // bool pair=false;
        // bool triplet=false;
        // bool five=false;
        // // for(auto it: mpp){
        //     if(it.second.first==2)pair=true;
        //     if(it.second.first==3 || it.second.first==4)triplet=true;
        // }
        set<char> s;
        for(int i=0;i<5;i++){
            s.insert(suits[i]);
        }
        if(s.size()==1)return "Flush";
        // if(triplet)return "Three of a Kind";
        // if(pair)return "Pair";
        // else return "High Card";
        sort(ranks.begin(),ranks.end());
        int maxi=1;
        int ans=1;
        for(int i=0;i<4;i++){
            
            if(ranks[i]==ranks[i+1])ans++;
            else ans=1;
            maxi=max(ans,maxi);
        }
        if(maxi>=3)return "Three of a Kind";
        if(maxi==2)return "Pair";
        else return "High Card";
    }
};