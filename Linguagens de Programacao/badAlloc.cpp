#include<iostream>

void atribuicao(){using namespace std;
    string s("abc");
    try{
        s.at(1)='X';
        s.at(5)='A';
    }
    catch(out_of_range p){
        cout << "\n Fora da faixa de valores:" << p.what() << "" <<<< endl;
    }
}