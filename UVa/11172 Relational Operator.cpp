#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int t , x , y  ; cin >> t ;
    while ( t-- )
    {
            cin >> x >> y ;
            if ( x == y )
            {
                puts("=");
            }
            else if ( x > y )
            {
                puts(">") ;
            }
            else
            {
                puts("<") ;
            }

    }
	return 0 ;
}
