#include <stdio.h>
#include <string.h>

#define MAX_LEN 10

char formula[MAX_LEN];


void process(){
	int var = 0;
	float ans = 0;
	char reply[1];
	float storedval[100];

	//saving input in storedval
	for (int i = 2; i < strlen(formula); i++)
	{
		float val[1];
		char c[2];
		memcpy(c, &formula[i], 1);
		c[1] = '\0';
		// printf("Variable number %d is: %s\n", i-1 , c);
		printf("Enter your value for %s: ", c);
		scanf("%f", val);
		storedval[i-2] = val[0];
		// printf("You entered %f for %s\n", storedval[i-2], c);
		var++;

	}
	// printf("%d\n", var);

	//calculate the result we want
	for (int i = 0; i < var; i++){
		if (i==0) {
			ans = storedval[i];
		} else {
			ans = ans * storedval[i];
		}
	}

	char c[2];
	memcpy(c, &formula[0], 1);
	c[1] = '\0';
	printf("The result for %s is %f\n", c, ans);

	while (reply[0] != 'y' && reply[0] != 'n') {
		printf("Do you want to use the same formula again? (y/n) ");
		scanf("%s", reply);
	}

	if (reply[0] == 'y') {
		calc();
	} else {
		return;
	}

}


int main(int argc, char const *argv[])
{

	printf("Enter a formula: ");
	scanf("%s", formula);

	process();

	return 0;
	
}