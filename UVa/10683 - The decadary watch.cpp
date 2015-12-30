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

char s[8] ;

void convert ( )
{
	int h = ( s[0]- '0')*10+ ( s[1] - '0' ) ;
	int m = ( s[2]- '0')*10+ ( s[3] - '0' ) ;
	int k = ( s[4]- '0')*10+ ( s[5] - '0' ) ;
	int c = ( s[6]- '0')*10+ ( s[7] - '0' ) ; 
	
	int  time =  ( 3600*h + 60*m + k )*100 + c ;
	time = time*125/108  ;
	printf("%07d\n", time);
	
}
int main ( )
{
	while ( gets (s) ) convert();
	return 0 ;
}
