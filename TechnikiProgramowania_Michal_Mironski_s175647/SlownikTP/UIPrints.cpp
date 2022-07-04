/*
	User Interface Prints
*/
#include <iostream>
#include <windows.h>
#include "funckje.h"
#include "UIPrints.h"

using namespace std;

//Prints main Menu
void Menu()
{
	system("cls");
	cout << "Wybierz jezyk: " << endl;
	cout << "1. Agnielski" << endl;
	cout << "2. Niemiecki" << endl;
	cout << "3. Hiszpanski" << endl;
	cout << "4. Zamknij program" << endl;

	int LangSelect = 0;
	while (LangSelect != 4)
	{
		LangSelect = checkNumber();
		switch (LangSelect)
		{
		case 1:
			Eng();
			break;
		case 2:
			Ger();
			break;
		case 3:
			Spa();
			break;
		case 4:
			exit(4);
			break;
		default:
			cout << "Wybierz poprawna opcje.";
			Sleep(1000);
			Menu();
		}
	}
}

//Prints dictionary options, dn - dictionary name, l - language
void dictionaryOptions(string dn, int l)
{
	int dictChoice = 0;

	system("cls");
	cout << "Opcje slownika" << endl;
	cout << "1. Wyswietl zawartosc slownika" << endl;
	cout << "2. Dodaj slowo do slownika" << endl;
	cout << "3. Usun slowo ze slownika" << endl;
	cout << "4. Powrot" << endl;

	dictChoice = checkNumber();
	switch (dictChoice)
	{
	case 1:
		printDictionary(dn);
		cout << "Wcisnij dowolny klawisz, aby kontynuowac..." << endl;
		system("pause >nul");
		dictionaryOptions(dn, l);
		break;
	case 2:
		AddToDictionary(dn);
		cout << "Wcisnij dowolny klawisz, aby kontynuowac..." << endl;
		system("pause >nul");
		dictionaryOptions(dn, l);
		break;
	case 3:
		RemoveFromDictionary(dn);
		cout << "Wcisnij dowolny klawisz, aby kontynuowac..." << endl;
		system("pause >nul");
		dictionaryOptions(dn, l);
		break;
	case 4:
		if (l == 1)
			Eng();
		else if (l == 2)
			Ger();
		else
			Spa();
		break;
	default:
		cout << "Wybierz poprawna opcje." << endl;
		system("pause >nul");
		dictionaryOptions(dn, l);
		break;
	}
}

//Prints menu for English language
void Eng()
{
	int engChoice = 0;

	system("cls");
	cout << "Wybierz opcje:" << endl;
	cout << "1. Polski - Angielski" << endl;
	cout << "2. Angielski - Polski" << endl;
	cout << "3. Opcje slownika" << endl;
	cout << "4. Powrot" << endl;

	engChoice = checkNumber();
	if (engChoice == 1)
	{
		TranslationPrep(engChoice, "Polski: ", "Angielski: ", "poleng.txt");
		cout << "Wcisnij dowolny klawisz, aby kontynuowac..." << endl;
		system("pause >nul");
		Eng();
	}
	else if (engChoice == 2)
	{
		TranslationPrep(engChoice, "Angielski: ", "Polski: ", "poleng.txt");
		cout << "Wcisnij dowolny klawisz, aby kontynuowac..." << endl;
		system("pause >nul");
		Eng();
	}
	else if (engChoice == 3)
	{
		dictionaryOptions("poleng.txt", 1);
		system("pause >nul");
		Eng();
	}
	else if (engChoice == 4)
	{
		system("cls");
		Menu();
	}
	else
	{
		cout << "Wybierz poprawna opcje." << endl;
		system("pause >nul");
		Eng();
	}
}

//Prints menu for German language
void Ger()
{
	int gerChoice = 0;

	system("cls");
	cout << "Wybierz opcje:" << endl;
	cout << "1. Polski - Niemiecki" << endl;
	cout << "2. Niemiecki - Polski" << endl;
	cout << "3. Opcje slownika" << endl;
	cout << "4. Powrot" << endl;

	gerChoice = checkNumber();
	if (gerChoice == 1)
	{
		TranslationPrep(gerChoice, "Polski: ", "Niemiecki: ", "polger.txt");
		cout << "Wcisnij dowolny klawisz, aby kontynuowac..." << endl;
		system("pause >nul");
		Ger();
	}
	else if (gerChoice == 2)
	{
		TranslationPrep(gerChoice, "Niemiecki: ", "Polski: ", "polger.txt");
		cout << "Wcisnij dowolny klawisz, aby kontynuowac..." << endl;
		system("pause >nul");
		Ger();
	}
	else if (gerChoice == 3)
	{
		//cout << "Opcje slownika WIP. Wcisnij dowolny klawisz zeby kontynuowac...";
		dictionaryOptions("polger.txt", 2);
		system("pause >nul");
		Ger();
	}
	else if (gerChoice == 4)
	{
		system("cls");
		Menu();
	}
	else
	{
		cout << "Wybierz poprawna opcje." << endl;
		system("pause >nul");
		Ger();
	}
}

//Prints menu for Spanish language
void Spa()
{
	int spaChoice = 0;

	system("cls");
	cout << "Wybierz opcje:" << endl;
	cout << "1. Polski - Hiszpanski" << endl;
	cout << "2. Hiszpanski - Polski" << endl;
	cout << "3. Opcje slownika" << endl;
	cout << "4. Powrot" << endl;

	spaChoice = checkNumber();
	if (spaChoice == 1)
	{
		TranslationPrep(spaChoice, "Polski: ", "Hiszpanski: ", "polspa.txt");
		cout << "Wcisnij dowolny klawisz, aby kontynuowac..." << endl;
		system("pause >nul");
		Spa();
	}
	else if (spaChoice == 2)
	{
		TranslationPrep(spaChoice, "Hiszpanski: ", "Polski: ", "polspa.txt");
		cout << "Wcisnij dowolny klawisz, aby kontynuowac..." << endl;
		system("pause >nul");
		Spa();
	}
	else if (spaChoice == 3)
	{
		//cout << "Opcje slownika WIP. Wcisnij dowolny klawisz zeby kontynuowac...";
		dictionaryOptions("polspa.txt", 3);
		system("pause >nul");
		Spa();
	}
	else if (spaChoice == 4)
	{
		system("cls");
		Menu();
	}
	else
	{
		cout << "Wybierz poprawna opcje." << endl;
		system("pause >nul");
		Spa();
	}
}
