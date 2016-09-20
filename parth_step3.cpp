#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

int main () {
  string line;
  ifstream infile ("test.in.txt");
  if (infile.is_open())
  {
  	ofstream outfile ("test.out.txt");
  	if (outfile.is_open())
  	{ 
		int i=0, over200=0;
		int num, x2, y2, z2;
		int x1=0, y1=0, z1=0;
		while ( getline (infile,line,' ') )
		{
			stringstream is( line );
			while (is >> num) { 
				i++;
				if (i == 1) x2=num;
				if (i == 2) y2=num;
				if (i == 3) { 
					z2=num; 
					cout << x2 << ' ' << y2 << ' ' << z2 << '\n';
					int distance = hypot(hypot(x1-x2,y1-y2),z1-z2);
					outfile << distance << '\n';
					x2=y2=z2=i=0; 
					if (distance > 200) over200++;
				}
			}
			if (i == 1) x2=num;
			if (i == 2) y2=num;
			if (i == 3) { 
				z2=num; 
				cout << x2 << ' ' << y2 << ' ' << z2 << '\n';
				int distance = hypot(hypot(x1-x2,y1-y2),z1-z2);
				outfile << distance << '\n';
				x2=y2=z2=i=0; 
				if (distance > 200) over200++;
			}
		}
		infile.close();
		outfile << over200 << '\n';
		outfile.close();
	} else {
  		cout << "Unable to output file";
		return 0;
	}
  } else {
	cout << "Unable to open input file";
	return 0;
  }
  return 0;
}
