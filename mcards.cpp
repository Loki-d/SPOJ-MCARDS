#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define vvi vector<vector<int> >
#define vi vector<int> 
#define endl '\n'
#define mp make_pair
#define pb push_back


const lli MOD = 1e9+7;

int LIS(vector<pair<int,int>> &v){
	vector<int> res;
	res.pb(v[0].first);
	for(int i=1;i<v.size();i++){
		auto it = lower_bound(res.begin(), res.end(),v[i].first);
		if(it==res.end())
			res.pb(v[i].first);
		else
			(*it)=v[i].first;
	}
	return (v.size() - res.size());
}

void change(vector<pair<int,int>> &v, vi &per){
	for(auto &p:v){
		//p.first = per[p.first-1];
		for(int i=0;i<per.size();i++){
			if(p.first==per[i]){
				p.first=i+1;
				break;
			}
		}

		p.first *=1000;
		p.first +=p.second;
	}
}


int main() {
    int c,n;
    scanf("%d%d",&c,&n);

	vector<pair<int,int>> v(c*n);
	for(int i=0;i<v.size();i++) scanf("%d%d",&v[i].first,&v[i].second);

	vi per(c);
	iota(per.begin(), per.end(),1);

	int ans=INT_MAX;

	do{
		vector<pair<int,int>> d(v.begin(), v.end());
		change(d,per);

		ans = min(ans,LIS(d));
	}while(next_permutation(per.begin(), per.end()));

	cout<<ans<<endl;
    return 0;
}
