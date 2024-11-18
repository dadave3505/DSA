#include<iostream>
using namespace std;
//STructure of each node of BST 
class node{
    public:
    int value;
    node *left,*right;
    node(int value){

        this->value=value;
         left=right=NULL;
          }
};
node* insert(node *root,int value){
    if(!root){
        node* temp= new node(value);
        return temp;
    }
    if(root->value<value){
        root->right = insert(root->right,value);
    }
      if(root->value>value){
        root->left = insert(root->left,value);
    }
    else{
        root->right=insert(root->right,value);
    }
    return root;
}
void inorder(node* root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout<<root->value<<" ";
    inorder(root->right);

}

int main(){
    int arr[10]={4,7,9,10,1,3,2,5,6,8};
    node* root;
    for(int i=0;i<10;i++){
     root=insert(root,arr[i]);
    }
    inorder(root);


    return 0;
}
