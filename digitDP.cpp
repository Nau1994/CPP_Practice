#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
string s1,s2;

void digitDp(string result,int index,bool last){
	//base
	if(index==s2.size()){
		cout<<result<<endl;
		return ;
	}

	//till
	int till= last?(s2[index]-'0'):9;
	//rec
	for(int i=0;i<=till;i++){
		digitDp(result+to_string(i),index+1,last && (i==till) );
	}

}

void digitDpFromTo(string result,int index,bool first,bool last){
	//base
	

	if(index==s2.size()){
		//output in integer
		cout<<stoi(result)<<endl;

		//output in string
		// cout<<result<<endl;
		return ;
	}

	

	//till
	
	int till= last?(s2[index]-'0'):9;

	//from
	// int from=(index<s1.size())?(first?(s1[index]-'0'):0):0;
	int from=first?(s1[index]-'0'):0;

	//rec
	for(int i=from;i<=till;i++){
		digitDpFromTo(result+to_string(i),index+1,first && (i==from),last && (i==till) );
	}

}

int main()
{
    
    cin>>s1>>s2;

    int dif=s2.size()-s1.size();

    //make number of digit same
    for(int i=0;i<dif;i++){
    	s1='0'+s1;
    }

    // digitDp("",0,true);

    digitDpFromTo("",0,true,true);
    
    cout<<endl;
    return 0;
}

// input:
// 4
// 44
// output:
// 4
// 5
// 6
// 7
// 8
// 9
// 10
// 11
// 12
// 13
// 14
// 15
// 16
// 17
// 18
// 19
// 20
// 21
// 22
// 23
// 24
// 25
// 26
// 27
// 28
// 29
// 30
// 31
// 32
// 33
// 34
// 35
// 36
// 37
// 38
// 39
// 40
// 41
// 42
// 43
// 44
