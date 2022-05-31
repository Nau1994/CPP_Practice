#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
int noConsecutiveOne(int n){
if (n==1){ return 2;}
else if (n==2){return 3;}
return(2+noConsecutiveOne(n-1));
}

int noConsecutiveOne_better(int n){
if (n==1){ return 2;}
else if (n==2){return 3;}
return(noConsecutiveOne_better(n-2)+noConsecutiveOne_better(n-1));
}

int main()
{
    
    int n;
    cin>>n;
    cout<<noConsecutiveOne_better(n);
    cout<<endl;
}