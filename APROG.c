#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
#include "colors.h"

void by()
{
    printf("*********************************************\n");
    printf("**            Progecto  Aprog              **\n");
    printf("**                                         **\n");
    printf("**        Tiago Ribeiro  1161053           **\n");
    printf("**        Sangueve Pedro 1160555           **\n");
    printf("**        Joao Neves     1160775           **\n");
    printf("**                                         **\n");
    printf("*********************************************\n");


    printf("\n\n");
    system("pause");
}


//Estruturas

typedef struct deputados{ //variavel global
    int codigo;
    char partido_sig[MAX];
    char nome_deputado[MAX];
    char genero;
    char circuloleitoral[MAX];
} tipo_deputado;
typedef struct partidos{ //variavel global
    char sigla[MAX];
    char nome_partido[MAX];
    int qtd_deputados;
    tipo_deputado conj_deputados[MAX];
} tipo_partido;
typedef struct parlamento{ //variavel global
    char nome_pais[MAX];
    tipo_partido conj_partidos[MAX];
} tipo_parlamento;


//-----X-----


//Funções auxiliares

int valiintervalo(int linf, int lsup){
    int num;
    do{
        foreground(GREEN);
        printf("\nIntroduza um valor entre %d e %d: ", linf, lsup);
        scanf("%d",&num);
        style(RESETALL);
    }
    while (num<linf || num>lsup);

return num;
}
int pesquisarsigla (char sigla[],tipo_parlamento parlamento,int cont_partidos){
    int resp=0, i;

    for(i=0; resp==0 && i<cont_partidos; i++){
        if(strcmp(sigla,parlamento.conj_partidos[i].sigla)==0)
            resp=1;
    }
    if (resp==1)
        return i-1;
    else
        return -1;
};
int s_n(){
    int s_n1;
    do{
        foreground(GREEN);
        printf("1 - Sim\n2 - Nao\n");
        fflush(stdin);
        style(RESETALL);
        scanf("%d", &s_n1);
        if (s_n1!=1&&s_n1!=2)
            foreground(RED);
            printf("Opcao invalida! \n");
            style(RESETALL);
    }
    while (s_n1!=1&&s_n1!=2);

    if(s_n1==1) return 1; //1- Sim
    else return 0; //0- Não

}


//-----X-----


//Funções Operárias

