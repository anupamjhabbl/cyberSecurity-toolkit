#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void addType(char* password, int length, int type, int startIndex){
    switch(type){
        case 1:
            srand((unsigned) time(NULL));
            for (int i=0;i<length;i++){
                password[startIndex++] = '0'+(rand()%9);
            }
            break;
        case 2:
            srand((unsigned) time(NULL));
            for (int i=0;i<length;i++){ 
                password[startIndex++] = 'A'+(rand()%25);
            }
            break;
        case 3:
            srand((unsigned) time(NULL));
            for (int i=0;i<length;i++){
                password[startIndex++] = 'a'+(rand()%25);
            }
            break;
        case 4:
            char* symbol = "!@#$*^";
            srand((unsigned) time(NULL));
            for (int i=0;i<length;i++){
                password[startIndex++] = symbol[(rand()%5)];
            }
            break;
        default:
            printf("Some error occured. Rerun the program.\n");
    }
}

void generatePassword(int length, char* password){

    // defining some orders
    int order[10][4] = {{1,2,3,4},{1,2,4,3},{1,3,2,4},{1,3,4,2},{1,4,3,2},{1,4,2,3},{2,3,4,1},{2,3,1,4},{4,3,2,1},{4,3,1,2}};

    // generating random number
    srand((unsigned) time(NULL));
    int k = rand()%10;
    
    // getting the length of each type
    int lengthEachType = length/4;
    int lastTypeLength = length%4;
    if (lastTypeLength!=0){
        lastTypeLength = lengthEachType + lastTypeLength;
    }
    else{
        lastTypeLength = lengthEachType;
    }

    // making of password
    addType(password, lengthEachType, order[k][0], 0);
    addType(password, lengthEachType, order[k][1], lengthEachType);
    addType(password, lengthEachType, order[k][2], lengthEachType*2);
    addType(password, lastTypeLength, order[k][3], lengthEachType*3);
    
}
