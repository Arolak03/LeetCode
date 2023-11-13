class Solution {
public:
    string sortVowels(string s) {
        // vector<string> code = {"A","E","I","O","U","a","e","i","o","u"};
        vector<char> code = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

        map<int, int> position;
       string alpha;
       for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < 10; j++) {
                if (s[i] == code[j]) {
                    alpha.push_back(s[i]); // Push the character, not string
                }
            }
        }
        //alpha has things
        sort(alpha.begin(),alpha.end());
        //alpha sahi bn rha h
        int index=0;
         for(int i=0;i<s.length();i++){
            for(int j=0;j<10;j++){
                if(s[i] == code[j]){
                    s[i]=alpha[index];
                    index++;
                    break;
                }
            }
        }
        // cout<<alpha;
        return s;
    }
};