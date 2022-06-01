#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;

void printList(list<int> l){
for (auto lt=l.begin();lt != l.end();++lt)
        cout << ' ' << *lt;
}

void TowerOfHanoi(int n,list<int>& A,list<int>& B,list<int>& C){
	if (n==0) return;
TowerOfHanoi(n-1,A,C,B);
B.push_back(A.back());  //A>B
A.pop_back();

TowerOfHanoi(n-1,C,B,A);
}

int noOfStepsTowerOfHanoi(int n){
	if (n==0) return 0;
return(1+noOfStepsTowerOfHanoi(n-1)*2);
}

void StepsTowerOfHanoi(int n,char A,char B,char C){
	if (n==0) return;
StepsTowerOfHanoi(n-1,A,C,B);
cout<<A<<"-->"<<B<<endl;
StepsTowerOfHanoi(n-1,C,B,A);
}

int main()
{
    
    int n;
    cin>>n;
    list<int> A,B,C ;
    for(int i=n;i>0;i--){
    	A.push_back(i);
    }
    cout <<"A[";
printList(A);
cout <<']'<<endl<<"B[";
printList(B);
cout <<']'<<endl<<"C[";
printList(C);
cout <<']'<<endl;
    TowerOfHanoi(n,A,B,C);
    cout <<"-----------"<<endl;
    cout <<"A[";
printList(A);
cout <<']'<<endl<<"B[";
printList(B);
cout <<']'<<endl<<"C[";
printList(C);
cout <<']'<<endl;
	
	cout <<"-----------"<<endl;
    cout <<"Steps : ";
    StepsTowerOfHanoi(n,'A','B','C');

    cout <<"-----------"<<endl;
    cout <<"Total no of steps : "<<noOfStepsTowerOfHanoi(n);
}


// input: 5
// output:
// A[ 5 4 3 2 1]
// B[]
// C[]
// -----------
// A[]
// B[ 5 4 3 2 1]
// C[]
// -----------
// Steps : A-->B
// A-->C
// B-->C
// A-->B
// C-->A
// C-->B
// A-->B
// A-->C
// B-->C
// B-->A
// C-->A
// B-->C
// A-->B
// A-->C
// B-->C
// A-->B
// C-->A
// C-->B
// A-->B
// C-->A
// B-->C
// B-->A
// C-->A
// C-->B
// A-->B
// A-->C
// B-->C
// A-->B
// C-->A
// C-->B
// A-->B
// -----------
// Total no of steps : 31