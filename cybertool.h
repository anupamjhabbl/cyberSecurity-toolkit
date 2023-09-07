// file_operations.h
#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

int registerYourFile(char* filename);
int checkIntegrity(char* filename);
int encrypt(char* filename);
int decrypt(char* filename);
int savePassword(char* filename, char* password);
int getPassword(char* filename);

#endif
