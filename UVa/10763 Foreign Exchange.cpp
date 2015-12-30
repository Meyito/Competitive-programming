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
    int n ; sc ( n ) ;
    while ( n != 0 )
    {
        map < pair <int,int> , int > m ;
        int s , t ;
        REP(i,n)
        {
            sc ( s ) ;
            sc ( t ) ;
            m [ mp ( min ( s ,t ) , max ( s, t ) ) ]++;
        }

        bool ok = true ;
        for ( std::map<pair<int,int>,int>::iterator it = m.begin() ; it != m.end() ; ++it )
        {

            if ( it->se % 2 != 0 )
            {
                cout << "NO" << endl;
                ok = false ;
                break ;
            }
        }

        if ( ok ) cout << "YES" << endl;
        sc ( n ) ;
    }

    return 0 ;
}
