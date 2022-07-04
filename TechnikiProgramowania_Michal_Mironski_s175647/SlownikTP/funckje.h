#ifndef FUNCKJE_H_INCLUDED
#define FUNCKJE_H_INCLUDED
//#pragma once
using namespace std;

int checkNumber();
void Translation(int d, string fl, string sl, string fn, string w);
string toLowerCase(string s);
bool isWord(string s);
void printDictionary(string dn);
void AddToDictionary(string dn);
void RemoveFromDictionary(string dn);
void welcome();
int countWords(string s);
void TranslationPrep(int choice, string FirstLang, string SecondLang, string FileName);


#endif // FUNCKJE_H_INCLUDED
