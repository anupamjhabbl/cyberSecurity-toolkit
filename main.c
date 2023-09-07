#include <stdio.h>
#include "cybertool.h"

int main(){
    // int k = checkIntegrity("/home/anupamjhabbl/Desktop/projects/cyberSecurityTollkit/integrityCheck.c");
    // printf("%d",k);

    int k = decrypt("/home/anupamjhabbl/Desktop/projects/cyberSecurityTollkit/README.encmd");
    printf("%d",k);

    return 0;
}