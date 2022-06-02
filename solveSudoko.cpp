#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
void printMat(int mat[][9],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool canPlace(int mat[][9],int x,int y,int n,int k){

//check in sub mat
	for(int i=(x/3)*3;i< (x/3)*3+3;i++){
		for(int j=(y/3)*3;j< (y/3)*3+3;j++){
			if (mat[i][j]==k){return false; }
		}
	}

//check in row
	for(int j=0;j<n;j++){
			if (mat[x][j]==k){return false; }
		}
// check in column
		for(int i=0;i<n;i++){
			if (mat[i][y]==k){return false; }
		}
	return true;

}

bool solveSudoku(int mat[][9],int n,int i,int j){
//base
	if (i==n){ 
		printMat(mat,n);
		return true ;}

	if (j==n){
		i=i+1;
		j=0;
	}

//check in mat
	if (mat[i][j] == 0){
		//bruts
		for (int k=0;k<10;k++){
			if(canPlace(mat,i,j,n,k)){
				mat[i][j]=k;
				if(!solveSudoku(mat,n,i,j+1)){
					mat[i][j]=0;
				}
				else return true;
			}
		}
		return false;
//canplace
	}
	else{
		return solveSudoku(mat,n,i,j+1);
	}


}

int main()
{
    
    int n=9;
    int mat[9][9]={
{5,3,0,0,7,0,0,0,0},
{6,0,0,1,9,5,0,0,0},
{0,9,8,0,0,0,0,6,0},
{8,0,0,0,6,0,0,0,3},
{4,0,0,8,0,3,0,0,1},
{7,0,0,0,2,0,0,0,6},
{0,6,0,0,0,0,2,8,0},
{0,0,0,4,1,9,0,0,5},
{0,0,0,0,8,0,0,7,9}
};

if(!solveSudoku(mat,n,0,0)){
    cout<<"Solution doesn't exist"<<endl;
}
}


//output
// 5 3 4 6 7 8 9 1 2 
// 6 7 2 1 9 5 3 4 8 
// 1 9 8 3 4 2 5 6 7 
// 8 5 9 7 6 1 4 2 3 
// 4 2 6 8 5 3 7 9 1 
// 7 1 3 9 2 4 8 5 6 
// 9 6 1 5 3 7 2 8 4 
// 2 8 7 4 1 9 6 3 5 
// 3 4 5 2 8 6 1 7 9