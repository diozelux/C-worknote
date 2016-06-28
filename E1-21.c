/*E1-21. Write a program entab that 
replaces strings of blank by the minimum number of tabs and blanks to achieve the same spacing.
Use the same tab stops as for detab. 
When either a tab or a single blank would suffice to reach a tab stop, which should be given preference? */

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
     int ori_i, edi_i, bl_start, bl_end; //array address counter _i, blank address counter bl_
	 int n, i; // for counter
	 int num_t, num_s;//number of tab, number of space
	 ori_i, edi_i, bl_start, bl_end = 0; //variable initialize
	 
     while(in[ori_i] != '\0')
	 {
		while(in[ori_i]!=' ' && in[ori_i]!='\0')
		{
			  out[edi_i] = in[ori_i];
			  ++edi_i;
			  ++ori_i;
		}
	 
		if(in[ori_i]== ' ' && bl_start == '0')
			bl_start=ori_i;
	 
		while(in[ori_i]==' ')
			++ori_i;
	 
		bl_end = ori_i;		//end address of the last blank.
		num_t = (bl_end/8) - (bl_start)/8;		//number of tab
		num_s = bl_end % 8;		//number of space
	 	 
		for(n=0;n<=num_t;++n)
		{
			out[edi_i]='\t';
			++edi_i;
		}	 
		for(n=0;n<num_s;++n)
		{
			out[edi_i]=' ';
			++edi_i;
		}
		bl_start = 0; //initialize bl_start to reuse in 'while'
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
