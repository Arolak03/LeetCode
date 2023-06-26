class Solution {
public:
    int maximum69Number (int num) {
        // int arr = to_int(num);
       string myarr = to_string(num);
        for(auto &currchar : myarr ){
            if(currchar == '6'){
                currchar = '9';
                break;
            }
        }
        return stoi(myarr);
        
    }
};