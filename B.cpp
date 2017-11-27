#include <bits/stdc++.h>

using namespace std;


int main(void){

	int n;
	cin >> n;
	if(n & 1) cout << 1 << "\n";
	else{
		int beauti=6, maxi=1, cont=1;
		while(beauti<=n){
			if((n % beauti)==0) maxi=beauti;
			cont++;
			beauti=beauti<<1;
			beauti=(1<<(cont+cont)) | beauti;
		}
		cout << maxi << "\n";
	} 


	return 0;
}