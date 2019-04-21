#include <iostream>
#define MAX_R 1005
#define MAX_C 3000

int a[MAX_R][MAX_C];
void calc_fac(int index);

using namespace std;

int main()
{
	

	for(int i = 0; i < MAX_R; ++i){
		for(int j = 0; j < MAX_C; ++j)
			a[i][j] = 0;			
	}

	a[0][0] = a[1][0] = 1;

	for(int i = 2; i < MAX_R; ++i)
		calc_fac(i);
	

	int n;
	while(cin >> n){
		int sum = 0;
		for(int i = 0; i < MAX_C; ++i)
			sum += a[n][i];
		cout << sum << endl;
	}


	return 0;
}



void calc_fac(int index){
	int tmp, carry = 0;
	for(int i = 0; i < MAX_C; ++i){
		tmp = a[index-1][i] * index + carry;
		if(tmp >= 10){
			a[index][i] = tmp % 10;
			carry = tmp / 10;
		}else{
			a[index][i] = tmp;
			carry = 0;
		}
	}
}
