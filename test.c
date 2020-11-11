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
    char cidade[20];
    char candidatoPrefeito[20];
    char partidoPrefeito[20];
    char candidatoVereador[20];
    char partidoVereador[20];
};

int main()
{    
    //uso de ponteiros
    FILE* prefeito;
    FILE* vereador;
    FILE* voto;
    prefeito = fopen("prefeito.txt", "a");
    vereador = fopen("vereador.txt", "a");
    voto = fopen("voto.txt", "a");

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
    if(voto==NULL)
    {
        printf("Falha ao abrir o arquivo\n");
        return 4;
    }

    printf ("URNA ELETRONICA\n");

    long long cpfDigitado;
    printf ("Insira seu CPF\n");
    scanf("%lld", &cpfDigitado);  
   
    while (cpfDigitado < 1 || cpfDigitado > 99999999999) {
        
        printf ("Inválido! Insira seu CPF, com 11 números, sem pontos ou hífen\n");
        scanf("%lld", &cpfDigitado);
    }







//teste leitura

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



    fclose(prefeito);
    fclose(vereador);
    fclose(voto);

    return 0;
}



/* código (que repeti algumas vezes) para popular lista nos txt (obs.: uso Ubuntu):
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
