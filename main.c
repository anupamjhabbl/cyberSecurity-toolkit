#include <stdio.h>
#include "cybertool.h"

int main() {
    int option;
    char filename[256];
    char password[50];
    int length;
    printf("CyberSecurity Toolkit\n");
    printf("Select an option:\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Generate a password\n");
    printf("4. Save a password\n");
    printf("5. Get a password\n");
    printf("6. Register a file\n");
    printf("7. Check file integrity\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    switch(option) {
        case 1:
        {
            printf("Enter filename to encrypt: ");
            scanf("%255s", filename);
            int encResult = encrypt(filename);
            if (encResult == 0) {
                printf("File encrypted successfully.\n");
            } else {
                printf("Encryption failed.\n");
            }
            break;
        }
        case 2:
        {
            printf("Enter filename to decrypt: ");
            scanf("%255s", filename);
            int decResult = decrypt(filename);
            if (decResult == 0) {
                printf("File decrypted successfully.\n");
            } else {
                printf("Decryption failed.\n");
            }
            break;
        }
        case 3:
        {
            printf("Enter password length: ");
            scanf("%d", &length);
            generatePassword(length, password);
            printf("Generated password: %s\n", password);
            break;
        }
        case 4:
        {
            printf("Enter filename to save password: ");
            scanf("%255s", filename);
            printf("Enter password to save: ");
            scanf("%49s", password);
            int saveResult = savePassword(filename, password);
            if (saveResult == 0) {
                printf("Password saved successfully.\n");
            } else {
                printf("Failed to save password.\n");
            }
            break;
        }
        case 5:
        {
            printf("Enter filename to get password: ");
            scanf("%255s", filename);
            int getResult = getPassword(filename);
            if (getResult == 0) {
                printf("Password retrieved successfully.\n");
            } else {
                printf("Failed to retrieve password.\n");
            }
            break;
        }
        case 6:
        {
            printf("Enter filename to register: ");
            scanf("%255s", filename);
            int regResult = registerYourFile(filename);
            if (regResult == 0) {
                printf("File registered successfully.\n");
            } else {
                printf("File registration failed.\n");
            }
            break;
        }
        case 7:
        {
            printf("Enter filename to check integrity: ");
            scanf("%255s", filename);
            int intResult = checkIntegrity(filename);
            if (intResult == 0) {
                printf("File integrity checked.\n");
            } else {
                printf("File integrity check failed.\n");
            }
            break;
        }
        default:
        {
            printf("Invalid option.\n");
        }
    }
    return 0;
}