#include <bits/stdc++.h>

using namespace std;

string table[15];
string ins;
int targets, wt, r;
bool complete;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
map<char, int> moves;

void resolve( int i, int wx, int wy ){
	if( targets == 0 && wt == 0 ){
		complete = true;
		return;
	}
	
	if( i >= ins.size() ) return;
	
	int nx, ny, bx, by;
	
	nx = wx + dx[ moves[ ins[i] ] ];
	ny = wy + dy[ moves[ ins[i] ] ];
	
	if( table[ny][nx] == '.' ){
		table[ny][nx] = 'w';
		
		if( table[wy][wx] == 'W' ){
			targets++;
			table[wy][wx] = '+';
			wt = 0;
		}else table[wy][wx] = '.';
		
	}else if( table[ny][nx] == 'b' || table[ny][nx] == 'B' ){
		bx = nx + dx[ moves[ ins[i] ] ];
		by = ny + dy[ moves[ ins[i] ] ];
		
		if( table[by][bx] == '.' || table[by][bx] == '+'){
			if( table[ny][nx] == 'B' ){
				table[ny][nx] = 'W';
				wt++;
			}else table[ny][nx] = 'w';
			
			if( table[wy][wx] == 'W' ){
				targets++;
				table[wy][wx] = '+';
				wt--;
			}else table[wy][wx] = '.';
		
			if( table[by][bx] == '.' ){
				table[by][bx] = 'b';
			}else if( table[by][bx] == '+' ){
				table[by][bx] = 'B';
				targets--;
			}
		} else{
			nx = wx;
			ny = wy;
		}
	}else if( table[ny][nx] == '+' ){
		targets--;
		wt++;
		table[ny][nx] = 'W';
		
		if( table[wy][wx] == 'W' ){
			targets++;
			table[wy][wx] = '+';
			wt--;
		}else table[wy][wx] = '.';
	}else{
		nx = wx;
		ny = wy;
	}
	
	/*cout << ins[i] << endl;
	
	for( int  i = 0; i < r; i++ ){
			cout << table[i] << "\n";
		}*/
		
	resolve( i+1, nx, ny);
}

int main(){
	int c, i, j, wx, wy, g;
	moves['U'] = 0;
	moves['D'] = 1;
	moves['L'] = 2;
	moves['R'] = 3;
	
	g  = 1;
	while( cin >> r >> c && r && c ){
		complete = false;
		targets = wt = 0;
		for( i = 0; i < r; i++ ){
			cin >> table[i];
			
			for( j = 0; j < c; j++ ){
				if( table[i][j] == '+' ) targets++;
				if( table[i][j] == 'W' ) wt++;
				if( table[i][j] == 'w' || table[i][j] == 'W' ){
					wx = j;
					wy = i;
				}
			}
		}
		
		cin >> ins;
		
		/*for( i = 0; i < r; i++ ){
			cout << table[i] << "\n";
		}*/
		
		resolve(0, wx, wy);
		
		cout << "Game " << g << ": ";
		if( complete ) cout << "complete\n";
		else cout << "incomplete\n";
		
		for( i = 0; i < r; i++ ){
			cout << table[i] << "\n";
		}
		 
		g++;
	}
	return 0;
}