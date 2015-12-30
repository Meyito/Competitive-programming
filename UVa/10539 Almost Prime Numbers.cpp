#include <bits/stdc++.h>
using namespace std;

bitset<1000010> bs ;
vector<long long> primes ;
vector<long long> almost ;
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

    for ( int i = 0 ; i < primes.size() ; i++ )
    {
        long long p = primes[ i ] ;
        for ( long long j = p*p ; j <= 1000000000000 ; j*=p ) almost.push_back( j );
    }
}



int main()
{
    sieve( 1000000 );

    int N ; cin >> N ;
    long long a , b ;

    while ( N-- )
    {
            cin >> a >> b ;
            long long ans = 0 ;
            for ( int i = 0 ; i < almost.size() ; i++ )
            {
                if ( almost[ i ] >= a && almost[ i ] <= b  ) ans++;
            }
            cout << ans << endl;
    }
    return 0;
}
