/*Write a program that converts upper case to lower or lower case to upper,
depending on the name it is invoked with, as found in argv[0].*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>

int main(int argc, char *argv)
{
    int c;
    //setlocale(LC_ALL, "C");

    while ((c = getchar()) != EOF)
    {
        putchar(toupper(c));
    }
}