/* test26
* input£º
* student. a am I
* I'm a Freshman and I like JOBDU!

* output£º
* I am a student.
* JOBDU! like I and Freshman a I'm
*/

#include <stdio.h>

#define MAXLINE 50000
#define MAXWORD 600

int main()
{
    char buff[MAXLINE];
    char *ptr, *word_end;
    char* word_tab[MAXWORD];
    int gap_tab[MAXWORD];
    int count, flag;

    while ( (ptr=fgets(buff, MAXLINE-1, stdin)) )
    {
        count = 0;
        word_end = NULL;
        flag = 0;

        while (*ptr != '\0')
        {
            if (*ptr != ' ' && *ptr != '\n')
            {
                if (flag != 1)
                {
                    // first char of a word
                    word_tab[count] = ptr;
                    gap_tab[count] = ptr - word_end;
                    count++;
                }
                flag = 1;
            }
            else
            {
                if (flag != 0)
                {
                    // end of the former word
                    *ptr = '\0';
                    word_end = ptr;
                }
                flag = 0;
            }
            ptr++;
        }
        word_tab[count] = '\0';

        while (--count > 0)
        {
            printf("%s", word_tab[count]);
            for (; gap_tab[count]; gap_tab[count]--)
                printf(" ");

        }
        printf("%s\n", word_tab[count]);
    }
}
