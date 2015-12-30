#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)v.size())

#define mp make_pair
#define fi first
#define se second

int main()
{
    int c ; sc ( c ) ;
    int n , t , m ;
    while ( c-- )
    {
        scanf("%d%d%d",&n,&t,&m);
        int a[m] ; REP(i,m) sc(a[i]);
        int time = 0 ;
        int aux = 0  ;
        for ( int i = (n+m-1)%n ; i < m ; i+=n )
        {
            aux = max ( time,a[i] );
            time = aux + 2*t ;
        }
        printf("%d %d\n",  time - t, (m + n - 1)/n);

    }
    return 0;
}
