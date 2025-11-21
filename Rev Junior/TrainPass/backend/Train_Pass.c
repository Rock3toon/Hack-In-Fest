#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//funzione di controllo per l'accesso alla sbarra del treno
int controllo_accesso(char *mod, const unsigned char *code){
    FILE *flag;
    char buffer[100];
    if (memcmp(mod, code, 0x0d) == 0) { 
        flag = fopen("flag.txt", "r");
        if (flag != NULL) {
            while (fgets(buffer, sizeof(buffer), flag) != NULL) {
                printf("%s", buffer);
            }
            fclose(flag);
        }
    } else {
        printf("Stringa di controllo errata, accesso alla sbarra negato.\n");
    }

    return 0;
}

int crypting(char *mod, char *input, int medio){
    int j;
    int length = strlen(input);
    for (j = 0; j <= length; j++) {
    mod[j] = input[j] ^ (char)0x12;        
    if (j > medio) {
        mod[j] = input[j] ^ (char)0x17;
        }
    }
    return 0;
}

const unsigned char *security_code(){
    static const unsigned char code[0x0d] = "sb`{f{?drdvzx"; 
    return code;
}

int main() {

    char mod[20], input[20];
    const unsigned char *code = security_code();
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
    printf("] \n");
    scanf("%19s", input); 

    length = strlen(input);
    
    medio = length / 2;
    
    
    mod[medio] = '\0'; 
    
    crypting(mod, input, medio);
    
    controllo_accesso(mod, code);

    return 0;
}
