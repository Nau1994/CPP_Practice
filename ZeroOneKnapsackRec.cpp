#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
//vector<int> dp;

int knapsacRec(int value[],int weight[],int s,int index){
	//cout<<"knapsacRec";
//base
	if (index==-1) return 0;
	if(value[index]>s) return knapsacRec(value,weight,s,index-1);

//rec
	return(max(weight[index]+knapsacRec(value,weight,s-value[index],index-1),knapsacRec(value,weight,s,index-1)));

}

int main()
{
    
    int s;
    cin>>s;
    int n;
    cin>> n;
    int value[n],weight[n];
    for (int i=0;i<n;i++){
    	cin>>value[i];
    	cin>>weight[i];
    }

//recursive
     cout<<knapsacRec(value,weight,s,n-1)<<endl;
    

    cout<<endl;
    return 0;
}


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