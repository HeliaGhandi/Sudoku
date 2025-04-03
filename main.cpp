#include<iostream>
#include<thread>
#include<chrono>
#include "clui.h"
#include "func.h"
#include<cstring>
#include<fstream>
using namespace std;

int main()
{
    clear_screen();
    PrinterEasy();
    loading();
    LoginPage();


    getch();

}