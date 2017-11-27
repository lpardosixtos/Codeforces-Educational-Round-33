#include <bits/stdc++.h>

using namespace std;

int main(void){
	int n, d;
	cin >> n >> d;
	vector <int> difmins, sums;
	int difmin=1000000000, sum=0, ind=1;
	int aux;
	for(int i=0; i<n; i++){
		cin >> aux;
		sum+=aux;
		if(aux==0){
			difmin=min(difmin, d-sum);
			difmins.push_back(difmin);
			sums.push_back(sum);
			difmin=1000000000;
		}
		else{
			if(sum>d) ind=0;
			difmin=min(difmin, d-sum);
		}
	}
	if(aux!=0){
		difmins.push_back(difmin);
	}
	else difmins.push_back(1000000000);

	if(ind==0) cout << -1 << "\n";
	else{
		stack <int> difInt;
		int s=difmins.size();
		difInt.push(difmins[s-1]);
		for(int i=s-2; i>0; i--){
			difmin=min(difmins[i], difmin);
			difInt.push(difmin);
		}
		s=sums.size();
		int acum=0, ans=0;
		for(int i=0; i<s; i++){
			if(sums[i]+acum<0){
				ans++;
				aux=difInt.top();
				difInt.pop();
				aux-=acum;
				if(aux<0){
					cout << -1 << "\n";
					return 0;
				}
				else{
					if(0-sums[i]-acum<=aux){
						acum+=min(d-sums[i]-acum, aux);
					}
					else{
						cout << -1 << "\n";
						return 0;
					}
				}
				
			}
			else difInt.pop();
		}
		cout << ans << "\n";
	}
	

	return 0;
}