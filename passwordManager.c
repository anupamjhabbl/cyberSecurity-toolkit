#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function for saving the key paired with that file
int savePassword(char* filename, char* password){

    // making the command to save the filename and key pair
    char command[600] = {'e','c','h','o',' '};

    int mainIndex = 5;
    int filenameIndex = 0;
    int passwordIndex = 0;

    while(filenameIndex<strlen(filename)){
        command[mainIndex++] = filename[filenameIndex++];
    }

    command[mainIndex++] = '#';
    command[mainIndex++] = '*';
    command[mainIndex++] = '#';

    while(passwordIndex<strlen(password)){
        command[mainIndex++] = password[passwordIndex++];
    }

    command[mainIndex++] = ' ';
    command[mainIndex++] = '>';
    command[mainIndex++] = ' ';

    char* outputfilename = "./passwordStoreTemp.txt";
    int outputfileIndex = 0;
    while (outputfileIndex<strlen(outputfilename)){
        command[mainIndex++] = outputfilename[outputfileIndex++];
    }

    // checking files exist or not because cat only works on existed file
    FILE* fp = fopen("./passwordStore.txt","r");
    if (fp==NULL){
        fopen("./passwordStore.txt","w");
    }
    else{
        fclose(fp);
    }

    // running the commands to store the password
    int success1 = system(command);
    int success2 = system("cat passwordStore.txt >> passwordStoreTemp.txt");
    int success3 = system("cat passwordStoreTemp.txt > passwordStore.txt");
    int success4 = system("echo > passwordStoreTemp.txt");

    int m = success1 || success2 || success3 ;
    if (m==0){
        printf("Successfully stored your password\n");
        return 0;
    }
    else{
        printf("Some error occured please try again\n");
        return 1;
    }
}

// function to get the password of given filename
int getPassword(char* filename){
    char value[500];

    // open the file passwordStore.txt
    FILE* fp = fopen(filename,"r");
    if (fp==NULL){
        printf("No password stored here\n");
        return 1;
    }

    while(fgets(value, 500, fp)){              // redaing the file line by line
        char fileinline[500] = {0};
        int mainIndex = 0;
        while(mainIndex<strlen(value)){
            if (value[mainIndex]=='#'){
                if (mainIndex+2<strlen(value) && value[mainIndex+1]=='*' && value[mainIndex+2]=='#'){
                    break;
                }
            }
            fileinline[mainIndex] = value[mainIndex];
            mainIndex++;
        }

        if (strcmp(fileinline, filename)==0){        // filegiven found
            char password[100] = {0};
            mainIndex += 3;
            int passwordIndex = 0;

            while(mainIndex<strlen(value)){
                password[passwordIndex++] = value[mainIndex++];
            }
            printf("%s",password);
            return 0;
        }
    }
    printf("There is no password stored for this file\n");
    return 1;
}


