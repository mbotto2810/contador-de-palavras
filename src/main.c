/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 */

#include <stdio.h>

int main() {

  char c;
  char c_passado;
  unsigned int palavras=0; 
  int begin=1; 
  int algarismo=0; 
  int antes_v=0; 
  int depois_v=0;
  
  c = ' ';

  while (c != '\n') {
    
    c_passado=c;
    scanf("%c", &c);


//Organiza e controla as variaveis de controle
    
    if((c=='.' || c==',' || c=='!' || c=='-') && c_passado == ' '){ begin=0; }
    
    if(c!='.' && c!=',' && c!='!' && c!= '-' && c!=' ' && c!='\n'){ begin=1; }
    
    if(antes_v==1 && depois_v==1){ algarismo=1; }
    
    if(c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7'|| c=='8'|| c=='9'){ antes_v=1; }
    
    if((c=='0'|| c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7'|| c=='8'|| c=='9') && (c_passado=='.' || c_passado==',')){ depois_v=1; }
    
    if((((c == ' ' || c=='\n') && c_passado != ' ') && begin==1) || ((c_passado=='.' || c_passado==',' || c_passado=='-' || c_passado=='!') && (c!=' ' && c!='.' && c!=',' && c!='-' && c!='\n' && c!='!'))) { palavras++; }
    
//verifica as condicoes para contar um algarismo floating point uma unica vez        
    if(algarismo==1) {
        antes_v=0;
        depois_v=0;
        algarismo=0;
        palavras--;
    }
    
  }
  

  printf("%i\n",palavras);
  return 0;
}
