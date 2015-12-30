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

int h , w ;
bool vis [ 55 ][ 55 ] ;
char a [ 55 ][ 55 ] ;


int dx[] = {1,-1,0,0} ;
int dy[] = {0,0,1,-1} ;

int ans ;

void dfs ( int x , int y, char c  )
{
    if ( x < 0 || y < 0 || x == h || y == w || vis[ x ][ y ] || a[ x ][ y ] != c ) return ;
    vis[ x ][ y ] = true ; ans++;
    for ( int i = 0 ; i < 4 ; i++ ) dfs ( x + dx[ i ] , y + dy[ i ] , c ) ;
}

bool cmp ( pair < char , int > p1 , pair < char , int > p2 )
{
    if ( p1.second == p2.second ) return ( p1.first > p2.first ) ;
    return ( p1.second < p2.second ) ;
}

int main ()
{
    int iter = 0;
    while ( cin >> h >> w )
    {
        iter++;
        if ( h == w && w == 0 ) break ;

        for ( int i = 0 ; i < h ; i++ )
            for ( int j = 0 ; j < w ; j++ )
                cin >> a[ i ][ j ] ;

        memset ( vis, false , sizeof(vis) ) ;

        vector < pair < char , int > > v ;

        for ( int i = 0 ; i < h ; i++ )
        {
            for ( int j = 0 ; j < w ; j++ )
            {
                if ( a[ i ][ j ] != '.' )
                {
                      ans = 0 ;
                      dfs ( i , j , a[ i ][ j ] );
                      if ( ans > 0 ) v.push_back ( make_pair ( a[ i ][ j ] , ans ) );
                }
            }
        }

        sort ( v.begin() , v.end() , cmp ) ;
        reverse ( v.begin() , v.end() ) ;
        printf("Problem %d:\n",iter) ;
        for ( int i = 0 ; i < v.size() ; i++ ) cout << v[i].first << " " << v[i].second << endl;
    }

    return 0;
}
