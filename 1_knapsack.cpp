#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,W;
	cin>>n>>W;
	int weight[n];
	int value[n];
	for(int i=0;i<n;i++)
	cin>>weight[i];
	for(int i=0;i<n;i++)
	cin>>value[i];
	int dp[n+1][W+1];
	for(int i=0;i<=n;i++){
	    for(int j=0;j<=W;j++){
	        if(i==0||j==0)
	        dp[i][j]=0;
	        else if(j<weight[i-1])
	        dp[i][j]=dp[i-1][j];
	        else{
	            dp[i][j]=max(dp[i-1][j],value[i-1]+dp[i-1][j-weight[i-1]]);
	        }
	    }
	}
	cout<<dp[n][W];

}
