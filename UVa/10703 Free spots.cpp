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

int main ( )
{
	int w , h , n ; 
	int x1 , x2 , y1 , y2 ;
	
	while ( scanf ("%d %d %d" ,&w , &h , &n ) == 3 )
	{
		if ( w == 0 && h == 0 && n == 0 ) break ;
		int M[h][w] ; memset ( M , -1 , sizeof(M) ) ;
		
		while ( n-- )
		{
			scanf("%d %d %d %d", &x1 , &y1 , &x2 , &y2 );
			y1--;
			y2--;
			x1--;
			x2--;
			
			for ( int y = min(y1,y2) ; y <= max(y1,y2) ; y++ )
			{
				for ( int x = min(x1,x2) ; x <= max(x1,x2) ; x++ )
				{
					M[y][x] = 0 ;
				}
			}	
		}
		
		int ans = 0 ; 
		for ( int i = 0 ; i < h ; i++ )
		{
			for ( int j = 0 ; j < w ; j++ )
			{
				ans -= M[i][j];
			}
		}
		
		if ( ans == 0 )
		{
			cout << "There is no empty spots." << endl;

		} else if ( ans == 1 )
		{
			cout << "There is one empty spot." << endl ;
		} 
		else 
		{
			cout << "There are "<< ans <<" empty spots." << endl;
		}
	}
	return 0 ;
}
