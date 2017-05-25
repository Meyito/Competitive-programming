#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <fstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    ifstream cin("pie_progress.txt");
    ofstream cout("output.txt");

	int t, tc, n, m, i, d;
	long long rta, b, a;
	vector<long long> aux;

	tc = 1;

	cin >> t;

	while( tc <= t ){
		cout << "Case #" << tc << ": ";
		rta = 0;
		priority_queue<long long, std::vector<long long>, std::greater<long long> > totals;

		cin >> n >> m;

		d = n;

		while( n-- ){
			aux. clear();
			for( i = 1; i <= m; i++){
				cin >> a;
				aux.push_back(a);
			}

			sort(aux.begin(), aux.end());

			for( i = 1; i <= m; i++){
                b = (i * i) - ( (i-1) * (i-1) );
				a = aux[i-1] + b;
				totals.push(a);
			}

			rta += totals.top();
			totals.pop();
		}

		cout << rta << "\n";
		tc++;
	}

	return 0;
}
