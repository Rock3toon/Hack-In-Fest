#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define CONST1 0x20
#define CONST2 0x14

int main() {
    FILE *flag;
    char buffer [100];
    int code_2, input, control, honey_pot, code_1, i;
 
    for (i=0; i < CONST1; i++) {
        code_1= i + 2;
    }
    code_1 =0xff;
    honey_pot = 0xfc3;
    code_2 = 0x309;
    control = code_1 ^ 0xff3c;
    control = control ^ 0xac23;
    code_1= honey_pot ^ 0x0f3c;
    honey_pot = code_1 ^ 0xabc3;
    code_1= honey_pot ^ 0x0ffa;
    honey_pot = code_1 ^ 0xabcd;
    code_1= honey_pot ^ 0x0ffa;
    printf("Inserisci la velocità desiderata (in Km/h): ");
    scanf("%d", &input);
    code_1 = code_2 ^ 0x0ffa;
    code_2 = code_1^ 0xabcd;
    control = control + code_2;
    if (control == input){
        flag = fopen("flag.txt", "r");
        if (flag == NULL) {
            printf("Errore nell'apertura del file flag.txt\n");
            return 1;
        }
        while (fgets(buffer, sizeof(buffer), flag) != NULL) {
        printf("%s", buffer);
        }
        fclose(flag);
    } else if (input > CONST2 && input != code_2) {
        printf("Velocità oltre il limite consentito, velocità impostata: 20 Km/h\n");
    } else if (input < 0) {
        printf("Velocità non valida, velocità impostata: 0 Km/h\n");
    } else if (input <= CONST2 && input != code_2) {
        printf("Velocità impostata: %d Km/h\n", input);
    } else {
        printf("Input non valido.\n");
    }
    return 0;

}
