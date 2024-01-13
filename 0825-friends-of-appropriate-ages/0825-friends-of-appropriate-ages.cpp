class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n =ages.size();
        vector<int> age_count(121, 0);
        for(int age: ages)
            age_count[age]++;
        for(int i=2; i<=120; i++) {
            age_count[i] += age_count[i-1];
        }
        
        int requests = 0;
        for(int age: ages) {
            int left = age*0.5+7; 
            int right = age;
            if(left < right) {
                // -1 to excluse self
                requests += age_count[right] - age_count[left] - 1; 
            }
        }
        return requests;
    
    }
};