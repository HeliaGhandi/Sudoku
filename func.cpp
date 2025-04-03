#include<iostream>
#include "clui.h"
#include "func.h"
#include "clui.h"
#include<cstring>
#include<fstream>
#include<stdbool.h>
#include<ctime>
#include<thread>
#include<chrono>
using namespace std;
#define SIZE 100 

string gamename;
int wrongs = 0 , rights = 0;
struct cordinate
    {
        int x , y;
    };
cordinate datas[81];
int Easy1[81];
int Medium1[81];
int Hard1[81];
int line = 0 ;
string names[SIZE];
string namess[SIZE];

int numOfNames = 110;
string password;
string username , user , userSaves;



// void timer(int seconds , int x , int y)
// {
// {
//     change_color_rgb(227, 242, 56);
//     cursor_to_pos(5 , get_window_cols()/2);
//     //clear_screen();
    
//     for(int i = seconds ; i > 0 ; i-- )
//     {
       
//         cursor_to_pos(5 , get_window_cols()/2 +3);
        
//         int min = i / 60 ;
//         printf("--0%d:%d%d--" , min , (i-60*min)/10  , (i-60*min)%10);
//         delay(1000);
//         //clear_screen();
//         cursor_to_pos(3 , get_window_cols()/2);
//         //change_color_rgb(227, 242, 56);
        
//     }
    
//     cursor_to_pos(x , y);
// }
// }

// void linker1()
// {
//     int x = get_cursor_x() ; 
//     int y = get_cursor_y();
//     clear_screen();
//     int seconds = 600 ; 
//     thread time([seconds , x , y](){
//     timer(seconds , x , y );
//     });
    
//     thread EasySudoku1([](){
//         EasyGame1();//sudoku template
//     });
//     time.join();
//     EasySudoku1.join();
//     EasyGame1();
// }

// void linker2()
// {
//     int x = get_cursor_x() ; 
//     int y = get_cursor_y();
//     clear_screen();
//     int seconds = 600 ; 
//     thread time([seconds , x , y](){
//     timer(seconds , x , y );
//     });
    
//     thread HardSudoku1([](){
//         HardGame1();//sudoku template
//     });
//     time.join();
//     HardSudoku1.join();
//     HardGame1();
// }

// void linker3()
// {
//     int x = get_cursor_x() ; 
//     int y = get_cursor_y();
//     clear_screen();
//     int seconds = 600 ; 
//     thread time([seconds , x , y](){
//     timer(seconds , x , y );
//     });
    
//     thread MediumSudoku1([](){
//         MediumGame1();//sudoku template
//     });
//     time.join();
//     MediumSudoku1.join();
//     MediumGame1();
// }

void LoginPage()
{
    line = 0 ;
    string signup = "Sign Up";
    string error = "Invalid Input, Please Try Again";
    string login1 = "Login";
    int loginOrsignUp = 0 ;
    change_color_rgb(82, 217, 222);
    whereIsCursor(login1.length());
    cout <<"1: " << "Login";
    whereIsCursor(signup.length());
    cout <<"2: " << "Sign Up";
    reset_color();

    change_color_rgb(75, 89, 196);
    whereIsCursor(0);
    cin >> loginOrsignUp;
    reset_color();
    if(loginOrsignUp == 1)
    {
        clear_screen();
        line = 0 ;
        Login();
    }
    else if(loginOrsignUp == 2)
    {
        clear_screen();
        line = 0 ;
        SignUp();
    }
    else
    {
        clear_screen();
        line = 0 ;
        whereIsCursor(error.length());
        change_color_rgb(232, 56, 76);
        cout << "Invalid Input, Please Try Again" ;
        getch();
        reset_color();
        clear_screen();
        line = 0 ;
        LoginPage();
    }
}
void Login()
{
    clear_screen();
    string name , pass , input1 , input2;
    string erorr3 = "This username doesn't exist.";
    string erorr4 = "Wrong password";
    bool exist2 = false , is_true = false;
    whereIsCursor(username.length()*2);
    change_color_rgb(101, 105, 235);
    cout << "Username: " ;
    change_color_rgb(219, 26, 129);
    cin >> name;

    int i = 0 ;
    ifstream file4("players.txt");
        while(file4 >> input1)
        {
            namess[i] = input1;
            i++;
        }
        
    for(int i = 0 ; i <SIZE ; i++)
    {
        if(namess[i] == name)
        {
            exist2 = true; ;
            break;
        }
    }

    if(exist2 == false)
    {
        clear_screen();
        line = 0;
        whereIsCursor(erorr3.length());
        change_color_rgb(232, 56, 76);
        cout << erorr3 ;
        delay(1500);
        clear_screen();
        reset_color();
        LoginPage();
    }
    else{
    change_color_rgb(101, 105, 235);
    whereIsCursor(password.length()*2);
    cout << "Password: " ;
    change_color_rgb(219, 26, 129);
    cin >> pass ;
    ifstream file5(username);
    file5 >> input2;
    for(int i = 0 ; i < pass.length() ; i++)
    {
        if(pass.length() != password.length() || pass[i] != password[i])
        {
        is_true = false;
        clear_screen();
        line = 0;
        whereIsCursor(erorr4.length());
        change_color_rgb(232, 56, 76);
        cout << erorr4 ;
        reset_color();
        break;
        Login();
        }
    }
    username = name;
    clear_screen();
    whereIsCursor(14);
    change_color_rgb(236, 245, 66);
    cout << "Wellcome back " << username << ", login was succesfull" ;
    delay(1500);
    reset_color();
    Menu();
    }
}



