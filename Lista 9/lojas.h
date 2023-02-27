typedef struct{
int numregistro;
char nome[20];
float preco;
} item;

typedef struct{
item itemdisp[200];
int qtddoitem[200];
int cnpj;
int numloja;
} estoque;

typedef struct{
estoque totalrede[200];
int totalestoque;
} rede;

void cadprodutos (FILE *entrada){
int i, opc;
item cadastra;

entrada = fopen("itens.dat", "ab");
if (entrada == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
for(i = 0; i < 200; i++){
fflush(stdin);
    printf("Digite o numero de registro do produto: ");
    scanf("%d", &cadastra.numregistro);
fflush(stdin);
    printf("Digite o nome do produto: ");
    scanf("%s", &cadastra.nome);
fflush(stdin);
    printf("Digite o preco do produto: ");
    scanf("%f", &cadastra.preco);

   fwrite(&cadastra, sizeof(item), 1, entrada);
printf("Digite 1 para encerrar ou qualquer outra tecla para continuar.");
scanf("%d",&opc);
if (opc == 1){
break;
}
}
}
fclose(entrada);
}

item ler_item(FILE* entrada) {
    item insere2;
    fread(&insere2, sizeof(item), 1, entrada);
    return insere2;
}

void escrever_estoque(FILE* entraux, estoque auxilia) {
    fwrite(&auxilia, sizeof(estoque), 1, entraux);
}

void escrever_itemestoque(FILE* entraux, item auxilia) {
entraux = fopen ("estoque.dat","ab");
fwrite(&auxilia, sizeof(item), 1, entraux);
}

void inserirestoque (FILE *entrada2){
int opc;
item insere2;
estoque insere;
char nomeprod[20];
FILE *entrada;

    printf("Digite o numero da loja a ter o produto inserido: ");
    scanf("%d", &insere.numloja);
    printf("Digite o CNPJ a ter o produto inserido: ");
    scanf("%d", &insere.cnpj);

    entrada = fopen("itens.dat", "rb");
    entrada2 = fopen("estoque.dat", "ab");

    int i = 0;
    while (i < 200) {
        insere2 = ler_item(entrada);
        if (insere2.numregistro == 0) {
            break;
        }
        insere.itemdisp[i] = insere2;
        printf("Digite a quantidade disponivel do produo %s na loja: ", insere2.nome);
        scanf("%d", &insere.qtddoitem[i]);
        i++;
        fflush(stdin);
        printf("Digite 1 para encerrar ou qualquer outra tecla para continuar.");
scanf("%d",&opc);
if (opc == 1){
break;
}
    }


    escrever_estoque(entrada2,insere);
    escrever_itemestoque(entrada2,insere2);

    fclose(entrada);
    fclose(entrada2);
}

void realizarvenda (FILE *entrada){
int numregisvend, numloja;
int i, encontrado = 0;
FILE *entradatemp, *entradaaux;
item venda;
estoque controleprod;

entradaaux = fopen("itens.dat", "rb");
entrada = fopen("estoque.dat", "rb");
entradatemp = fopen("estoquetemp.dat", "wb");

if (entrada == NULL){
printf("\nO arquivo tem de ser criado!");
}

fflush(stdin);
printf("Digite o numero do registro vendido: ");
scanf("%d", &numregisvend);
fflush(stdin);
printf("Digite o numero da loja que realizou a venda: ");
scanf("%d", &numloja);

for(i = 0; i < 200; i++){
while (fread(&venda, sizeof(venda), 1, entradaaux) == 1 && fread(&controleprod, sizeof(controleprod), 1, entrada) == 1) {
        if (venda.numregistro == numregisvend && controleprod.numloja == numloja) {
        controleprod.qtddoitem[i] = controleprod.qtddoitem[i]-1;
          encontrado = 0;
        } else {
            encontrado = 1;
        }
          fwrite(&controleprod, sizeof(controleprod), 1, entradatemp);
    }
}
fclose(entradatemp);
fclose(entrada);
fclose(entradaaux);

remove("estoque.dat");
rename("estoquetemp.dat","estoque.dat");

    if (encontrado) {
        fflush(stdin);
        printf("Operacao realizada com sucesso!\n");
    } else {
        fflush(stdin);
        printf("Conta nao foi encontrada.\n");
    }
}

