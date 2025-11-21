#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const unsigned char* string1 () {
    static const unsigned char str[0x06] = ">?E4C=";
    return str;
}

const unsigned char* string2 () {
    static const unsigned char str[0x01] = "L";
    return str;
}

const unsigned char* string3 () {
    static const unsigned char str[0x03] = "}@E";
    return str;
}

const unsigned char* string4 () {
    static const unsigned char str[0x03] = "020";
    return str;
}

const unsigned char* string5 () {
    static const unsigned char str[0x04] = "u=28";
    return str;
}

const unsigned char* string6 () {
    static const unsigned char str[0x01] = "N";
    return str;
}






#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#else
#include <unistd.h>
#endif

static void msleep(int ms) {
#ifdef _WIN32
    Sleep(ms);
#else
    usleep(ms * 1000);
#endif
}

#ifdef _WIN32
void enable_ansi_windows(void) {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) return;
    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) return;
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}
#endif

void clear_screen() {
    printf("\x1b[2J\x1b[H");
}

void print_centered(const char *s, int termwidth) {
    int len = (int)strlen(s);
    int pad = 0;
    if (termwidth > len) pad = (termwidth - len) / 2;
    for (int i = 0; i < pad; ++i) putchar(' ');
    puts(s);
}



int get_term_width() {
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        return csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
    return 80;
#else
    char *cols = getenv("COLUMNS");
    if (cols) return atoi(cols);
    return 80;
#endif
}


#define START 33
#define END 126
#define RANGE 94

void rot47(char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        unsigned char c = text[i];
        if (c >= START && c <= END) {
            c = START + ((c - START + 47) % RANGE);
        }
        text[i] = c;
    }
}

int main(void) {
#ifdef _WIN32
    enable_ansi_windows();
#endif

    int tw = get_term_width();

const char *banner[] = {
    "_____   ____  _      _____  _____  ____",
    "|  __ \\ / __ \\| |    |_   _|/ ____|/ ___|",
    "| |__) | |  | | |      | | | |    |  |__ ",
    "|  ___/| |  | | |      | | | |    |   __| ",
    "| |    | |__| | |____ _| |_| |____|  |__ ",
    "|_|     \\____/|______|_____|\\_____|\\____|",
    NULL
};
    clear_screen();

    // lampeggio blu e bianco per 8 cicli
    for (int flash = 0; flash < 8; ++flash) {
        clear_screen();

        // Colore alternato: blu (34) e bianco (97)
        const char *color = (flash % 2 == 0) ? "\x1b[34m" : "\x1b[97m";

        for (int i = 0; banner[i] != NULL; ++i) {
            printf("%s", color);
            print_centered(banner[i], tw);;
        }
        printf("\x1b[0m"); // reset
        fflush(stdout);
        msleep(250);
        system("clear");
    }

    // Colore finale fisso (blu)
    clear_screen();
    system("clear");
    for (int i = 0; banner[i] != NULL; ++i) {
        printf("\x1b[34m");
        print_centered(banner[i], tw);
    }
    printf("\x1b[0m\n");

    // Menù semplice sotto la scritta
    const char *menu[] = {
        "1) Accesso al sistema Semaforico\n",
        "2) Database\n",
        "3) Terminale di servizio\n",
        "4) Esci\n",
        NULL
    };

    for (int i = 0; menu[i] != NULL; ++i) {
        printf(menu[i], tw);
        msleep(120);
    }

    printf("\n");
    print_centered("Scelta Funzione Desiderata: ", tw);
    fflush(stdout);

    int choice = 0;
#ifdef _WIN32
    int ch = _getch();
    if (ch >= '1' && ch <= '9') choice = ch - '0';
#else
    int ch = getchar();
    if (ch >= '1' && ch <= '9') choice = ch - '0';
#endif

    clear_screen();
    switch (choice) {
        case 1: printf("\n");
            print_centered("\x1b[32mRichiesta chiave di sicurezza\x1b[0m", tw);
            printf("\n");
            print_centered("\x1b[32mInserisci la chiave di sicurezza nel file criptato per l'accesso\x1b[0m", tw); break;
        case 2: printf("\n");
            print_centered("\x1b[33mApertura database...\x1b[0m", tw); break;
        case 3: printf("\n");
            print_centered("\x1b[36mTerminale attivo\x1b[0m", tw); break;
        case 4: printf("\n");
            print_centered("\x1b[31mUscita...\x1b[0m", tw); break;
        default: printf("\n");
            print_centered("\x1b[35mScelta non valida\x1b[0m", tw); break;
    }

    printf("\n");
    msleep(800);
    return 0;
}


void message(){
    printf("Se dimentichi la key l'abbiamo salvata per te");
    printf("Però trovatela tu!\n");
}

void message2(){
    printf("key: https://rb.gy/g9eylf");
}