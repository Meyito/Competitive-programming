#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <string.h>
#include <fstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    ifstream cin("c.in");
    ofstream cout("c.out");

	int t, tc, d, n, i, j, k, w, cont, v;
	bool flag;

	char pattern[3][4] = { {'I','I','O','O'}, {'/','/','/','/'}, {'O','O','I','I'} };

	tc = 1;

	cin >> t;

	while( tc <= t ){
		cout << "Case #" << tc << ":\n";

		cin >> d >> n;

		if( n == 0 ) cout << "/OI/\n";

		cont = 0;
		while( n > 0 ){
			cont++;
			j = 0;
			v = 0;
			for( k = 0; k < 3; k++ ){
				j = 0;
				w = n;
				
				if( cont > 1 ){
					for( i = 0; i < 50 ; i++, w--, v++){
						if( w > 0 ){
							cout << pattern[k][j];
							j++;
							j%=4;
						}else{
							cout << "/";
						}
						
					}
				}else{
					for( i = 0; i < 50 && w > 0 ; i++, w--, v++){
						cout << pattern[k][j];
						j++;
						j%=4;
					}
				}
				cout << "\n";
			}
			n = w;
		}
		
		tc++;
	}

	return 0;
}
