//#include "sha256.cpp"
#include <iostream>
#include <fstream>
#include "sha1.cpp"

using namespace std;
 // for std::cout only, not needed for hashing library
int main()
{
  // create a new hashing object
  FILE* fp;
  fp = fopen("new.txt","r");
//  SHA256 sha256;
  SHA1 sha1;
  // hashing an std::string
  ifstream outfile;
  outfile.open("text.txt");
  ifstream res;
  res.open("new.txt");
  string str;
  outfile.seekg(0,ios::end);
  str.reserve(outfile.tellg());
  outfile.seekg(0,ios::beg);
  str.assign((istreambuf_iterator<char>(outfile)),
            istreambuf_iterator<char>());
  cout<<"first file :"<<sha1(str)<<endl;
  string str2;
  outfile.seekg(0,ios::end);
  str2.reserve(outfile.tellg());
  outfile.seekg(0,ios::beg);
  str2.assign((istreambuf_iterator<char>(res)),
            istreambuf_iterator<char>());
  cout<<"second file :"<<sha1(str2)<<endl;
  //cout <<"fp: " <<sha256(str) << endl;
  // => a591a6d40bf420404a011733cfb7b190d62c65bf0bcda32b57b277d9ad9f146e
  // hashing a buffer of bytes
  const char* buffer = "How are you";
  //cout <<"How are you: " <<sha256(buffer, 11) << endl;
  // => 9c7d5b046878838da72e40ceb3179580958df544b240869b80d0275cc07209cc
  // or in a streaming fashion (re-use "How are you")
  //SHA256 sha256stream;
  const char* url = "create.stephan-brumme.com"; // 25 bytes
  int step = 5;
  cout<<"create.stephan-brumme.com: ";
  for (int i = 0; i < 25; i += step)
  //  sha256stream.add(url + i, step); // add five bytes at a time
//  cout << sha256stream.getHash() << endl;
  // => 82aa771f1183c52f973c798c9243a1c73833ea40961c73e55e12430ec77b69f6
  return 0;
}
