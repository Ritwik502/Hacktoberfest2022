#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    int x=str.length();
		    int y=x;
		    int tab[x+1][y+1];
            for(int i=0;i<=x;i++){
                tab[i][0]=0;
            }
            for(int i=0;i<=y;i++){
                tab[0][i]=0;
            }
            int mx=0;
            for(int i=1;i<=x;i++){
                for(int j=1;j<=y;j++){
                    if(str[i-1]==str[j-1] && i!=j){
                        tab[i][j]=1+tab[i-1][j-1];
                        mx=max(tab[i][j],mx);
                    }
                    else{
                        tab[i][j]=max(tab[i][j-1],tab[i-1][j]);
                    }
                }
            }
            return mx;
		}
};
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
