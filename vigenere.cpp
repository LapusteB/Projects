#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "vigenere.h"

using namespace std;


VigenereEncrypt::VigenereEncrypt(const string& file = "", const string& unEncrypted = "")
    : EncryptedFileWriter(file)
    {
        code = unEncrypted;
        for(int i = 0; i<code.size(); i++)
            code[i] = toupper(code[i]);

    }
VigenereDecrypt::VigenereDecrypt(const string& file = "", const string& Encrypted = "")
    : EncryptedFileReader(file)
    {
        code = Encrypted;
        for(int i = 0; i < code.size();i++)
            code[i] = toupper(code[i]);
    }

string VigenereEncrypt::encrypt(const string& orig)
{
    int shift, c = 0;
    string cipher = orig;
    for(int i=0; i< cipher.size(); i++)
    {
        if(isalpha(cipher[i]))
        {
            cipher[i] = toupper(orig[i]);
            count = c % code.size();
            shift = code[count] - 'A';
            cipher[i] = (cipher[i] - 'A' + shift) % 26 + 'A';
            c++;
        }
    }
    return cipher;
}

string VigenereDecrypt::decrypt(const string& cipher)
{
    int shift, c = 0;
    string orig = cipher;
    for(int i = 0; i< orig.size(); i++)
    {
        if(isalpha(orig[i]))
        {
            orig[i] = tolower(cipher[i]);
            count = c % code.size();
            shift = code[count] - 'A';
            orig[i] = (orig[i] - 'a' - shift + 26) % 26 + 'a';
            c++;
        }
    }
    return orig;
}

