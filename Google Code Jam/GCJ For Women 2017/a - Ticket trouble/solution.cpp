#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <string.h>
#include <fstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    ifstream cin("data2.in");
    ofstream cout("data2.out");

	int t, tc, f, s, c, r, i;
	unsigned long rta;
	map< int, set<int> > cont;

	tc = 1;

	cin >> t;

	while( tc <= t ){
		cout << "Case #" << tc << ": ";
		cont.clear();
		cin >> f >> s;
		rta = 0;

		for( i = 0; i < f; i++ ){
			cin >> c >> r;
			cont[c].insert(r);
			cont[r].insert(c);
			
			rta = max( rta, cont[c].size() );
			rta = max( rta, cont[r].size() );
		}

		cout << rta << "\n";
		tc++;
	}

	return 0;
}
