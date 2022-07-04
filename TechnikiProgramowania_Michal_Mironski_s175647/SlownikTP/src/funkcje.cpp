#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include "funkcje.h"

using namespace std;
//Function returns string w with small letter only - DONE
string toLowerCase(string w)
{
	for (int i = 0; i < w.length(); i++)
	{
		if (int(w[i]) >= 65 && int(w[i]) <= 90)
			w[i] = int(w[i]) + 32;
	}
	return w;
}

//Function checks if given number is between 0-9 - DONE
int checkNumber()
{
	string n = "0";
	cin >> n;
	while( n[0] < 48 || n[0] > 57)
	{
		cin.clear();
		cin.ignore();
		cout << "Podana zla wartosc, wpisz poprawna." << endl << endl;
		cin >> n;
	}
	return stoi(n);
}

//Function checks if given string is only made of letters - DONE
bool isWord(string w) //isWord = true only when all characters are letters; else false
{
	bool result = true;
	for (int i = 0; i < w.length(); i++)
	{
		if (w[i] < 65 || (w[i] > 90 && w[i] < 97) || w[i] > 122)
			result = false;
	}
	return result;
}

//Counts how many words is in string
int countWords(string s)
{
	bool inWord = false;
	int counter = 0;
	for (int i = 0; i < s.length() - 1; i++)
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			inWord = false;
		else if (inWord == false)
		{
			inWord = true;
			counter++;
		}
	}
	return counter;
}

//Splits string to separated words and sends it to main translation function
void TranslationPrep(int choice, string FirstLang, string SecondLang, string FileName)
{
	string beforeTranslation;
	string word;
	cin.clear();
	cin.ignore();
	getline(cin, beforeTranslation);
	word = "";
	for (int i = 0; i < beforeTranslation.length(); i++)
	{
		if (beforeTranslation[i] == ' ')
		{
			Translation(choice, FirstLang, SecondLang, FileName, word);
			word = "";
		}
		else
			word = word + beforeTranslation[i];
	}
	Translation(choice, FirstLang, SecondLang, FileName, word);

}

//Main tranlation function. Translating word to language choosen by user. - DONE
void Translation(int choice, string FirstLang, string SecondLang, string FileName, string beforeTranslation)
{
	string afterTranslation;
	if (!isWord(beforeTranslation))
		cout << beforeTranslation << "- to nie wyglada na slowo. Slowo powinno skladac sie z samych liter." << endl;
	else
	{
		ifstream LangFile(FileName);
		string line;
		int position = 0;
		int spacerPos=0;
		int found = 0;
		while (getline(LangFile, line))
		{
			position = line.find(toLowerCase(beforeTranslation));
			spacerPos = line.find('-');
			if (position != string::npos) //string.find returns npos=-1 if it didn't find matching substring
			{
				found = 1;
				break;
			}
		}
		if (found == 1)
		{
			if (line.substr(0, spacerPos) != beforeTranslation &&
				line.substr((spacerPos + 1), (line.length() - spacerPos)) != beforeTranslation)
			{
				cout << FirstLang << beforeTranslation << endl;
				cout << "Nieznane slowo. Sprawdz pisownie lub dodaj slowo za pomoca Opcji slownika." << endl << endl;
			}

			else
			{
				if (choice == 2)
					afterTranslation = line.substr(0, spacerPos);
				else
					afterTranslation = line.substr((spacerPos + 1), (line.length() - spacerPos));

				if (afterTranslation == beforeTranslation)
					cout << "Slowo jest juz przetlomaczone." << endl << endl;
				else
				{
					cout << FirstLang << beforeTranslation << endl;
					cout << SecondLang << afterTranslation << endl << endl;
				}

			}
		}
		else
		{
			cout << FirstLang << beforeTranslation << endl;
			cout << "Nieznane slowo. Sprawdz pisownie lub dodaj slowo za pomoca Opcji slownika." << endl << endl;
		}
		LangFile.close();
	}
}
//Function prints dictionary - DONE
void printDictionary(string dn)
{
	ifstream DictFile(dn);
	string line;
	while (getline(DictFile, line))
		cout << line << endl;
	DictFile.close();
}

//Function add new transtlation to dictionary - DONE
void AddToDictionary(string dn)
{
	string PLWord = ""; //Polish language word
	string OLWord = ""; //Other language word
	ofstream DictFile;
	cout << "Wpisz polskie slowo: " << endl;
	cin >> PLWord;
	if (!isWord(PLWord)) cout << "Wprowadzone dane nie sa slowem." << endl;
	else
	{
		cout << "Wprowadz tlumaczenie: " << endl;
		cin >> OLWord;
		if (!isWord(OLWord)) cout << "Wprowadzone dane nie sa slowem." << endl;
		else
		{
			DictFile.open(dn, ios_base::app);
			DictFile << endl << PLWord << "-" << OLWord;
			DictFile.close();
			cout << "Tlumaczenie dodane do slownika." << endl;
		}
	}
}

//Function remove translation from dictionary - DONE
void RemoveFromDictionary(string dn)
{
	string stringToRemove;
	cout << "Podaj slowo do usuniecia: " << endl;
	cin >> stringToRemove;
	if(!isWord(stringToRemove)) cout << "Wprowadzono nieprawidlowe dane." << endl;
	else
	{
		int position = -1;
		string line;
		ifstream DictFile(dn);
		ofstream tempFile("tempFile.txt");
		while (getline(DictFile, line))
		{
			position = line.find(toLowerCase(stringToRemove));

			if (line.length() == 0)
				continue;
			if (position != string::npos)
				tempFile << "";
			else
				tempFile << line << endl;
		}
		DictFile.close();
		tempFile.close();

		char tf[] = "tempFile.txt";
		if (remove(dn.c_str()) != 0 || rename(tf, dn.c_str()) != 0)
			perror("Wystapil blad podczas usuwania pliku lub zmieniania nazwy pliku.");
		else if (position == string::npos)
			cout << "Nieznaleziono podanego tlumaczenia." << endl;
		else
			cout << "Tlumaczenie usuniete." << endl;
	}
}

void welcome()
{
	cout << "13. Maly slownik by Michal Mironski" << endl;
	cout << "Wcisnij dowolny klawisz, aby rozpoaczac..." << endl;
	system("pause >nul");
}
