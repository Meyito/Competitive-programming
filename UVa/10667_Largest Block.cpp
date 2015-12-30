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

int M [104][104] ;

int kadane ( int a[] , int n )
{
	int max_so_far = 0 ; 
	int max_ending_here = 0 ; 
	
	for ( int i = 0 ; i < n ; i++ )
	{
		max_ending_here += a[i] ; 
		if ( max_ending_here < 0 ) max_ending_here = 0 ; 
		if ( max_so_far < max_ending_here ) max_so_far = max_ending_here ;
	}
	return max_so_far ;
}

int solve ( int n )
{
	int max = 0 ; 
	for ( int left = 0 ; left < n ; left++ )
	{
		int temp[n];
		memset ( temp , 0 , sizeof ( temp ) ) ;
		
		for ( int right = left ; right < n ; right++ )
		{
			for ( int i = 0 ; i < n ; i++ )
			{
				temp[i] += M[i][right] ;
			}
			
			int sum = kadane( temp , n );
        	if  ( sum > max ) max = sum ; 
		}
	}
	return max ;
}

int main ()
{
	int p ; cin >> p ; 
	while ( p-- )
	{
		int s ; cin >> s ; 
		for ( int i = 0 ; i < s ; i++ )
		{
			for ( int j = 0 ; j < s ; j++ )
			{
				M[i][j] = 1 ;
			}
		}
		int b ; cin >> b ; 
		int r1, c1 , r2 , c2 ; 
		for ( int i = 0 ; i < b ; i++ )
		{
			cin >> r1 >> c1 >> r2 >> c2 ; 
			r1-- ; c1-- ; r2-- ; c2--;
			for ( int y = r1 ; y <= r2 ; y++ )
			{
				for ( int x = c1 ; x <= c2 ; x++ )
				{
					 M[y][x] = -105 ; 
				}
			}
		}
		cout << solve ( s ) << endl;	
	}
	return 0 ;
}
