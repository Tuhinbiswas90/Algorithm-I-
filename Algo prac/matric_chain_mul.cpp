#include<iostream>
using namespace std;

int main(){
    int n=5;
    int p[]={5,4,2,7,6};
    int m[5][5]={0};
    int s[5][5]={0};

    int j,i,q,min;

    for(int d=1;d<n-1;d++){         //this loop is for diagonal ...... 1st diagonal then 2nd & then 3rd...
        for(int i=1;i<n-d;i++){     // i=row
            j=i+d;

            for(int k=i;k<j-1;k++){  //this loop is for finding the min
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];    //formula
                if(q<min){
                    min=q;
                    s[i][j]=k;
                }
            }
            m[i][j]=min;
        }
    }
    cout<<m[i][n-1];
}