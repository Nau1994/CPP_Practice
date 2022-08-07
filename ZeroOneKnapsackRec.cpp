#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
const int N=1e5;
int value[N],weight[N];

int knapsacRecOptimized(int i,int s){ 
    if (i<0) return 0;
    
    int ans=0;
    //rec
    if (value[i]<=s){
        ans=max(ans,knapsacRecOptimized( i-1, s-value[i])+weight[i]);
    }

    ans=max(ans,knapsacRecOptimized( i-1, s));
    return ans;
}

int knapsacRec(int value[],int weight[],int s,int index){ 
	//cout<<"knapsacRec";
//base
	if (index==-1) return 0;
//rec
	//exclude
	if(value[index]>s) return knapsacRec(value,weight,s,index-1);


	//include
	return(max(weight[index]+knapsacRec(value,weight,s-value[index],index-1),knapsacRec(value,weight,s,index-1)));

}

int main()
{
    
    int s,n;
    cin>>s;
    
    cin>> n;
    
    for (int i=0;i<n;i++){
    	cin>>value[i];
    	cin>>weight[i];
    }

//recursive
      cout<<knapsacRec(value,weight,s,n-1)<<endl;
      
      cout<<knapsacRecOptimized(n-1,s)<<endl;
      

    cout<<endl;
    return 0;
}

// constraint
// 1≤N.≤100
// 1≤W.≤10^5
// 1≤w(i)≤W.
// 1≤v(i)≤10^9

// Input: 
// V. N.
// v1 w1 
// v2 w2 
// .  .  
// .  .  
// vN wN 

// input:
// 4 5
// 1 8
// 2 4
// 3 0
// 2 5
// 2 3
// output:
// 13

// input:
// 4 3
// 3 30
// 2 15
// 2 18
// output:
// 33