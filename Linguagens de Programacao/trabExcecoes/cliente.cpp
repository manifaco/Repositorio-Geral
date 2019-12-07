#include <iostream>
#include <cmath>
#include <clocale>
#include "exceptions.h"

using namespace std;

excecoes<float> objExcecoesFloat;
excecoes<int> objExcecoesInt;
excecoes<string> objExcecoesStr;

int main(){
    setlocale(LC_ALL, "");
    int op = 0,num,num2;
    float numerador, denominador, operando, result,tam;
    string dia, mes, ano, str1,str2;
    puts("-----------------------------------------------------------MENU------------------------------------------------");
    puts("Escolha um teste");
    puts("1-Verificar se eh divisivel por 0");
    puts("2-Checar se eh numero");
    puts("3-Checar se eh caractere");
    puts("4-Verificar se uma data eh valida");
    puts("5-Raiz quadrada");
    puts("6-Verificar se uma alocacao de memoria foi bem sucedida");
    puts("7-Verificar se houve um acesso fora do alcance maximo de um vetor");
    puts("8-verificar se um set de bits foi inserido corretamente");
    puts("0-Sair");
    do{
    	scanf("%i",&op);
    	switch(op){
    		case 1:
                puts("Informe o numerador e o denominador, respectivamente:\n");
                scanf("%i%i", &numerador,&denominador);
                if(!objExcecoesFloat.isDivByZero(denominador)){
                    result = (numerador/denominador);
                    printf("resultado: %.2f\n", result);
                }
                break;
                
            case 5:
            	fflush(stdin);
                puts("Informe um numero");
                scanf("%f", &result);
                if(!objExcecoesFloat.isNegativeSQR(result)){
                    result = sqrt(result);
                    printf("resultado: %.2f\n", result);
                }
                setbuf(stdin,NULL);
                break;
                
            case 2:
                puts("informe uma cadeia de caracteres numericos:");
                cin >> str1;
                if (!objExcecoesStr.isNumber(str1)) puts("tudo ok, Somente numeros foram recebidos");
                break;
            case 3:
                cout << "Informe uma cadeia de caracteres nao numericos\n";
                cin >> str2;
                if (!objExcecoesStr.isWord(str2)) puts("tudo ok, somente caracteres nao numericos foram recebidos");
                break;
                
            case 4:
                puts("Informe a data:");
                puts("dia:");
                cin >> dia;
                setbuf(stdin,NULL);
                puts("mes:");
                cin >> mes;
                setbuf(stdin,NULL);
                puts("ano:");
                cin >> ano;
                setbuf(stdin,NULL);
                if (!objExcecoesStr.isDate(dia,mes,ano)) puts("a data informada eh valida");
                break;
                
            case 6:
            	puts("Informe um tamanho que deseja alocar:");
            	scanf("%i",&tam);
            	if(!objExcecoesInt.badAlloc(tam)) puts("alocao bem sucedida");
            	
                break;
                
            case 8:
            	setbuf(stdin,NULL);
            	cin >> str1;
            	if(!objExcecoesStr.bitSet(str1)) puts("set de bits verdadeiro");
            	setbuf(stdin,NULL);
            	break;
            
            case 7:
            	puts("informe o tamanho do vetor e a posicao que deseja acessar:");
            	scanf("%i%i",&num,&num2);
            	if(!objExcecoesInt.outOfRange(num,num2)) puts("posicao acessada com sucesso");
            	break;
            	
            default:
                puts("Por favor, insira um numero valido:");
            
        }
    }while(op);
	return 0;
}

