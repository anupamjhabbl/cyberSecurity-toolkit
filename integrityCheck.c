#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// function to register your file
int registerYourFile(const char *filename)
{
    // checking the file given exists or not
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("This file doesnot exist");
        return 1;
    }
    fclose(fp);

    // making the command to genrate hash of the file given
    char command[500] = {0};
    char *precommand = "openssl dgst -sha1 ";
    char *postcommand = " > filenameToHashTemp.txt";

    int precommandIndex = 0;
    int maincommandIndex = 0;
    while (precommandIndex < strlen(precommand))
    {
        command[maincommandIndex++] = precommand[precommandIndex++];
    }

    int filenameIndex = 0;
    while (filenameIndex < strlen(filename))
    {
        command[maincommandIndex++] = filename[filenameIndex++];
    }

    int postcommandIndex = 0;
    while (postcommandIndex < strlen(postcommand))
    {
        command[maincommandIndex++] = postcommand[postcommandIndex++];
    }

    // making confirm that filenameToHash.txt exists
    FILE* fp2 = fopen("./filenameToHash.txt","a");
    fclose(fp2);

    // Save the filename and their hash by running command omething
    int status1 = system(command);
    int status2 = system("cat filenameToHash.txt >> filenameToHashTemp.txt");
    int status3 = system("cat filenameToHashTemp.txt > filenameToHash.txt");
    if ((status1 || status2 || status3) == 0)
    {
        printf("Successfully registered your file\n");
        return 0;
    }
    else
    {
        printf("Some error ocuured. Try again please");
        return 1;
    }
    
}

// function to check the integrity
int checkIntegrity(const char *filename)
{
    // checking the file given exists or not
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("This file doesnot exist");
        return 1;
    }
    fclose(fp);

    // making the command to generate the hash of the file given
    char command[500];
    char *precommand = "openssl dgst -sha1 ";
    char *postcommand = " > tempHash.txt";

    int precommandIndex = 0;
    int maincommandIndex = 0;
    while (precommandIndex < strlen(precommand))
    {
        command[maincommandIndex++] = precommand[precommandIndex++];
    }

    int filenameIndex = 0;
    while (filenameIndex < strlen(filename))
    {
        command[maincommandIndex++] = filename[filenameIndex++];
    }

    int postcommandIndex = 0;
    while (postcommandIndex < strlen(postcommand))
    {
        command[maincommandIndex++] = postcommand[postcommandIndex++];
    }
    
    // Save the filename and their hash in tempHash.txt by running command
    int status = system(command);

    // if command runs properly then compare from the hash of the file stored previously
    if (status == 0)
    {
        // Now compare from preexisting
        FILE *hashfile = fopen("filenameToHash.txt", "r");
        if(hashfile==NULL){
            printf("You have not registered any file\n");
            return 1;
        }

        // reading the file "filenameToHash.txt" line by line and checking that filename matches with the given filename
        char hash[500];
        while (fgets(hash, 500, hashfile))
        {
            char temp[500] = {0};
            int tempIndex = 0;
            int mainIndex = 0;
            while (mainIndex<strlen(hash) && hash[mainIndex++] != '(')
            {
                // nothing
            }

            while (mainIndex<strlen(hash) && hash[mainIndex] != ')')
            {
                temp[tempIndex++] = hash[mainIndex++];
            }

            if (strcmp(temp,filename)==0)   // filename found so now comapre the previously stored hash and currently generated hash  
            {
                FILE *tempfile = fopen("tempHash.txt", "r");
                if (tempfile == NULL) {
                    printf("Temporary hash file not found.\n");
                    return 1;
                }
                char value[500];
                fgets(value, 500, tempfile);
                if (strcmp(value,hash)==0)  // both hash matches
                {
                    printf("Your file is completely safe.\n");
                    return 0;
                }
                else{
                    printf("Your file is changed\n");
                    return 0;
                }
                fclose(tempfile);
            }
        }

        // file not found in registered files
        printf("You had never registered this file\n");
        fclose(hashfile);
        return 0;
    }
    else{
        printf("Some error occured.Please try again\n");
        return 1;
    }
}