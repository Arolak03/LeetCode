class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> dupli = heights;
        sort(dupli.begin(),dupli.end());
        vector<int> indices;
        for(int i = 0;i<heights.size();i++){
            if(dupli[i]!=heights[i]){
                indices.push_back(i);
            }
        }
        return indices.size();
    }
};