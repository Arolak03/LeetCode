class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) {
            return 0; // Base case for n = 1
        }
        
        // Calculate the mid point for the previous row (n - 1)
        int parent = kthGrammar(n-1,k/2+k%2);
        //odd pr parent jaise
        if(k%2!=0) return parent;
        else {
            if (parent==0)return 1;
            else return 0;
        }
        return 0;
    }
};
