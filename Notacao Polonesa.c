//Feito por: Leonardo Fernandes Alonso

#include <stdio.h>
#include <string.h>


char code_after[20], code_before[20] = "", espera[20] = "", aux[20] = "";
int a = NULL, b = NULL;

//função para inverter os itens que estão em espera
void reverse(){
    a = 0;
    for(b = strlen(espera) - 1; b >= 0; b--){
        aux[a] = espera[b];
        a++;
    }
    aux[a] = '\0';
}
// não conseguia fazer strcat(code_before, code_after[x]); então fiz essa função (não gostei de fazer dessa forma)
void letras(char a){
    switch(a){
        case 'a': strcat(code_before, "a"); break; case 'b': strcat(code_before, "b"); break; case 'c': strcat(code_before, "c"); break;
        case 'd': strcat(code_before, "d"); break; case 'e': strcat(code_before, "e"); break; case 'f': strcat(code_before, "f"); break;
        case 'g': strcat(code_before, "g"); break; case 'h': strcat(code_before, "h"); break; case 'i': strcat(code_before, "i"); break;
        case 'j': strcat(code_before, "j"); break; case 'k': strcat(code_before, "k"); break; case 'l': strcat(code_before, "l"); break;
        case 'm': strcat(code_before, "m"); break; case 'n': strcat(code_before, "n"); break; case 'o': strcat(code_before, "o"); break;
        case 'p': strcat(code_before, "p"); break; case 'q': strcat(code_before, "q"); break; case 'r': strcat(code_before, "r"); break;
        case 's': strcat(code_before, "s"); break; case 't': strcat(code_before, "t"); break; case 'u': strcat(code_before, "u"); break;
        case 'v': strcat(code_before, "v"); break; case 'w': strcat(code_before, "w"); break; case 'x': strcat(code_before, "x"); break;
        case 'y': strcat(code_before, "y"); break; case 'z': strcat(code_before, "z"); break;
    }
}
//mesma coisa que a função anterior
void elementos(char a){
    switch(a){
        case '+': strcat(espera, "+"); break; case '/': strcat(espera, "/"); break; case '*': strcat(espera, "*"); break;
        case '-': strcat(espera, "-"); break; case '>': strcat(espera, ">"); break; case '<': strcat(espera, "<"); break;
        case '%': strcat(espera, "%"); break; case '.': strcat(espera, "."); break;
    }
}

int main(void){

    //iniciando pedindo o código
    printf("\n Digite um codigo: ");
    scanf("%s", code_after);

    //for verificando cada elemento da frase
    for(int i = 0; code_after[i] != '\0'; i++){
        //verifica se é letra
        if(isalpha(code_after[i])){
            letras(code_after[i]);
        }
        else{
            //verifica se é um sinal
            if(code_after[i] == '/' || code_after[i] == '+' || code_after[i] == '-' || code_after[i] == '*' ||
               code_after[i] == '%' || code_after[i] == '<' || code_after[i] == '>' || code_after[i] == '.'){
                elementos(code_after[i]);
            }
            else{
                //verifica se está fechando o parenteses
                if(code_after[i] == ')'){
                    //inverte e add o que estiver na espera
                    reverse();
                    strcat(code_before, aux);
                    for(int y = 0; aux[y] != '\0'; y++){\
                        aux[y] = ' ';
                        espera[y] = ' ';
                    }
                }
                //se não for nada dos outros só ignora
                else{
                }
            }
        }
    }
    //inverte e add o resto que estiver na espera
    reverse();
    strcat(code_before, aux);
    system("cls");

    int tetoechao = strlen(code_after) + 27;
    char tetoechao2[100];
    for(int p = 0; p <= tetoechao; p++){
        strcat(tetoechao2, "-");
    }
    //mostra o resultado
    printf("%s \n", tetoechao2);
    printf("|| Codigo Digitado:   %s \n", code_after);
    printf("|| Codigo Processado: %s \n", code_before);
    printf("%s \n", tetoechao2);
}
