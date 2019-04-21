#include <iostream>

int a[105][105];

void CalcPascal(int m, int n);


using namespace std;

int main()
{
	

	for(int i = 1; i <= 100; ++i){
		for(int j = 0; j <= i; ++j){
			CalcPascal(i, j);
		}
	}

	int m, n;
	while(cin >> m >> n){
		if(!m && !n)  break;
		cout << m << " things taken " << n << " at a time is " << a[m][n] << " exactly.\n";
	}
	
	return 0;
}

void CalcPascal(int m, int n){
	if(n == 0 || n == m)  a[m][n] = 1;
	else  a[m][n] = a[m-1][n-1] + a[m-1][n];
}


