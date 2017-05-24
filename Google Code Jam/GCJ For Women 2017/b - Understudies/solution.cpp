#include <iostream>
#include <stdio.h>
#include <map>
#include <set>
#include <queue>
#include <string.h>
#include <fstream>

using namespace std;

int main() {
    ifstream cin("b2.in");

	int t, tc, n, i, j, m;
	long double p, rta;
	vector<long double> aux;

	tc = 1;

	cin >> t;

	while( tc <= t ){
		cin >> n;
		aux.clear();

		m = n*2;
		for( i = 0; i < m; i++){
			cin >> p;
			aux.push_back( p );
		}

		sort( aux.begin(), aux.end() );

		rta = ( 1 - ( aux[0] * aux[m-1] ) );
		//cout << rta << " ";
		for( i = 1, j = m-2; i < j; i++, j-- ){
			rta *= ( 1 - ( aux[i] * aux[j] ) );
			//cout << i << " " << j << " " <<rta << endl;
		}
		printf("Case #%d: %.6Lf\n", tc, rta);
		tc++;
	}

	return 0;
}
