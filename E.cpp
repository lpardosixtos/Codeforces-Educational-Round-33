#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;

int A[1000002];
long long int fact[2000000];
long long int sieve_size;
    bitset<1000002> bs;
    vector<int> primes;

void sieve(long long int up){
    sieve_size = up+1;
    bs.set();
    bs[0]=bs[1]=0;
    for(long long int i=2;i<=sieve_size;i++) if(bs[i]){
    	A[i]=i;
        for(long long int j=i*i;j<=sieve_size;j+=i){
        	bs[j]=0;
        	if(A[j]==0) A[j]=i;
        }
        primes.push_back((int) i);
    }
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           

long long int exp(long long int n, int p){
	if(p==0) return 1;
	if(p==1) return n;
	long long int x;
	if(p & 1){
		x=exp(n, (p-1)/2);
		x=(x*x)%MOD;
		x=(x*n)%MOD;
		return x;
	}
	x=exp(n, p/2);
	x=(x*x)%MOD;
	return x;
}

int main(void){

	A[1]=1;
	sieve(1000000);
	long long int q, x, y;
	long long int last=0;
	cin >> q;
	fact[0]=1;
	while(q--){
		cin >> x >> y;
		long long int ans=1;
		int s1=0;
		while(x!=1){
			s1++;
			int ant=A[x];
			int pow=0;
			while(A[x]==ant){
				x/=A[x];
				pow++;
			}
			if(fact[y+pow-1]==0){
				for(int i=last+1; i<=y+pow-1; i++){
					fact[i]=(i*fact[i-1])%MOD;
				}
				last=y+pow-1;
			}
			
			ans=(ans*fact[y+pow-1])%MOD;
			ans=(ans*exp(fact[pow], MOD-2))%MOD;


		}
		long long int invy=exp(fact[y-1], MOD-2);
		invy=exp(invy, s1);
		ans=(ans*invy)%MOD;
		ans=(ans*exp(2, y-1))%MOD;
		cout << ans << "\n";
	}

	return 0;
}