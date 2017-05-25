#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

unsigned long long rta;
long long m, d, l, n;

void wad(priority_queue< pair<unsigned long long,long long>,vector<pair<unsigned long long,long long> >, greater<pair<unsigned long long,long long> > > wt, queue<unsigned long long> dry){
	unsigned long long bg, tf;
	long long cont=0;
	pair<unsigned long long, long long> aux;
	int sv=m;

	while(cont<l){
		aux = wt.top();
		wt.pop();
		bg=aux.first;
		wt.push(make_pair(bg+aux.second, aux.second));

		if(sv>0){
			sv--;
			dry.push(bg+d);
		}else{
			tf=dry.front();
			dry.pop();
			if(tf<bg){
				dry.push(bg+d);
			}else{
				dry.push(tf+d);
			}
		}
		cont++;
	}

	rta=dry.back();
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    ifstream cin("lm.txt");
    ofstream cout("salida.txt");

    int tc, t;
    long long aux;
    long long i;

    cin>>tc;
    t=1;

    while(t<=tc){
    	rta=0;
    	queue<unsigned long long> dry;
    	priority_queue< pair<unsigned long long,long long>,vector<pair<unsigned long long,long long> >, greater<pair<unsigned long long,long long> > > wt;

    	cin>>l>>n>>m>>d;

    	for(i=0; i<n; i++){
    		cin>>aux;
    		wt.push(make_pair(aux, aux));
    	}

    	wad(wt, dry);

    	cout<<"Case #"<<t<<": "<<rta<<endl;
    	t++;
    }

    return 0;
}
