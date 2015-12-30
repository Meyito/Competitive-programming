#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define FOR( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)v.size())

#define mp make_pair
#define fi first
#define se second

#define MOD 1000000007

int n ;
bool vis[ 105 ][ 105 ] ;
int a[ 105 ][ 105 ] ;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int ans ;

void dfs ( int x , int y , int c )
{
    if ( x < 0 || y < 0 || x == n || y == n || vis[ x ][ y ] || a[ x ][ y ] != c ) return ;
    vis [ x ][ y ] = true ; ans++;
    for ( int i = 0 ; i < 4 ; i++ ) dfs ( x + dx[ i ] , y + dy[ i ] , c ) ;
}

int main ()
{
    while ( cin >> n )
    {
            if ( n == 0 ) break ;

            memset( vis , 0 , sizeof(vis) ) ;
            memset ( a , 0 , sizeof(a) ) ;

            int x , y ;

            string aux , s ;
            getline ( cin , aux ) ;

            for ( int i = 1 ; i < n ; i++ )
            {
                getline (cin, s) ;
                stringstream is(s);
                while( is >> x >> y ) a[ x - 1][ y - 1 ] = i ;
            }

            bool ok = true ;

            for ( int i = 0 ; i < n ; i++ )
            {
                for ( int j = 0 ; j < n ; j++ )
                {
                    if ( !vis[ i ][ j ] )
                    {
                        ans = 0 ;
                        dfs ( i , j , a[ i ][ j ] ) ;
                        if ( ans != n ) ok = false ;
                    }
                }
            }
            puts(ok?"good":"wrong");
    }

    return 0;
}
