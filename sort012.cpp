#include<iostream>
using namespace std;
void printArray(int arr[],int n){
   for (int i = 0; i <n; i++)
   {
     cout<<arr[i];
   }
   

}

void sortOne(int arr[],int n){
    int start=0;
    int mid=0;
    int end=n-1;

    while(mid<=end){

        switch(arr[mid]){
            case 0:
               swap(arr[start++],arr[mid++]);
               break;
            case 1:
              mid++;
               break;
            case 2:
              swap(arr[mid],arr[end--]);
              break;
        }
      }
}

int main(){
    int arr[100];

    int n;
    cout<<"Enter the size of the array :";
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   sortOne(arr,n);
   printArray(arr,n);
}