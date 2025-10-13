#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    FILE *flag;
    char buffer[100]; 
    char mod[20], input[20];
    char code[20] = "sb`{f{"; 
    int i, length, medio;
    
    printf("Attendi per la stringa di controllo: ");
    fflush(stdout);
    printf("[");
    fflush(stdout);
    for (i = 0; i < 10; i++) {
        printf("#");
        fflush(stdout);
        usleep(500000);
    }
    printf("] ");
    scanf("%19s", input); 

    length = strlen(input);
    medio = length / 2;
    
    for (i = 0; i < medio; i++) {
        mod[i] = input[i] ^ (char)0xf5abcd12;
        if ((i + 1) < medio) {
            mod[i + 1] = input[i + 1] ^ (char)0xffab;
        }
    }
    mod[medio] = '\0'; 
    
    printf("\nStringa di controllo ricevuta: %s\n", mod);
    
    if (strcmp(mod, code) == 0) {
        flag = fopen("../flag.txt", "r");
        if (flag != NULL) {
            while (fgets(buffer, sizeof(buffer), flag) != NULL) {
                printf("%s", buffer);
            }
            fclose(flag);
    } else {
        printf("Stringa di controllo errata, accesso alla sbarra negato.\n");
    }
    return 0;
    }
}