void SignUp()
{
    clear_screen();
    line = 0 ;
   // string password;
    string input;
    string erorr2 = "This username already exist, please try again!";
    
    bool exist = false , space = false;
    char c = ' ';
    string save = "_save";
    string savedGames = "_savedGames";
    change_color_rgb(54, 76, 245);
    whereIsCursor(username.length()*2);
    cout << "Username: " ;
    change_color_rgb(242, 41, 236);
    cin >> username ;

    // for(int i = 0 ; i < username.length() ; i++)
    // {
    //     if(strchr(username.c_str() , ' ') != NULL)
    //     {
    //         space = true;
    //         clear_screen();
    //         line = 0 ;
    //         whereIsCursor(username.length()*2);
    //         change_color_rgb(232, 56, 76);
    //         cout << "Username invalid, don't use space in your username";
    //         reset_color();
    //         break;
    //     }
    // }
    // if(space == true)
    // {
    // getch();
    // SignUp();
    // }
    int i = 0 ;
    ifstream file3("players.txt");
        while(file3 >> input)
        {
            names[i] = input;
            i++;
        }
        
    for(int i = 0 ; i <numOfNames ; i++)
    {
        if(names[i] == username) // c style 
        {
            exist = true;
            clear_screen();
            line = 0 ;
            whereIsCursor(erorr2.length());
            change_color_rgb(232, 56, 76);
            cout << "This username already exist, please try again!" ;
            break;
        }
    }
    if(exist == true)
    {
    getch();
    clear_screen();
    line = 0 ;
    reset_color();
    LoginPage();
    }
    string usernameCopy = username;
    ofstream file("players.txt" , ios:: app);
    file << username << endl;
    user = username.append("_save");
    ofstream file19(user);
    file19 << 0;
    username = usernameCopy;
    userSaves = username.append("_savedGames");
    ofstream file40(userSaves,ios::app);
    username = usernameCopy;
    ofstream file1(username , ios:: app);
    //file1 << username << "  " ;
    change_color_rgb(54, 76, 245);
    whereIsCursor(password.length()*2);
    cout <<"Password: " ;
    change_color_rgb(242, 41, 236);
    cin >> password ;
    //encryption(password);
    file1 << password;
    reset_color();
    clear_screen();
    whereIsCursor(14);
    cout << "Thanks for signing up. We are happy to have you on board :) ";
    delay(1500);
    Menu();
}

void timer(int seconds , int x , int y)
{
{
    change_color_rgb(227, 242, 56);
    cursor_to_pos(5 , get_window_cols()/2);
    //clear_screen();
    
    for(int i = seconds ; i > 0 ; i-- )
    {
       
        cursor_to_pos(5 , get_window_cols()/2 +3);
        
        int min = i / 60 ;
        printf("--0%d:%d%d--" , min , (i-60*min)/10  , (i-60*min)%10);
        delay(1000);
        //clear_screen();
        cursor_to_pos(3 , get_window_cols()/2);
        //change_color_rgb(227, 242, 56);
        
    }
    
    cursor_to_pos(x , y);
}
}

