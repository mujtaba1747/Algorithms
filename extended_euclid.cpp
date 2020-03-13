// Author : Syed Mujtaba
// Seek knowledge from the Cradle to the Grave !!
// https://www.linkedin.com/in/syed-mujtaba-064a5016a 

#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b, int &x, int &y) // ax + by = gcd(a, b) // returns a single solution to ax + by = gcd(a, b) and if gcd(a, b) == 1 then x is modular inverse of a
{
	if(a == 0)
	{
		x = 0;
		y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd(b%a, a, x1, y1);
	x = y1 - (b / a)*x1;
	y = x1;
	return d;
}
int modinv(int a, int b)
{
	int x, y;
	if(gcd(a, b, x, y) != 1)
		return -1; // Mod Inv Does not Exist
	return (x%b + b)%b;
}
int main() // main for testing the above functions.
{
	int x, y;
	int a, b;
	cin >> a >> b;
	gcd(a, b, x, y);
	cout << x << " " << y << endl; // This is a solution to the equation  
	cout << (x%b + b)%b << endl;   // This is the Modular Inverse
	cout << (7*685)%799 << endl;
	cout << (7*-114 + 799)%799 << endl;
	cout << modinv(a, b) << endl;
}
// ax + my = 1 // take mod both sides ax = 1 mod m hence x is the modular inverse
