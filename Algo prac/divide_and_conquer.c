#include<stdio.h>
int dac(int arr[],int low,int high){
    if(low==high){
        return 0;
    }
    int mid=(low+high)/2;
    int left=dac(arr,low,mid);
    int right=dac(arr,mid+1,high);
    return (left<right)?left:right;
}
int main(){
    int arr[]={10,5,2,7,1};
    int n=sizeof(arr)/sizeof(arr[0]); 
    int min=dac(arr,0,n-1);
    printf("The minimum element in the array is %d\n",min);
    return 0;

    
}