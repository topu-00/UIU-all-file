#include<stdio.h>
int main() 
{
	int i = 0, n;
	printf("Total students are \n");
	scanf("%d", &n);
	for (i = 1;i <= n;i++) 
    {
		float a, b, c, d, e, sum;
		printf("The marks are : \n");
		scanf("%f%f%f%f%f", &a, &b, &c, &d, &e);
		sum = (a + b + c + (d * 2 * 0.3) + (e * 0.4));
		if (sum >= 90 && sum <= 100) {
			printf("Student %d : A\n",i);
		}
		else if (sum >= 86 && sum <= 89) {
			printf("Student %d : A-\n",i);
		}
		else if (sum >= 82 && sum <= 85) {
			printf("Student %d : B+\n",i);
		}
		else if (sum >= 78 && sum <= 81) {
			printf("Student %d : B\n",i);
		}
		else if (sum >= 74 && sum <= 77) {
			printf("Student %d : B-\n",i);
		}
		else if (sum >= 70 && sum <= 73) {
			printf("Student %d : C+\n",i);
		}
		else if (sum >= 66 && sum <= 69) {
			printf("Student %d : C\n",i);
		}
		else if (sum >= 62 && sum <= 65) {
			printf("Student %d : C-\n",i);
		}
		else if (sum >= 58 && sum <= 61) {
			printf("Student %d : D+\n",i);
		}
		else if (sum >= 55 && sum <= 57) {
			printf("Student %d : D\n",i);
		}
		else {
			printf("Student %d : F\n",i);
		}
	}
	return 0;
}