char menu(){

    char resp;

    do
    {
        system("cls");
        foreground(GREEN);
        style(BRIGHT);
        printf("------x------x-Menu Principal-x------x------\n\n");
        printf("Selecione uma das opcoes:\n");
        printf("1 - Inserir informacao \n");
        printf("2 - Eliminar informacao \n");
        printf("3 - Mostrar informacao \n");
        printf("4 - Sair \n\n");
        style(RESETALL);
        fflush(stdin);
        scanf("%c", &resp);
        if(resp!='1'&&resp!='2'&&resp!='3'&&resp!='4')
        {
            foreground(RED);
            printf("\n***Opcao Invalida!***\n\n");
            style(RESETALL);
            system("\npause");
        }
    }
    while (resp!='1'&& resp!='2' && resp!='3'&&resp!='4');

return resp;
}
void inserir_inf(tipo_deputado deputado_add[],int *cont_deputados ){
    char resp;
    int n,i,j,resp1, s_n1;


voltar:
    do{
        system("cls");
        foreground(BLUE);
        style(BRIGHT);
        printf("------x------x-Menu inserir-x------x------\n");
        printf("Em que setor deseja inserir informacao?:\n");
        printf("1 - Deputados\n");
        printf("2 - Partidos\n");
        printf("3 - Parlamento\n");
        printf("4 - Voltar ao menu principal\n\n");
        style(RESETALL);
        fflush(stdin);
        scanf("\n %c", &resp);
        if(resp!='1'&&resp!='2'&&resp!='3'&&resp!='4')
        {
            foreground(RED);
            printf("\n***Opcao Invalida!***\n\n");
            style(RESETALL);
            system("\npause");
        }

    }
    while(resp!='1'&&resp!='2'&&resp!='3'&&resp!='4');

    switch (resp){
        case ('1'):
            {
                system("cls");
                foreground(GREEN);
                printf("Quantos deputados deseja adicionar?");
                style(RESETALL);
                n=valiintervalo(0,MAX);
                for(j=0;j<n;j++){
                    i=*cont_deputados+1;
                    foreground(BLUE);
                    style(BRIGHT);
                    printf("Nome?\n");
                    foreground(MARGENTA);
                    fflush(stdin);
                    gets(deputado_add[i].nome_deputado);
                    foreground(BLUE);
                    style(BRIGHT);
                    printf("Genero?\n");
                    foreground(MARGENTA);
                    fflush(stdin);
                    scanf("%c", &deputado_add[i].genero);
                    foreground(BLUE);
                    style(BRIGHT);
                    printf("Partido?\n");
                    foreground(MARGENTA);
                    fflush(stdin);
                    gets(deputado_add[i].partido_sig);
                    foreground(BLUE);
                    style(BRIGHT);
                    printf("Circulo eleitoral?\n");
                    foreground(MARGENTA);
                    fflush(stdin);
                    gets(deputado_add[i].circuloleitoral);
                    foreground(RED);
                    printf("Tem certeza que deseja adicionar este deputado?\n");
                    style(RESETALL);
                    resp1=s_n();
                    if(resp1==1){
                        *cont_deputados+=1;
                        deputado_add[i].codigo=i;
                        //alterar a quantidade de deputados (qts_deputados), no partido introsuzido
                        foreground(GREEN);
                        printf("\nDeputado adicionado com sucesso! (codigo atribuido: %d\n)", deputado_add[i].codigo);
                        style(RESETALL);
                    }

                    system("pause");

                }

                system("cls");
                foreground(BLUE);
                style(BRIGHT);
                printf("\nDeseja voltar ao menu anterior?:\n\n");
                style(RESETALL);
                s_n1=s_n();
                if (s_n1==1)
                    goto voltar;
                else
                    foreground(GREEN);
                    printf("Obrigado pela preferencia, e ate Breve :)");
                    printf("\n-------------------------------------------------------------------");
                    style(RESETALL);
                    break;
            }
        case ('2'):
            {
                system("cls");
                foreground(MARGENTA);
                printf("Quantos partidos deseja adicionar?(entre 0 e MAX");
                style(RESETALL);
                n=valiintervalo(0,MAX);

               break;
            }
        case ('3'):
            {
                system("cls");
                //????-Sang
                foreground(MARGENTA);
                printf("Quantos parlamentos deseja adicionar?(entre 0 e MAX");
                style(RESETALL);
                n=valiintervalo(0,MAX);

               break;
            }
        case ('4'):
            {
                return ;
            }

    }




}
void mostrar_inf(int cont_partidos,int cont_deputados, tipo_parlamento parlamento){

    char resp, carac, matchsigla[MAX], sigla[MAX];
    int i=0,j=0,k=0,l=0, m=0, cont_fem,cont_fem1 ,  qtd, sigresp, s_n1;
    float a1,perc_fem,percentagemf;
    cont_fem=0;
    voltar:
    do{
        system("cls");
        foreground(BLUE);
        style(BRIGHT);
        printf("------x------x-Menu Mostrar-x------x------\n\n");
        printf("O que deseja visualizar?:\n");
        printf("1 - Quantidade de  deputados num dado partido \n");
        printf("2 - Partidos que constituem o parlamento \n");
        printf("3 - Estatistica sobre o parlamento \n");
        printf("4 - Voltar ao menu principal\n\n");
        style(RESETALL);
        fflush(stdin);
        scanf("\n %c", &resp);
        if(resp!='1'&&resp!='2'&&resp!='3'&&resp!='4')
        {
            foreground(RED);
            printf("\n***Opcao Invalida!***\n\n");
            style(RESETALL);
            system("\npause");
        }

    }
    while (resp!='1'&& resp!='2' && resp!='3'&& resp!='4');
    switch (resp){

        case ('1'): //check! -Sang
            {
                do{
                    system("cls");
                    foreground(BLUE);
                    style(BRIGHT);
                    printf("Introduza a sigla de um partido existente: \n");
                    printf("Partidos existentes: \n");
                    style(RESETALL);
                    for(k=0;k<cont_partidos;k++){
                        foreground(MARGENTA);
                        printf("%s\n", parlamento.conj_partidos[k].sigla);
                    }
                    foreground(RED);
                    printf("\n*E feita uma diferenciacao entre maisculas e minusculas");
                    printf("\n(Ex: Zeus!=zeus!=ZEUS)\n\n");
                    foreground(MARGENTA);
                    scanf("%s", &sigla);
                    style(RESETALL;)
                    sigresp=pesquisarsigla(sigla, parlamento, cont_partidos);
                    if(sigresp==-1)
                        foreground(RED);
                        printf("\nEsta sigla nao corresponde a nenhum partido existente!\n");
                        foreground(BLUE);
                        style(BRIGHT);
                        printf("Prima qualquer tecla para reentroduzir a sigla.\n\n");
                        style(RESETALL);
                        system("pause");
                }
                while(sigresp==-1); // -1 -Não existe
                foreground(BLUE);
                style(BRIGHT);
                printf("\nNo partido %s estao inscritos %d deputados\n\n\n", sigla, parlamento.conj_partidos[sigresp].qtd_deputados);
                style(RESETALL);
                system("Pause");

                system("cls");
                foreground(MARGENTA);
                printf("\nDeseja voltar ao menu anterior?:\n");
                style(RESETALL);
                s_n1=s_n();
                if (s_n1==1)
                    goto voltar;
                else
                    foreground(GREEN);
                    style(BRIGHT);
                    printf("Obrigado pela preferencia, e ate Breve :)");
                    printf("\n-------------------------------------------------------------------");
                    style(RESETALL);
                    break;
            }
        case ('2'): //check! -Sang
            {
                system("cls");
                foreground(GREEN);
                printf("\nDe momento o parlamento tem %d partidos\n\n", cont_partidos);
                printf("Sendo estes:\n");
                for(i=0;i<cont_partidos;i++){
                    foreground(BLUE);
                    printf("%s", parlamento.conj_partidos[i].nome_partido);printf("(%s)\n", parlamento.conj_partidos[i].sigla);
                }
                style(RESETALL);
                printf("\n\n");
                system("Pause");

                system("cls");
                foreground(MARGENTA);
                style(BRIGHT);
                printf("\nDeseja voltar ao menu anterior?:\n");
                style(RESETALL);
                s_n1=s_n();
                if (s_n1==1)
                    goto voltar;
                else
                    foreground(GREEN);
                    style(BRIGHT);
                    printf("Obrigado pela preferencia, e ate Breve :)");
                    printf("\n-------------------------------------------------------------------");
                    break;

               break;
            }
        case ('3'): //check! -Sang
            {
                system("cls");

                foreground(YELLOW);
                style(BRIGHT);
                printf("---**---Estatistica---**---\n\n");
                foreground(BLUE);
                style(BRIGHT);
                printf("%d deputados no parlamento\n\n", cont_deputados);
                foreground(MARGENTA);
                style(BRIGHT);
                printf("Distribuidos da seguinte forma:\n");
                for(m=0;m<cont_partidos;m++)
                    {
                    foreground(YELLOW);
                    style(BRIGHT);
                    qtd=parlamento.conj_partidos[m].qtd_deputados;
                    printf("No partido %s : ", parlamento.conj_partidos[m].sigla);
                    a1=qtd*100.0/cont_deputados;
                    printf("%d ",qtd);printf("(%.2f%%)\n", a1);
                    }


                for(j=0;j<cont_partidos;j++)
                    {
                    for(l=0;l<parlamento.conj_partidos[j].qtd_deputados;l++)
                        {
                            if(parlamento.conj_partidos[j].conj_deputados[l].genero=='F')
                            {
                                cont_fem=cont_fem+1;
                            }
                        }
                    }
                cont_fem1=cont_fem;
                percentagemf=(cont_fem1*100.0)/cont_deputados;
                foreground(GREEN);
                style(BRIGHT);
                printf("\nNo parlamento existem %d deputados do sexo feminino", cont_fem1);
                printf("(%.2f%%)\n", percentagemf);
                printf("\n\n");
                style(RESETALL);
                system("Pause");

                system("cls");
                foreground(BLUE);
                style(BRIGHT);
                printf("Deseja voltar ao menu anterior?:\n");
                s_n1=s_n();
                if (s_n1==1)
                    goto voltar;
                else
                    foreground(GREEN);
                    style(BRIGHT);
                    printf("Obrigado pela preferencia, e ate Breve :)");
                    printf("\n-------------------------------------------------------------------");
                    style(RESETALL);
                    break;
            }
        case ('4'):
            {
               return ;

            }

    }

}
void eliminar_inf(int cont_partidos,int cont_deputados, tipo_parlamento parlamento){

    int resp;
    int c,x,k=1;
    do{
        system("cls");
        foreground(GREEN);
        style(BRIGHT);
        printf("------x------x-Menu Eliminar-x------x------\n\n");
        printf("Em que setor deseja eliminar informacao?:\n");
        printf("1 - Deputados\n");
        printf("2 - Partidos\n");
        printf("3 - Parlamento\n");
        printf("4 - Voltar ao menu principal\n\n");
        fflush(stdin);
        scanf("%d", &resp);
        if(resp!=1&&resp!=2&&resp!=3&&resp!=4)
        {
            foreground(RED);
            printf("\n***Opcao Invalida!***\n\n");
            style(RESETALL);
            system("\npause");
        }
    }
    while(resp!=1&&resp!=2&&resp!=3&&resp!=4);

    switch (resp){

        case (1):
            {

                system("cls");
                foreground(BLUE);
                style(BRIGHT);
                printf("Estes sao os deputados atualmente inscritos:\n\n");
                for(c=0;c<cont_partidos;c++)
                {
                    for(x=0;x<parlamento.conj_partidos[c].qtd_deputados;x++)
                    {
                        foreground(MARGENTA);
                        style(BRIGHT);
                        printf("%s-----", parlamento.conj_partidos[c].conj_deputados[x].nome_deputado);
                        printf("%d\n",k);
                        k=k+1;
                        style(RESETALL);


                    }
                }
                foreground(RED);
                style(BRIGHT);
                printf("\nQual deseja eliminar?\n");
                style(RESETALL);
               break;
            }
        case (2):
            {
                system("cls");

               break;
            }
        case (3):
            {
                system("cls");

               break;
            }
        case (4):
            {

                return ;
            }

    }
}


