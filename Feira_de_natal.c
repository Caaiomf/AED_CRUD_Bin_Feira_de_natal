#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>

typedef struct {
	int codigo_barraca,tel;
	char nome_responsavel[50],CPF[20],CNPJ[20],tipo_produto[60],obs[100];
}CADASTRO;

int menu(){
	int opcao;
	printf("\n-------------Feira de Natal------------");
	printf("\n1 - Cadastrar Expositores ");
	printf("\n2 - Listar Expositores ");
	printf("\n3 - Alterar Expositor ");
	printf("\n4 - Deletar Expositor ");
	printf("\n5 - Alterar Tipo do Produto ");
	printf("\n0 - Sair ");
	scanf("%d",&opcao);
	return opcao;
}

int busca(FILE *arquivo, int codigo_barraca){
	CADASTRO cad;
	rewind(arquivo);
	fread(&cad, sizeof(CADASTRO), 1, arquivo);
	while (!feof(arquivo) && cad.codigo_barraca != codigo_barraca)
	{
		fread(&cad,sizeof(CADASTRO),1,arquivo);
	}
	if(!feof(arquivo))
		return(ftell(arquivo)-sizeof(CADASTRO));
	else
		return -1;
}

void cadastrar()
{
	FILE *arquivo;
	CADASTRO cad;
	int pos;
	arquivo=fopen("feira_de_natal.bin","ab+");
	if(arquivo==NULL)
		printf("Erro no arquivo");
	else
	{
		do{
			system("cls");
			printf("\nCodigo da barraca ");
			scanf("%d",&cad.codigo_barraca);
			pos=busca(arquivo,cad.codigo_barraca);
			if(pos==-1)
			{
				printf("\nNome: "); fflush(stdin);
				gets(cad.nome_responsavel);
				printf("\nPessoa Fisica? S/N ");
				if(toupper(getch())=='S')
				{
					printf("\nEntre com o CPF para cadastro ");fflush(stdin);
					gets(cad.CPF);
				}
				else
				{
					printf("\nEntre com o CNPJ para cadastro ");fflush(stdin);
					gets(cad.CNPJ);
				}
				printf("\nEntre com o telefone de contato ");
				scanf("%d",&cad.tel);
				printf("\nEntre com o tipo de produto ");fflush(stdin);
				gets(cad.tipo_produto);
				printf("\nEntre com as observacoes ");fflush(stdin);
				gets(cad.obs);
			}
			printf("Deseja Continuar (S/N) ? ");
		}while (toupper(getch()) == 'S');
		fclose(arquivo);
	}
}
int main (){
	int opc;
	do{
		opc = menu();
		switch(opc) {
			case 1: cadastrar();
				break;
			case 2: //listar();
				break;
			case 3: //alterar();
				break;
			case 4: //deletar();
				break;
			case 5: //alterarProduto();
				break;
			case 0: printf("\n-----Encerrando-----\n ");
			default: printf("Opcao Invalida! \n ");
				break;
		}
	}while (opc != 0);
	return 0;
}
