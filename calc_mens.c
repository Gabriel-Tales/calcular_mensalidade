#include <stdio.h>
#include <time.h>

#define PRINTD(x) printf("\nA variavel "#x" tem valor %d\n\n",x)

#define DEBUG
//#undef DEBUG

int main(void){
  char v[3]; /* Verificador de continuacao do programa*/
  struct tm *t; /* estrutura de tempo*/
  int mon[12], /* array com dias dos seus respectivos meses */
  dia_ins, /* variavel que guarda a entrada do dia da instalacao */
  mes, /* variavel que guarda a entrada do mes da instalacao */
  ven, /* variavel que guarda a entrada do vencimento do boleto em questao*/
  dia_bol; /* variavel que guarda os dias do dia_inst ate o ven */ 
  time_t segundos; /* variavel para iniciar o struct tm */
  float valor; /* valor inicial, diario e final */ 

  time(&segundos); /* guarda os segundos atuais do pc */

  t = localtime(&segundos); /* inicializa o tempo */

  /* Inicializacao dos dias dos meses guardados na array */
  mon[0]= 31;
  mon[1]= t->tm_year % 4 == 0 ? 29 : 28;
  mon[2]= 31;
  mon[3]= 30;
  mon[4]= 31;
  mon[5]= 30;
  mon[6]= 31;
  mon[7]= 31;
  mon[8]= 30;
  mon[9]= 31;
  mon[10]= 30;
  mon[11]= 31;

  /* debug */
#ifdef DEBUG
  printf("O mes %d tem %d dias\n\n",t->tm_mon+1,mon[1]);
#endif
  
  /* while principal */
  while (1){
    printf("Qual o valor do servico? ");
    scanf("%f",&valor);
    valor /= 30;
#ifdef DEBUG
    printf("\nvalor: %.2f\n\n",valor);
#endif
    
    /* verificador do mes de instalacao */
    while(1){
    printf("Qual o mes da instalacao? ");
    scanf("%d",&mes);
    if (mes > 1 && mes < 13) break;
    else printf("Esse mes nao existe, insira novamente o mes!!!\n");
    }
#ifdef DEBUG
  PRINTD(mes);
#endif
    
  /* verificador do dia da instalacao */
    while(1){
    printf("Qual o dia da instalacao? ");
    scanf("%d",&dia_ins);
    if (dia_ins > 1 && dia_ins <= mon[mes-1]) break;
    else printf("Dia do mes nao existe! Insira Novamente\n");
    }
#ifdef DEBUG
    PRINTD(dia_ins);
#endif
    
    /* verificador do dia do vencimento */
    while(1){
    printf("Qual o dia do vencimento? ");
    scanf("%d",&ven);
    if (ven > 1 && ven <= 31) break;
    else printf("Dia Invalido!! Tente Novamente\n");
    }
#ifdef DEBUG
    PRINTD(ven);
#endif
    dia_bol = (mon[mes-1] - dia_ins) + ven;
#ifdef DEBUG
    printf("\n%d\n\n",dia_bol < 15);
#endif
    
    /* verifica se os dias eh menor que 15, se for pula um mes */
    if (dia_bol < 15) 
      dia_bol = ((mon[mes-1]+mon[mes]) - dia_ins) + ven;
#ifdef DEBUG
    PRINTD(dia_bol);
#endif
    valor *= dia_bol;
    printf("Quantidade de dias do boleto: %d\n", dia_bol);
    printf("O valor do primeiro boleto sera: %.2f\n\n",valor);
    
    /* flag */
    printf("Deseja continuar?[SIM/NAO] ");
    scanf("%s",v);
#ifdef DEBUG
    printf("\n%s\n\n",v);
#endif
    if (v[0] == 'n' || v[0] == 'N') break;
  }


  return 0;
}