void atualizaprod (FILE *entrada){
int numregisprod;
float novopreco;
int i, encontrado = 0;
FILE *entradatemp;
item localiza;

entrada = fopen("itens.dat", "rb");
entradatemp = fopen("itenstemp.dat", "wb");

if (entrada == NULL){
printf("\nO arquivo tem de ser criado!");
}

fflush(stdin);
printf("Digite o numero do registro do item a ser atualizado: ");
scanf("%d", &numregisprod);
fflush(stdin);
printf("Digite a quantia que deseja incrementar ao preco: ");
scanf("%f", &novopreco);

for(i = 0; i < 200; i++){
while (fread(&localiza, sizeof(localiza), 1, entrada) == 1) {
        if (localiza.numregistro == numregisprod) {
        localiza.preco = localiza.preco+novopreco;
          encontrado = 0;
        } else {
            encontrado = 1;
        }
          fwrite(&localiza, sizeof(localiza), 1, entradatemp);
    }
}
fclose(entradatemp);
fclose(entrada);

remove("itens.dat");
rename("itenstemp.dat","itens.dat");

    if (encontrado) {
        fflush(stdin);
        printf("Operacao realizada com sucesso!\n");
    } else {
        fflush(stdin);
        printf("Produto nao foi encontrada.\n");
    }
}

void compraprod (FILE *entrada){
int qtdincrementar, i, nomelojacompra, encontrado = 0;;
char nomeprodcompra[20];
FILE *entradatemp;
item localiza;
estoque regiscompra, qtdaumenta;

entrada = fopen("estoque.dat", "rb");
entradatemp = fopen("estoquetemp.dat", "wb");

if (entrada == NULL){
printf("\nO arquivo tem de ser criado!");
}

fflush(stdin);
printf("Digite o nome do produto a ser comprado: ");
scanf("%s", &nomeprodcompra);
fflush(stdin);
printf("Digite a quantidade dele a ser comprada: ");
scanf("%d", &qtdincrementar);
printf("Para qual loja?: ");
scanf("%d", &nomelojacompra);

for(i = 0; i < 200; i++){
while (fread(&localiza, sizeof(localiza), 1, entrada) == 1) {
        if (strcmp(localiza.nome, nomeprodcompra) == 0 && regiscompra.numloja == nomelojacompra) {
        qtdaumenta.qtddoitem[i] = regiscompra.qtddoitem[i]+qtdincrementar;
          encontrado = 0;
        } else {
            encontrado = 1;
        }
          fwrite(&qtdaumenta, sizeof(qtdaumenta), 1, entradatemp);
    }
}
fclose(entradatemp);
fclose(entrada);

remove("estoque.dat");
rename("estoquetemp.dat","estoque.dat");

    if (encontrado) {
        fflush(stdin);
        printf("Operacao realizada com sucesso!\n");
    } else {
        fflush(stdin);
        printf("Produto nao foi encontrada.\n");
    }
}

void anulaitem (FILE *entrada){
int iteminvalida;
int i, encontrado = 0;
FILE *entradatemp;
item localiza;

entrada = fopen("itens.dat", "rb");
entradatemp = fopen("itenstemp.dat", "wb");

if (entrada == NULL){
printf("\nO arquivo tem de ser criado!");
}

fflush(stdin);
printf("Digite o numero de registro do item que deseja invalidar: ");
scanf("%d", &iteminvalida);

for(i = 0; i < 200; i++){
while (fread(&localiza, sizeof(localiza), 1, entrada) == 1) {
        if (localiza.numregistro == iteminvalida) {
          localiza.numregistro = 0;
        } else {
            encontrado = 1;
        }
        fwrite(&localiza, sizeof(localiza), 1, entradatemp);
    }
}
fclose(entradatemp);
fclose(entrada);

remove("itens.dat");
rename("itenstemp.dat","itens.dat");

    if (encontrado) {
        fflush(stdin);
        printf("Conta anulada com sucesso!\n");
    } else {
        fflush(stdin);
        printf("Conta nao foi encontrada.\n");
    }
}

