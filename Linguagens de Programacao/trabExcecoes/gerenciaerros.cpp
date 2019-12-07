#include <iostream>
#include <fstream>
#include <clocale>
#include <jagpdf/api.h>
#include <cstdlib>
//$(SolutionDir)dependencies\jagpdf\include
using namespace std;
using namespace jag;
int main(){
    setlocale(LC_ALL, "");
    char op = '0';

    cout << "--------ERROR MANAGEMENT--------\n";

	do{
        cout << "--------Pick an option: --------\n";
        cout << "1. Read error log.\n";
        cout << "2. Generate a error resume, type PDF.\n";
        cout << "0. End program.\n";
        cout << "Write your option: ";
        cin >> op;
        fflush(stdin);
        if (op == '1'){
            cout << "\nWait the exhibition: \n\n";
            cout << "logDeErros.dat:\n";
            FILE *arq1 = fopen("../ArquivoErro/logDeErros.dat", "r");
            char c1;
            while((c1=getc(arq1)) != EOF){
                cout << c1;
            }
            fclose(arq1);
            free(arq1);
            cout << "\n\n---------------------------------------\n";
            cout << "You got it, man! Enjoy your logDeErros!";
            cout << "\n---------------------------------------\n\n";
        }
        else{
            if (op == '2'){
                cout << "\nGenerating an error resume...\n";
                FILE *arq = fopen("../ArquivoErro/logDeErros.dat", "r");
                char c, line[100];
                int i=0, t=850, j=0, k=0;
                while (k < 100){
                    line[k] = '\0';
                    k++;
                }
                pdf::Document doc(pdf::create_file("../ArquivoErro/logDeErros.pdf"));
                doc.page_start(597.6, 848.68);
                t-=40;
                doc.page().canvas().text_start(50,t);
                doc.page().canvas().text("Error Resume");
                doc.page().canvas().text_translate_line(0,-15);
                doc.page().canvas().text_end();
                t-=20;
                while((c=getc(arq)) != EOF){
                    line[i]=c;
                    if(line[i]=='\n'){
                        line[i]=' ';
                        if(t!=0){
                            t-=20;
                            doc.page().canvas().text_start(50,t);
                            doc.page().canvas().text(line);
                            doc.page().canvas().text_translate_line(0,-15);
                            doc.page().canvas().text_end();
                            while(j!=i){
                                line[j]=' ';
                                j++;
                            }
                            i=-1;j=0;
                        }
                    }
                    i++;
                }
                doc.page_end();
                doc.finalize();
                fclose(arq);
                cout << "You got it, man! Enjoy your logDeErros\n\n";
            }
            else {
                if (op == '0'){
                    cout << "Ending program...\n";
                }
                else  cout << "Error! Try again.\n\n";
            }
        }
    } while (op != '0');
	return 0;
}
