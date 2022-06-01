#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
void printBoard(int board[][20],int n){
for (int i=0;i<n;i++){
	for (int j=0;j<n;j++){
		cout<<board[i][j]<<" ";
	}
	cout<<endl;
}
for (int i=0;i<n;i++){
	
	cout<<"--";
}
cout<<endl;

}

bool canPlace(int board[][20],int n,int x,int y){
//column
	for(int i=0;i<x;i++){
		if(board[i][y]==1){ return false;}
	}
//left diag
	int i=x;
	int j=y;
	while(i>=0 & j>=0){
		if(board[i][j]==1){ return false;}
		i--;
		j--;
	}
//right diag
	 i=x;
	 j=y;
	while(i>=0 & j<n){
		if(board[i][j]==1){ return false;}
		i--;
		j++;
	}

	return true;
}


bool solveQueen(int board[][20],int n,int i){
//base
if (i==n){
	printBoard(board,n);

	return true;
}

//checkSuccess
for (int j=0;j<n;j++){
	if (canPlace(board,n,i,j)){
		board[i][j]=1;
		bool succes=solveQueen(board,n,i+1);
		//rec
		if (succes){
			return true;
		}
		board[i][j]=0;

		
	}
}

return false;


}

bool solveQueenAllSolution(int board[][20],int n,int i,int *noSol){
//base
if (i==n){
	// printBoard(board,n);
	printBoard(board,n);
	
	*noSol=*noSol+1;
	return true;
}

//checkSuccess
for (int j=0;j<n;j++){
	if (canPlace(board,n,i,j)){
		board[i][j]=1;
		bool succes=solveQueenAllSolution(board,n,i+1,noSol);
		
		board[i][j]=0;
		
	}
}

return false;


}

int solveQueenAllSolution2(int board[][20],int n,int i){
//base
if (i==n){
	// printBoard(board,n);
	printBoard(board,n);
	return 1;
}

int way=0;
//checkSuccess
for (int j=0;j<n;j++){
	if (canPlace(board,n,i,j)){
		board[i][j]=1;
		way+=solveQueenAllSolution2(board,n,i+1);
		board[i][j]=0;
		
	}
}

return way;

}

int main()
{
    int board[20][20]={0};
    int n,noSol=0;
    cin>>n;

    //1. to see is there any solution exist or not
    //solveQueen(board,n,0);  

    //2. to see all solution using pass by reference
    // solveQueenAllSolution(board,n,0,&noSol);  
    // cout<<"Total no of Solution : "<<noSol;

    //3. to see all solution using loacl variable
    cout<<solveQueenAllSolution2(board,n,0);
     return 0;
}

// input: 5

// output:
// 1 0 0 0 0 
// 0 0 1 0 0 
// 0 0 0 0 1 
// 0 1 0 0 0 
// 0 0 0 1 0 
// ----------
// 1 0 0 0 0 
// 0 0 0 1 0 
// 0 1 0 0 0 
// 0 0 0 0 1 
// 0 0 1 0 0 
// ----------
// 0 1 0 0 0 
// 0 0 0 1 0 
// 1 0 0 0 0 
// 0 0 1 0 0 
// 0 0 0 0 1 
// ----------
// 0 1 0 0 0 
// 0 0 0 0 1 
// 0 0 1 0 0 
// 1 0 0 0 0 
// 0 0 0 1 0 
// ----------
// 0 0 1 0 0 
// 1 0 0 0 0 
// 0 0 0 1 0 
// 0 1 0 0 0 
// 0 0 0 0 1 
// ----------
// 0 0 1 0 0 
// 0 0 0 0 1 
// 0 1 0 0 0 
// 0 0 0 1 0 
// 1 0 0 0 0 
// ----------
// 0 0 0 1 0 
// 1 0 0 0 0 
// 0 0 1 0 0 
// 0 0 0 0 1 
// 0 1 0 0 0 
// ----------
// 0 0 0 1 0 
// 0 1 0 0 0 
// 0 0 0 0 1 
// 0 0 1 0 0 
// 1 0 0 0 0 
// ----------
// 0 0 0 0 1 
// 0 1 0 0 0 
// 0 0 0 1 0 
// 1 0 0 0 0 
// 0 0 1 0 0 
// ----------
// 0 0 0 0 1 
// 0 0 1 0 0 
// 1 0 0 0 0 
// 0 0 0 1 0 
// 0 1 0 0 0 
// ----------
// 10