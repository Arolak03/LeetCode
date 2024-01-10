class Solution {
public:
    int m=0;
    vector<vector<int>> rects;
    Solution(vector<vector<int>>& r) {
        rects=r;
    }
    
    vector<int> pick() {
//         vector<int> ans(2);
//         while(m<rects.size()){
//             int ymin1=min(rects[m][1],rects[m][3]);
//             int ymax1=max(rects[m][1],rects[m][3]);
//             int xmin1=min(rects[m][0],rects[m][2]);
//             int xmax1=max(rects[m][0],rects[m][2]);
//             int i=xmin1;
//             int j=ymin1;

//             if(j>=ymin1 && j<=ymax1){
//                 ans[1]=j;
//                 ans[0]=i;
//                 j++;
//                 if(j<ymax1){
//                     j=ymin1;
//                     i++;
//                     if(i<=xmax1 && i>=xmin1)ans[0]=i;
//                 }
//             }
//             m++;
//         }
//         if(m==rects.size())m=0;
//         return ans;
                vector<int> ans(2);
        int totalPoints = 0;
        
        for (int i = 0; i < rects.size(); ++i) {
            int ymin1 = min(rects[i][1], rects[i][3]);
            int ymax1 = max(rects[i][1], rects[i][3]);
            int xmin1 = min(rects[i][0], rects[i][2]);
            int xmax1 = max(rects[i][0], rects[i][2]);

            totalPoints += (ymax1 - ymin1 + 1) * (xmax1 - xmin1 + 1);
            
            if (rand() % totalPoints < (ymax1 - ymin1 + 1) * (xmax1 - xmin1 + 1)) {
                ans[0] = rand() % (xmax1 - xmin1 + 1) + xmin1;
                ans[1] = rand() % (ymax1 - ymin1 + 1) + ymin1;
            }
        }

        return ans;

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */