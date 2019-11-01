//Feito por Leonardo Fernandes e Jesse Tavares

#include <stdio.h>

int polonesa(){
	int i, k, tamanho;
	char codigo[15], descarrega[15], fila[15];
	system("cls");
	printf("Digite:\n");
	scanf("%s",&codigo);
	tamanho = strlen(codigo);
	k = 0;
	i = 0;


	for(i = 0 ; i < tamanho; i++){
		if(codigo[i] == '+' || codigo[i] == '-' || codigo[i] == '*' || codigo[i] == '/'){

			fila[k] = codigo[i];
			k++;

		}
		else if(codigo[i] == ')'){
			k--;
			printf("%c",fila[k]);


		}
		else{
			if(codigo[i] != '('){
				printf("%c",codigo[i]);
			}
		}
	}
	printf("%c\n",fila[k-1]);
	system("pause");
}

void error(){
    system("cls");
    printf("Uma das opcoes amigo! \n\n");
    system("pause");
}

int main(){
	int opcao;

  	do
    {
    	system("cls");

        printf("Digite uma das opcoes ");
        printf("\n1 - Fazer Polonesa Inversa");
        printf("\n0 - Sair\n");
        scanf("%d",&opcao);
        switch(opcao)
        {
            case 1:
            	polonesa();
            	break;
            break;
            default:
            error();
        }
    }while(opcao != 0);

return 0;
}
