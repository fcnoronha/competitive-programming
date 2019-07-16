ll cap[112345], accum[112345];

int main(){
	ll t; scanf("%lld", &t);
	while(t--){
		ll n, m;
		cin >> n >> m;

		ms(accum, 0);
		for(ll i = 0; i < n; i++){
			cin >> cap[i];
			//dbg(cap[i]);
		}



		vii op;

		fr(i, m){
			int a, b;
			cin >> a >> b;
			a--;
			op.pb({a, b});
		}

		sort(all(op));

		int j = 0;

		fr(i, n){
			//dbg(cap[i]);
			while(j < m && op[j].first == i){
				accum[i] += op[j++].snd;
			}
			if(accum[i] > cap[i]){
				accum[i+1] += accum[i] - cap[i];
			}
			else cap[i] = accum[i];

		}


		cout << accum[n] << "\n";
		fr(i, n) cout << cap[i] << " \n"[i == n-1];
	}
}
