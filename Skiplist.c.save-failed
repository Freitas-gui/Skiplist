#include "skiplist.h"

void createList(no **List){// eh passado para a funçao ponteiro de ponteiro pois assim eh alterado o valor na memoria fora do escopo da funçao.
    no *novo=(no*)malloc(sizeof(no));
    if(!novo) return NULL;
    novo->i=MAXLEVEL; //no caso da estrutura ser uma lista o campo de inteiro recebe o nivel de hierarquia superior + 1.
    novo->prox=(no**)calloc(MAXLEVEL , sizeof(no*));//por utilizar calloc, tds os ponteiros apontam para NULL
    *List=novo;
}

no *createNo(int i , int level){
    no *novo=(no*)malloc(sizeof(no));
    if(!novo) return NULL;
    novo->i=i;//no caso da estrutura ser um No que compoem cada elemento, o campo de inteiro recebe uma chave
    novo->prox=(no**)calloc(level+1 , sizeof(no*));//por utilizar calloc, tds os ponteiros apontam para NULL ,nivel de hierarquia == level
    return novo;
}

int isEmptyList(no *List){
    if(!List) return 1; //verifica se List=NULL
    if(List->prox[0]==NULL) //verifica se todos os campos de ponteiro da cabeca estao apontados para NULL
        return 1;
    else
        return 0;
}

int searchList(int i, no *List , no **searchVet , int imprimir , FILE *fileW){
    if(isEmptyList(List)){
        return 0;
    }
    no *aux=List; //elemento auxiliar para pecorrer a lista
    int level; //referente ao nivel de hierarquia
    for(level=MAXLEVEL-1; level>-1 ;){ //repeticao para percorrer a lista, comecando pelo nivel de hierarquia superior, finalizando no nivel 0
        if(aux->prox[level]==NULL || aux->prox[level]->i>=i){ //verifica se o proximo elemento eh o ultimo elemento do nivel de hierarquia == level ou se o proximo elemento possui a chave > ou = a chave buscada =i
            searchVet[level]=aux;//a posicao == level do vetor searchVet recebe o elemento anterior ao ultimo elemento do nivel de hierarquia == level ou o elemento anterior ao elemento que carrega a (chave buscada = i ou uma chave buscada > i
            if(imprimir==1){//imprime algo se imprimir = 1
                char chaveLevel[20];
                if(aux!=List){ //caso tenha achado um elemento que carrega a chave = ou > que a chave buscada no nivel de hierarquia == level
                    sprintf(chaveLevel,"%d %d",aux->i,level); //chaveLevel recebe uma string com a chave do elemento e o nivel de hierarquia ex: 2 1
                    fprintf(fileW,"%s\n",&chaveLevel);//imprime a chave e o nivel de hierarquia ex: 2 1 no arquivo fileW
                }

            }
            level--; //desce um nivel de hierarquia
            if(level>-1) //se ainda nao percorreu todos os elementos da lista
                aux=List;//aux recebe a cabeca com nivel de hierarquia atualizado
        }
        else
            aux=aux->prox[level]; //aux percorre proximo elemento na sublista de mesmo nivel de hierarquia
    }
    if(aux->prox[0]==NULL || aux->prox[0]->i>i) //caso nao tenha achado o elemento buscado em toda lista
        return 0;
    else if(aux && aux->prox[0]->i==i){ //caso tenha achado o elemento buscado
        if(imprimir==1){ //imprime algo se imprimir = 1
            char chaveLevel[20];
            sprintf(chaveLevel,"%d 0",i); //chaveLevel recebe uma string com a chave do elemento buscado e o nivel de hierarquia == 0 ex: 3 0
            fprintf(fileW,"%s\n",&chaveLevel);//imprime a chave e o nivel de hierarquia 0 ex: 3 0 no arquivo fileW
        }

        return 1;
    }
}

