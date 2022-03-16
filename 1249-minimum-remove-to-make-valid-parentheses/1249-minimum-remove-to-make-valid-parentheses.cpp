class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // stack to store '('
        stack<int> stack;
        string temp="";
        for(int i=0;i<s.size();i++)
        {
            // take a new string
            // add charater to this string if cahr is aphabet 
            // if cahrat(i) == '(' push it in stack 
            // if cahrat(i) is ')' 
           
            if(s[i]=='('){
                temp+=s[i];
                stack.push(i);
            }
            else if(s[i]==')')
            {
                // if stack is empty don't add ')'
                if(stack.empty())
                    s[i]='*';      
                // pop if stack is not empty
                else{
                    temp+=s[i];
                    stack.pop();}
            }
            else
            {
                temp+=s[i];
            }
                
        }
        while(!stack.empty())
        {
            int i=stack.top();
            s[i]='*';
            stack.pop();
        }
     
        s.erase(remove(s.begin(),s.end(),'*'),s.end());
      
  
        return s;
        
    }
};