//-----X-----

//Main
int main(){

    char resp, sigla[MAX];
    int cont_partidos, cont_deputados;
    tipo_parlamento parlamento;
    tipo_partido partido[MAX];
    tipo_deputado deputado[MAX];


{ //inicializações


    //inicialização deputados
    deputado[0].codigo=1;strcpy(deputado[0].partido_sig,"Zeus");strcpy(deputado[0].nome_deputado,"Hercules");deputado[0].genero='M';strcpy(deputado[0].circuloleitoral,"Aveiro");
    deputado[1].codigo=2;strcpy(deputado[1].partido_sig,"Zeus");strcpy(deputado[1].nome_deputado,"Hermes");deputado[1].genero='F';strcpy(deputado[1].circuloleitoral,"Porto");
    deputado[2].codigo=3;strcpy(deputado[2].partido_sig,"Zeus");strcpy(deputado[2].nome_deputado,"Morfeu");deputado[2].genero='M';strcpy(deputado[2].circuloleitoral,"Braga");
    deputado[3].codigo=4;strcpy(deputado[3].partido_sig,"Zeus");strcpy(deputado[3].nome_deputado,"Pan");deputado[3].genero='F';strcpy(deputado[3].circuloleitoral,"Lisboa");
    deputado[4].codigo=5;strcpy(deputado[4].partido_sig,"Atenas");strcpy(deputado[4].nome_deputado,"Heracles");deputado[4].genero='M';strcpy(deputado[4].circuloleitoral,"Evora");
    deputado[5].codigo=6;strcpy(deputado[5].partido_sig,"Atenas");strcpy(deputado[5].nome_deputado,"Eolo");deputado[5].genero='M';strcpy(deputado[5].circuloleitoral,"Coimbra");
    deputado[6].codigo=7;strcpy(deputado[6].partido_sig,"Atenas");strcpy(deputado[6].nome_deputado,"Asclepio");deputado[6].genero='F';strcpy(deputado[6].circuloleitoral,"Viseu");
    deputado[7].codigo=8;strcpy(deputado[7].partido_sig,"Atenas");strcpy(deputado[7].nome_deputado,"Ares");deputado[7].genero='F';strcpy(deputado[7].circuloleitoral,"Beja");
    deputado[8].codigo=9;strcpy(deputado[8].partido_sig,"Hades");strcpy(deputado[8].nome_deputado,"Apolo");deputado[8].genero='M';strcpy(deputado[8].circuloleitoral,"Faro");
    deputado[9].codigo=10;strcpy(deputado[9].partido_sig,"Hades");strcpy(deputado[9].nome_deputado,"Boreas");deputado[9].genero='F';strcpy(deputado[9].circuloleitoral,"Castelo Branco");
    deputado[10].codigo=11;strcpy(deputado[10].partido_sig,"Hades");strcpy(deputado[10].nome_deputado,"Dionisio");deputado[10].genero='M';strcpy(deputado[10].circuloleitoral,"Leiria");
    deputado[11].codigo=12;strcpy(deputado[11].partido_sig,"Hades");strcpy(deputado[11].nome_deputado,"Hefesto");deputado[11].genero='M';strcpy(deputado[11].circuloleitoral,"Setubal");



    //inicialização partidos
    strcpy(partido[0].sigla,"Zeus");strcpy(partido[0].nome_partido,"Partido Autoritario");partido[0].qtd_deputados=4;partido[0].conj_deputados[0]=deputado[0];partido[0].conj_deputados[1]=deputado[1];partido[0].conj_deputados[2]=deputado[2];partido[0].conj_deputados[3]=deputado[3];
    strcpy(partido[1].sigla,"Atenas");strcpy(partido[1].nome_partido,"Partido Sabio");partido[1].qtd_deputados=4;partido[1].conj_deputados[0]=deputado[4];partido[1].conj_deputados[1]=deputado[5];partido[1].conj_deputados[2]=deputado[6];partido[1].conj_deputados[3]=deputado[7];
    strcpy(partido[2].sigla,"Hades");strcpy(partido[2].nome_partido,"Partido Verossimil");partido[2].qtd_deputados=4;partido[2].conj_deputados[0]=deputado[8];partido[2].conj_deputados[1]=deputado[9];partido[2].conj_deputados[2]=deputado[10];partido[2].conj_deputados[3]=deputado[11];

    //inicialização Parlamento
    strcpy(parlamento.nome_pais,"Olimpo");
    parlamento.conj_partidos[0]=partido[0];
    parlamento.conj_partidos[1]=partido[1];
    parlamento.conj_partidos[2]=partido[2];

    //Início do programa
    cont_deputados=12;
    cont_partidos=3;

}
by();
inicio:
    resp=menu();

    switch (resp){

        case('1'):
            inserir_inf(deputado, &cont_deputados);
            goto inicio;
            break;
        case ('2'):
            eliminar_inf(cont_partidos,cont_deputados, parlamento);
            break;
        case ('3'):
            mostrar_inf(cont_partidos,cont_deputados, parlamento);
            goto inicio;
            break;
         case ('4'):
            foreground(GREEN);
            style(BRIGHT);
            printf("Obrigado pela preferencia, e ate Breve :)");
            printf("\n-------------------------------------------------------------------");
            style(RESETALL);
            break;
    }


return 0;
}
