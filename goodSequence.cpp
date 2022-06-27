#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;

vector<int> give_prime(int element){
vector<int> primes;
for(int i=2;i*i<=element;i++){
	if(element%i ==0){
		primes.push_back(i);
		while(element%i ==0) element /=i;
	}

}

if(element > 1){
	primes.push_back(element);
}

return primes;
}

int main()
{
    
    int n;
    int N=1e5+1;
    cin>>n;
    int sequence[n],dp_prime[N];
    memset(dp_prime,0,sizeof(dp_prime));

    for(int i=0;i<n;i++){
    	cin>>sequence[i];

    	int ans=0;
    	vector<int> prime_div=give_prime(sequence[i]);
    	for(int p:prime_div){
    		
    		ans=max(ans,dp_prime[p]);
    	}
    	

    	for(int p:prime_div){
    		dp_prime[p]=ans+1;
    	}
    }



	 cout<< *max_element(dp_prime,dp_prime+N); 

    
    cout<<endl;
    return 0;
}

// input:
// 9
// 1 2 3 5 6 7 8 9 10
// output:
// 4