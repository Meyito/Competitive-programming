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
 
//#define MOD 1000000009
#define INF (1<<30)
#define EPS (1e-5) 
#define MAX 10005
#define ERR (1e-9)
#define SIZE 100005 

using namespace std ;

int memo[220] ; 

int solve ( int x )
{
	if ( x == 0 ) return 0 ; 
	if ( x == 1 ) return 1 ; 
	if ( x == 2 ) return 3 ; 
	
	if ( memo[x] != -1 ) return memo[x] ; 
	
	int maxx = -1 ; 
	for ( int i = 1 ; i < x ; i++ )
	{
		maxx = max (  solve ( i ) + solve ( x-i ) , maxx ) ; 
	}
	
	return memo[x] = maxx ;  
}

int main()
{
	int N ;
	while ( cin >> N )
	{
		memset ( memo , -1 , sizeof(memo));
		cout << solve(N) << endl;
	}
	return 0;
}
