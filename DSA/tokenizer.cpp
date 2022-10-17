#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>

using namespace std;
#define int long long int

void tokenize(string s, string del = " ")
{
    // int start, end = -1*del.size();
    // do {
    //     start = end + del.size();
    //     end = s.find(del, start);
    //     cout << s.substr(start, end - start) << endl;
    // } while (end != -1);

    int start=0, end=-1*del.size();
    

    while(end!=-1){	
    	start=end+1*del.size();
    	end=s.find(del, start);
    	cout << s.substr(start, end - start) << endl;
    	
    }
}
int32_t main()
{
    // Takes C++ string with any separator
    string a ,w;
    getline(cin,a);
    getline(cin,w);
    tokenize(a, w);
    cout << endl;
 
    return 0;
}