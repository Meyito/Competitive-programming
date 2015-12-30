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
	int h1, m1, s1, sp1, h2, m2, s2 , sp2 ;
	h1 = m1 = s1 = sp1 = 0 ;
	float distance = 0 ; 
	char str[30] ;

	while ( gets(str) )
	{
		int len = strlen ( str ) ; 
		if ( len == 8 )
		{
			sscanf(str,"%d:%d:%d",&h2,&m2,&s2);
			distance += ( (float)( (h2-h1)*3600.0 + (m2-m1)*60 + (s2-s1) ) ) * ( (sp1) / 3600.0f )  ;
			h1 = h2 ; 
			m1 = m2 ; 
			s1 = s2 ; 
			printf("%d%d:%d%d:%d%d %.2f km\n",h2/10,h2%10,m2/10,m2%10,s2/10,s2%10, distance ) ;
			
		} else 
		{
			sscanf(str,"%d:%d:%d %d",&h2,&m2,&s2,&sp2);
			distance += ( (float)( (h2-h1)*3600.0 + (m2-m1)*60 + (s2-s1) ) ) * ( (sp1) / 3600.0f )  ;
			h1 = h2 ; 
			m1 = m2 ; 
			s1 = s2 ; 
			sp1 = sp2 ; 
		}	
	}
	return 0 ;
}
