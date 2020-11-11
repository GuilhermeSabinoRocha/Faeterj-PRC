#include <stdio.h>
#include <stdlib.h>

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
    char* cidade;
    char* candidatoPrefeito;
    // char partidoPrefeito[20];
    char* candidatoVereador;
    // char partidoVereador[20];
};

long long cpfDigitado;
char* votoParaPrefeitoPetropolis;
char* votoParaVereadorPetropolis;
char* votoParaPrefeitoTeresopolis;
char* votoParaVereadorTeresopolis;

int carregaVotacao();              
char* votoPrefeitoPetropolis();
char* votoVereadorPetropolis();
char* votoPrefeitoTeresopolis();
char* votoVereadorTeresopolis();
int relatorio();


int main()
{    
    printf ("URNA ELETRONICA\n");

// //código para incluir voto
//     FILE* voto5 = fopen("voto.txt", "a"); 
// struct votoStruct votoMember = {11652341579, "Petropolis", "A", "H"};

// fwrite(&votoMember, sizeof(votoMember), 1, voto5);

//      fclose(voto5);
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

// FILE* voto4 = fopen("voto.txt", "r");
// char* test;
// struct votoStruct votoMember;
//      while(fread(&votoMember, sizeof(struct votoStruct), 1, voto4)) {
//         fscanf(voto4,"%s", test);
//         printf("%s", test);
        
//     }     
//     fclose(voto4);  

//teste leitura
// printf("%lld", votoMember.cpf);

    // struct prefeitoStruct prefeitoMember;
    // prefeito = fopen("prefeito.txt", "r");
    // struct vereadorStruct vereadorMember;
    // vereador = fopen("vereador.txt", "r");

    // while(fread(&prefeitoMember, sizeof(struct prefeitoStruct), 1, prefeito)) 
    //     printf ("%s", prefeitoMember.nome); 
    //     printf ("%s", prefeitoMember.partido); 

    //     while(fread(&vereadorMember, sizeof(struct vereadorStruct), 1, vereador)) 
    //     printf ("%s", vereadorMember.nome); 
    //     printf ("%s", vereadorMember.partido);     

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

// printf("%lld", votoMember.cpf);
    // fread(&votoMember, sizeof(struct votoStruct), 1, voto);

    fclose(voto);

    FILE* voto2 = fopen("voto.txt", "a"); 

    printf("Digite 1 para voto em Petropolis, ou 2 para voto em Teresopolis: \n");
    
    struct votoStruct votoRegistrado;
    int opcao;
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            votoRegistrado.cpf = cpfDigitado;
            votoRegistrado.cidade = "Petropolis";
            votoParaPrefeitoPetropolis = votoPrefeitoPetropolis();
            votoParaVereadorPetropolis = votoVereadorPetropolis();
            votoRegistrado.candidatoPrefeito = votoParaPrefeitoPetropolis;            
            votoRegistrado.candidatoVereador = votoParaVereadorPetropolis;
            fwrite(&votoRegistrado, sizeof(votoRegistrado), 1, voto);


            break;

        case 2:
            votoPrefeitoTeresopolis();
            votoVereadorTeresopolis();
            break;
        
        default:
            break;
        }
   
    fclose(voto2);

    return 0;

}   

int relatorio() {

    //uso de ponteiros cfme escopo do trabalho
    
    FILE* prefeito = fopen("prefeito.txt", "r");
    FILE* vereador = fopen("vereador.txt", "r");
    FILE* voto3 = fopen("voto.txt", "r"); 

    // checa por erro ao abrir arquivos
    if(prefeito==NULL)
    {
        printf("Falha ao abrir o arquivo\n");
        return 2;
    }
    if(vereador==NULL)
    {
        printf("Falha ao abrir o arquivo\n");
        return 3;
    }
    if(voto3==NULL)
    {
        printf("Falha ao abrir o arquivo\n");
        return 4;
    } 

    struct prefeitoStruct prefeitoMember;
    struct vereadorStruct vereadorMember;

    fread(&prefeitoMember, sizeof(struct prefeitoStruct), 1, prefeito);
    fread(&vereadorMember, sizeof(struct vereadorStruct), 1, vereador);
    fclose(prefeito);
    fclose(vereador);
    fclose(voto3);

}

char* votoPrefeitoPetropolis(){
 printf("Escolha seu candidato a Prefeito\n");
 printf("Digite 1 para votar no candidato A, ou 2 para votar no candidato B: \n");
         int opcao;
         scanf("%d", &opcao);
         switch (opcao)
         {
            case 1:
                printf("Voto registrado com sucesso\n");
                return "A";
                break;

            case 2:
                printf("Voto registrado com sucesso\n");
                return "B";
                break;
            
            default:
                break;
         }
        
     }

char* votoVereadorPetropolis() {
 printf("Escolha seu candidato a Vereador\n");
 printf("Digite 1 para votar no candidato H, digite 2 para votar no candidato I, ou digite 3 para votar no candidato J: \n");
         int opcao;
         scanf("%d", &opcao);
         switch (opcao)
         {
            case 1:
                printf("Voto registrado com sucesso\n");
                return "H";
                break;

            case 2:
                printf("Voto registrado com sucesso\n");
                return "I";
                break;

            case 3:
                printf("Voto registrado com sucesso\n");
                return "J";
                break;
            
            default:
                break;
         }
     }

char* votoPrefeitoTeresopolis() {
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

char* votoVereadorTeresopolis() {
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

/* código (que repeti algumas vezes) para popular lista nos txt (obs:eu uso Ubuntu):
struct prefeitoStruct prefeitoMember = {"E", 4, "Y", "Teresopolis"};
struct vereadorStruct vereadorMember = {"M", 16, "X", "Teresopolis"};

fwrite(&prefeitoMember, sizeof(prefeitoMember), 1, prefeito);
fwrite(&vereadorMember, sizeof(vereadorMember), 1, vereador);

struct votoStruct votoMember = {11652341579, "Petropolis", "B", "Y", "I", "Y"};

fwrite(&votoMember, sizeof(votoMember), 1, voto);

     fclose(prefeito);
     fclose(vereador);
     fclose(voto);
     */