int InsertNo(no **List, int novo, int level, no **searchVet){
    no *novoNo=createNo(novo,level); //novoNo = No que compoem um elemento a ser inserido na lista List com valor da chave = novo
    if(!novoNo) return 0; //caso nao consegui criar um novo elemento No
    if(isEmptyList(*List)){ //verifica se a lista eh vazia
        createList(List); //List recebe uma estrutua utilizada para Cabeca de lista recentemente criada
        for(int c=0; c<=level; c++){//percorre os niveis de hierarquia que o novo elemento a ser inserido possui

            (*List)->prox[c]=novoNo;// List recebe o primeiro elemento = novoNo

        }
        return 1; //caso tenha conseguido inserir
    }
    else if(searchList(novo,*List,searchVet,0,NULL)==0){ //caso a lista nao possui um elemento que carrega a mesma chave do elemento a ser inserido
        for(int c=0; c<=level; c++){ //percorre os niveis de hierarquia que o novo elemento a ser inserido possui
            if(searchVet[c]->prox[c]) //caso o elemento de posicao == c do vetor searchVet aponte para um elemento de chave maior que a chave a ser inserida
                novoNo->prox[c]=searchVet[c]->prox[c];//novo elemento a ser inserido aponta para o primeiro elemento com chave maior que a chave dele no nivel de hierarquia = c
            searchVet[c]->prox[c]=novoNo; //Cabeca de lista aponta para novo elemento ou elemento que carrega a chave menor que novo mais proximo de novo em ordem crescente aponta para novoNo
        }
        return 1; //inseriu um novo elemento
    }
    else{
        return 0; //nao modificou a lista
    }
}

int removeNo(no **List, int kay, no **searchVet){
    if(isEmptyList(*List))//verifica se a lista eh vazia
        return 0;//nao modifica a lista
    if(searchList(kay,*List,searchVet,0,NULL)==0){//caso a lista nao possui um elemento que carrega a mesma chave do elemento a ser inserido
        return 0; //nao modifica a lista
    }
    else{//caso encontre o elemento com chave == kay, esse elemento deve ser removido
        no *aux=searchVet[MAXLEVEL-1];//aux recebe elemento anterior ao elemento que deve ser removido no nivel de hierarquia superior ou cabeca de lista caso o elemento nao esteja presente neste nivel de hierarquia
        no *auxPrev;//acompanha os avancos de aux, mantendo-se 1 elemento anterior a aux
        int level;//para controle de nivel de hierarquia
        for(level=MAXLEVEL-1; ; ){//laco de repeticao que faz aux apontar para elemento a ser removido que possui chave = kay e apontar auxPrev para o antigo aux
            if(aux!=*List && aux->i==kay)//caso  aux aponta para elemento a ser removido e nao n confundir com a chave que a cabeca de lista carrega que a proposito eh = MAXLEVEL
                break; //finaliza laco de repeticao
            else if(!aux->prox[level]){// se o proximo elemento no nivel de hierarquia == level for NULL
                level--; //level recebe proximo nivel de hierarquia inferior
                aux=searchVet[level]; //aux recebe cabeca de lista ou elemento anterior ao elemento que deve ser removido
            }
            else{ //se nao auxPrev recebe aux e aux avanca para o proximo elemento no mesmo nivel de hierarquia == level
                auxPrev=aux;
                aux=aux->prox[level];
            }
        }
        for(int c=level; c>-1; c--){ //laco de repeticao para percorre os niveis de hierarquia do mais superior ao mais inferior que o elemento a ser revovido possui
            searchVet[c]->prox[c]=aux->prox[c]; //lista perde apontamento para elemento que deve ser removido
        }

        free(aux); //desaloca o espaco de memoria do elemento removido

        return 1; //remocao realizada com sucesso
    }
}

void printListLevel(no *List, int level, FILE *fileW){
    if(isEmptyList(List))//verifica se a lista eh vazia
        return; //nao precisa imprimir nada
    no *aux=List->prox[level]; //aux recebe o primeiro elemento da lista no nivel de hierarquia == level
    char chaveLevel[20]; //String para ser impressa

    for( ;aux; aux=aux->prox[level]){ //enquanto aux for != NULL, aux avanca para proximo elemento no mesmo nivel de hierarquia == level
            sprintf(chaveLevel,"%d %d",aux->i,level); //chaveLevel recebe uma string com a chave do elemento e o nivel de hierarquia ex: 2 1
            fprintf(fileW,"%s\n",&chaveLevel); //imprime a string chaveLevel ex: 2 1 em uma linha do arquivo fileW
    }
}


void all(no *List , FILE *fileW){
    if(isEmptyList(List))//verifica se a funcao eh vazia
        return;//nao precisa imprimir nada
    int level=MAXLEVEL-1; //level recebe o nivel de hierarquia mais superior da lista
    for( ; level>-1 ; level--){ //laco de repeticao que serve para percorrer os niveis de hierarquia do mais superior para o mais inferior
        printListLevel(List,level,fileW); //imprime todos elementos do nivel de hierarquia == level,  da lista List no arquivo fileW
    }
}




