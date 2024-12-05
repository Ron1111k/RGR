#pragma once
#include <iostream>
#include<string>
#include<random>
#include<cstdint>
#include<locale.h>
#include <vector>
#include <cctype>
#include<cstdint>
#include <fstream>
#include <sstream>

 using namespace std;


bool isRightPassword();
void EncryptionMethods( string &fileName,  string &programEncrFile,  string &programOutFile, string &DecFile);
void Atbash(string &fileName, string &programEncrFile, string &programOutFile);
void Caesar( string &fileName, string &programEncrFile, string &programOutFile);
void PlayFair(string &fileName, string &programEncrFile, string &programOutFile,string &DecFile);
void inFile( string& outputFile);
void displayFile( string &str);