void linker1()
{
    int x = get_cursor_x() ; 
    int y = get_cursor_y();
    clear_screen();
    int seconds = 600 ; 
    thread time([seconds , x , y](){
    timer(seconds , x , y );
    });
    
    thread EasySudoku1([](){
        EasyGame1();//sudoku template
    });
    time.join();
    EasySudoku1.join();
    EasyGame1();
}

void linker2()
{
    int x = get_cursor_x() ; 
    int y = get_cursor_y();
    clear_screen();
    int seconds = 600 ; 
    thread time([seconds , x , y](){
    timer(seconds , x , y );
    });
    
    thread HardSudoku1([](){
        HardGame1();//sudoku template
    });
    time.join();
    HardSudoku1.join();
    HardGame1();
}

void linker3()
{
    int x = get_cursor_x() ; 
    int y = get_cursor_y();
    clear_screen();
    int seconds = 600 ; 
    thread time([seconds , x , y](){
    timer(seconds , x , y );
    });
    
    thread MediumSudoku1([](){
        MediumGame1();//sudoku template
    });
    time.join();
    MediumSudoku1.join();
    MediumGame1();
}

void Menu()
{
    clear_screen();
    //loading();
    clear_screen();
    line = 0 ; //شاید باید منفی بشه
    string wellcome = "wellcome";
    string play = "Lets play game";
    int option;

    whereIsCursor(0);
    change_color_rgb(240, 12, 179);
    cout << "Wellcome " << username;
    delay(300);
    whereIsCursor(0);
    change_color_rgb(245, 181, 5);
    cout << play ;
    delay(300);
    whereIsCursor(0);
    change_color_rgb(109, 76, 217);
    cout << "<Game options>" ;
    whereIsCursor(0);
    change_color_rgb(151, 124, 242);
    cout << "1- Start a New Game";
    whereIsCursor(0);
    cout << "2- Play a Saved Game";
    whereIsCursor(0);
    cout << "3- Leader Board";
    whereIsCursor(0);
    cout << "4- Exit";
    delay(200);
    whereIsCursor(0);
    cout <<"-------------";
    whereIsCursor(0);
    cout << "Choose an option : " ;
    // line = 14;
    cin >> option;
    //cout << "            " << "|";
    whereIsCursor(0);
    cout << "-------------";

    switch (option)
    {
    case 1:
        NewGamePage();
        break;
    case 2:
        SavedGamesPage();
        break;
    case 3:

        break;
    case 4: 
    LoginPage();
        break;
    default:
        break;
    }
}



void NewGamePage()
{
    clear_screen();
    loading();
    clear_screen();
    line = 0;
    int level;
    wrongs = 0 , rights = 0;

    change_color_rgb(235, 160, 232);
    whereIsCursor(0);
    cout << "Game Levels :" ;
    change_color_rgb(240, 252, 252);
    whereIsCursor(0);
    cout << "-------------";
    change_color_rgb(105, 245, 29);
    whereIsCursor(0);
    cout << "1- Easy";
    change_color_rgb(245, 148, 29);
    whereIsCursor(0);
    cout << "2- Medium";
    change_color_rgb(245, 0, 0);
    whereIsCursor(0);
    cout << "3- Hard";
    change_color_rgb(105, 55, 105);
    whereIsCursor(0);
    cout << "4- Exit";
    change_color_rgb(240, 252, 252);
    whereIsCursor(0);
    cout << "-------------";
    change_color_rgb(235, 160, 232);
    whereIsCursor(0);
    cout << "Choose a Level: ";
    change_color_rgb(237, 225, 237);
    cin >> level;

    switch (level)
    {
    case 1:
    EasyGame1();
        break;
    case 2:
    MediumGame1();

        break;
    case 3:
    HardGame1();
        break;
    case 4:
    Menu();
        break;
    default:
        break;
    }

}
void HardGame1(){
    clear_screen();
    ifstream file9("hard1.txt");
    int hard1;
    int k = 0;


    while(file9 >> hard1)
    {
        Hard1[k] = hard1;
        k++;
    }
int counter = 0 , j = 0 , p = -5 , s = -5;
for(int i = 0 ; i < 9 ; i++)
{
    //SudokuCursor(i-5-p,j-5);
    cursor_to_pos(get_window_rows() / 2 +p,get_window_cols() / 2 +s);
    //SudokuCursor(i-5,j-5);
    cout << "| " ;
    if(i%3 == 0 && i != 0)
    {
      //  SudokuCursor(i-5-p,j-5);
        cout << "---------------------- |" ;
        p++;
        cursor_to_pos(get_window_rows() / 2 +p,get_window_cols() / 2 +s);
        //SudokuCursor(i-5-p,j-5);
        cout << "| " ;
    }

    for(int j = 0 ; j < 9  ; j++)
    {
        if(j%3 == 0 && j != 0)
        {
            cout << "| " ;
            datas[counter].y +=2;
        }
        // if(Easy1[counter] != 0)
        //     change_color_rgb(78, 153, 133);
         cout << Hard1[counter] << " ";

         datas[counter].x = get_cursor_x();
         datas[counter].y = get_cursor_y();

        counter++;
    }
    cout << " |" ;
    p++;
}
cursor();
}


