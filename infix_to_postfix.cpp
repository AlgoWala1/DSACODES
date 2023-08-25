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
    char check,t;
    stack<int> st;
    stack<int> out;
    string instring;
    cout<<" Enter input infix string:";
    cin>>instring;
    for (i = 0;i < instring.length();i++)
    {
        t = instring[i];
        cout<<"got here";
        if(t == '+' || t == '-' || t == '*'||t == '/')
        {
        if (!st.empty())
        {
            if(priority(t)<=priority(st.top()))
            {
            while(!st.empty())
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
    while(!out.empty()){
        cout<<out.top();
    }
}
