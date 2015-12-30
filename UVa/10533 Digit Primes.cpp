#include <bits/stdc++.h>
using namespace std;

bitset<1000010> bs ;
vector<int> dp ;

int sum_dif ( int N )
{
    int sum = 0 ;
    while ( N > 0 )
    {
        sum += ( N % 10 ) ;
        N /= 10 ;
    }
    return sum ;
}

void sieve ( long long MAX )
{
    bs.reset() ; bs.flip() ; bs[ 0 ] = bs[ 1 ] = false ;
    for ( long long i = 2 ; i < MAX + 1 ; i++ )
    {
        if ( bs[ i ] )
        {
            for ( long long j = i*i ; j < MAX + 1 ; j += i ) bs[ j ] = false ;
            if ( bs[ sum_dif ( i ) ] ) dp.push_back ( i ) ;
        }
    }
}

int main()
{
    sieve( 1000000 );

    int N , t_1 , t_2 ; cin >> N ;
    while ( N-- )
    {
            scanf("%d %d",&t_1,&t_2);
            int lo = lower_bound(dp.begin(), dp.end(), t_1) - dp.begin();
            int hi = lower_bound(dp.begin(), dp.end(), t_2) - dp.begin();
            if(hi == dp.size() || dp[hi] != t_2) printf("%d\n", hi - lo);
            else printf("%d\n", hi - lo + 1);
    }
    return 0;
}
