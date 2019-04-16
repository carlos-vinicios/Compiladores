#include <stdio.h>

//Inicio do código 2
int comentarios2(char *linha, int tam_lin){
  int e1, e2, e3, e4, e5, i;
  e1 = 1;
  e2 = e3 = e4 = e5 = 0;

  for(i = 0; i < tam_lin; i++){
    printf("%c\n", linha[i]);
    if(e1 && linha[i] == '/'){
      e1=0;
      e2=1;
    }else{
      if(e2 && linha[i] == '*'){
        e2=0;
        e3=1;
      }else{
        if(e3 && linha[i] == '*'){
          e3=0;
          e4=1;
        }else{
          if(e4 && linha[i] != '/'){
            e4 = 0;
            e3 = 1;
          }else{
            if(e4){
              e4 = 0;
              e5 = 1;
            }
          }
        }
      } 
    }
    if(e5){
      return 1;
    }
  }
  return 0;
}
//Fim do código 2

//Inicio do código 3
int aceita(int estado){
  if(estado == 5)
    return 1;
  
  return 0;
}

int erro(int estado, char ch){
  if(estado > 5 || estado == 0 || ch == '\0')
    return 1;
  
  return 0;
}

int change(int estado, char ch){
  switch(estado){
    case 1:
      if(ch == '/')
        return 2;
      break;
    case 2:
      if(ch == '*')
        return 3;
      break;
    case 3:
      if(ch != '*')
        return 3;
      if(ch == '*')
        return 4;
      break;
    case 4:
      if(ch == '/')
        return 5;
      if(ch == '*')
        return 4;
      if(ch != '/' || ch != '*')
        return 3;
      break;
  }
  return 1;
}

int comentarios3(char *linha, int tam_lin){
  int estado = 1, i=0;

  while(!aceita(estado) && !erro(estado, linha[i])){
    estado = change(estado, linha[i]);
    i++;
  }
  if(aceita(estado))
    return 1;
  else
    return 0;
}
//Fim do código 3

int main(void) {
  char coment[30] = "/*aaaaaa*/lanodsasdasd";

  if(comentarios3(coment, 30))
    printf("É comentário");
  else
    printf("Não é comentário");
  
  return 0;
}