void MediumGame1()
{
         clear_screen();
    ifstream file8("medium1.txt");
    int medium1;
    int k = 0;


    while(file8 >> medium1)
    {
        Medium1[k] = medium1;
        k++;
    }
int counter = 0 , j = 0 , p = -5 , s = -5;
for(int i = 0 ; i < 9 ; i++)
{
    //SudokuCursor(i-5-p,j-5);
    cursor_to_pos(get_window_rows() / 2 +p,get_window_cols() / 2 +s);
    //SudokuCursor(i-5,j-5);
    cout << "| " ;
    if(i%3 == 0 && i != 0)
    {
      //  SudokuCursor(i-5-p,j-5);
        cout << "---------------------- |" ;
        p++;
        cursor_to_pos(get_window_rows() / 2 +p,get_window_cols() / 2 +s);
        //SudokuCursor(i-5-p,j-5);
        cout << "| " ;
    }

    for(int j = 0 ; j < 9  ; j++)
    {
        if(j%3 == 0 && j != 0)
        {
            cout << "| " ;
            datas[counter].y +=2;
        }
         cout << Medium1[counter] << " ";

         datas[counter].x = get_cursor_x();
         datas[counter].y = get_cursor_y();

        counter++;
    }
    cout << " |" ;
    p++;
}
cursor();

}

void SavedGamesPage()
{
    clear_screen();
    string nline , savedgame;
    int linecounter = 0 , n , index = 0 , i = 0;
    ifstream file16(user);
    file16 >> linecounter;
    // for(int i = 0 ; i < 200 ; i++)
    // {
    //     getline(file16 , nline);
    //     if(nline.length() != 0)
    //     {
    //         linecounter++;
    //     }
    // }
    // linecounter--; // -password
    cursor_to_pos(get_window_rows() /2 , get_window_cols() / 2);
    cout << "You have " << linecounter << " Saved Games.";
    cursor_to_pos(get_window_rows() /2 + 2, get_window_cols() / 2);
    cout << "Choose a Number Between 0 - " << linecounter << ": ";
    cursor_to_pos(get_window_rows() /2 +2, get_window_cols() / 2 + 37);
    cin >> n;
    cursor_to_pos(get_window_rows() /2 + 4, get_window_cols() / 2);
    cout << "---------------------------------";
    ifstream file17(username);
    for(int i = 0 ; i < n ; i++)
    {
        getline(file17 , savedgame);
        cursor_to_pos(get_window_rows() /2 + 10 + i, get_window_cols() / 2);
        cout << savedgame;
    }
    while(file17 >> index)
    {
        Easy1[i] = index;
        i++;
    }
    EasyGame1();

}

void PrinterEasy()
{
    ifstream file5("easy1.txt");
    int easy1;
    int k = 0;


    while(file5 >> easy1)
    {
        Easy1[k] = easy1;
        k++;
    }
}


