#include <stdio.h>

using namespace std;

int main(){
    int n,i, max, actual; 
    scanf("%i", &n);
    bool anteriorDer=false;
    int pos[n];
    int h[n];
    max=0;
    i=0;
    actual=i;
    scanf("%i %i", &pos[i], &h[i]);
    i++;
    while(i<n){
        scanf("%i %i", &pos[i], &h[i]);
        if(i==1){
            max++;
        }else if(anteriorDer){
            if((pos[actual]-h[actual])>(pos[actual-1]+h[actual-1])){
                max++;
                anteriorDer=false;
            }else if((pos[actual]+h[actual])<pos[i]){
                max++;
                anteriorDer=true;
            }else{
                anteriorDer=false;
            }
        }else if((pos[actual]-h[actual])>pos[actual-1]){
            max++;
            anteriorDer=false;
        }else if((pos[actual]+h[actual])<pos[i]){
            max++;
            anteriorDer=true;
        }
        actual=i;
        i++;
    }
    max++;
    printf("%i\n", max);
}