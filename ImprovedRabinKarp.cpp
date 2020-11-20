
#include <bits/stdc++.h> 
using namespace std; 

// d is the number of characters in the input alphabet 
#define d 256 

void search(char pat[], char txt[], int q) 
{ 
	int M = strlen(pat); 
	int N = strlen(txt); 
	int i, j; 
	int p = 0; // hash value for pattern 
	int t = 0; // hash value for txt 
	int h = 1; 

    double q_t, q_p;
    
	for (i = 0; i < M - 1; i++) 
		h = (h * d) % q; 


	for (i = 0; i < M; i++) 
	{ 
		p = (d * p + pat[i]) % q; 
		t = (d * t + txt[i]) % q; 
	} 


	for (i = 0; i <= N - M; i++) 
	{ 

		q_t=t/q;            //calculating quotient for text
		q_p=p/q;            //calculating quotient for pattern
		
		if ( p == t && q_t == q_p)    //comparing quotients alongside remainders
		{ 
			cout<<"Pattern found at index "<< i<<endl; 
		} 

		if ( i < N-M ) 
		{ 
			t = (d*(t - txt[i]*h) + txt[i+M])%q; 

			if (t < 0) 
			t = (t + q); 
		} 
	} 
} 

/* Driver code */
int main() 
{ 
	char txt[] = "GEEKS FOR GEEKS"; 
	char pat[] = "GEEK"; 
		
	// A prime number 
	int q = 101; 
	

	search(pat, txt, q); 
	return 0; 
} 

