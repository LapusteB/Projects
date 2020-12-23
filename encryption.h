#ifndef __ENCRYPTION_H
#define __ENCRYPTION_H

#include <iostream>
#include <fstream>
using namespace std;

const int ALPHABET_SIZE = 26;

class EncryptedFileWriter : public ofstream
{
  friend EncryptedFileWriter& operator<<(EncryptedFileWriter&, const string&);
public:
  EncryptedFileWriter(const string& file = "")
    : ofstream(file) {}
  virtual string encrypt(const string&);
};

class EncryptedFileReader : public ifstream
{
  friend EncryptedFileReader& operator>>(EncryptedFileReader&, string&);
public:
  EncryptedFileReader(const string& file = "")
    : ifstream(file) {}
  virtual string decrypt(const string&);
};

EncryptedFileWriter& operator<<(EncryptedFileWriter&, const string&);
EncryptedFileReader& operator>>(EncryptedFileReader&, string&);

#endif