void EasyGame1()
{
    clear_screen();

int counter = 0 , j = 0 , p = -5 , s = -5;
cursor_to_pos(get_window_rows() / 2 +p-1,get_window_cols() / 2 +s+2);
for(int i = 1 ; i < 10 ; i ++)
{
    change_color_rgb(80, 235, 137);
    cout<< i <<" ";
    if(i%3 == 0) cout<<"  ";
}
reset_color();
for(int i = 0 ; i < 9 ; i++)
{
    //SudokuCursor(i-5-p,j-5);
    cursor_to_pos(get_window_rows() / 2 +p,get_window_cols() / 2 +s);
    cout << "| " ;
    if(i%3 == 0 && i != 0)
    {
      //  SudokuCursor(i-5-p,j-5);
        cout << "---------------------- |" ;
        p++;
        cursor_to_pos(get_window_rows() / 2 +p,get_window_cols() / 2 +s);
        //SudokuCursor(i-5-p,j-5);
        cout << "| " ;
    }
        // cursor_to_pos(get_window_rows() / 2 +p,get_window_cols() / 2 +s-3);
        //cursor_to_pos(get_window_rows() / 2 +p,get_window_cols() / 2 +s);

    for(int j = 0 ; j < 9  ; j++)
    {
        if(j%3 == 0 && j != 0)
        {
            cout << "| " ;
            datas[counter].y +=2;
        }
        if(Easy1[counter] != 0)
        {
        change_color_rgb(235, 80, 189);
        cout << Easy1[counter] << " ";
        reset_color();
        }
        if(Easy1[counter] == 0)
        {
            cout << Easy1[counter] << " ";
        }
         datas[counter].x = get_cursor_x();
         datas[counter].y = get_cursor_y();

    // int temp1 = get_cursor_x() , temp2 = get_cursor_y();
    // cursor_to_pos(get_window_rows() - 3 , 2);
    // cout << counter << " : " << temp1 << " " << temp2 << " - ";
    // delay (2000);
    // cout << " /// ";
    // delay(2000);
    // cout << counter << " : " << datas[counter].x << " " << datas[counter].y << " - ";
    // cursor_to_pos(temp1,temp2);
    // reset_color();

        counter++;
    }
    cout << " | " ;
        change_color_rgb(80, 235, 137);
        cout << i+1 << " ";
        reset_color();
    p++;
}
cursor();
    // for(int i = 0 ; i < 9 ; i++)
    // {
    //     for(int j = 0 ; j < 9 ; j++)
    //     {
    //         cout << Easy1[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // getch();
    // Menu();
}


void cursor()
{
    int right = 0, left = 0, up = 0, down = 0, o = 0;
    int input, i = 0, j = 0;
    int max_rows = get_window_rows();
    int max_cols = get_window_cols();
    cursor_to_pos(max_rows / 2, max_cols / 2 +7);
    int x = 5 , y = 5 ,s = 0;



    while (true)
    {
            input = getch(); // Get the actual key code

            switch (input)
            {
            case 75: // Left arrow key
                left++;
                right--;
                if (left < 6) { // && i > 0
                j+=2;
                y-=1;
                    SudokuCursor(i, j-7);
                }
                else
                {
                    left--;
                    right++;
                }
                break;
            case 77: // Right arrow key
                right++;
                left--;
                if (right < 6 ) { //&& i < max_cols - 1
                j-=2;
                y+=1;
                    SudokuCursor(i, j-7);
                }
                else
                {
                    right--;
                    left++;
                }
                break;
            case 72: // Up arrow key
                up++;
                down--;
                
                if (up < 6 ) { //&& j > 0
                x-=1;
                    SudokuCursor(++i, j-7);
                }
                else
                {
                    up--;
                    down++;
                }
                break;
            case 80: // Down arrow key
                down++;
                up--;
                if (down < 6 ) { //&& j < max_rows - 1
                    SudokuCursor(--i, j-7);
                    x+=1;
                }
                else
                {
                    down--;
                    up++;
                }
                break;
            case 82 : // insert
            easy1soloution(input);
            break;

            case 115 : // save
            savedGameNames(s);
            EasyGame1();
            ofstream file15(username , ios::app);
            for(int i = 0 ; i < 81 ; i++)
            {
                file15 << Easy1[i] << " ";
            }
            file15 << endl;
            ifstream file20(user);
            file20 >> s;
            s++;
            ofstream file21(user);
            file21 << s ;
            ofstream file24(userSaves);
            file24 << gamename << " " << wrongs << " " << rights << endl;
            break;
            }
        } 
    }

