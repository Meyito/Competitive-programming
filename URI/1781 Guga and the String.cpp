#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int tc, i, q, ins, cant, despC, despV, j, x, y;
    vector<int> indV;
    vector<int> indC;
    map<int, int> coord;
    string s, ss;
    cin>>tc;
    i=1;
    while(i<=tc){
        cin>>s>>q;
        cout<<"Caso #"<<i<<":\n";
         
        indV.clear();
        indC.clear();
        coord.clear(); 
         
        despV=despC=0;
        ss=s;
        x=y=0;
        for(j=0; j<s.size(); j++){
            if(s[j]=='a' ||  s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u'){
                indV.push_back(j);
                coord[j]=x;
                x++;
            }else{
                indC.push_back(j);
                coord[j]=y;
                y++;
            }
        }
         
        while(q>0){
            cin>>ins;
            if(ins==2){
                for(j=0; j<s.size(); j++){
                    if(s[j]=='a' ||  s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u'){
                        ss[indV[(coord[j]+despV)%indV.size()]]=s[j];
                    }else{
                        ss[indC[(coord[j]+despC)%indC.size()]]=s[j];
                    }
                }
                cout<<ss<<endl;
            }else{
                cin>>cant;
                if(ins==0){
                    despV+=cant;
                }else{
                    despC+=cant;
                }
            }
            q--;
        }
         
        i++;
    }
     
    return 0;
}