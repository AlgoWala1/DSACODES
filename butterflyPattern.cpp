for (i = 1;i<=5;i++)
    {
        for(j = 1;j<=i;j++)
        {
            cout<<"*";
        }
        k = 2*(5-i);
        for(j = 0;j<k;j++)
        {
            cout<<" ";
        }
        for(j = 1;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
