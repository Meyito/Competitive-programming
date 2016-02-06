#include <iostream>
using namespace std;

int binaryExponentiation(int a, int b, int c){
    if (b == 0){
    	return 1;
    } 
    if (b % 2 == 0){
        int temp = binaryExponentiation(a,b/2, c);
        return ((long long)(temp) * temp) % c;
    }else{
        int temp = binaryExponentiation(a, b-1, c);
        return ((long long)(temp) * a) % c;
    }
}

int main() {
	int r;
	int c=2147483647;
	cin>>r;
	cout<<binaryExponentiation(3, r, c)<<"\n";
	return 0;
}