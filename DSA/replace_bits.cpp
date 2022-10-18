#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
// #define int long long int
void decToBin(int x){
	int i=16;

	while(i>=0){
		int mask=(1<<i);
		// cout<<mask<<"mask"<<endl;
		if(x & mask) cout<<'1';
		else cout<<'0';
		i--;
	} cout<<endl;
}

int32_t main()
{
    
    int M=23+256+128+64,N=11+16;
    int i=2,j=6;
    int mask=(-1<<j+1)^(-1<<i);
    cout<<"M:                     ";decToBin(M);
    cout<<"N:                     ";decToBin(N);
    cout<<"Mask:                  ";decToBin(~mask);
    cout<<"Clear M,i="<<i<<" to j="<<j<<":	   ";decToBin(M & (~mask));
    cout<<"replace i to j with N: ";decToBin((M & (~mask))|(N<<i));
    
    // cout<<(mask);
}

// output:
// M:                     111010111
// N:                     000011011
// Mask:                  110000011
// Clear M,i=2 to j=6:	   110000011
// replace i to j with N: 111101111
