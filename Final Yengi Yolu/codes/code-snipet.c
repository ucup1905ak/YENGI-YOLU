//jangan lupa include yang dibawah ini
#include <stdio.h>
#include <windows.h>
#include <unistd.h>
#include <string.h>

#include <conio.h>
/*
Name	Description
kbhit	Determines if a keyboard key was pressed as well
cgets	Reads a string directly from the console
cscanf	Reads formatted values directly from the console
putch	Writes a character directly to the console
cputs	Writes a string directly to the console
cprintf	Formats values and writes them directly to the console
clrscr	Clears the screen
getch	Get char entry from the console
getche	Get char entry from the console with echo
*/
#include <time.h>
/*
time_t ucup;
ucup = time(NULL);
tm iniStruct;

iniStruct = *localtime(&ucup);

*/
#include <ctype.h>
/*
isalnum()	Checks whether a character is alphanumeric
isalpha()	Checks whether a character is a letter
isblank()	Checks whether a character is a space or tab
iscntrl()	Checks whether a character is a control character
isdigit()	Checks whether a character is a decimal digit
isgraph()	Checks whether a character has a graphical representation
islower()	Checks whether a character is a lowercase letter
isprint()	Checks whether a character is a printable character
ispunct()	Checks whether a character is a punctuation character
isspace()	Checks whether a character is a whitespace character
isupper()	Checks whether a character is an uppercase letter
isxdigit()	Checks whether a character is a hexadecimal digit
tolower()	Returns a lowercase version of a character
toupper()	Returns an uppercase version of a character
*/


#define NORMAL "\033[0m"

//Forground
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
//background
#define BG_RED      "\033[41m"
#define BG_GREEN    "\033[42m"
#define BG_YELLOW   "\033[43m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define BG_CYAN     "\033[46m"
#define BG_WHITE    "\033[47m"


//clear '/n'
/*

while (getchar() != '\n'); 
*/

void alert(){
    printf("%c", 7);
}



void gotoxy(int x, int y);
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void removeCursor();
void removeCursor(){
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

/*
🎯 3. Move the Cursor
c
Copy
Edit
printf("\033[10;10H");  // Move to row 10, column 10
Or relative movements:

c
Copy
Edit
printf("\033[2A");  // Move cursor up 2 lines
printf("\033[3B");  // Move cursor down 3 lines
printf("\033[5C");  // Move cursor right 5 columns
printf("\033[4D");  // Move cursor left 4 columns

*/

int isEmptyString(char * s){
    if(strlen(s)==0 ||strcmp(s, "-")==0||strcmp(s, "")==0){
        return 1;
    }
    return 0;
}

void input_String_something(char *s){
    printf("\033[s");
    do{
        printf("\nMasukan string\t:");
        fflush(stdin);
        gets(s);
        if(isEmptyString(s)){
            printf("\n\t[!] String tidak boleh kosong [!]");
            getch();
            printf("\033[u");
            printf("\033[2J");
        }
    }while(isEmptyString(s));
}

