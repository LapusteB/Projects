#ifndef VIGENERE_H
#define VIGENERE_H
#include "encryption.h"
#include <iostream>

using namespace std;

class VigenereEncrypt : public EncryptedFileWriter
{   private:
    int count;
    string code;
    
    public:
        VigenereEncrypt(const string& fileName,const string& code);
        virtual string encrypt(const string&);
};

class VigenereDecrypt : public EncryptedFileReader
{   private:
    int count;
    string code;

    public:
        VigenereDecrypt(const string& fileName,const string& code);
        virtual string decrypt(const string&);
};


#endif