#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
int priority(char op)
{
    if(op == '+' || op == '-')
    {
        return 1;
    }
    else if(op == '*' || op == '/')
    {
        return 2;
    }
    
}
int main()
{
    int i = 0;
    char t;
    stack<char> rev;
    stack<char> st;
    stack<char> out;
    string instring;
    cout<<" Enter input infix string:";
    cin>>instring;
    for (i = 0;i < instring.length();i++)
    {
        t = instring[i];
        if(t == ')')
        {
           cout<<"Got here";
           while(st.top()!='(')
           {
              out.push(st.top());
              st.pop();
           }
           st.pop();
        }
       else if(t == '+' || t == '-' || t == '*'||t == '/')
        {
        if (!st.empty())
        {
            if(priority(t)<=priority(st.top()))
            {
            while(!st.empty() && st.top()!='(')
            {
                out.push(st.top());
                st.pop();
            }
            st.push(t);
            }
            else
            {
                st.push(t);
            }
        }
        else{
            st.push(t);
        }
        }
        else{
            out.push(t);
        }
    }
    //simply push
    while(!st.empty()){
        out.push(st.top());
        st.pop();
    }
    //Reverse the string output(which is another stack)
    while(!out.empty()){
        rev.push(out.top());
        out.pop();
    }
    while(!rev.empty())
    {
        cout<<rev.top();
        rev.pop();
    }
}
  
