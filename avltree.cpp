#include <iostream>
using  namespace std;
//AVL TREE
class avl{ //structure of a node
  public:
    int data;
    int height;
    avl *left, *right;
  

};
//assignment
avl* createnode(int data){
    avl* root=new avl;//run time creation
    root->data=data;
    root->left=NULL;root->right=NULL;
    root->height=1;
    return root;
}
int max(avl* root){

}

avl* insert(avl *root,int data){
//empty
if(!root){
    root=createnode(data);
    return root;
}
// filled
else{
    // greater 
    if(data>root->data){
        //go to right
        root->right=insert(root->right,data);
    }
    // less
     else if(data<root->data){
        //go to right
        root->left=insert(root->left,data);
    }
    
}
root->height+=1;
// LL
if((root->left->height - root->right->height)>1 && data<root->left->data){
    //rotate right
    avl* temp = root->left->right;
    root->left->right = root;
    root->left= temp;
   return root->left;
}
// RR
else if((root->left->height - root->right->height)<1 && data>root->right->data){
    avl* temp = root->right->left;
    root->right->left = root;
    root->right= temp;
   return root->right;
}
// LR
else if((root->left->height - root->right->height)<1 && data>root->right->data){
    avl* temp = root->right->left;
    root->right->left = root;
    root->right= temp;
   return root->right;
}

// RL
else if((root->left->height - root->right->height)<1 && data>root->right->data){
    avl* temp = root->right->left;
    root->right->left = root;
    root->right= temp;
   return root->right;
}
}

int main(){
avl *root;
int arr[]={4,1,78,43,56,21};
int size = sizeof(arr)/sizeof(arr[0]);
for(int i=0;i<size;i++){

    root = insert(root,arr[i]);
}


    return 0 