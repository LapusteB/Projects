#include <cctype>
#include <iostream>
using namespace std;
#include "encryption.h"

/*
  Output function for EncryptedFileWriter
  Encrypts the given string and writes the contents to file
  Will call subclass's encrypt if overridden
  Outputs to cout if file is not open for writing
*/
EncryptedFileWriter& operator<<(EncryptedFileWriter& efw, const string& str)
{
  if (!efw.is_open())
    cout << efw.encrypt(str);
  else
    static_cast<ofstream&>(efw) << efw.encrypt(str);
    //Invokes default ofstream& print function for efw
  return efw;
}

/*
  Input function for EncryptedFileReader
  Reads in a word from the input, decrypts it, 
  and updates the given string
  Reads from cin if file is not open
*/
EncryptedFileReader& operator>>(EncryptedFileReader& efr, string& str)
{
  if (!efr.is_open())
    cin >> str;
  else
    static_cast<istream&>(efr) >> str;
    //Invokes default ifstream& read function for efr
  str = efr.decrypt(str);
  return efr;
}

/*
  Trivial "encryption" function
  Capitalizes all letters
*/
string EncryptedFileWriter::encrypt(const string& plain)
{
  string cipher = plain;
  for (int i = 0; i < cipher.size(); i++)
    if (isalpha(cipher[i]))
      cipher[i] = toupper(cipher[i]);
  return cipher;
}

/*
  Trivial "decryption" function
  Converts all letters to lowercase
*/
string EncryptedFileReader::decrypt(const string& cipher)
{
  string plain = cipher;
  for (int i = 0; i < plain.size(); i++)
    if (isalpha(plain[i]))
      plain[i] = tolower(cipher[i]);
  return cipher;
}
