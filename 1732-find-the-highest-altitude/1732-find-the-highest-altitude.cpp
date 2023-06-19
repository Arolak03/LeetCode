class Solution {
public:

    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int sum = 0;
        int total = sum;
        for(int i: gain){
            total+=i;
            sum=max(sum,total);
        }
        return sum;
    }
};
