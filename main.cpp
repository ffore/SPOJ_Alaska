#include <iostream>
#include <cstdlib>

using namespace std;
//================================================================
int answers[10000];
int count = 0;
//================================================================
int compare(const void * a, const void * b){
	return ( *(int*)a - *(int*)b );
}
//================================================================
void check(int * a, int size, int c){
	if(a[size-1] >= 1322){
		for(int i = 0; i < size-1; i++){
			if(a[i+1]-a[i] > 200){
				//impossible
				answers[c] = 0;
				return;
			}
		}
		//possible
		answers[c] = 1;
		return;
	}
	else{
		//impossible
		answers[c] = 0;
		return;
	}
}
//================================================================
int main(){


	bool choice = true;
	while(choice){
		int n;
		scanf("%d", &n);

		if(n == 0){
			break;
		}

		int * arr = new int[n];

		for(int i = 0; i < n; i++){
			scanf("%d", &arr[i]);
		}

		qsort(arr, n, sizeof(int), compare);

		check(arr, n, count);

		delete arr;
		count++;
	}

	for(int i = 0; i < count; i++){
		if(answers[i] == 0){
			cout << "IMPOSSIBLE" << endl;
		}
		else{
			cout << "POSSIBLE" << endl;
		}
	}

	return 0;
}