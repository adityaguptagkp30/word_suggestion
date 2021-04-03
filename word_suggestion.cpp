#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

// function to find the minimum of three numbers
int min(int x, int y, int z) { return min(min(x, y), z); }

int editDistDP(string str1, string str2, int m, int n)
{
	// Create a table to store results of subproblems and space for storing dp table
	int dp[m + 1][n + 1];

	// Fill d[][] in bottom up manner
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			// If first string is empty, only option is to
			// insert all characters of second string
			if (i == 0)
				dp[i][j] = j; // Min. operations = j

			// If second string is empty, only option is to
			// remove all characters of second string
			else if (j == 0)
				dp[i][j] = i; // Min. operations = i

			// If last characters are same, ignore last char
			// and recur for remaining string
			else if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];

			// If the last character is different, consider
			// all possibilities and find the minimum
			else
			{
				dp[i][j]
					= 1
					+ min(dp[i][j - 1], // Insert
							dp[i - 1][j], // Remove
							dp[i - 1][j - 1]); // Replace
			}
		}
	}

	return dp[m][n];
}
int main(){
	ifstream myFile;
	
	myFile.open("dictionary.csv");
	int m=0;
	string last;
	
	map<string,int> mp;
	while(!myFile.eof()){
		string line;
		int count;
		m++;
		getline(myFile,line,',');
		
		if(m%2==0)
		count=stoi(line);
		else{
		last=line;
		last.erase(remove(last.begin(), last.end(), '"'), last.end());
		last.erase(remove(last.begin(), last.end(), '\n'), last.end());
		
	  }
		if(m%2==0){
			mp[last]=count;
		}
		
		}
		
		map<int,vector<string>> m1;
		string str1,str2;
		
		cout<<"Enter the word for which you want to check\n";
		cin>>str2;
	for(auto i:mp){
		str1=i.first;
		int x=editDistDP(str1, str2, str1.length(),
					str2.length());
					m1[x].push_back(i.first);
	}
	int c=0;
	for(auto i:m1){
		for(auto j:i.second){
			if(c==5)
			break;
			cout<<j<<" ";
			c++;
		}
	}
	}
