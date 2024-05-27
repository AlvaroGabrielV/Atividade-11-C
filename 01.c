#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <locale.h>

char aluno[5][10];

void cadastro_notas();
void alteracao_notas();
void menu();

int main() {
    setlocale(LC_ALL, "");
    menu();
    return 0;
}

void cadastro_notas() {
    system("cls");
    printf("Cadastro de Alunos/Notas\n");
    
    int contador, contador1;
    float notas[5][10], media;
    float totalnotas = 0;
    
    for (contador = 0; contador < 5; contador++) {
        totalnotas = 0;    
        printf("Aluno: ");    
        scanf("%s", aluno[contador]);
        
        for (contador1 = 0; contador1 < 4; contador1++) {
            printf("Nota %i: ", contador1 + 1); 
            scanf("%f", &notas[contador][contador1]);
            totalnotas += notas[contador][contador1];
        }
        
        media = totalnotas / 4;
        printf("Total de notas: %f\n", totalnotas);
        printf("Média das notas: %f\n", media);
        
        if (media < 4) {
            printf("O aluno %s está reprovado\n", aluno[contador]);
        } else if (media >= 4 && media <= 6) {
            printf("O aluno %s está de recuperação\n", aluno[contador]);
        } else if (media > 6) {
            printf("O aluno %s está aprovado\n", aluno[contador]);
        }
        
        printf("--------------------------------\n");
    }
}

void alteracao_notas() {
    system("cls");
    printf("Alteração de Notas/Alunos\n");
    
    int contador, contador1;
    float notas[5][10], media;
    float totalnotas = 0;
    
    printf("Nomes dos alunos cadastrados:\n");
    for (contador = 0; contador < 5; contador++) {
        printf("%i - Aluno: %s\n", contador+1, aluno[contador]); 
    }
    
    for (contador = 0; contador < 5; contador++) {
        totalnotas = 0;    
        printf("Aluno: %s\n", aluno[contador]);
        
        for (contador1 = 0; contador1 < 4; contador1++) {
            printf("Nota %i: ", contador1 + 1); 
            scanf("%f", &notas[contador][contador1]);
            totalnotas += notas[contador][contador1];
        }
        
        media = totalnotas / 4;
        printf("Total de notas: %f\n", totalnotas);
        printf("Média das notas: %f\n", media);
        
        if (media < 4) {
            printf("O aluno %s está reprovado\n", aluno[contador]);
        } else if (media >= 4 && media <= 6) {
            printf("O aluno %s está de recuperação\n", aluno[contador]);
        } else if (media > 6) {
            printf("O aluno %s está aprovado\n", aluno[contador]);
        }
        
        printf("\n____________________________________________\n");
    }
}

void menu() {
    int opcao = 0;
    
    while (opcao != 3) {
        system("cls");
        printf("Bem vindo ao meu sistema\n\n");
        printf("##############\n");
        printf("##          ##\n");
        printf("##   Menu   ##\n");
        printf("##          ##\n");
        printf("##############\n\n");
        printf("1 - Cadastro de Notas/Alunos\n");
        printf("2 - Alteração de Notas/Alunos\n");
        printf("3 - Sair\n\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                cadastro_notas();
                break;
            case 2:
                alteracao_notas();
                break;
            case 3:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida. Por favor, escolha uma opção válida.\n");
                break;
        }
        
        system("pause");
    }
}
