#include <iostream>
#include <vector>
#include <deque>
#include <fstream>

using namespace std;

int main() {
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    ifstream cin("input.in");
    ofstream cout("output.out");

	int t, i, travels, n, a, x;
	vector<int> w;

	cin >> t;
	i = 1;

	while( i <= t ){
		cout << "Case #" << i << ": ";
		travels = 0;
		w.clear();

		cin >> n;
		while ( n-- ){
			cin >> a;
			w.push_back( a );
		}

		sort( w.begin(), w.end() );
		deque<int> ww ( w.begin(), w.end() );

		while( !ww.empty() ){
			a = ww.back();
			ww.pop_back();

			if( a >= 50 ){
				travels++;
			}
			else{
				x = 1;
				while( !ww.empty() ){
					x++;
					ww.pop_front();
					if( a * x >= 50 ){
						travels++;
						break;
					}
				}
			}
		}


		cout << travels << "\n";
		i++;
	}
	return 0;
}