void anulaloja (FILE *entrada){
int lojainvalida;
int i, encontrado = 0;
FILE *entradatemp;
estoque anula;

entrada = fopen("estoque.dat", "rb");
entradatemp = fopen("estoquetemp.dat", "wb");

if (entrada == NULL){
printf("\nO arquivo tem de ser criado!");
}

fflush(stdin);
printf("Digite o numero do CNPJ da loja que deseja invalidar: ");
scanf("%d", &lojainvalida);

for(i = 0; i < 200; i++){
while (fread(&anula, sizeof(anula), 1, entrada) == 1) {
        if (anula.cnpj == lojainvalida) {
          anula.cnpj = 0;
        } else {
            encontrado = 1;
        }
        fwrite(&anula, sizeof(anula), 1, entradatemp);
    }
}
fclose(entradatemp);
fclose(entrada);

remove("estoque.dat");
rename("estoquetemp.dat","estoque.dat");

    if (encontrado) {
        fflush(stdin);
        printf("Conta anulada com sucesso!\n");
    } else {
        fflush(stdin);
        printf("Conta nao foi encontrada.\n");
    }
}

void otimiza (FILE *entrada,FILE *entrada2){
char nome[81];
int i, encontrado = 0;
FILE *entradatemp, *entrada2temp;
item anulaitem;
estoque anulaloja;

entrada = fopen("itens.dat", "rb");
entradatemp = fopen("itenstemp.dat", "wb");
entrada2 = fopen("estoque.dat", "rb");
entrada2temp = fopen("estoquetemp.dat", "wb");

if (entrada == NULL){
printf("\nO arquivo tem de ser criado!");
}

for(i = 0; i < 200; i++){
while (fread(&anulaitem, sizeof(anulaitem), 1, entrada) == 1) {
        if (anulaitem.numregistro != 0) {
            fwrite(&anulaitem, sizeof(item), 1, entradatemp);
        } else {
            encontrado = 1;
        }
        if (anulaloja.cnpj != 0) {
            fwrite(&anulaloja, sizeof(estoque), 1, entrada2temp);
        } else {
            encontrado = 1;
        }
    }
}
fclose(entrada2temp);
fclose(entrada2);

remove("estoque.dat");
rename("estoquetemp.dat","estoque.dat");

    if (encontrado) {
        fflush(stdin);
        printf("Loja ou item removido com sucesso!\n");
    } else {
        fflush(stdin);
        printf("Loja ou item nao encontrados.\n");
    }
}

void relatorioestoque (FILE *entrada){
int i, aux = 0, aux2 = 0;
estoque sinalizar;
item insere2, insere3[200];
FILE *entrada2;
rede aponta;

entrada = fopen("estoque.dat", "rb");
entrada2 = fopen("itens.dat", "rb");

if (entrada == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
printf("Listagem do Estoque:\n");

while (!feof(entrada)){
for (i = 0; i<200;i++){
aux = fread(&sinalizar, sizeof(estoque), 1, entrada);
aux2 = fread(&insere2, sizeof(item), 1, entrada2);
if (aux){
printf("Numero da Loja %d", sinalizar.numloja);
printf("\nCNPJ: %d\n", sinalizar.cnpj);
printf("Produto %s | Quantidade %d: \n", insere2.nome,sinalizar.qtddoitem[i]);
}
}
}
fclose(entrada);
fclose(entrada2);
}
}

void relatorioitem (FILE *entrada){
int i, aux = 0;
item sinaliza;

entrada = fopen("itens.dat", "rb");

if (entrada == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
printf("Listagem dos Itens:");

while (!feof(entrada)){
aux = fread(&sinaliza, sizeof(item), 1, entrada);
if (aux){
printf("Numero de Registro do Item: %d", sinaliza.numregistro);
printf("\nNome do Item: %s\n", sinaliza.nome);
printf("Preco do Item: %f\n", sinaliza.preco);
}
}
fclose(entrada);
}
}

void relatorioconsolidado (FILE *entrada){
int i, totalitem, aux = 0, aux2 = 0;
estoque soma;
item indica;
FILE *entradatemp;

entrada = fopen("estoque.dat", "rb");
entradatemp = fopen("itens.dat", "rb");

if (entrada == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
printf("Listagem do Total dos Itens por Loja:");

while (!feof(entrada)){
aux = fread(&soma, sizeof(estoque), 1, entrada);
aux2 = fread(&indica, sizeof(item), 1, entradatemp);
if (aux){
if (indica.nome == indica.nome){
totalitem += soma.qtddoitem[i];
printf("O item %s esta disponivel na quantidade %d\n", indica.nome, totalitem);
}
}
}
fclose(entrada);
}
}
