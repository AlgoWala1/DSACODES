#include <iostream>
#include<queue>
using namespace std;
void printV(vector<int> list)
{
    cout<<endl;
    while(!list.empty())
    {
        cout<<" "<<list.front();
        list.erase(list.begin());
    }
    cout<<endl;
}
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
        if(walker->data>=newdata)
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
    int dist(binTree *root,int node1,int node2)
    {
        binTree* walker = root;
        vector<int>Paths1;
        vector<int>Paths2;
      while(walker->data != node1)
        {
            Paths1.push_back(walker->data);
            if(walker->data>=node1)
            {
                walker = walker->left;
            }
            else{
                 walker = walker->right;
            }
        }
        Paths1.push_back(walker->data);
        walker = root;
       while(walker->data!=node2)
        {
            Paths2.push_back(walker->data);
            if(walker->data>=node2)walker = walker->left;
            else walker = walker->right;
        } 
        Paths2.push_back(walker->data);
        while(true)//remove common nodes
        {
            if(Paths1.front() != Paths2.front())//where diversion occurs
            {
                break;
            }
            Paths1.erase(Paths1.begin());
            Paths2.erase(Paths2.begin());
        }
        return Paths2.size()+Paths1.size();
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
    cout<<endl;
    cout<<"Distance between node 3 and 14 is: "<<root->dist(root,3,14);
}
