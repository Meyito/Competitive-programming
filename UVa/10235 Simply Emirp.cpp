#include <bits/stdc++.h>
using namespace std;

bitset<1000010> bs ;
vector<int> primes ;

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
}

int rev ( int N )
{
    int ans = 0 ;
    while ( N > 0 )
    {
        ans = 10*ans + ( N % 10 ) ;
        N /= 10 ;
    }
    return ans ;
}

int main()
{
    sieve( 1000000 );
    int N ;
    while ( cin >> N )
    {
        if ( !bs[ N ] )
        {
            printf("%d is not prime.\n",N) ;
        }
        else if ( N == rev ( N ) || !bs[ rev( N ) ] )
        {
            printf("%d is prime.\n",N) ;
        }
        else
        {
            printf("%d is emirp.\n",N) ;
        }
    }
    return 0;
}
