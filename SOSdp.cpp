// CPP program for brute force
// approach of SumOverSubsets DP
#include <bits/stdc++.h>
using namespace std;


// function to print the sum over subsets value
// O(N*2^N)
void SumOverSubsetsOptimal2(int a[], int n) {
  // array to store the SumOverSubsets
  int sos[1 << n];
  memcpy(sos, a, sizeof(sos));
  // iterate for the bitwise subsets only
    for (int i = 0; i < n; i++ ){
    // iterate for all possible x
  for (int x = 0; x < (1 << n); x++) {
    	if((x>>i)&1){
    		sos[x] += sos[x^(1<<i)];
    	}
    }     
  }
  // print all the subsets
  for (int i = 0; i < (1 << n); i++)
    cout << sos[i] << " ";
}



// function to print the sum over subsets value
// O(N*2^N)
void SumOverSubsetsOptimal(int a[], int n) {
  // array to store the SumOverSubsets
  int sos[1 << n] = {0};

  // iterate for all possible x
  for (int x = 0; x < (1 << n); x++) {
    sos[x] = a[0];
    // iterate for the bitwise subsets only
    for (int i = x; i > 0; i = (i - 1) & x)
      sos[x] += a[i];
  }
  // print all the subsets
  for (int i = 0; i < (1 << n); i++)
    cout << sos[i] << " ";
}

// function to print the sum over subsets value
// O(2^N*2^N)
void SumOverSubsetsBrutforce(int a[], int n) {
// array to store the SumOverSubsets
int sos[1 << n] = {0};
// iterate for all possible x
for (int x = 0; x < (1 << n); x++) {
	// iterate for all possible bitwise subsets
	for (int i = 0; i < (1 << n); i++) {
	// if i is a bitwise subset of x
	if ((x & i) == i)
		sos[x] += a[i];
	}
}
// printa all the subsets
for (int i = 0; i < (1 << n); i++)
	cout << sos[i] << " ";
}

// Driver Code
int main() {
int a[] = {7, 12, 14, 16};
int n = 2;
SumOverSubsetsBrutforce(a, n);
cout<<endl;
SumOverSubsetsOptimal(a, n);
cout<<endl;
SumOverSubsetsOptimal2(a, n);
cout<<endl;


return 0;
}
