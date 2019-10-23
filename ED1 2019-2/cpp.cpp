#include <iostream>
#include <string>
#include <exception>
using namespace std;
class trataDivZero{
    public:
        trataDivZero(int n);
        void msg();
    
    private:
        int NLinha
}

trataDivZero:: trataDivZero(int n){
    NLinha = n;
}

void trataDivZero::msg(){
    cout << "Tentativa de divisao por zero ..." << endl;
    cout << "Erro na linha:" <<NLinha << ebdl;
}

bool divByZero(int d){
    try{
        if(d==0){
            throw(trataDivZero(_LINE_));
            return true;
        }
        else return false;
    }
    catch(trataDivZero)
}