#include "skiplist.h"

int main(){
    no *List=NULL; //cabeca da skipList
    no *search[MAXLEVEL]; //vetor de busca

    FILE *fileR,*fileW; //fileR arquivo de leitura e fileW arquivo para escrever
    char linha[10]; //armazena uma linha do arquivo fileR
    int *chave; //vetor que representa uma chave, sendo que cada posicao armazena apenas 1 casa do numero completo
    int *level; //vetor que representa um nivel de hierarquia, sendo que cada posicao armazena apenas 1 casa do numero completo
    chave=(int*)malloc(sizeof(int));
    level=(int*)malloc(sizeof(int));

    fileW= fopen("fileW.txt","w");     //abre arquivo para escrever nele
    fileR = fopen("fileR.txt","r");    //abre arquivo para ler
    if(!fileR)    //caso nao exista o arquivo no diretorio
        printf("nao encontrou o arquivo");

    while(!feof(fileR)){     //enquanto o arquivo nao chegou ao fim
        fgets(&linha,10,fileR);  //linha recebe ate 10 caracteres da atual linha

        if(linha[0]=='I'){ //caso a primeira letra da linha seja I, ou seja comando de inserir

            int c,tam; //c para percorrer a linha , tam para controlar a quantidade de casas que um numero possui
            int chaveInt=0 ,levelInt=0; //chaveInt chave real a ser inserida  e  levelInt nivel de hierarquia real no qual a chave vai ser inserida

            for(c=2 , tam=1 ;linha[c]!=' '; c++ , tam++){ //c=2 para posicionar na primeira casa da chave , tam eh a quantidade de casas ,' ' pois eh onde as casas da chave acabam
                chave=(int*)realloc(chave,tam*sizeof(int)); //realoca espaco de memoria devido a quantidade de casas da chave a ser inserida
                chave[tam-1]=linha[c]-'0'; //posicao tam-1 do vetor chave recebe uma casa do numero chave a ser inserido
            }
            for(int casa=1 , cont=tam-2 ;cont>-1; casa=casa*10 , cont--)//cont para percorrer o vetor chave, casa para controlar a concatenacao correta do numero completo que foi fragmentado no vetor chave
                chaveInt += chave[cont]*casa; //chaveInt recebe o numero completo pela concatenacao


            for(c++ , tam=1 ;linha[c+1]!='\0'; c++,tam++){//c++ para posicionar na primeira casa do nivel de hierarquia , tam eh a quantidade de casas , '\0' pois eh onde as casas do nivel de hierarquia acabam
                level=(int*)realloc(level,tam*sizeof(int));//realoca espaco de memoria devido a quantidade de casas do nivel de hierarquia no qual a chave deve ser inserida
                level[tam-1]=linha[c]-'0';//posicao tam-1 do vetor level recebe uma casa do numero nivel de hierarquia no qual a chave deve ser inserida
            }
            for(int casa=1 , cont=tam-2 ;cont>-1; casa=casa*10,cont--)//cont para percorrer o vetor level, casa para controlar a concatenacao correta do numero completo que foi fragmentado no vetor level
                levelInt += level[cont]*casa; //levelInt recebe o numero completo pela concatenacao

            if(InsertNo(&List,chaveInt,levelInt,&search)==1) //insere a chave == chaveInt no nivel de hierarquia ==levelInt referente a lista List
                fprintf(fileW,"true\n"); //imprime true no arquivo fileW se a chave for inserida com sucesso
            else
                fprintf(fileW,"false\n"); //imprime false no arquivo fileW se a chave nao for inserida com sucesso


        }
        else if(linha[0]=='R'){ //caso a primeira letra da linha seja R, ou seja comando de remover
            int c,tam; //c para percorrer a linha , tam para controlar a quantidade de casas que um numero possui
            int chaveInt=0; //chaveInt chave real a ser removida

            for(c=2 , tam=1 ;linha[c+1]!='\0'; c++ , tam++){//c=2 para posicionar na primeira casa da chave , tam eh a quantidade de casas ,'\0' pois eh onde as casas da chave acabam
                chave=(int*)realloc(chave,tam*sizeof(int));//realoca espaco de memoria devido a quantidade de casas da chave a ser removida
                chave[tam-1]=linha[c]-'0';//posicao tam-1 do vetor chave recebe uma casa do numero chave a ser removido
            }
            for(int casa=1 , cont=tam-2 ;cont>-1; casa=casa*10 , cont--)//cont para percorrer o vetor chave, casa para controlar a concatenacao correta do numero completo que foi fragmentado no vetor chave
                chaveInt += chave[cont]*casa;//chaveInt recebe o numero completo pela concatenacao

            if(removeNo(&List,chaveInt,&search)==1)//remove a chave == chaveInt referente a lista List
                fprintf(fileW,"true\n");//imprime true no arquivo fileW se a chave for removida com sucesso
            else
                fprintf(fileW,"false\n");//imprime false no arquivo fileW se a chave nao for removida com sucesso
        }

        else if(linha[0]=='B'){//caso a primeira letra da linha seja B, ou seja comando de Busca
            int c,tam; //c para percorrer a linha , tam para controlar a quantidade de casas que um numero possui
            int chaveInt=0; //chaveInt chave real a ser removida

            for(c=2 , tam=1 ;linha[c+1]!='\0'; c++ , tam++){//c=2 para posicionar na primeira casa da chave , tam eh a quantidade de casas ,'\0' pois eh onde as casas da chave acabam
                chave=(int*)realloc(chave,tam*sizeof(int));//realoca espaco de memoria devido a quantidade de casas da chave buscada
                chave[tam-1]=linha[c]-'0'; //posicao tam-1 do vetor chave recebe uma casa do numero chave buscada
            }
            for(int casa=1 , cont=tam-2 ;cont>-1; casa=casa*10 , cont--)//cont para percorrer o vetor chave, casa para controlar a concatenacao correta do numero completo que foi fragmentado no vetor chave
                chaveInt += chave[cont]*casa;//chaveInt recebe o numero completo pela concatenacao

            if(searchList(chaveInt,List,&search,1,fileW)==1)//busca a chave == chaveInt referente a lista List
                fprintf(fileW,"true\n");//imprime true no arquivo fileW se a chave for encontrada
            else
                fprintf(fileW,"false\n");//imprime false no arquivo fileW se a chave nao for encontrada
        }

        else if(linha[0]=='P'){//caso a primeira letra da linha seja P, executa o comando de imprimir a lista em um determinado nivel de hierarquia

            int c,tam;//c para percorrer a linha , tam para controlar a quantidade de casas que um numero possui
            int levelInt=0;//levelInt nivel de hierarquia real em que todas as chaves serao impressas

            for(c=2 , tam=1 ;linha[c+1]!='\0'; c++ , tam++){ //c=2 para posicionar na primeira casa do nivel de hierarquia == level , tam eh a quantidade de casas ,'\0' pois eh onde as casas do nivel de hierarquia == level acabam
                level=(int*)realloc(level,tam*sizeof(int)); //realoca espaco de memoria devido a quantidade de casas do nivel de hierarquia == level
                level[tam-1]=linha[c]-'0'; //posicao tam-1 do vetor level recebe uma casa do numero nivel de hierarquia que sera impresso
            }
            for(int casa=1 , cont=tam-2 ;cont>-1; casa=casa*10 , cont--) //cont para percorrer o vetor level, casa para controlar a concatenacao correta do numero completo que foi fragmentado no vetor level
                levelInt += level[cont]*casa; //levelInt recebe o numero completo pela concatenacao

           printListLevel(List,levelInt,fileW); //imprime no arquivo fileW, todas as chaves e nivel de hierarquia == levelInt presentes na lista List. ex de impressao em cada linha: 2 0

        }
        else if(linha[0]=='A') //caso a primeira letra da linha seja A
            all(List,fileW); // imprime todos os elementos de todos os niveis de hierarquia existentes na lista List no arquivo fileW

    }
    //fexa os arquivos fileR e fileW
    fclose(fileR);
    fclose(fileW);
    return 0;
}
