#include <bits/stdc++.h>

using namespace std;

int main(void){

	int n, ind=0;
	cin >> n;
	vector<int> spectator;
	spectator.push_back(3);
	for(int i=0; i<n; i++){
		int aux;
		cin >> aux;
		if(aux!=spectator[i]){
			spectator.push_back(6-spectator[i]-aux);
		}
		else{
			ind=1;
		}
	}
	if(ind & 1) cout << "NO\n";
	else cout << "YES\n";

	return 0;
}