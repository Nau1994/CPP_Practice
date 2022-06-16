#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
int cnt=0;
vector<vector<int>> dp;


int makeFenceGreatRec(int board[],int rubal[],int index,int n,int stat){
	++cnt;
	//cout<<stat<<endl;
//base
	if (index==n){
		return 0;
	}
	if(dp[index][stat]!=-1) return dp[index][stat];

//rec
	int ans;
	if (board[index]== board[index+1]){
	
	if (index >=0 and board[index]== board[index-1]){
	ans= 2*rubal[index]+makeFenceGreatRec(board,rubal,index+1,n,0);
	}
	else{
		ans= rubal[index]+makeFenceGreatRec(board,rubal,index+1,n,0);
	}
	
	
	board[index+1]=board[index+1]+1;
	ans= min(ans,rubal[index+1]+makeFenceGreatRec(board,rubal,index+1,n,1));
	board[index+1]=board[index+1]-1;
	
	}
	else{
		ans= makeFenceGreatRec(board,rubal,index+1,n,0);
	}
	
	return dp[index][stat]=ans;

	
}

int main()
{
    
    int n;
    cin>>n;
    int board[n],rubal[n];
    for(int i=0;i<n;i++){
    	cin>>board[i]>>rubal[i];
    }

    dp.resize(n,vector<int>(3,-1));

    cout<<makeFenceGreatRec(board,rubal,0,n,0)<<endl;
    //cout<<cnt<<endl; //call count

    cout<<endl; 
    return 0;
}

// input:
// 5
// 2 4
// 2 1
// 3 5
// 3 4
// 4 2
// output:
// 6

// input:
// 6
// 2 4
// 2 1
// 3 5
// 3 4
// 4 2
// 5 3
// output:
// 6

// input:
// 7
// 2 4
// 2 1
// 3 5
// 3 4
// 4 2
// 5 3
// 5 2
// output:
// 8

// input:
// 8
// 2 4
// 2 1
// 3 5
// 3 4
// 4 2
// 5 3
// 5 2
// 5 3
// output:
// 8