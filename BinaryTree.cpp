#include <iostream>
#include<queue>
using namespace std;
//binary tree
class AVLTree{
    AVLTree *left;
    AVLTree *right;
    int data;
    public:
    void insert(AVLTree* &root,int newdata)
    {
        AVLTree *walker = root;
        AVLTree *insert = new AVLTree(newdata);
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
    void print(AVLTree *root)
    {
        queue<AVLTree *> values;
        AVLTree *walker;
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
    int heights(AVLTree *root,int key)//For calculation height
    {
        
    }
    int height()
    AVLTree(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};
int main()
{
    AVLTree *root = new AVLTree(8);
    root->insert(root,3);
    root->insert(root,10);
    root->insert(root,1);
    root->insert(root,6);
    root->insert(root,14);
    root->print(root);
    cout<<endl;
}
