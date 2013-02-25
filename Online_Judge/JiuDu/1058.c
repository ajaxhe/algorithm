#include <stdio.h>

int main()
{
    char buff[6];
    char temp;

    while (fgets(buff, 6, stdin))
    {
        temp = buff[0];
        buff[0] = buff[3];
        buff[3] = temp;
        temp = buff[1];
        buff[1] = buff[2];
        buff[2] = temp;
        buff[4] = '\0';
        printf("%s\n", buff);
    }
}
