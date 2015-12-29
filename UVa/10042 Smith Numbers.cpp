#include <bits/stdc++.h>
using namespace std;

bitset<32010> bs ;
vector<int> primes ;

void sieve ( )
{
    bs.reset() ; bs.flip() ; bs[ 0 ] = bs[ 1 ] = false ;
    for ( long long i = 2 ; i <= 32001 ; i++ )
    {
        if ( bs[ i ] )
        {
            for ( long long j = i*i ; j <= 32001 ; j += i ) bs[ j ] = false ;
            primes.push_back ( i ) ;
        }
    }
}

int sum_digits ( int N )
{
    int ans = 0 ;
    while ( N > 0 )
    {
        ans += ( N % 10 ) ;
        N /= 10 ;
    }
    return ans ;
}

bool smith ( int N )
{
    int pf_idx = 0 , pf = primes[ pf_idx ] ;

    long long sum_div = 0 ;
    long long sum_cif = sum_digits ( N ) ;

    bool prime = true ;

    while ( N != 1 && pf*pf <= N )
    {
        while ( N % pf == 0 )
        {
            N /= pf ;
            prime = false;
            sum_div += sum_digits( pf ) ;
        }
        pf = primes[ ++pf_idx ] ;
    }

    if ( N != 1 ) sum_div += sum_digits( N ) ;

    return ( !prime && ( sum_div == sum_cif ) ) ;
}

void solve ( int N )
{
    int i = N + 1 ;
    while ( true )
    {
        if  ( smith ( i ) )
        {
            cout << i << endl;
            return ;
        }
        i++;
    }
}


int main()
{
    int n, x ; sieve() ; cin >> n ;
    for ( int i = 0 ; i < n ; i++ ) cin >> x , solve ( x ) ;
    return 0;
}
