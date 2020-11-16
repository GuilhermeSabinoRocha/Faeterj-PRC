#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define MAX 20

struct prefeitoStruct
{
    char nome[20];
    int numeroCandidato;
    char partido[20];
    char cidade[20];
};

struct vereadorStruct
{
    char nome[20];
    int numeroCandidato;
    char partido[20];
    char cidade[20];
};

struct votoStruct
{
    long long cpf;
    char cidade[40];
    char candidatoPrefeito[40];
    // char partidoPrefeito[20];
    char candidatoVereador[40];
    // char partidoVereador[20];
};
// }criaVoto;

long long cpfDigitado;
char Prefeito[];
char partidoPrefeito[];
char Vereador[];
char partidoVereador[];
char cidade[];
int contadorVotosCandidatoA;
int contadorVotosCandidatoB;
int contadorVotosCandidatoC;
int contadorVotosCandidatoD;
int contadorVotosCandidatoE;
int contadorVotosCandidatoF;
int contadorVotosCandidatoG;
int contadorVotosCandidatoH;
int contadorVotosCandidatoI;
int contadorVotosCandidatoJ;
int contadorVotosCandidatoK;
int contadorVotosCandidatoL;
int contadorVotosCandidatoM;
int contadorVotosPartidoX;
int contadorVotosPartidoY;
int contadorVotosPartidoZ;
int contadorVotosPetropolis;
int contadorVotosTeresopolis;
int votoParaVereadorPetropolis;
int votoParaPrefeitoTeresopolis;
int votoParaVereadorTeresopolis;

int carregaVotacao();              
int votandoPetropolis(long long cpf);
int votoVereadorPetropolis(char Prefeito[],char partidoPrefeito[]);
int votandoTeresopolis(long long cpf);
int votoVereadorTeresopolis(char Prefeito[],char partidoPrefeito[]);
int registraVoto(char cidade[],char Prefeito[],char partidoPrefeito[],char Vereador[],char partidoVereador[] );
int relatorio();


int main()
{    
    printf ("URNA ELETRONICA\n");
     
     void menu() {
         printf("Digite 1 para votação, 2 para gerar relatório ou 3 para Sair: \n");
         int opcao;
         scanf("%d", &opcao);
         switch (opcao)
         {
            case 1:
                carregaVotacao();
                menu();
                break;

            case 2:
                relatorio();
                menu();
                break;

            case 3:
                break;
            
            default:
                break;
         }
     }

     menu();   

    return 0;


}

int carregaVotacao() { 
      
    printf ("Insira seu CPF\n");
    scanf("%lld", &cpfDigitado);  
   
    while (cpfDigitado < 1000000000 || cpfDigitado > 99999999999) {
        
        printf ("Inválido! Insira seu CPF, com 11 dígitos, sem pontos ou hífen\n");
        scanf("%lld", &cpfDigitado);
    } 
    //uso de ponteiros cfme escopo do trabalho
    FILE* voto = fopen("voto.txt", "r");  

    // checa por erro ao abrir arquivos
    if(voto==NULL)
    {
        printf("Falha ao abrir o arquivo\n");
        return 4;
    } 

    struct votoStruct votoMember;

    while(fread(&votoMember, sizeof(struct votoStruct), 1, voto)) {
        if (cpfDigitado == votoMember.cpf) {
            printf("Eleitor com voto já cadastrado!\n");
            return 0;
        } 
    }  

    fclose(voto);

    FILE* voto2 = fopen("voto.txt", "a"); 

    printf("Digite 1 para voto em Petropolis, ou 2 para voto em Teresopolis: \n");
        
    int opcao;
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            
            votandoPetropolis(cpfDigitado);
            break;

        case 2:
            votandoTeresopolis(cpfDigitado);
            break;
        
        default:
            break;
        }
   
    fclose(voto2);

    return 0;

}   

int relatorio() {

    //uso de ponteiros cfme escopo do trabalho
    
    FILE* voto3 = fopen("voto.txt", "r"); 

    // checa por erro ao abrir arquivos
    if(voto3==NULL)
    {
        printf("Falha ao abrir o arquivo\n");
        return 4;
    } 


    // struct votoStruct *relatorioPorCidade = malloc(sizeof(struct votoStruct));
    //  while(fread(&relatorioPorCidade, sizeof(struct votoStruct), 1, voto3)) {
    //     printf("%s", relatorioPorCidade->cidade);        
    // }     

    fclose(voto3);
    return 0;

}

