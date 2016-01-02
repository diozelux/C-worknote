/* print a histogram fo the lengths of words - horizonal version */
/* read inputs, count lengths of words smaller than 10, store its value
print * which is same with the value */

#include <stdio.h>
  int c, i, n; /* read inputs, lengths of words 0 to 10, printing number of * */
  int lengths; /* lengths of words */
  int lnumber[11]; /* length is 0 to 10 */
  
  main(){
	  int i;
	  for(i = 0; i<=11;++i)
		  lnumber[i] = 0;
	  lengths = 0;
	  
	  /* record the frequency value to the array */
	  while((c = getchar()) != EOF){
		  if( c != ' ' && c != '\t' && c != '\n')
			  ++ lengths;
			  else if( lengths <= 10){
				  ++ lnumber[lengths];
			      lengths = 0;
			  }
	  }
	  
	  /* prints the value of the array */
	  printf("The histogram from inputs\n");
	     for(i = 0;i <= 10;++i){
	       printf("%2d|",i);
	      for(n = 1;n <= lnumber[i];++n)
		   putchar(219); 
	     printf("\n");
	     }
  }
