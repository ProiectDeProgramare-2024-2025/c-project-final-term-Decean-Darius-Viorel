#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>



int rezervare() {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    FILE *filew;           // Declare a file pointer
    char input[100];       // Array to store the user input
    int end=1;

    // Open the file in write mode. If the file doesn't exist, it will be created.
    filew = fopen("F:\\proiect\\rezervari_personale.txt", "w");

    if (filew == NULL) {
        // If file couldn't be opened, print an error message and exit
        printf("Error opening file for writing.\n");
        return 0;
    }

    // Prompt user to enter text
    printf("Alegeti ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("Masa ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("(ex: 10)\n");
    scanf("%s",input, sizeof(input), stdin);
    fprintf(filew, "%s", input);
    fprintf(filew, "%c" " ");
    system("cls");
    printf("Alegeti ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("ora ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("(ex: 19:30)\n");
    scanf("%s",input, sizeof(input), stdin);
    fprintf(filew, "%s", input);
    fprintf(filew, "%c" " ");
    system("cls");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("Alegeti ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("Data ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("(ex: 23/05)\n");
    scanf("%s",input, sizeof(input), stdin);
    fprintf(filew, "%s", input);
    fprintf(filew, "%c" " ");



    system("cls");
    // Close the file after writing
    fclose(filew);

}

int valabilitate() {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    FILE *filer;
    char ch;
    int end=1;

    filer = fopen("F:\\proiect\\mese_valabile.txt", "r");


    if (filer == NULL) {
        printf("Error opening the file.\n");
        return 0;

    }

    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    printf("Mese ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("Valabile.\n");
    while ((ch = fgetc(filer)) != EOF) {
        putchar(ch);
    }
    fclose(filer);
    printf("\nPentru a da inapoi apasati 0.\n");
    while (end!=0) {
        scanf("%d", &end);
    }
    system("cls");
}

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    int alegere;
    while (1) {
        printf("\n--- Meniu Rezervari ---\n");
        printf("1. ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("Rezerva Masa\n");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("2. ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf("Mese Valabile\n");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("3. ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        printf("Iesire\n");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("Alege o optiune: ");
        scanf("%d", &alegere);
        if (alegere == 1) {system("cls");rezervare();}
        if (alegere == 2) {system("cls");valabilitate();}
        if (alegere == 3) {system("cls");printf("Iesire din program");sleep(2);return 0;}
        if (alegere != 1 && alegere != 2 && alegere != 3) {system("cls");printf("Optiune invalida. Te rog sa alegi din nou.\n");}
    }
}

