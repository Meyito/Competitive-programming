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

int x , y ;
int pos_0_x , pos_0_y ;
int num_beepers ;
int pos_beep[ 15 ][ 2 ] ;
bool vis[ 15 ] ;
int minn_cost  ;

void backtrack ( int n , int cost_so_far , int last_x , int last_y )
{
    if ( cost_so_far > minn_cost ) return ;

    if ( n == num_beepers )
    {
         cost_so_far += abs( pos_0_x - last_x ) +  abs( pos_0_y - last_y ) ;

         minn_cost = min ( minn_cost , cost_so_far ) ;

         return ;
    }
    else
    {

        for ( int i = 0 ; i < num_beepers ; i++ )
        {
            if ( !vis[ i ] )
            {
                 vis[ i ] = true ;

                 cost_so_far += abs( pos_beep[ i ][ 0 ] - last_x ) +  abs( pos_beep[ i ][ 1 ] - last_y ) ;

                 backtrack  ( n + 1 , cost_so_far , pos_beep[ i ][ 0 ] , pos_beep[ i ][ 1 ]  ) ;

                 cost_so_far -= abs( pos_beep[ i ][ 0 ] - last_x ) +  abs( pos_beep[ i ][ 1 ] - last_y ) ;

                 vis[ i ] = false ;
            }
        }
    }

}


int main ()
{
    int cases ; cin >> cases ;
    while ( cases-- )
    {
        cin >> x >> y ;
        cin >> pos_0_x >> pos_0_y ;
        cin >> num_beepers ;
        for ( int i = 0 ; i < num_beepers ; i++ ) cin >> pos_beep[ i ][ 0 ] >> pos_beep[ i ][ 1 ];
        minn_cost = INT_MAX ;
        backtrack( 0 , 0 , pos_0_x , pos_0_y ) ;
        printf("The shortest path has length %d\n", minn_cost ) ;

    }
    return 0 ;
}
