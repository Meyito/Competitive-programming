#include<bits/stdc++.h>

#define endl "\n"

using namespace std;

int main(){
    int n,min1,max1,min2,max2,min3,max3, min, max, acum;

    cin>>n>>min1>>max1>>min2>>max2>>min3>>max3;

    min=min1+min2+min3;
    max=max1+max2+max3;

    if(min==n){
        cout<<min1<<" "<<min2<<" "<<min3<<endl;
    }else if(max==n){
        cout<<max1<<" "<<max2<<" "<<max3<<endl;
    }else{
        acum=min2+min3;
        if(acum+max1>=n){
            cout<<(n-acum)<<" "<<min2<<" "<<min3<<endl;
        }else{
            acum-=min2;
            acum+=max1;
            if(acum+max2>=n){
                cout<<max1<<" "<<(n-acum)<<" "<<min3<<endl;
            }else{
                acum+=max2;
                acum-=min3;
                cout<<max1<<" "<<max2<<" "<<(n-acum)<<endl;
            }
        }
    }
}