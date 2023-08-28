# cyberSecurity-toolkit

This is a cyberSecurity toolkit containing multiple tools like file encryption-decryption, secure password manager, selective traffic blocker etc.

## project structure
> "We are going to make a library named cyberSecurityToolkit that will have muliple functions using which you can do multiple tasks. THe list of function with what they do is listed below:"
1. encryptFile
2. decryptFile
3. generatePassword
4. encryptPassword
5. storePassword
6. getPassword
7. IntegrityRegister
8. INtegrityChecker

## Get started
> "As I have already given the list of functions, now let see how these function looks and what they do"
1. #### encryprFile
   
   This function have two version. Let see both of them:
     1. int encryptFile(FILE* fileptr)

        This function takes one argument and that argument is filepointer pointing to the file which you want to encrypt and it will encrypt that file and store it in **_./encrypted_** with name actualFileName_encrypted_.

        It returns status value where 1 means successfully encrypted the file and 0 means some error occured.
     2. int encryptFile(File* fileptr, string path)

        This function takes two argument and these arguments are filepointer pointing to the file which you want to encrypt and path of directory where you want to store the encrypted file. It will encrypt that file and store it in the given directory.

        It returns status value where 1 means successfully encrypted the file and 0 means some error occured.
2. #### decryptFile

   This function have two version. Let see both of them:
     1. int decryptFile(FILE* fileptr)

        This function takes one argument and that argument is filepointer pointing to the file which you want to decrypt and it will decrypt that file and store it in **_./decrypted_** with name actualfilename.

        It returns status value where 1 means successfully decrypted the file and 0 means some error occured.
     2. int decryptFile(File* fileptr, string path)

        This function takes two argument and these arguments are filepointer pointing to the file which you want to decrypt and path of directory where you want to store the decrypted file. It will encrypt that file and store it in the given directory.

        It returns status value where 1 means successfully encrypted the file and 0 means some error occured.
3. #### generatePassword

   This function has three versions. let see them:
    1. string generatePassword()

        This function takes no argument. It just generates a strong password for you.
       
        It returns the genrated password string.
    3. string generatePassword(int strength)

        This function takes one argument and that argument is basically stength of which you want to generate password. The value ranges from **_1-5_**.
       
        It returns the genearated password string according to strength given by you.
    5. string generatePassword(int strength, int length)

        This function takes two argument and the first arguments is stength of which you want to generate password and the second argument is the length of the password you want. The strength value ranges from **_1-5_**.
       
        It returns the genearated password string according to strength and length given by you.
4. #### encryptPassword

    string encryptPassword(string password)

      This function takes one argument and convert it into an encrypted version of it and returns to you.

      It returns a string that is basically the encrypted version of the password you gave in the argument.
5. #### storePassword

    int storePassword(string app_name, string password)

     It takes two argument app_name and password, encrypt them and store them in a very secure file.

     It returns the status code where 1 means successfully stored the credentials and 0 means some error occured.
6. #### getPassword

    string getPassword(string app_name)

    It takes single argument that specifies the application name which password you are asking. when this function runs it asks for your master password. verify you.

    If everything goes right it returns you the password else returns an empty string.
       
       
