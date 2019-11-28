#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	/* The static macs are read from static_mac.txt and an array of static macs
	is built.
	Fresh  mac data is then read in from rawmac.txt  and compared to above mac array.
	Only new macs are written to newmac.txt*/

   FILE *fp, *fp2;
   char buff[255];
   char puff[6000];
   char puff2[20][100];
   char socc[10];
   char  filename[255];


   int k,m;
   int c,n;
   int ret,result;
   int occ,istatic;
   int imatch;

   n = 001;

   fp = fopen("static_mac.txt", "r");
   istatic = 0;  // count number of statics
   // Read in the very first mac
   // and form array of static mac addresses
   for (k = 0; k < 900000; k++) {
	   c = fscanf(fp, "%s", buff);
           c = fscanf(fp, "%s", socc);
           occ=atoi(socc);
	   printf("Staticread %d %s %d\n", k, buff,occ);
	   if (c == EOF)break;
           if(occ > 10){
              strcpy(puff2[istatic], buff);
              istatic++;
             }
   }
   fclose(fp);
   printf("Print out array of istatic %d\n",istatic);
   // print out test sequence of static macs
   for (k = 0; k < istatic; k++) {
	   printf("Static %d %s\n", k, puff2[k]);
   }
   // Open mac file and read in string values
   // compare each mac to the static list in the array 

   printf("Read new macs\n");
   fp = fopen("rawmac.txt", "r");
   fp2 = fopen("newmac.txt", "w+");
   for (k = 0; k < 90000; k++) {
	   c = fscanf(fp, "%s", buff);
	   if (c == EOF)break;
	   //printf("Mac read %d %s\n", k, buff);
	   //fflush(stdout);
	   if (strlen(buff) != 0) {
		   // cycle check all of the static macs
		   imatch = 0;
		   for (m = 0; m < istatic; m++) {
			   result = strcmp(buff, puff2[m]);
			   if (result == 0) {
				   imatch++;
				   break;
			   }  // end if
		   } //end m  loop
		   if (imatch == 0) {
			   // write freshly detected non-static mac to file
			   fprintf(fp2, "%s\n", buff);
		   }

	   } // end if 
   } // end k loop

   fclose(fp2);
   fclose(fp);

   
   

}
