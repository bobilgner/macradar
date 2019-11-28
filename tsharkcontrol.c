#include <stdio.h>
#include <stdlib.h>
#include <string.h>

   FILE *fp, *fp2;
   char buff[255];
   char  filename[255];
   int n=100;

int k;

int main()
{
    // Write a log for the issued command
	fp2 = fopen("harvest.log", "a");
    for(k=100;k<105;k++){
	   sprintf(buff, "cat lst8a.txt|./cpipe");
       system(buff);
       fprintf(fp2, "%s\n", buff);
	}
	fclose(fp2);

    return 0;
}
