#include <iostream>
#include <exception>
#include <stdexcept>
#include <ctime>
#include <clocale>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>
#include <vector>
#include <new>

using namespace std;

template <class T> class excecoes{
 public:
    class erro{ }; //classe para referência na ocorrencia de erro. Utiliza-se construtor por ocultação
    void Mensagem (string msg); //Permite passar por parâmetro qualquer mensagem e exibi-la para o usuário
    bool isDivByZero (T numero); //retorna true se ocorreu uma tentativa de divisao por zero
    bool isNegativeSQR (T numero); //retorna true se houver tentativa de raiz negativa
    bool isNumber (T numero); //retorna true se o valor valor passado possui apenas números
    bool isWord (T palavra); //retorna true se o valor valor passado possui apenas char
    bool isDate (T dia, T mes, T ano); //returna true se for uma data válida
    T* alocation(T* ptr); //Caso não ocorra um erro de alocação de memmória devolve um ponteriro alocado
	bool isBissexto(T ano);
	void acessaArquivo(string msg);
	bool bitSet(T palavra);
	bool badAlloc(T numero);
	bool outOfRange(T numero, T numero2);
	
 private:
    T item; //Atributo privado que futuramente pode ser utilizado
};


template <class T> void excecoes<T>::acessaArquivo(string msg){
		fflush(stdin);
		Mensagem(msg);
		int tam = msg.size();
		char mensagem[tam];
		int i=0;
		for(i=0;i<=msg.size();i++){
			mensagem[i] = msg[i];
		}
		
		FILE* arq;
        arq = fopen("logDeErros.txt", "a");
        
        if(!arq){
        	Mensagem("Erro ao abrir arquivo");
        	return;
		}
		
        struct tm * infoTempo;
        time_t tempoB;
        time (&tempoB);
        infoTempo = localtime(&tempoB);
        char saida[50];
        strftime(saida, 50,"%d/%m/%Y as %H:%M:%S", infoTempo);
        fprintf(arq, "%s Horario da ocorrencia: %s\n", mensagem, saida);
        fclose(arq);
        setbuf(stdin,NULL);
        return;
}

template <class T> void excecoes<T>::Mensagem(string msg){
    cout << msg << endl;
}

template <class T> bool excecoes<T>::isDivByZero(T numero){
    try{ if (!numero) throw (erro()); }
    
    catch (excecoes::erro){
    	acessaArquivo("Erro 01: Divisao por 0");
        return true;
    }
    return false;
}

template <class T> bool excecoes<T>::isNegativeSQR(T numero){
    try { if (numero < 0) throw (erro()); }
    catch (excecoes::erro){
    	fflush(stdin);
    	acessaArquivo("Erro 05: raiz de numero negativo");
        return true;
    }
    return false;
}

template <class T> bool excecoes<T>::isNumber(T numero){
    string String;
    std::stringstream numToChar;
    numToChar << numero;
    String = numToChar.str();
    int pos = 0;
    try {
        while (pos < String.size()){
            if (!isdigit(String[pos])) throw (erro());
            pos++;
        }
    }
    catch (excecoes::erro){
        acessaArquivo("Erro 02: caracteres nao numericos encontrados");
        return true;
    }
    return false;
}

template <class T> bool excecoes<T>::bitSet(T palavra){
  	try {
    	std::bitset<5> mybitset (palavra);
  	}
	
    catch (const std::invalid_argument){
        acessaArquivo("Erro 08: caracteres nao binarios encontrados");
        return true;
    }
    return false;
}

template <class T> bool excecoes<T>::badAlloc(T numero){
	
  	try { int* novoVetor = new int[numero]; }
  		
  	catch (std::bad_alloc){
  		acessaArquivo("Erro 06: erro de alocacao de memoria");
        return true;
    }
    return false;
}

template <class T> bool excecoes<T>::outOfRange(T numero, T numero2){
		std::vector<int> meuVetor(numero);
  		try {
    		meuVetor.at(numero2)=100;
  		}
  		
  		catch (const std::out_of_range){
        acessaArquivo("Erro 07: erro de acesso a posicao fora de alcance");
        return true;
    }
    return false;
}


template <class T> bool excecoes<T>::isWord(T palavra){
    string String;
    std::stringstream valueToChar;
    valueToChar << palavra;
    String = valueToChar.str();
    unsigned int pos = 0;
    try {
        while (pos < String.size()){
            if (!isalpha(String[pos])) throw (erro());
            pos++;
        }
    }
    
    catch (excecoes::erro){
        acessaArquivo("Erro 03: caracteres numericos encontrados");
        return true;
    }
    return false;
}

template <class T> bool excecoes<T>::isDate(T dia, T mes, T ano){
    std::stringstream streamDia;
    std::stringstream streamMes;
    std::stringstream streamAno;
    string stringDia, stringMes, stringAno;
    streamDia << dia;
    streamMes << mes;
    streamAno << ano;
    stringDia = streamDia.str();
    stringMes = streamMes.str();
    stringAno = streamAno.str();
    int pos;
    
    try{
    	
        for (pos=0; pos<stringDia.size(); pos++) if (!isdigit(stringDia[pos])) throw (erro());
        for (pos=0; pos<stringMes.size(); pos++) if (!isdigit(stringMes[pos])) throw (erro());
        for (pos=0; pos<stringAno.size(); pos++) if (!isdigit(stringAno[pos])) throw (erro());

        int d, m, a;
        streamDia >> d;
        streamMes >> m;
        streamAno >> a;
		
		if (d <= 0 || d > 31 || m <= 0 || m > 12 || a <= 1582) throw (erro());

        else if ((m == 4 || m == 6 || m == 9 || m == 11) && (d <= 30)) return true;

        else if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && (d <= 31)) return true;

        if (a%4 == 0 && a%100!=0) if (m == 2 && d <= 29) return true;

        else if (a%4 == 0 && a%100!=0) if (m == 2 && d <= 28) return true;

        else throw (erro());

        return true;
    }
    
    catch(excecoes::erro){
        acessaArquivo("Erro 04: Data invalida.");
        return true;
    }
    return false;
}