int votandoPetropolis(long long cpf){
 printf("Escolha seu candidato a Prefeito\n");
 printf("Digite 1 para votar no candidato A, ou 2 para votar no candidato B: \n");
         int opcao;
         
         scanf("%d", &opcao);
         switch (opcao)
         {
            case 1:                
                Prefeito[0] = "A";
                partidoPrefeito[0] = "Z";
                votoVereadorPetropolis(Prefeito, partidoPrefeito);
                printf("Voto registrado com sucesso\n");
                return 0;
                break;

            case 2:
                Prefeito[0] = "B";
                partidoPrefeito[0] = "Y";
                votoVereadorPetropolis(Prefeito, partidoPrefeito);
                printf("Voto registrado com sucesso\n");
                return 0;
                break;
            
            default:
                break;
         }
        
     }

int votoVereadorPetropolis(char Prefeito[],char partidoPrefeito[]) {
 printf("Escolha seu candidato a Vereador\n");
 printf("Digite 1 para votar no candidato H, digite 2 para votar no candidato I, ou digite 3 para votar no candidato J: \n");
         int opcao;
         scanf("%d", &opcao);
         switch (opcao)
         {
            case 1:
                cidade[0] = "Petropolis ";
                Vereador[0] = "H";
                partidoVereador[0] = "Z";
                registraVoto(cidade,Prefeito,partidoPrefeito,Vereador,partidoVereador);                                
                printf("Voto registrado com sucesso\n");
                break;

            case 2:
                cidade[0] = "Petropolis ";
                Vereador[0] = "I";
                partidoVereador[0] = "Y";
                registraVoto(cidade,Prefeito,partidoPrefeito,Vereador,partidoVereador );                                
                printf("Voto registrado com sucesso\n");
                break;

            case 3:
                cidade[0] = "Petropolis ";
                Vereador[0] = "J";
                partidoVereador[0] = "X";
                registraVoto(cidade,Prefeito,partidoPrefeito,Vereador,partidoVereador );                                
                printf("Voto registrado com sucesso\n");
                break;
            
            default:
                break;
         }
     }

int votandoTeresopolis(long long cpf) {
    printf("Escolha seu candidato a Prefeito\n");
    printf("Digite 1 para votar no candidato C, ou 2 para votar no candidato D: \n");
         int opcao;
         scanf("%d", &opcao);
         switch (opcao)
         {
            case 1:
                printf("Voto registrado com sucesso\n");
                return "C";
                break;

            case 2:
                printf("Voto registrado com sucesso\n");
                return "D";
                break;
            
            default:
                break;
         }
     }

int votoVereadorTeresopolis(char Prefeito[],char partidoPrefeito[]) {
    printf("Escolha seu candidato a Vereador\n");
 printf("Digite 1 para votar no candidato K, digite 2 para votar no candidato L, ou digite 3 para votar no candidato M: \n");
         int opcao;
         scanf("%d", &opcao);
         switch (opcao)
         {
            case 1:
                printf("Voto registrado com sucesso\n");
                return "K";
                break;

            case 2:
                printf("Voto registrado com sucesso\n");
                return "L";
                break;

            case 3:
                printf("Voto registrado com sucesso\n");
                return "M";
                break;
            
            default:
                break;
         }

}

int registraVoto(char cidade[],char Prefeito[],char partidoPrefeito[],char Vereador[],char partidoVereador[]){
     FILE *voto6 = NULL;
struct votoStruct criaVoto;
    int i = 0;
    memset(&criaVoto, 0, sizeof(criaVoto));
    criaVoto.cpf = cpfDigitado;
    memcpy(criaVoto.cidade, cidade, 10);
    memcpy(criaVoto.candidatoPrefeito, Prefeito, 1);
    memcpy(criaVoto.candidatoVereador, Vereador, 1);

    //Open the file to write
    if ((voto6 = fopen("voto.txt", "a+")) == NULL) {
        printf("Error opening file to write\n");
        return -1;
    }
        fwrite(&criaVoto, sizeof(criaVoto), 1, voto6);
   
    fclose(voto6);
    
// struct votoStruct votoTeste;
// if ((voto5 = fopen("voto.txt", "r")) == NULL) {
//         printf("Error opening file for read\n");
//         return -1;
//     }
//  while(fread(&votoTeste, sizeof(struct votoStruct), 1, voto5))
//     {
//         fread(&votoTeste, sizeof(votoTeste), 1, voto5);
        
//         if (1)
//         {
//         printf("%lld\t%s\t%s\t%s\n", votoTeste.cpf, votoTeste.cidade, votoTeste.candidatoPrefeito, votoTeste.candidatoVereador);
//             /* code */
//         }

//     }
//          fclose(voto5);
}
