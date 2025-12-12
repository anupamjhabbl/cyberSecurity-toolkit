# cyberSecurity-toolkit

This is a cyberSecurity toolkit containing multiple tools like file encryption-decryption, secure password manager, selective traffic blocker etc.

## project structure
> "We are going to make a library named cyberSecurityToolkit that will have muliple functions using which you can do multiple tasks. THe list of function with what they do is listed below:"
1. encrypt
2. decrypt
3. generatePassword
4. savePassword
5. getPassword
6. registerYourFile
7. checkIntegrity

## Get started
> "As I have already given the list of functions, now let see how these function looks and what they do"
1. #### encryprFile
   
   This function have two version. Let see both of them:
     1. int encryptFile(char* filepath)

        This function takes one argument and that argument is filepath pointing to the file which you want to encrypt and it will encrypt that file and store it in **_./encrypted_** with name actualFileName_encrypted_.

        It returns status value where 0 means successfully encrypted the file and 1 means some error occured.
     2. int encryptFile(char* filepath, char* path)

        This function takes two argument and these arguments are filepath pointing to the file which you want to encrypt and path of directory where you want to store the encrypted file. It will encrypt that file and store it in the given directory.

        It returns status value where 0 means successfully encrypted the file and 1 means some error occured.
2. #### decryptFile

   This function have two version. Let see both of them:
     1. int decryptFile(char* filepath)

        This function takes one argument and that argument is filepath pointing to the file which you want to decrypt and it will decrypt that file and store it in **_./decrypted_** with name actualfilename.

        It returns status value where 0 means successfully decrypted the file and 1 means some error occured.
     2. int decryptFile(char* filepath, char* path)

        This function takes two argument and these arguments are filepath pointing to the file which you want to decrypt and path of directory where you want to store the decrypted file. It will encrypt that file and store it in the given directory.

        It returns status value where 0 means successfully encrypted the file and 1 means some error occured.
3. #### generatePassword

   This function has three versions. let see them:
    1. void generatePassword(int length,char* password)

        This function takes two argument, first is length of password you want and second is password in which your generated password will be stored. It just generates a strong password for you.
       
    2. string generatePassword(int strength)

        This function takes one argument and that argument is basically stength of which you want to generate password. The value ranges from **_1-5_**.
       
        It returns the genearated password string according to strength given by you.
    3. string generatePassword(int strength, int length)

        This function takes two argument and the first arguments is stength of which you want to generate password and the second argument is the length of the password you want. The strength value ranges from **_1-5_**.
       
        It returns the genearated password string according to strength and length given by you.

4. #### savePassword

    int savePassword(char* filename, char* password)

     It takes two argument app_name and password,  store them in a very secure file.

     It returns the status code where 0 means successfully stored the credentials and 1 means some error occured.
5. #### getPassword

    int getPassword(char* filename)

    It takes single argument that specifies the filename which password you are asking. print the password linked to that file.

    It return the integar status code where 0 means program is running successfully and 1 means some error occured.
6. #### registerYourFile

    int registerYourFile(char* filename)

    It takes single argument that specifies the filename and generates its hash and store its hash value with filename.

    It return the status code, where 0 means successfully stored the hash and 1 means some error occured.
7. #### checkIntegrity

    int checkIntegrity(char* filename)

    It takes one argument that is filename and checks that it is changed from the last registered or not.

    It returns the status code where 0 means successfully checked and 1 means some error occured.
       