void savedGameNames(int s)
{

    string inputGamename;
    string gamenames[100];
    int i = 0 ;
            clear_screen();
            cursor_to_pos(get_window_rows()/2 , get_window_cols()/2 - 17);
            cout << "Choose a name for your game: ";
            cursor_to_pos(get_window_rows()/2 - 2 , get_window_cols()/2 - 17);
            cin >> gamename ;
            ifstream file23(user);
        while(file23 >> inputGamename)
        {
            gamenames[i] = inputGamename;
            i++;
        }
        
    for(int i = 0 ; i < s ; i++)
    {
        if(gamenames[i] == gamename) // c style 
        {
            change_color_rgb(227, 30, 30);
            cursor_to_pos(get_window_rows()/2 - 4 , get_window_cols()/2 - 17);
            cout << "This name is already taken, choose another name for your game.";
            reset_color();
            getch();
            savedGameNames(s);            
        }
    }


}

void easy1soloution(int input)
{
    int tempX = get_cursor_x() , tempY = get_cursor_y();
    int answer;
    //int Input = int(input - '0');
    int index_i = 0 , index_j = 0;
    int easy1_1 , easy1_2 ,easy1_3;

    int easy1Unsoved [9][9];
    int easy1solution [9][9];

    ifstream file6("easy1.txt");
    
        for(int i = 0 ; i < 9 ; i++)
        {
            for(int j = 0 ; j < 9 ; j++)
            {
                file6 >> easy1_1;
                easy1Unsoved[i][j] = easy1_1;
            }
        }

    ifstream file7("easy1solution.txt");

        for(int i = 0 ; i < 9 ; i++)
        {
            for(int j = 0 ; j < 9 ; j++)
            {
                file7 >> easy1_2;
                easy1solution[i][j] = easy1_2;
            }
        }
        cursor_to_pos(48,62);
        cout << "---------------";
        change_color_rgb(94, 224, 209);
        cursor_to_pos(50,65);
        cout << "i: ";
        cursor_to_pos(50,70);
        cin >> index_i;
        cursor_to_pos(52,65);
        cout << "j: ";
        cursor_to_pos(52,70);
        cin >> index_j;
        cursor_to_pos(54 , 65);
        cout << "answer: ";
        cursor_to_pos(54,75);
        cin >> answer ;
        reset_color();

        if(0 == easy1Unsoved[index_i - 1][index_j - 1])
        {
            if(answer == easy1solution[index_i - 1][index_j -1])
            {
                // cursor_to_pos(tempX , tempY);
                // cout << answer;

                Easy1[9*(index_i - 1) + index_j - 1] = answer;
                rights++;
                EasyGame1();

            }
            else
            {
                wrongs++;
                cursor_to_pos(54,80);
                change_color_rgb(227, 30, 30);
                cout << "Wrong answer, try again.";
                delay(1500);
                reset_color();
                if(wrongs == 4)
                {
                    clear_screen();
                    cursor_to_pos(get_window_rows()/2 ,get_window_cols()/2 -18);
                    change_color_rgb(212, 8, 76);
                    cout << "YOU LOST THE GAME, BETER LUCK NEXT TIME." ;
                    delay(2500);
                    Menu();
                }
                else
                EasyGame1();
            }
        }
        else
        {
            cursor_to_pos(54,80);
            cout << "You Can't change this index.";
            delay(1500);
            EasyGame1();
        }
        // cout << endl << index_i << "- " << index_j << "- " << answer << endl << easy1solution[index_i][index_j] << endl << easy1Unsoved[index_i][index_j]; 
        cursor_to_pos(tempX , tempY);
        cursor();
}


// void easy1solution(int x , int y , int input)
// {
//     int temp;

