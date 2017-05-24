#include <iostream>
#include <set>
#include <fstream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);

    ifstream cin("C2.in");
    ofstream cout("c-medium.out");

	int TC, t, n, k, mv, mxv, r;
	set<int>::iterator it;
	int p[] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576};
	set<int> pows( p, p+20);
	
	cin >> TC;
	t = 1;
	
	while( t <= TC ){
		cin >> n >> k;
		
		mxv = mv  = 0;
		if( k < n ){
			it = pows.upper_bound(k);
			r = *it;
			
			mxv = ( n - k  + ( r / 2 ) ) / r;
			mv = ( n - k ) / r;
		}
		
		cout << "Case #" << t << ": " << mxv << " " << mv << "\n";
		t++;
	}
	
	return 0;
}