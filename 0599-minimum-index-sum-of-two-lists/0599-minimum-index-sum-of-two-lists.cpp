class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        int index1=INT_MAX;
        // int index2=0;
        for(int i=0; i<list1.size();i++){
            for(int j= 0;j<list2.size();j++){
                if(list1[i]==list2[j]){
                    int index = i+j;
                    if(index<index1){
                        ans.clear();
                        ans.push_back(list1[i]);
                        index1=index;
                    }
                    else if(index==index1){
                        ans.push_back(list1[i]);
                    }
                }
            }
        }
           
        
        
        
        return ans;
    }
};