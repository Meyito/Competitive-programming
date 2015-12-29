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

int MODEXP ( int mod , long long BASE , int EXP )
{
	long long ANS = 1 ; 
	while ( EXP > 0 )
	{
		if ( EXP & 1 ) ANS = (ANS * BASE) % mod ; 
		BASE = ( BASE * BASE ) % mod ;
		EXP /= 2 ; 
	}
	return ANS ;	
}

bool prime ( int n )
{
	if ( n == 1 ) return false ; 
	if ( n == 2 ) return true ;
	for ( int i = 2 ; i <= (int)(sqrt (n) + 1 ) ; i++ )
	{
		if ( n % i == 0 ) return false ; 
	}
	return true ; 
}

bool Charmichael ( int n )
{
	if ( n == 1 ) return false ;
	if ( prime ( n ) ) return false ;
	for ( int i = 2 ; i <= n - 1 ; i++ )
	{
		if ( MODEXP ( n , i , n ) != i ) return false ;
	}
	return true ;
}

int main()
{
    int n ; cin >> n ; 
    while ( n != 0 )
    { 
    	if ( Charmichael ( n ) )
    	{
    		printf("The number %d is a Carmichael number.\n", n) ;
    	} else 
    	{
    		printf("%d is normal.\n", n) ;
    	}
    	cin >> n ;
    }
    return 0;
}
