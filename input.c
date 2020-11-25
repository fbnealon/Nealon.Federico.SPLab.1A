#include "input.h"

int getInt(char message[], char errorMessage[], int min, int max)
{
    int x;
    printf("%s", message);
    scanf("%d", &x);
    while(x<min || x>max)
    {
        printf("%s", errorMessage);
        fflush(stdin);
        scanf("%d", &x);
    }
    return x;
}



float getFloat(char message[], char errorMessage[], float min, float max)
{
    float x;
    printf("%s", message);
    scanf("%f", &x);
    while(x<min || x>max)
    {
        printf("%s", errorMessage);
        fflush(stdin);
        scanf("%f", &x);
    }
    return x;
}

char getLetter(char message[], char errorMessage[])
{
    char letter;
    printf("%s", message);
    fflush(stdin);
    scanf("%c", &letter);
    while((letter<'a' || letter>'z') && (letter<'A' || letter>'Z'))
    {
        printf("%s", errorMessage);
        fflush(stdin);
        scanf("%c", &letter);
    }
    return letter;
}

void getStrings(char message[], char errorMessage[], int len, char str[])
{
    char auxStr[128];
    printf("%s", message);
    fflush(stdin);
    gets(auxStr);

    while(strlen(auxStr) >= len-1)
    {
        printf("%s", errorMessage);
        fflush(stdin);
        gets(auxStr);
    }
    strcpy(str, auxStr);
    //strupr(str);
    strlwr(str);
    str[0]= toupper(str[0]);

    for(int i=0; i<strlen(str); i++)
    {
        if(str[i]== ' ')
        {
            str[i+1] = toupper(str[i+1]);
        }
    }
}

void firstUpper(char str[])
{
    int i=0;
    while(str[i]!='\0')
    {
        str[0]= toupper(str[0]);
        if(str[i]==' ')
        {
            str[i+1]=toupper(str[i+1]);
        }
        i++;
    }

}

void getNumberString(char message[], char errorMessage[], char nums[])
{
    char auxStr[100];
    int i=0;
    printf("%s", message);
    fflush(stdin);
    gets(auxStr);

    while(auxStr[i]!='\0')
    {
        if(auxStr[i]<'0'||auxStr[i]>'9')
        {
            printf("%s", errorMessage);
            fflush(stdin);
            gets(auxStr);
            i=0;
        }
        i++;
    }
    strcpy(nums, auxStr);
}

void getAlphaString(char message[], char errorMessage[], char str[])
{
    char auxStr[100];
    int i=0;
    printf("%s", message);
    fflush(stdin);
    gets(auxStr);

    while(auxStr[i]!= '\0')
    {
        if((auxStr[i]!=' ') && (auxStr[i]<'a'||auxStr[i]>'z') && (auxStr[i]<'A'||auxStr[i]>'Z'))
        {
            printf("%s", errorMessage);
            fflush(stdin);
            gets(auxStr);
            i=0;
        }
        i++;
    }
    firstUpper(auxStr);
    strcpy(str, auxStr);
}

