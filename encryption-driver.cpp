#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

#include "encryption.h"
#include "vigenere.h"

int main()
{
  string cmd, infile, outfile, password;

  cout << "Enter a command:\n"
       << "encrypt [input file] [output file] [password]\n"
       << "decrypt [input file] [output file] [password]\n"
       << "quit\n";
  cin >> cmd;
  if (cmd != "quit")
    cin >> infile >> outfile >> password;

  while (cmd != "quit")
  {
    if (cmd == "encrypt")
    {
      //Read contents of input file
      ifstream in(infile);
      if (in.is_open())
      {
        ostringstream oss;
        string line;
        while (getline(in, line))
          oss << line << '\n';
        
        //Write encrypted file
        VigenereEncrypt encrypt(outfile, password);
        if (encrypt.is_open())
          encrypt << oss.str();
        else
          cout << "Could not open " << outfile << " for writing\n";
      }
      else
        cout << "Could not open " << infile << " for reading\n";
    } //encrypt end
    else if (cmd == "decrypt")
    {
      //Open output file for writing
      ofstream out(outfile);
      if (out.is_open())
      {
        //Decrypt encrypted file
        VigenereDecrypt decrypt(infile, password);
        if (decrypt.is_open())
        {
          string word;
          char c;
          //Write contents of encrypted file to out
          while (decrypt >> word)
          {
            out << word;
            char c;
            //Write whitespace between words
            while (decrypt && isspace(c = decrypt.get()))
              out << c;
            decrypt.unget();
          }
        }
        else
          cout << "Could not open " << infile << " for reading\n";
      }
      else
        cout << "Could not open " << outfile << " for writing\n";
    } //decrypt end
    else if (cmd != "quit")
      cout << "Command \"" << cmd << "\" not recognized\n"
           << "Enter a command:\n"
           << "encrypt [input file] [output file] [password]\n"
           << "decrypt [input file] [output file] [password]\n"
           << "quit\n";
    
    //Get next command
    cin >> cmd;
    if (cmd != "quit")
      cin >> infile >> outfile >> password;
  } //while end

  return 0;
}