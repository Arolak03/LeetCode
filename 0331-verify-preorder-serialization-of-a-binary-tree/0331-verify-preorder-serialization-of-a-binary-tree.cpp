class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        int node=1;
        string word;
        // int j=0;
        while(getline(ss,word,',')){
            node--;
            if(node<0)return false;
            if(word!="#"){
                node+=2;
            }
        }
        return node==0;
    }
};
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
            
                
//                  bool isValidSerialization(string preorder) {
//         stringstream ss(preorder);
//         string curr;
//         int nodes = 1;
//         while (getline(ss, curr, ',')) {
//             nodes--;
//             if (nodes < 0) return false;
//             if (curr != "#") nodes += 2;
//         }
//         return nodes == 0;
//     }
// };