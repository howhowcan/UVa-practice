#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

typedef long long ll;

ll a[25][25];

ll calc(int i, int j);

ll max1(int i, int j);
ll max2(int i, int j);
ll max3(int i, int j);	

int n;

int main()
{
	int an1;

	while(cin >> n >> an1){
		memset(a, -1, sizeof(a));
		
		a[n][1] = an1;
		a[1][n] = calc(1, n);
		cout<< a[1][n] << endl;
	}
	return 0;
}


ll calc(int i, int j){
	if(a[i][j] != -1)  return a[i][j];
	
	if(i >= j){
		a[i][j] = max1(i, j) + max2(i, j);
		return a[i][j];
	}else{
		a[i][j] = max3(i, j);
		return a[i][j];
	}
	cout << "calc error" << endl;
	return -10;
}


ll max1(int i, int j){
	ll max = 0, tmp = 0;
	for(int k = i+1; k <= n; k++){
		tmp = calc(k, 1) + calc(k, j);
		if(tmp > max)  max = tmp;
	}
	return max;
}


ll max2(int i, int j){
	ll max = 0, tmp = 0;
	for(int k = 1; k < j; k++){
		tmp = calc(i, k) + calc(n, k);
		if(tmp > max)  max = tmp;
	}
	return max;
}



ll max3(int i, int j){
	ll max = 0, tmp = 0;
	for(int k = i; k < j; k++){
		tmp = calc(i, k) + calc(k+1, j);
		if(tmp > max)  max = tmp;
	}
	return max;	
}


















