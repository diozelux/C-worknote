/*E1-21. Write a program entab that replaces strings of blacnk by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank would suffice to reach a tab stop, which should be given preference? */

#include <stdio.h>
#define MAXLINE 1000

void entab(char in[], char out[], int lim);
int gline(char s[], int lim);

/* entab function */
/* 1. record address from first blank
 * 2. if another blank is added
 * 3. record total amount of blanks
 * 4. and replace blanks to tab(s) to initial address
 */
void entab(char in[MAXLINE], char out[MAXLINE], int lim)
{
     int flag, o_i, s_i, blnum, bl_start, n, n_b, i, blend;
  
     for(s_i = 0; s_i <= lim; ++s_i){
        if(in[s_i] != ' '){
          out[o_i] = in[s_i];
          blnum = 0;
        }
        n = 0;
       while(in[s_i + n] == ' '){
                  ++ blnum;
                  ++ n;
        }
        blend = s_i + n -1;

        n_b = blend/8; // number of tab
        n = blend % 8; // number of blank
        for(i = 0; i < n_b; ++i){
          out[o_i] = '\t';
          ++o_i;
        }
        for(i = 0; i < n; ++i){
           out[o_i] = ' ';
           ++o_i;
        }
        ++o_i;       
        s_i = blend + 1;
      }
}

/*getline function*/
int gline(char s[MAXLINE], int lim)
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


/* main function */
int main(){
    char s[MAXLINE], in[MAXLINE], out[MAXLINE];
    int len, lim;

    while((len = gline(s, lim)) > 0)
         entab(in, out, len);
    if(len > 0)
      printf("%s\n", out);
}
