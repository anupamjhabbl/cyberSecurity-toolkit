#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// function to encrypt the file
int encrypt(const char* filename){

    // checking the file given exists or not
    FILE* fp = fopen(filename,"r");   
    if (fp==NULL){
        printf("%s %s %s","The file",filename,"does not exist.\n");
        return 1;
    }
    fclose(fp);  

    // making the command to encrypt the file
    char command[1000] = {0};
    char* precommand = "openssl enc -aes-128-cbc -md sha512 -pbkdf2 -iter 10000 -salt -in ";
    char* postcommand = " -out ";
    char* extension = ".enc";

    int mainIndex, precommandIndex, postcommandIndex, filenameIndex, extensionIndex;
    mainIndex = precommandIndex = postcommandIndex = filenameIndex = extensionIndex= 0;

    while(precommandIndex<strlen(precommand)){
        command[mainIndex++] = precommand[precommandIndex++];
    }

    while(filenameIndex<strlen(filename)){
        command[mainIndex++] = filename[filenameIndex++];
    }

    while(postcommandIndex<strlen(postcommand)){
        command[mainIndex++] = postcommand[postcommandIndex++];
    }

    filenameIndex = 0;
    while(filenameIndex<strlen(filename) && filename[filenameIndex] != '.'){
        command[mainIndex++] = filename[filenameIndex++];
    }

    while (extensionIndex<strlen(extension)){
        command[mainIndex++] =extension[extensionIndex++];
    }

    filenameIndex++;
    while(filenameIndex<strlen(filename)){
        command[mainIndex++] = filename[filenameIndex++];
    }

    // running the command for encrypting the file and storing encrypted file
    int successStatus = system(command);
    if (successStatus==0){
        printf("Successfully stored an encrypted version of your file\n");
        return 0;
    }
    else{
        printf("Some error occured\n");
        return 1;
    }
}

// function to decrypt the file
int decrypt(char* filename){

    // checking the file given exists or not
    FILE* fp = fopen(filename,"r");
    if (fp==NULL){
        printf("%s %s %s","The file",filename,"does not exist.\n");
        return 1;
    }
    fclose(fp);

    // making the command for decrypting the file
    char command[1000] = {0};
    char* precommand = "openssl enc -aes-128-cbc -md sha512 -pbkdf2 -in ";
    char* postcommand = " -out ";

    int mainIndex, precommandIndex, postcommandIndex, filenameIndex, extensionIndex;
    mainIndex = precommandIndex = postcommandIndex = filenameIndex = extensionIndex= 0;

    while(precommandIndex<strlen(precommand)){
        command[mainIndex++] = precommand[precommandIndex++];
    }

    while(filenameIndex<strlen(filename)){
        command[mainIndex++] = filename[filenameIndex++];
    }

    while(postcommandIndex<strlen(postcommand)){
        command[mainIndex++] = postcommand[postcommandIndex++];
    }

    filenameIndex = 0;
    while(filenameIndex<strlen(filename) && filename[filenameIndex] != '.'){
        command[mainIndex++] = filename[filenameIndex++];
    }
    filenameIndex += 4;

    command[mainIndex++] = '.';
    while(filenameIndex<strlen(filename)){
        command[mainIndex++] = filename[filenameIndex++];
    }
    command[mainIndex++] = ' ';
    command[mainIndex++] = '-';
    command[mainIndex] = 'd';
    
    // running the command and decrypting the file given and storing the decrypted file
    int successStatus = system(command);
    if (successStatus==0){
        printf("Successfully stored an decrypted version of your file\n");
        return 0;
    }
    else{
        printf("Some error occured\n");
        return 1;
    }
}
