class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="+" && tokens[i]!="/" && tokens[i]!="*" && tokens[i]!="-"){
                s.push(stoi(tokens[i]));
                
            }
            else{
                int a1=(s.top());
                    s.pop();
                    int a2 =(s.top());
                    s.pop();
                
                if(tokens[i]=="+"){
                    s.push(a1+a2);
                }
                else if(tokens[i]=="-"){
                    s.push(a2-a1);
                }
                else if(tokens[i]=="*"){
                    s.push(a1*a2);
                }
                else if(tokens[i]=="/"){
                    s.push(a2/a1);
                }
                
            }
        }
        return s.top();
    }
};