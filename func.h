#ifndef FUNC_H
#define FUNC_H
#include<thread>
#include<chrono>
#include<iostream>
#include<stdio.h>
#include "clui.h"
using namespace std;
void whereIsCursor(int);
void SudokuCursor(int,int);
void LoginPage();
void Login();
void SignUp();
void encryption(string);
void decryption(string);
void Menu();
void loading();
void NewGamePage();
void EasyGame1();
void MediumGame1();
void HardGame1();
void SavedGamesPage();
void cursor();
void easy1soloution(int);
void PrinterEasy();
void timer(int,int,int);
void linker1();
void linker2();
void linker3();
bool itsZero();
void paused();
void savedGameNames(int);

#endif