
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

bool isPrime ( int N )
{
    if ( N < 1000000 ) return bs[ N ] ;
    int i = 0 ;
    while ( primes[ i ]*primes[ i ] <= N )
    {
        if ( N % primes[ i ] == 0 ) return false ;
        i++;
    }
    return true ;
}

int main()
{
    sieve( 1000000 );
    bool check [10010];
    memset ( check,  false , sizeof( check ) ) ;
    for ( int i = 0 ; i <= 10000 ; i++ ) 
    {
        int num = i*i+ i + 41 ;
        if ( isPrime( num ) ) check[ i ] = true ;
    }
    int a , b  ;
    while ( cin >> a >> b )
    {
        double cont = 0 ;
        for ( int i = a ; i <= b ; i++ ) if ( check[ i ] ) cont++;
        double ans =  roundf( 10000.0 * cont  / ( double ) ( b - a + 1 + 1e-9 ) ) / 100.00 ;
        printf("%.2lf\n",ans);
    }
    return 0;
}
