#include <bits/stdc++.h>
using namespace std;

bitset<47010> bs ;
vector<int> primes ;
bool check [ 1000005 ] ;

void sieve ( long long MAX )
{
    bs.reset() ; bs.flip() ; bs[ 0 ] = bs[ 1 ] = false ;
    for ( long long i = 2 ; i <= MAX + 1 ; i++ )
    {
        if ( bs[ i ] )
        {
            for ( long long j = i*i ; j <= MAX + 1 ; j += i ) bs[ j ] = false ;
            primes.push_back ( i ) ;
        }
    }
}

int main()
{
    sieve( 47000 );

    int l , u ;
    while ( cin >> l >> u )
    {
        if(l<2) l = 2;
        if(u<l) u = l;

        memset ( check , true , sizeof( check ) ) ;

        for ( int i = 0 ; i < primes.size() ; i++ )
        {
        // get the first index that is multiple of prime p inside the interval
              int start = (int)(ceil( l /(double)( primes[ i ] ))) ; 
              if ( start == 1 ) start++; // check if p >= l ( the prime is inside the interval )
              for ( int j = start ; j*primes[ i ] - l < u - l + 1 ; j++ ) check[ j*primes[ i ] - l ] = false ;
        }


        int last_prime = -1 ;
        int next_prime = -1 ;
        int minn_dif = 1000005 ;
        int minn_x , minn_y ;
        int maxx_dif = -1 ;
        int maxx_x , maxx_y ;
        int diff ;

        for ( int i = 0 ; i < u - l + 1 ; i++ )
        {
            if ( check[ i ] )
            {
                next_prime = i ;
                if ( last_prime != -1 )
                {
                    if ( next_prime - last_prime > maxx_dif )
                    {
                        maxx_dif = next_prime - last_prime ;
                        maxx_x = next_prime + l ;
                        maxx_y = last_prime + l ;
                    }

                    if ( next_prime - last_prime < minn_dif )
                    {
                        minn_dif = next_prime - last_prime ;
                        minn_x = next_prime + l  ;
                        minn_y = last_prime + l  ;
                    }

                }
                last_prime = next_prime ;
            }
        }
        if ( maxx_dif == -1 ) puts ( "There are no adjacent primes." );
        else printf("%d,%d are closest, %d,%d are most distant.\n", minn_y,minn_x,maxx_y,maxx_x);
    }
    return 0;
}
