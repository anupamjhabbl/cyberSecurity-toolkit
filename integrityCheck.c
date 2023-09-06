#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int registerYourFile(const char *filename)
{
    // let's check the file exist or not
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("This file doesnot exist");
        return 1;
    }
    fclose(fp);

    // command string making
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

    // Save the filename and their hash by running command omething
    int status1 = system(command);
    int status2 = system("cat filenameToHash.txt >> filenameToHashTemp.txt");
    int status3 = system("cat filenameToHashTemp.txt > filenameToHash.txt");
    if ((status1 || status2 || status3) == 0)
    {
        printf("Successfully registered your file\n");
    }
    else
    {
        printf("Some error ocuured. Try again please");
    }
    return 0;
}

int checkIntegrity(const char *filename)
{
    // let's check the file exist or not
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("This file doesnot exist");
        return 1;
    }
    fclose(fp);

    // command string making
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
    
    // Save the filename and their hash by running command
    int status = system(command);
    if (status == 0)
    {
        // Now compare from preexisting
        FILE *hashfile = fopen("/home/anupamjhabbl/Desktop/projects/cyberSecurityTollkit/filenameToHash.txt", "r");

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

            if (strcmp(temp,filename)==0)
            {
                FILE *tempfile = fopen("/home/anupamjhabbl/Desktop/projects/cyberSecurityTollkit/tempHash.txt", "r");
                char value[500];
                fgets(value, 500, tempfile);
                if (strcmp(value,hash)==0)
                {
                    printf("Your file is completely safe.\n");
                    return 0;
                }
                fclose(tempfile);
            }
        }
        printf("Your file is changed\n");
        fclose(hashfile);
        return 0;
    }
    else{
        printf("Some error occured.Please try again\n");
        return 1;
    }
}