//     for(int i = 0 ; i < 81 ; i++)
//     {
//         if(get_cursor_x() == datas[i].x && get_cursor_y() == datas[i].y)
//         {
//             temp = i;
//             break;
//         }
//     }

//     // if(x==4 || x == 5 || x ==6)
//     //     x--;

//     // if(x==8 || x == 9 || x ==10)
//     //     x-=2;

//     // int temp1 = get_cursor_x() , temp2 = get_cursor_y();
//     // cursor_to_pos(get_window_rows() - 2 , 2);
//     // cout << "x: " << x << "y: " << y;
//     // cursor_to_pos(temp1,temp2);
//     int wrongs = 0 ;
//     int easy1_1 , easy1_2 ,easy1_3;
//     int easy1Unsoved [9][9];
//     int easy1solution [9][9];
//     int solution1d_e [81];

//     ifstream file6("easy1.txt");
    
//         for(int i = 0 ; i < 9 ; i++)
//         {
//             for(int j = 0 ; j < 9 ; j++)
//             {
//                 file6 >> easy1_1;
//                 easy1Unsoved[i][j] = easy1_1;
//             }
//         }

//     ifstream file7("easy1solution.txt");

//         for(int i = 0 ; i < 9 ; i++)
//         {
//             for(int j = 0 ; j < 9 ; j++)
//             {
//                 file7 >> easy1_2;
//                 easy1solution[i][j] = easy1_2;
//             }
//         }
//         ifstream file8("easy1solution.txt");
//         for(int i = 0 ; i < 81 ; i++)
//         {
//                 file8 >> easy1_3;
//                 solution1d_e[i] = easy1_3;
//         }

//    // bool Zero = itsZero();
//     int e1Input;
//     string error5 = "YOU LOST THE GAME!";
//     e1Input = int(input - '0');
//     if(e1Input <= 9 && e1Input >= 1)
//     //cout << e1Input;


// // int temp3 = get_cursor_x() , temp4 = get_cursor_y();
// // cursor_to_pos(get_window_rows() - 3 , 2);
// // for(int i = 0 ; i < 81 ; i++)
// // {
// // cout << Easy1[i] << " ";
// // }
// // cursor_to_pos(0 , 0);

//     {
//     if(Easy1[temp] == 0)
//     {
//         if(e1Input == solution1d_e[temp])
//         {
//             cout << e1Input;
//         }
//         else
//         {
//             //change_color_rgb(247, 7, 7);
//             //cout << e1Input;
//             //delay(1500);
//             //reset_color();
//             //cout << " ";
//             wrongs++;
//             // if(wrongs == 4)
//             // {
//             //     clear_screen();
//             //     whereIsCursor(error5.length());
//             //     change_color_rgb(247, 7, 15);
//             //     cout << error5;
//             //     delay(1500);
//             //     Menu();
//             // }
//         }
//     }
    
//     }
// }
    
// bool itsZero(int input)
// {
// int theInput = int(input - '0');
// }

void loading()
{
    clear_screen();
    line = 0;
    string loading = "loading";
    whereIsCursor(loading.length());
    for(int i = 0 ; i < loading.length() ; i++)
    {
        delay (100);
        change_color_rgb(50 + 25*i, 235, 0 + 35*i);
        cout << loading[i] ;
        delay (100);
    }
    for(int i = 0 ; i < 5 ; i++)
    {
        delay(100);
        change_color_rgb(122, 230, 204);
        cout << " ." ;
    }
    whereIsCursor(loading.length());
    for(int i = 0 ; i < 5 ; i++)
    {
        delay(100);
        change_color_rgb(122, 230, 204);
        cout << " ." ;
    }
    clear_screen();
}



void encryption(string password)
{
    for(int i = 0 ; i < password.length() ; i++)
    {
        password[i] = password[i] + i;
    }
}


void SudokuCursor(int lines , int col)
{
    int row = get_window_rows();
    int column = get_window_cols();
    cursor_to_pos(row / 2 - lines , column / 2 - col);
}
void whereIsCursor(int a)
{
    // string login1 = "Login";
    // string signup = "Sign Up";
    // static int line = 0;
    int row = get_window_rows();
    int column = get_window_cols();
    cursor_to_pos(row / 2 + line , column / 2 - a/2);
    line += 2; 
}

