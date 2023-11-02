#include <iostream>
#include<queue>
#include<math.h>
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
    binTree(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
    int calcDepthTree(binTree *tree)//we are calculationg height as height = depth
    {
      if(tree== NULL)return 0;     
      return 1+max(calcDepthTree(tree->left),calcDepthTree(tree->right));
    }
    int calcDepthNode(binTree *tree,int key)
    {
      
      if(tree->data==key)//node found 
      {
          return 0;
      }
      else if(tree->data>key)
      {
          return 1+calcDepthNode(tree->left,key);
      }
      else{
          return 1+calcDepthNode(tree->right,key);
      }
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
    root->insert(root,20);
    root->insert(root,2);
    root->insert(root,-1);
    root->print(root);
    cout<<endl;
    cout<<"Depth of node 14 is "<<root->calcDepthNode(root,14)<<endl;
    cout<<"Depth of Tree is "<<root->calcDepthTree(root);
}
