#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
void findSubset(char *input,char *output,int i,int j){
//base codition
if (input[i]=='\0'){

 	output[j]='\0';
 	if (output[0]=='\0') {cout<<"NULL";}
	cout<<output<<endl; 
	return;
}

//rec condition	
output[j]=input[i];
findSubset(input,output,i+1,j+1);

//output[j]='\0';
findSubset(input,output,i+1,j);

}

int main()
{
    
    char input[100],output[100];
    cin>>input;		//input abcdef
    findSubset(input,output,0,0);
    cout<<endl;
    return 0;
}