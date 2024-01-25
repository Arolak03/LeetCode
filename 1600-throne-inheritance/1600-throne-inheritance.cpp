class ThroneInheritance {
public:
    unordered_map<string, vector<string>> mpp;
    unordered_map<string, int> dead;
    string presentKing;
    
    ThroneInheritance(string kingName) {
        presentKing=kingName;
        
    }
    
    void birth(string parentName, string childName) {
        mpp[parentName].push_back(childName);
        // mpp[parentName].insert(parentName);
    }
    
    void death(string name) {
        dead[name]=1;
    }
    
    void dfs(vector<string>& ans, string& king)
       {
           if(dead[king]!=1)ans.push_back(king);
           // vis[root]=true;
           // if(root=="")return;
           // for(auto it: mpp[root]){
           for(string& it: mpp[king])dfs(ans,it);
           
       }    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(ans,presentKing);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */