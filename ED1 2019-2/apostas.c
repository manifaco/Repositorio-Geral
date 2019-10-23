#include <stdio.h>
#include <stdlib.h>

int main() {
    srand((unsigned)time(NULL) );
    int i;
    int vet[6];
    for(;;){
      if(i==6) {
          printf("\n");
          if(vet[i] == 60) break;
          i==0;
      }
      vet[i] = rand()%(61);
      printf("|%i| ", vet[i]);
      i++;
    }
    return 0;
}
