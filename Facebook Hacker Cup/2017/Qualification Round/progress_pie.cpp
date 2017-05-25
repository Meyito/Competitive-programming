#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

struct point {
	double x, y;
  	point() {
  		x = y = 0.0;
  	}
  	point(double _x, double _y) : x(_x), y(_y) {}
  	bool operator == (point other) const {
   		return (fabs(x - other.x) < 1e-9 && (fabs(y - other.y) < 1e-9));
   	}
};

struct vec {
	double x, y;
  	vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVector(point a, point b) {
	return vec(b.x - a.x, b.y - a.y);
}

double euclideanDistance(point p1, point p2) {
  return hypot(p1.x - p2.x, p1.y - p2.y);
}

double RadToDeg(double r) {
	return r * 180.0 / acos(-1.0);
}

double angle(point a, point b, point c) {
  	vec ba = toVector(b, a);
  	vec bc = toVector(b, c);
  	return acos((ba.x * bc.x + ba.y * bc.y) / sqrt((ba.x * ba.x + ba.y * ba.y) * (bc.x * bc.x + bc.y * bc.y)));
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    ifstream cin("progress_pie.txt");
    ofstream cout("output.out");

	int t, i, x, y;
	double p, a, b;
	string rta;

	cin >> t;
	i = 1;

	while( i <= t ){
		cout << "Case #" << i << ": ";
		rta = "white";

        cin >> p >> x >> y;

        if( euclideanDistance( point(50, 50), point (x, y) ) <= 50.0 ){

            if( x == 50 && y == 50 && p >= 1 ){
                rta = "black";
            } else {
                b = angle( point(50, 100), point(50, 50), point(x,y) );
                a = RadToDeg( b );
                if( x < 50 ) {
                    a = 360 - a;
                }

                a = (a * 100 ) / 360;

                if( a <= p) rta = "black";
            }
        }

		cout << rta << "\n";
		i++;
	}

	return 0;
}
