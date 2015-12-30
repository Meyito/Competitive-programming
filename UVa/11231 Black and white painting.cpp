#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

int main()
{
    long long n , m , ans ;
    int c ;
    while ( cin >> n >> m >> c )
    {
        if ( n == m && m == c && c == 0 ) break ;
        if ( c == 1 )
        {
            if ( ( n + m ) % 2 == 1 )
            {
                ans = ( n - 7 )*( m - 7 )/2 ;
            }
            else
            {
                ans = ( ( n - 7 )*( m - 7 ) + 1 )/2 ;
            }

        }
        else
        {
            ans = ( n - 7 )*( m - 7 )/2 ;
        }
        cout << ans << endl;
    }

    return 0 ;
}
