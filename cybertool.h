int encrypt(char* filename);
int decrypt(char* filename);
void generatePassword(int length, char* password);
void addType(char* password, int length, int type, int startIndex);
int checkIntegrity(const char *filename);
int registerYourFile(const char *filename);
int savePassword(char* filename, char* password);
int getPassword(char* filename);