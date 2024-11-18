#include<stdio.h>

//print,radix_sort,countingsort,maxelement
//print elements
void print(int arr[],int n){
   for(int i=0;i<n;i++){
      printf("%d  ",arr[i]);
  }
}
//get max element
int getmax(int arr[],int n){
   int max = arr[0];
   for(int i = 1;i<n;i++){
   if(max<arr[i]){
      max = arr[i];
   }
   }
   return max;
}
//counting algorithm
void countingsort(int arr[],int n,int exp){
   int count[10]={0};
    
   //stored counting of digits
   for(int i=0;i<n;i++){
      count[(arr[i]/exp)%10]++;
   }
   //given them a position where they should be stored
   for(int i=1;i<10;i++){
    count[i] += count[i-1];
   }
   //copy into temp array then back into original array
  int temp[n];
   
   for(int i=n-1;i>0;i--){
      temp[count[(arr[i]/exp)%10] - 1] = arr[i];
      count[(arr[i]/exp)%10]--;
   }
  for(int i=0;i<n;i++){
      arr[i]=temp[i];
   }
}
void radix_sort(int arr[],int n){
   int max = getmax(arr,n);
   for(int exp=1;max/exp>0;exp*=10){
      countingsort(arr,n,exp);
   }
}
 
 int main(){

int arr[] = {23,1,1243,55,789,890,987};
int n = sizeof(arr)/sizeof(arr[0]);
printf("original array is: ");
print(arr,n);

radix_sort(arr,n);

printf("\n array after radix sort: ");
print(arr,n);


    return 0;
 }