//Davi Passos e Luís Gabryel

#include <stdio.h>
#include <string.h> 

typedef struct {
  int num;
  float saldo;
  char nome[50];
} Conta;

int main(void) {
  Conta conta[15];
  int i, j, op, posi = 0, achou = 0, numConta, menor;
  char nome[50];


for (int i = 0; i < 15; i++) {
  conta[i].num = 0;
  conta[i].saldo = 0;
  conta[i].nome[0] = '\0'; 
}

do {
  printf("1. Cadastrar contas\n");
  printf("2. Visualizar todas as contas de determinado cliente\n");
  printf("3. Excluir a conta com menor saldo\n");
  printf("4. Sair\n");
  scanf("%d", &op);

  if ((op < 1) || (op > 4)) {
    printf("Opção inválida\n");
    } else if (op == 1) {
  if (posi >= 15) {
    printf("Todas as contas ja foram cadastradas\n");
} else {
    printf("Digite o numero da conta a ser incluida: ");
    scanf("%d", &numConta);

    achou = 0;
    for (i = 0; i < posi; i++) {
      if (conta[i].num == numConta) {
        achou = 1;
break; 
   }
}

  if (achou) {
    printf("ja existe conta cadastrada com esse numero\n");
} else {
    conta[posi].num = numConta;
    printf("digite o nome do cliente: ");
    scanf("%s", conta[posi].nome);
    printf("digite o saldo da conta: ");
    scanf("%f", &conta[posi].saldo);
    printf("conta cadastrada com sucesso\n");
     posi++;
    }
}
    
  } else if (op == 2) {
    printf("Digite o nome do cliente a ser consultado: ");
    scanf("%s", nome);
    achou = 0;
for (i = 0; i < posi; i++) {
    if (strcmp(conta[i].nome, nome) == 0) { 
    printf("Conta %d: Saldo %.2f\n", conta[i].num, conta[i].saldo);
    achou = 1;
  }
}
if (!achou) {
  printf("não existe conta cadastrada com esse cliente\n");
  }
    
} else if (op == 3) {
    if (posi == 0) {
    printf("Nenhuma conta foi cadastrada\n");
} else {
 menor = conta[0].saldo;
  achou = 0;
for (i = 1; i < posi; i++) {
  if (conta[i].saldo < menor) {
    menor = conta[i].saldo;
    achou = i; 
  }
}
if (achou != 0) { 
  for (i = achou; i < posi - 1; i++) {
    conta[i].num = conta[i + 1].num;
    strcpy(conta[i].nome, conta[i + 1].nome); 
    conta[i].saldo = conta[i + 1].saldo;
}
  posi--; 
  printf("Conta excluida com sucesso\n");
} else {
  printf("Nenhuma conta foi excluída.\n");
      }
    }
  }
} while (op != 4); 

return 0;
}