#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <cctype>
 
#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define f(i,x,y) for (int i = x; i < y; i++)
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define pii pair< int , int >
#define pll pair< ll , ll >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
 
//#define MOD 1000000009
#define INF (1<<30)
#define EPS (1e-5) 
#define MAX 10005
#define ERR (1e-9)
#define SIZE 100005 

using namespace std ;

string line;
char keyboard[256];
 
int main() 
{
    for(int i = 0; i < 256; i++)
        keyboard[i] = i;
    // remap
    keyboard['1'] = '`';
    keyboard['2'] = '1';
    keyboard['3'] = '2';
    keyboard['4'] = '3';
    keyboard['5'] = '4';
    keyboard['6'] = '5';
    keyboard['7'] = '6';
    keyboard['8'] = '7';
    keyboard['9'] = '8';
    keyboard['0'] = '9';
    keyboard['-'] = '0';
    keyboard['='] = '-';
    keyboard['W'] = 'Q';
    keyboard['E'] = 'W';
    keyboard['R'] = 'E';
    keyboard['T'] = 'R';
    keyboard['Y'] = 'T';
    keyboard['U'] = 'Y';
    keyboard['I'] = 'U';
    keyboard['O'] = 'I';
    keyboard['P'] = 'O';
    keyboard['['] = 'P';
    keyboard[']'] = '[';
    keyboard['\\'] = ']';
    keyboard['S'] = 'A';
    keyboard['D'] = 'S';
    keyboard['F'] = 'D';
    keyboard['G'] = 'F';
    keyboard['H'] = 'G';
    keyboard['J'] = 'H';
    keyboard['K'] = 'J';
    keyboard['L'] = 'K';
    keyboard[';'] = 'L';
    keyboard['\''] = ';';
    keyboard['X'] = 'Z';
    keyboard['C'] = 'X';
    keyboard['V'] = 'C';
    keyboard['B'] = 'V';
    keyboard['N'] = 'B';
    keyboard['M'] = 'N';
    keyboard[','] = 'M';
    keyboard['.'] = ',';
    keyboard['/'] = '.';
 
    while(getline(cin, line)) {
        for(int i = 0; i < line.length(); i++) {
            line[i] = keyboard[line[i]];
        }
        cout << line << endl;
    }
    return 0 ;
}
