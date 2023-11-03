#include <iostream>
#include<queue>
using namespace std;
//binary tree
class binTree{
    binTree *left;
    binTree *right;
    int data;
    public:
    void insert(binTree* root,int newdata)
    {
        queue <binTree *> values;
        binTree* newVar = new binTree(newdata);
        binTree *walker;
        values.push(root);
        while(!values.empty())
        {
            walker = values.front();
            if(walker->left == NULL)
            {
                walker->left = newVar;
                break;
            }
            else if(walker->right == NULL)
            {
                walker->right = newVar;
                break;
            }
            else{
            values.pop();
            values.push(walker->left);
            values.push(walker->right);
            }
        }
    }
    void print(binTree *root)
    {
        queue<binTree *> values;
        binTree *walker;
        values.push(root);
        while(!values.empty())
        {
            walker = values.front();
            values.pop();
            if(walker->left)
            {
                values.push(walker->left);
            }
            if(walker->right)
            {
                values.push(walker->right);
            }
            if(walker->data == -1)continue;
            cout<<walker->data<<" ";
        }
    }
   void deleteBinary(binTree *tree,int key)
    {
        queue<binTree *> values;
        binTree *walker;
        binTree *flag;
        values.push(tree);
        while(!values.empty())
        {
            walker = values.front();
            flag = walker;
            values.pop();
            if(walker->left)
            {
                values.push(walker->left);
            }
            if(walker->right)
            {
                values.push(walker->right);
            }
        }
        
        walker = tree;
        values.push(tree);
        while(!values.empty())
        {
            walker = values.front();
            values.pop();
            if(walker->data == key)
            {
                break;
            }
            if(walker->left)
            {
                values.push(walker->left);
            }
            if(walker->right)
            {
                values.push(walker->right);
            }
        }
        walker->data = flag->data;
        flag->data = -1;
    }
    bool searchTree(binTree *tree,int key)
    {
        if(tree == NULL)return false;
        if(tree->data>key)return searchTree(tree->left,key);
        if(tree->data<key)return searchTree(tree->right,key);
        if(tree->data == key)return true;
    }
    binTree(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};
int main()
{
    binTree *root = new binTree(8);
    root->insert(root,17);
    root->insert(root,10);
    root->insert(root,11);
    root->insert(root,6);
    root->insert(root,14);
    root->print(root);
    cout<<endl;
    if(root->searchTree(root,3))
    {
    cout<<"Found";
    }
    else{
        cout<<"Not found";
    }
    cout<<endl;
    root->deleteBinary(root,11);
    root->print(root);
}
