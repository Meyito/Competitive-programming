#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

double pi = 2*acos(0.0) ;

int main()
{
    double a , b , v , A , s ;
    while ( cin >> a >> b >> v >> A >> s )
    {
        if ( a == b && b == v && v == A && A == s && s == 0 ) break ;
        double v_x = v * cos ( A * pi / 180.0 ) ;
        double v_y = v * sin ( A* pi / 180.0 ) ;
        int d_x = ( a + v_x * s ) / ( 2.0*a ) ;
        int d_y = ( b + v_y * s ) / ( 2.0*b ) ;
        cout << d_x << " " << d_y << endl;
    }
    return 0 ;
}
