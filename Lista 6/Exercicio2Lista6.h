typedef struct {
int idade, matricula;
float cr;
char nome [80], curso [50];
} aluno;

typedef struct {
aluno discente;
float notas;
int faltas;
} alunosmat;

typedef struct {
int codigo;
alunosmat turma[40];
char nomedisc [50];
} disciplina;
