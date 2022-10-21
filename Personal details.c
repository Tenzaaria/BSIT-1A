//program in C to create and store information in a text file
#include <stdio.h>
#include <stdlib.h>

int main()
{
		char datastr[500];
		FILE *fpdo;
		char doname[30]="personal.txt";
		printf("\n Create a file (personal.txt) and input text : \n ");
		printf("=============================================\n");
		fpdo=fopen(doname, "w");
	
	if(fpdo==NULL)
	{
		printf("\nError in creating a file!!!\n");
		exit(1);
	}
	printf("\nName :");
	 fgets(datastr,sizeof datastr,stdin);
	 fprintf(fpdo,"%s",datastr);
	printf("\nAge :");
	 fgets(datastr,sizeof datastr,stdin);
	 fprintf(fpdo,"%s",datastr);
	printf("\nBirtdate :");
	 fgets(datastr,sizeof datastr,stdin);
	 fprintf(fpdo,"%s",datastr);
	printf("\nContact Number :");
	 fgets(datastr,sizeof datastr,stdin);
	 fprintf(fpdo,"%s",datastr);
	 fclose(fpdo);
	 printf("\n %s file created successfully!!!\n", doname);
	
	return 0;
}
