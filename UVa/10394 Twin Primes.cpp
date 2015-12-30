#include <bits/stdc++.h>
using namespace std;

bitset<20000010> bs ;
vector<int> primes ;
vector< pair < int,int > > twins ;

void sieve ( long long MAX )
{
    bs.reset() ; bs.flip() ; bs[ 0 ] = bs[ 1 ] = false ;
    for ( long long i = 2 ; i < MAX + 1 ; i++ )
    {
        if ( bs[ i ] )
        {
            for ( long long j = i*i ; j < MAX + 1 ; j += i ) bs[ j ] = false ;
            primes.push_back ( i ) ;
        }
    }

    for ( int i = 1 ; i < primes.size() ; i++ )
    {
        if ( primes[ i ] - primes[ i - 1 ] == 2 )
        {
            twins.push_back( make_pair ( primes[ i - 1 ] , primes[ i ] ) ) ;
        }
    }
}


int main()
{
    sieve( 20000010 );
    int n ; while ( cin >> n ) cout << "(" << twins[ n - 1 ].first << ", " << twins[ n - 1 ].second << ")" << endl;
    return 0;
}
