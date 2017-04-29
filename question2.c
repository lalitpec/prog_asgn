#include<stdio.h>
#include<stdlib.h>

//long long int n;
int n;

int getdigits(int n) {
	if (n==0) return 0;
	if (n<9) return 1;
	int num=0;
	int temp=0;
	int i;
	for (i=9; i>1;i--) {
		if (n%i==0) {
			temp = getdigits(n/i);
			if(temp ==-1) { return -1;}
			num = temp + 1;
			return num;
		}
	}
	return -1;
}


int main() {
int num;
//	scanf("%ll",&n);
	scanf("%d",&n);
	if (n<1) return -1;
	if (n<9) { printf("1"); return;}

	num = getdigits(n);
	printf("%d",num);
	return 0;
}
