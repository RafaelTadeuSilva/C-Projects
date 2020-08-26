#include<stdio.h>
#include<string.h>

int main(){
    char str1[31], str2[31] = {' '};
    int j = 0;

    scanf("%s", str1);
    
    for (int i = strlen(str1)-1; i >= 0; i--)
    {
        str2[j++] = str1[i];
    }

    if(strcmp(str1, str2) == 0)
        printf("A palavra %s e um palindromo.", str1);
    else
        printf("A palavra %s nao e um palindromo.", str1);

    return 0;
}