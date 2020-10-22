#include <stdio.h>
#include <stdlib.h>

int dado(){
    srand((unsigned)time(NULL));
    return 1 + rand() % 6;
}

int main(void)
{
    printf("Numero aletorio gerado entre 1 e 6: %d", dado());
}
