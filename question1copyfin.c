#include<stdio.h>
#include<stdlib.h>

int * fillarrnum;
int * fillarrdenom;
int n;

void printfracnew(int n, int fillsum) {
int tempnum = 0;
int tempdenom = 0;
//edge cases
	if(n==0 || n==1) { return;}

	int i,j;
	for (i=n; i>1; i--) { // print for all from n to 1
		for(j = 1; j<=i;j++) { //fill all num and denom slots
//			printf("i j %d %d\n",i,j);
			tempnum =i-j; 
			tempdenom = i;
//			printf(" fillsum number = %d\n", (fillsum*(i-j))/j);
			fillarrnum[(fillsum*(i-j))/i] = tempnum;
			fillarrdenom[(fillsum*(i-j))/i] = tempdenom;
		}
	}
}

void outfracnew(int n, int fillsum) {
	int i;
	for (i = 1; i < fillsum ; i++) {
		if (fillarrnum[i]!=0 && fillarrdenom[i]!=0){
			printf("%d/%d, ",fillarrnum[i],fillarrdenom[i]);
		}
	}
}
void printdump (int n, int fillsum) {
	int i;
	for (i = 1; i < fillsum ; i++) {
			printf("%d/%d, ",fillarrnum[i],fillarrdenom[i]);
	}
}

int main() {
	scanf("%d",&n);
	if (n<1) return -1;

//	int fillsum = (n*(n-1))/2 + 2;
	int fillsum = n*n*n;
	fillarrnum = calloc(fillsum, sizeof(int));
	fillarrdenom = calloc(fillsum, sizeof(int));


	printfracnew(n,fillsum);

	printf("F%d = ",n);
	printf("0/1, ");
	outfracnew(n,fillsum);
	printf("1/1");

//	printf("\n");
//	printdump(n, fillsum);

	return 0;
}
