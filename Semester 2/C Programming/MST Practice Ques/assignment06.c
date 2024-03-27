#include <stdio.h>

// Print counting 1 to 10 using recursive function.

void count(int n){
	if (n > 10)
	{
		return;
	}
	printf("%d\n", n);
	count(n + 1);
}

int main(){
	int n = 1;
	count(1);

	return 0;
}