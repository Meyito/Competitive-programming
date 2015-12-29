#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <cctype>
 
#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define f(i,x,y) for (int i = x; i < y; i++)
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define pii pair< int , int >
#define pll pair< ll , ll >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
 
#define MOD 1000000009
#define INF (1<<30)
#define EPS (1e-5) 
#define MAX 1000000000
#define ERR (1e-9)
#define SIZE 100005 

using namespace std ;
 
vector < vector <int> > adj_list ; 
vector <int> color ; 
int a , b , l , n ; 

bool COLORABLE ( int n )
{
	bool ans = true ;
	for ( int i = 0 ; i < adj_list[n].size() ; i++ )
	{
		if ( color [ adj_list[n][i] ] != 0 && color[ adj_list[n][i]] == color[ n ] ) return false ;
		if ( color [ adj_list[n][i] ] == 0 )
		{
			color[adj_list[n][i]] = (color[n] == 1? 2 : 1);
			ans = ans && COLORABLE ( adj_list[n][i] );
		}
	}
	
	return ans ;
}

int main()
{
    cin >> n ; 
    while ( n != 0  )
    {
    	cin >> l ;
    	adj_list.clear();
        adj_list.resize(n);
        color.assign(n, 0);
       	for ( int i = 0 ; i < l ; i++ )
       	{
       		cin >> a >> b ; 
       		adj_list[a].push_back ( b ) ; 
       		adj_list[b].push_back ( a ) ;
       	}
       	
       	color[0] = 1 ; 
       	printf("%s\n", COLORABLE(0)? "BICOLORABLE." : "NOT BICOLORABLE.");
        
    	cin >> n ;
    }
    return 0;
}
