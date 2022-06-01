#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
int gerateBrakets1(string output,int open,int close,int index,int n)
{
	//base
	if (index==n*2){
		cout<<output<<endl;
		return 1;
	}
	int ways=0;
	//rec
	// '('
	if(open<n){ //bruts force
		ways=+gerateBrakets1(output+"(",open+1,close,index+1,n);
	}
	// ')'
	if(open>close){ //bruts force
		ways+=gerateBrakets1(output+")",open,close+1,index+1,n);
	}
	return ways;
}

int gerateBrakets2(string output,int open,int close,int index,int n)
{
	//base
	if (index==n*2){
		cout<<output<<endl;
		return 1;
	}
	int ways=0;
	//rec
	// '('
	if(open<n){
		output=output+"("; //bruts force
		ways+=gerateBrakets2(output,open+1,close,index+1,n);
		output.pop_back(); //backtrack
	}
	// ')'
	if(open>close){
		output=output+")";  //bruts force
		ways+=gerateBrakets2(output,open,close+1,index+1,n);
		output.pop_back(); //backtrack
	}
	return ways;
}


int main()
{
    string output;
    int n;
    cin>>n;
    cout<<"------bruts force-------"<<endl;
    cout<<gerateBrakets1(output,0,0,0,n);//bruts force
    cout<<endl<<"------backtrack-------"<<endl;
    cout<<gerateBrakets2(output,0,0,0,n);////backtrack
    return 0;
}