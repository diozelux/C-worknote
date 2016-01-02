/* print a histogram fo the lengths of words - vertical version */
/* read inputs, count lengths of words smaller than 10, store its value */


#include <stdio.h>
  int c, i, n; /* read inputs, int variable */
  int lengths; /* lengths of words */
  int lnumber[11]; /* length is 0 to 10 */
  int max;     /* storing maximum frequency */
  
  main(){
	  int i;
	  for(i = 0;i<=10;++i)
		  lnumber[i] = 0;
	  lengths = 0;
	  
	  /* record the frequency to the array */
	  while((c = getchar()) != EOF){
		  if(c != ' ' && c != '\t' && c != '\n')
			  ++ lengths;
		  else if(lengths <= 10){
			  ++ lnumber[lengths];
			 lengths = 0;
			 }
	     }
		   
	  
	  /* find maximum frequency among the lnumber */
	  max = 0;
	   for(i = 0;i <= 10;++i){
		   if(max < lnumber[i])
			 max = lnumber[i];
	     }
		 
	  /* prints histogram in vertical way*/
	     while(max >= 1){
		   for(i = 0;i <= 9;++i){
		     if( max <= lnumber[i] )
			 printf("**");
		     else printf("  ");
		     }
			 printf("\n");
			 -- max;
		 }
		 for(n = 0;n <= 10;++n)
		   printf("--");
	     printf("\n");
		 for(n = 0;n <= 10;++n)
			 printf("%2d",n);
  }
