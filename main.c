#include <stdio.h>
#include "cybertool.h"

int main(){
    // int k = checkIntegrity("/home/anupamjhabbl/Desktop/projects/cyberSecurityTollkit/integrityCheck.c");
    // printf("%d",k);

    int k = getPassword("/home/anupamjhabbl/Desktop/projects/cyberSecurityTollkit/passwordStore.txt");
    printf("%d",k);

    return 0;
}