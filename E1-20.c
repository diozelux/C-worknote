/*E1-20 : Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter? */

#include <stdio.h>
#define MAXLINE 1000

int gline(char line[], int maxline);
void det(char detab[], char from[],int len);

/* detab function */
void det(char detab[], char from[],int len)
{
   int f_i, d_i, n, l;
   f_i = d_i = 0;

   while(f_i <= len){
        if(from[f_i] != '\t'){
          detab[d_i] = from[f_i];
          ++d_i;
        }
        else if(from[f_i] == '\t'){
           n = 8 - (d_i % 8);
          for(l = 0;l < n; ++l){
          detab[d_i+l] = ' ';
          }
        d_i = d_i + n;
        }
   ++f_i;
  }
}

/*getline function*/
int gline(char s[], int lim)
{
    int c, i;

    for(i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
       s[i] = c;
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

main(){
    int c, len; /*c gets input*/
    char detab[MAXLINE], line[MAXLINE];

    /* if there is a sentence */
        while((len = gline(line, MAXLINE)) > 0)
         if(len > 0){
         det(detab, line, len);
         }

    printf("Detabed result\n%s", detab);

   return 0;
}
