//Written by Syed Mujtaba - (aka) mujtaba1747.
//Seek knowledge from the Cradle to the Grave !!
// https://www.linkedin.com/in/syed-mujtaba-064a5016a  
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector< int >
#define pb push_back 
#define MP make_pair
#define fi first
#define se second
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

}








































/*
bool prime[n+1]
memset(prime,true,sizeof(prime));
void sieve()
{

	for (int p=2; p*p<=n; p++) 
	{  
		if (prime[p] == true) 
		{  
			for (int i=p*p; i<=n; i += p) 
				prime[i] = false; 
		} 
	} 
}
	// Print all prime numbers 
	for (int p=2; p<=n; p++) 
	if (prime[p]) 
		cout << p << " "; */
*/

// C++ program to find prime factorization of a 
// number n in O(Log n) time with precomputation 
// allowed. 

/*
#define MAXN 100001 

// stores smallest prime factor for every number 
int spf[MAXN]; 

// Calculating SPF (Smallest Prime Factor) for every 
// number till MAXN. 
// Time Complexity : O(nloglogn) 
void sieve() 
{ 
	spf[1] = 1; 
	for (int i=2; i<MAXN; i++) 

		// marking smallest prime factor for every 
		// number to be itself. 
		spf[i] = i; 

	// separately marking spf for every even 
	// number as 2 
	for (int i=4; i<MAXN; i+=2) 
		spf[i] = 2; 

	for (int i=3; i*i<MAXN; i++) 
	{ 
		// checking if i is prime 
		if (spf[i] == i) 
		{ 
			// marking SPF for all numbers divisible by i 
			for (int j=i*i; j<MAXN; j+=i) 

				// marking spf[j] if it is not 
				// previously marked 
				if (spf[j]==j) 
					spf[j] = i; 
		} 
	} 
} 

// A O(log n) function returning primefactorization 
// by dividing by smallest prime factor at every step 
vector<int> getFactorization(int x) 
{ 
	vector<int> ret; 
	while (x != 1) 
	{ 
		ret.push_back(spf[x]); 
		x = x / spf[x]; 
	} 
	return ret; 
} 

// driver program for above function 
int main(int argc, char const *argv[]) 
{ 
	// precalculating Smallest Prime Factor 
	sieve(); 
	int x = 12246; 
	cout << "prime factorization for " << x << " : "; 

	// calling getFactorization function 
	vector <int> p = getFactorization(x); 

	for (int i=0; i<p.size(); i++) 
		cout << p[i] << " "; 
	cout << endl; 
	return 0; 
} 
*/
 











