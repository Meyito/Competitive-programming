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
    int n , m ;
    while ( true )
    {
            scanf("%d%d",&n,&m);
            if ( n == m && m == 0 ) break ;

            int d[n] ; int h[m];
            for ( int i = 0 ; i < n ; i++ ) sc(d[i]) ;
            for ( int i = 0 ; i < m ; i++ ) sc(h[i]) ;

            if ( m < n )
            {
                puts("Loowater is doomed!") ;
                continue ;
            }

            sort ( d , d + n ) ;
            sort ( h , h + m ) ;

            int ind = 0 ;
            int ans = 0 ;

            bool flag = true ;

            for ( int i = 0 ; i < n ; i++ )
            {
                bool ok = false ;
                for ( int j = ind ; j < m && !ok ; j++ )
                {
                    if ( d[i] <= h[j] )
                    {
                        ans += h[j] ;
                        ind = j + 1 ;
                        ok = true ;
                    }
                }

                if ( !ok )
                {
                    puts("Loowater is doomed!");
                    flag = false ;
                    break;
                }
            }

            if ( flag ) printf("%d\n",ans);
    }
    return 0 ;
}
