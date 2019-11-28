#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	/* The premise behind this filter is that the macs have been sorted and that the
	mac would occur several in that file if the mac is a static. i.e. static means that
	the mac is part of zone being scanned.*/

   FILE *fp, *fp2;
   char buff[255];
   char prev[255];
   char  filename[255];


   int k;
   int c,n;
   int ret;
   int occ;

   n = 001;
   sprintf(filename, "static_mac.txt");

   fp = fopen("background.txt", "r");
   fp2 = fopen(filename, "w+");
   if (fp2 == 0) {
	   fprintf(stderr, "Difficulty opening static_mac.txt");
	   exit(1);
   }
   // Read in the very first mac
   fscanf(fp, "%s", prev);
   occ = 1;
   for(k=0;k<90000;k++) {
   	c=fscanf(fp, "%s", buff);
	if (c == EOF){
           fprintf(fp2, "%s  %d\n", prev, occ);
	   break;
        }
	// compare the read string to the previous
	ret = strcmp(prev, buff);
	if (ret == 0) {
		//add one on to the occurence counter
		occ++;
	}
	else
	{
                printf("%d : %s\n", occ, prev);
		fprintf(fp2, "%s  %d\n", prev, occ);
		occ = 1;   //reset occurence buffer
	}

	strcpy(prev, buff);
   }

   
 
   printf("Closing files and ending\n"
);
   fclose(fp2);
   fclose(fp);

}
