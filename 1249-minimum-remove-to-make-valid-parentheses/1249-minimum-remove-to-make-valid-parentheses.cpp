class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // stack to store '('
        stack<char> stack;
        string temp="";
        for(int i=0;i<s.size();i++)
        {
            // take a new string
           
            // add charater to this string if cahr is aphabet 
            // if cahrat(i) == '(' push it in stack 
            // if cahrat(i) is ')' 
           
            if(s[i]=='('){
                temp+=s[i];
                stack.push('(');
            }
            else if(s[i]==')')
            {
                // if stack is empty don't add ')'
                if(stack.empty())
                    continue;      
                // pop if stack is not empty
                else{
                    temp+=s[i];
                    stack.pop();
                }
            }
            else
            {
                temp+=s[i];
            }
                
        }
        string ans ="";
     
        for(int i = temp.size()-1;i>=0;i--)
        {
            
                if(temp[i]!= '(' || stack.empty() )
                {
                    cout<<"true";
                    ans+=temp[i];
                }
                else
                {
                    cout<<"false";
                    stack.pop();
                }
        }
            
            
      
        reverse(ans.begin(),ans.end());
       cout<<ans;
        return ans;
        
    }
};