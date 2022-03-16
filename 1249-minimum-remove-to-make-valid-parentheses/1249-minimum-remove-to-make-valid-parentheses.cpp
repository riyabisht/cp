class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // stack to store location of '('
        // idea is to put * in place of invalid '(' , ')'
        stack<int> stack;
        for(int i=0;i<s.size();i++)
        {
            // if character at(i) == '(' push back the location i
            if(s[i]=='('){
                stack.push(i);
            }
            else if(s[i]==')')
            {
                // if stack is empty and found')' this mean we have to remove ')' mark it as * 
                if(stack.empty())
                    s[i]='*';      
                // pop if stack is not empty
                else
                    stack.pop();
            }
                
        }
        while(!stack.empty())
        {
            // mark * at all the location in left in the stack
            int i=stack.top();
            s[i]='*';
            stack.pop();
        }
        //remove all the occurances of *
        s.erase(remove(s.begin(),s.end(),'*'),s.end());
        return s;
        
    }
};