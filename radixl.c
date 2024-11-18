#include<stdio.h>
#include<stdlib.h>

//max element,radix_sort,print,createnode,insertnode,deletehead_node
struct node{
    int data;
    struct node* next;
};

struct node* createnode(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}

void insert_node(struct node** head,int data){//used passby reference
    if(*head==NULL){
        *head=createnode(data);
    }
    else{
        struct node* temp = *head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
       temp->next=createnode(data);
    }
}

int max_element(int arr[],int n){
    int temp = arr[0];
    for(int i=0;i<n;i++){
        
        if(temp<arr[i]){
            temp=arr[i];
        }
    }
    return temp;
}


int delete_headnode(struct node** head){
    int data = (*head)->data;
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
    return data;

}
/*this passes pointer which points 1st element of array thus 
changes will happen in original array*/

void radix_sort(int arr[],int n){
    struct node* bucket[10]={NULL};
    int max = max_element(arr,n);
for(int exp=1;max/exp!=0;exp*=10){

   for(int i=0;i<n;i++){//insertion into bucket
    insert_node(&bucket[(arr[i]/exp)%10],arr[i]);
 }
 int index = 0;
 for(int i=0;i<10/*use 10*/;i++){//copy back to original array
  while(bucket[i/*use i for sorted copy*/] !=NULL){//use while loop
    arr[index++]=delete_headnode(&bucket[i]);
  }
 }
}
}
//print
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        printf(" %d ",arr[i]);
    }
}
int main(){

    int arr[]={454,12,1,8700,12,243,454,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("original array was:");
    print(arr,n);
    radix_sort(arr,n);
    printf("\n after sorting array is: ");
    print(arr,n);
    return 0;
}

