#include <iostream>
#include <string>

using namespace std;

int main()
{
	int m, n;
	string dict_name[1005];
	int dict_salary[1005];
	cin >> m >> n;

	for(int i = 0; i < m; ++i)
		cin >> dict_name[i] >> dict_salary[i];
	
	for(int i = 0; i < n; ++i){
		int sum = 0;
		string s;
		while(cin >> s && s != "."){
			for(int j = 0; j < m; ++j)
				if(dict_name[j] == s)  sum += dict_salary[j];
		}
		cout << sum << endl;
	}
	
	
	return 0;
}