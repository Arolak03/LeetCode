class Solution {
public:
    bool match(string &s, int i, string &a){
        int k=0;
        while(k<a.length()){
            if(s[i]!=a[k]) return false;
            i++; k++;

        }
        return true;
    }

    int min(int a, int b){
        if(a<b) return a;
        else return b;
    }
    int find(string &s, string &b, int i, int k){
        //set the range in which j has to be found
        int start = max(0, i-k);
        int end = min((i+k), (s.length()-b.length()));

        while(start<=end){
            if(s[start] == b[0]){
                if(match(s, start, b)){
                    //s[start] = '&';
                    return start;
                }
            }
            start++;
        }
        return -1;

    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> ans;
        int i=0;
        int j=-1;
        
        
        if(s.find(b)==string::npos) return ans;
        else j= s.find(b);
        if(s.length()<a.length() || s.length()<b.length()) return ans;
        while(i<=s.length()-a.length()){
            if(s[i] == a[0]){
                if(match(s, i, a)){
                    //cout<<"here"<<"for"<<i<<endl;
                    //now find a string b within the given range
                    if(j!=-1 && abs(j-i)<=k){
                            ans.push_back(i);
                    }
                    else{
                        if(j>i+k){
                            i++; continue;
                        }
                        j=find(s, b, i, k);
                        if(j>-1){
                            ans.push_back(i);
                        }
                    }
                }
            }
        i++;
        }


        sort(ans.begin(), ans.end());
        return ans;
    }
};