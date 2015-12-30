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
    string s , t ;
    while ( cin >> s >> t )
    {
         int s_size = s.size();
         int t_size = t.size();

         int ind = 0 ;
         bool ans = true ;

         for ( int i = 0 ; i < s_size ; i++ )
         {
              bool ok = false ;
              for ( int j = ind ; j < t_size && !ok ; j++ )
              {
                  if ( t[j] == s[i] )
                  {
                       ok = true ;
                       ind = j + 1 ;
                  }
              }

              if ( !ok )
              {
                  ans = false;
                  puts("No");
                  break;
              }
         }

         if ( ans ) puts("Yes");
    }
    return 0;
}
