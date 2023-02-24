typedef struct {
int numconta;
char cpf[13];
int saldo;
} cliente;

typedef struct {
cliente totalclientes[100];
} sistema;

void lerdados (FILE *entrada){
int i, opc;
cliente registra;

entrada = fopen("contas.dat", "ab");
if (entrada == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
for(i = 0; i < 100; i++){
fflush(stdin);
    printf("Digite o numero da conta: ");
    scanf("%d", &registra.numconta);
fflush(stdin);
    printf("Digite o CPF da Conta: ");
    fgets(registra.cpf, 13, stdin);
fflush(stdin);
    printf("Digite o saldo da conta: ");
    scanf("%d", &registra.saldo);

   fwrite(&registra, sizeof(cliente), 1, entrada);
printf("Digite 1 para encerrar ou qualquer outra tecla para continuar.");
scanf("%d",&opc);
if (opc == 1){
break;
}
}
}
fclose(entrada);
}

void excluicliente (FILE *entrada){
int numconta;
int i, encontrado = 0;
FILE *entradatemp;
cliente registroatual;

entrada = fopen("contas.dat", "rb");
entradatemp = fopen("contastemp.dat", "wb");

if (entrada == NULL){
printf("\nO arquivo tem de ser criado!");
}

fflush(stdin);
printf("Digite o numero da conta que deseja remover: ");
scanf("%d", &numconta);

for(i = 0; i < 100; i++){
while (fread(&registroatual, sizeof(cliente), 1, entrada) == 1) {
        if (registroatual.numconta == numconta) {
          registroatual.numconta = 0;
        } else {
            encontrado = 1;
        }
        fwrite(&registroatual, sizeof(cliente), 1, entradatemp);
    }
}
fclose(entradatemp);
fclose(entrada);

remove("contas.dat");
rename("contastemp.dat","contas.dat");

    if (encontrado) {
        fflush(stdin);
        printf("Conta anulada com sucesso!\n");
    } else {
        fflush(stdin);
        printf("Conta nao foi encontrada.\n");
    }
}

void relatorio (FILE *entrada){
int i, aux = 0;
cliente registroatual;

entrada = fopen("contas.dat", "rb");

if (entrada == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
printf("Listagem dos Contatos:");

while (!feof(entrada)){
aux = fread(&registroatual, sizeof(cliente), 1, entrada);
if (aux){
printf("Numero da Conta: %d", registroatual.numconta);
printf("\nCPF: %s\n", registroatual.cpf);
printf("Saldo: %d\n", registroatual.saldo);
}
}
fclose(entrada);
}
}

void devedores (FILE *entrada){
int encontrado = 0;
cliente registroatual;

entrada = fopen ("contas.dat","rb");


while (fread(&registroatual, sizeof(cliente), 1, entrada) == 1) {
        if (registroatual.saldo < 0) {
        printf("Numero da Conta: %d", registroatual.numconta);
        printf("\nCPF: %s\n", registroatual.cpf);
        printf("Saldo: %d\n", registroatual.saldo);
            break;
            encontrado = 1;
        }
        if (!encontrado) {
        printf("Contato nao foi encontrado!\n");
        break;
    }
    }
fclose(entrada);
}

void otimiza (FILE *entrada){
char nome[81];
int i, encontrado = 0;
FILE *entradatemp;
cliente registroatual;

entrada = fopen("contas.dat", "rb");
entradatemp = fopen("contastemp.dat", "wb");

if (entrada == NULL){
printf("\nO arquivo tem de ser criado!");
}

for(i = 0; i < 100; i++){
while (fread(&registroatual, sizeof(cliente), 1, entrada) == 1) {
        if (registroatual.numconta != 0) {
            fwrite(&registroatual, sizeof(cliente), 1, entradatemp);
        } else {
            encontrado = 1;
        }
    }
}
fclose(entradatemp);
fclose(entrada);

remove("contas.dat");
rename("contastemp.dat","contas.dat");

    if (encontrado) {
        fflush(stdin);
        printf("Contato removido com sucesso!\n");
    } else {
        fflush(stdin);
        printf("Contato nao encontrado.\n");
    }
}

void depositaresacar (FILE *entrada){
int numconta, quantia, escolha;
int i, encontrado = 0;
FILE *entradatemp;
cliente novoregistro;

entrada = fopen("contas.dat", "rb");
entradatemp = fopen("contastemp.dat", "wb");

if (entrada == NULL){
printf("\nO arquivo tem de ser criado!");
}

fflush(stdin);
printf("Digite o numero da conta que deseja depositar ou sacar: ");
scanf("%d", &numconta);
fflush(stdin);
printf("Depositar (1) ou Sacar (2)?: ");
scanf("%d", &escolha);
fflush(stdin);
printf("Quantia?: ");
scanf("%d", &quantia);

for(i = 0; i < 100; i++){
while (fread(&novoregistro, sizeof(novoregistro), 1, entrada) == 1) {
        if (escolha == 1 && novoregistro.numconta == numconta) {
        novoregistro.saldo = novoregistro.saldo+quantia;
          encontrado = 1;
        }
        else if (escolha == 2 && novoregistro.numconta == numconta) {
         novoregistro.saldo = novoregistro.saldo-quantia;
            encontrado = 1;
        } else if (novoregistro.numconta != numconta) {
            printf("Conta nao foi encontrada.\n");
        }
          fwrite(&novoregistro, sizeof(novoregistro), 1, entradatemp);
    }
}
fclose(entradatemp);
fclose(entrada);

remove("contas.dat");
rename("contastemp.dat","contas.dat");

    if (encontrado = 1 || encontrado > 1) {
        fflush(stdin);
        printf("Operacao realizada com sucesso!\n");
    } else if (encontrado = 0) {
        fflush(stdin);
        printf("Conta nao foi encontrada.\n");
    }
}
