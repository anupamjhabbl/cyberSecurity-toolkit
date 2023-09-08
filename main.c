#include <stdio.h>
#include "cybertool.h"

int main(){
    // int k = checkIntegrity("/home/anupamjhabbl/Desktop/projects/cyberSecurityTollkit/integrityCheck.c");
    // printf("%d",k);

    // char password[50];
    // generatePassword(10,password);
    // printf("%s",password);

    // int success = savePassword("/home/anupamjhabbl/Desktop/projects/cyberSecurityTollkit/cybertool.h", "65rqRQ#@*@");
    // printf("%d\n",success);

    // int success = encrypt("/home/anupamjhabbl/Desktop/projects/cyberSecurityTollkit/cybertool.h");
    // printf("%d",success);

    // int success = getPassword("/home/anupamjhabbl/Desktop/projects/cyberSecurityTollkit/cybertool.h");
    // printf("%d",success);

    // int success = decrypt("/home/anupamjhabbl/Desktop/projects/cyberSecurityTollkit/cybertool.ench");
    // printf("%d",success);

    // int success = registerYourFile("/home/anupamjhabbl/Desktop/projects/cyberSecurityTollkit/encryptionDecryption.c");
    // printf("%d",success);

    int success = checkIntegrity("/home/anupamjhabbl/Desktop/projects/cyberSecurityTollkit/encryptionDecryption.c");
    printf("%d",success);

    return 0;
}