#include <bits/stdc++.h>
using namespace std;

int N , p ;

vector<int> ans ;

int gcd ( int a , int b )
{
    if ( b == 0 ) return a ;
    return gcd ( b , a % b ) ;
}

void solve ( int N , int pos )
{
    if ( pos == p+1 )
    {
        if ( N != 0 ) return ;
        printf("%d",ans[1]);
        for ( int i = 2 ; i <= p ; i++ ) printf(" %d",ans[ i ]) ;
        cout << endl;
        return;
    }
    else
    {
        for ( int i = 1 ; i <= N ; i++ )
        {
            ans.push_back ( i ) ;
            if ( i >= ans[ pos-1 ]  )
            {
                bool ok = true ;
                for ( int j = 1 ; j < ans.size()-1 ; j++ )
                {
                    if ( gcd ( i , ans[ j ] ) != 1 )
                    {
                        ok = false ;
                        break ;
                    }
                }
                if ( ok ) solve ( N - i , pos + 1 ) ;
            }
            ans.pop_back() ;
        }
    }
}

int main()
{

    int t ; cin >> t ;

    for ( int i = 1 ; i <= t ; i++ )
    {
            ans.clear();
            ans.push_back ( 1 ) ;
            cin >> N >> p ;
            printf("Case %d:\n",i);
            solve ( N , 1 ) ;
    }
    return 0;
}
