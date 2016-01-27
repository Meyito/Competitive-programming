#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int tc, i, n;
    string line, w;
    vector<string> words[55];
    set<int> tam;
    bool flag;
 
    while(cin>>tc){
        getline(cin, line);
        while(tc>0){
            istringstream inp;
            getline(cin, line);
            inp.str(line);
            flag=false;
            while(inp>>w){
                tam.insert(w.size());
                words[w.size()].push_back(w);
            }
             
            set<int>::reverse_iterator it;
            for (it=tam.rbegin(); it!=tam.rend(); ++it){
                n=*it;
                for(i=0; i<words[n].size(); i++){
                    if(!flag){
                        flag=true;
                    }else{
                        cout<<" ";
                    }
                    cout<<words[n][i];
                }
                words[n].clear();
            }
            cout<<endl;
            tc--;
        }
     
    }
    return 0;
}