#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string btm, top;

	while(cin >> btm >> top){

		int b_len = btm.length(), t_len = top.length();
		int min_len = b_len + t_len;

		for(int i = 0; i < t_len - 1; i++)	btm = "0" + btm + "0";
		int i = 0, j = 0;		
		for(i = 0; i < t_len + b_len - 1; i++){
			int a = 0, b = 0;
			for(j = 0; j < t_len; j++){
				if(btm[i+j] == '2' && top[j] == '2')	break;
			}

			if(j == t_len){
				if(i >= t_len - 1)	a = t_len - 1;
				else	a = i;
				if(i >= b_len - 1)	b = i + t_len - 1;
				else	b = t_len + b_len - 2;

				if(b - a + 1 < min_len)	min_len = b - a + 1;
			}
		}
		printf("%d\n", min_len);

//		cout << btm << " len = " << b_len << endl << top << " len = "  << t_len << endl;
	}
	return 0;
}