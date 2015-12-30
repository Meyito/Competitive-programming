#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

int main()
{
    int n ;
    while ( cin >> n )
    {
        if ( n == 0 ) break ;
        {
            int log_2 = log2 ( n ) ;
            int k = 1 << log_2 ;
            if ( n == k )
            {
                cout << n << endl;
            }
            else
            {
                cout << ( n - k ) * 2 << endl;
            }
        }
    }
    return 0 ;
}
