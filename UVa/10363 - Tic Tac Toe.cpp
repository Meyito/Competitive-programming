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

char board[3][3] ; 

void check ()
{
	// Number of X
	int x = 0 ; 
	for ( int i = 0 ; i < 3 ; i++ )
	{
		for ( int j = 0 ; j < 3 ; j++ )
		{
			x += ( board[i][j] == 'X' ) ;
		}
	}
	// Number of O
	int o = 0 ; 
	for ( int i = 0 ; i < 3 ; i++ )
	{
		for ( int j = 0 ; j < 3 ; j++ )
		{
			o += ( board[i][j] == 'O' ) ;
		}
	}

	// Check if by numbers are possible
	
	int rcd[8] ; memset ( rcd , 0 , sizeof ( rcd ) ) ;
		 
		 if ( board[0][0] == board[0][1] && board[0][1] == board[0][2] )
		 {
		 	if ( board[0][0] == 'X' ) rcd[0] = 1 ; 
		 	else if ( board[0][0] == 'O' ) rcd[0] = -1 ; 
		 }
		 
		 if ( board[1][0] == board[1][1] && board[1][1] == board[1][2] )
		 {
		 	if ( board[1][0] == 'X' ) rcd[1] = 1 ; 
		 	else if ( board[1][0] == 'O' ) rcd[1] = -1 ; 
		 }
		 
		 if ( board[2][0] == board[2][1] && board[2][1] == board[2][2] )
		 {
		 	if ( board[2][0] == 'X' ) rcd[2] = 1 ; 
		 	else if ( board[2][0] == 'O' ) rcd[2] = -1 ; 
		 }
		 
		 if ( board[0][0] == board[1][0] && board[1][0] == board[2][0] )
		 {
		 	if ( board[0][0] == 'X' ) rcd[3] = 1 ; 
		 	else if ( board[0][0] == 'O' ) rcd[3] = -1 ; 
		 }
		 
		 if ( board[0][1] == board[1][1] && board[1][1] == board[2][1] )
		 {
		 	if ( board[0][1] == 'X' ) rcd[4] = 1 ; 
		 	else if ( board[0][1] == 'O' ) rcd[4] = -1 ; 
		 }
		 
		 if ( board[0][2] == board[1][2] && board[1][2] == board[2][2] )
		 {
		 	if ( board[0][2] == 'X' ) rcd[5] = 1 ; 
		 	else if ( board[0][2] == 'O' ) rcd[5] = -1 ; 
		 }
		 
		 if ( board[0][0] == board[1][1] && board[1][1] == board[2][2] )
		 {
		 	if ( board[0][0] == 'X' ) rcd[6] = 1 ; 
		 	else if ( board[0][0] == 'O' ) rcd[6] = -1 ; 
		 }
		 
		 if ( board[0][2] == board[1][1] && board[1][1] == board[2][0] )
		 {
		 	if ( board[0][2] == 'X' ) rcd[7] = 1 ; 
		 	else if ( board[0][2] == 'O' ) rcd[7] = -1 ; 
		 }
		 
		 int num_win_x = 0 ; 
		 int num_win_o = 0 ; 
		 
		 for ( int i = 0 ; i < 8 ; i++ ) num_win_x += ( rcd[i] ==  1 ) ;
		 for ( int i = 0 ; i < 8 ; i++ ) num_win_o += ( rcd[i] == -1 ) ;

		 if ( (num_win_x != 0 && num_win_o != 0 ) || ( num_win_x != 0 && x - o != 1  ) || ( num_win_o  && x - o != 0 ) || ( x - o != 0 && x-o != 1))
		 {
		 	cout << "no" << endl;
		 }
		 else 
		 {
		 	cout << "yes" << endl;
		 }
}

int main ( )
{
	int n ; cin >> n ; 
	for ( int i = 0 ; i < n ; i++ )
	{
		cin >> board[0][0] >> board[0][1] >> board[0][2] ;
		cin >> board[1][0] >> board[1][1] >> board[1][2] ;
		cin >> board[2][0] >> board[2][1] >> board[2][2] ;
		check();
	}
	
	return 0 ;
}
