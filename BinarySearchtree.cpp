#include <iostream>
#include<queue>
using namespace std;
//binary tree
class binTree{
    binTree *left;
    binTree *right;
    int data;
    public:
    void insert(binTree* &root,int newdata)
    {
        binTree *walker = root;
        binTree *insert = new binTree(newdata);
        while(walker!=NULL)
        {
        if(walker->data>newdata)
        {
            if(walker->left == NULL){
            walker->left = insert;
            break;
            }
            else{
                walker = walker->left;
            }
        }
        else{
         if(walker->right == NULL)
         {
            walker->right = insert;
            break;
         }   
         else{
             walker = walker->right;
         }
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
            cout<<walker->data<<" ";
        }
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
    root->insert(root,3);
    root->insert(root,10);
    root->insert(root,1);
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
}
