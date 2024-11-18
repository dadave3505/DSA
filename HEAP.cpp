#include<iostream>
using namespace std;

class heap{
    int size,totalsize;
    int *arr;
    public:
    heap(int n){
        size=0;
        arr = new int[n];
        totalsize=n;
    }
    void insert(int value){
    if(size==totalsize){
        return;
    }
   arr[size]=value;
   int index=size;
   size++;
   
 while(index>0&&arr[index]<arr[(index-1)/2]){
    swap()
   }
}

};



int main(){


heap h1(4);

    return 0;
}