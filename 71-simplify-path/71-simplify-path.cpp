class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string> st;
        string res;
         
        int i=0;
        for( ;i<path.size();i++)
        {
            if(path[i] == '/')    
                continue;
           string temp;
			// iterate till we doesn't traverse the whole string and doesn't encounter the last /
            for(;i < path.size() && path[i] != '/';i++)
            {
				// add path to temp string
                temp += path[i];

            }
            if(temp == ".")
                continue;
			// pop the top element from stack if exists
            else if(temp == "..")
            {
                if(!st.empty())
                    st.pop();
            }
            else
			// push the directory file name to stack
                st.push(temp);
        
        }
        
        // if stack is empty return "/"
        if(st.empty())
            return "/";
		// adding all the stack elements to res
        while(!st.empty())
        {
            res = "/" + st.top()+res;
            st.pop();
        }
        
        
        return res;
    }
};