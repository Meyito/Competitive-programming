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

#define ALT 10
#define MAX 1000
#define UP 60
#define RIGHT 30
#define DOWN 20
#define INF 1e9

int memo[ ALT ][ MAX + 5 ] ;
int w[ ALT ][ MAX + 5 ] ;
int m ;

int dp (  int dist , int alt )
{
    if ( alt >= ALT || alt < 0 || dist > m ) return INF ;

    if ( dist == m  )
    {
        if ( alt == 0 )
        {
            return 0 ;
        }
        else
        {
            return INF ;
        }
    }

    if ( memo[alt][dist] != -1 ) return memo[alt][dist] ;

    return memo[alt][dist] = min (  60 - w[alt][dist] + dp ( dist+1,alt+1 ) ,
                                  min (  30 - w[alt][dist] + dp ( dist+1,alt ) , 20 - w[alt][dist] + dp ( dist+1 , alt-1 ) ) ) ;
}

int main()
{
    int N ; sc ( N ) ;
    while (N--)
    {
        int X ; sc ( X ) ;
        m = X / 100 ;


        REP ( i, ALT)
            REP ( j , m )
                sc( w[ALT-i-1][j]);

        clr ( memo , -1 ) ;
        cout << dp ( 0 , 0 ) << endl;
    }
    return 0 ;
}
