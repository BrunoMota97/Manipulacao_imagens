#include<stdio.h>
#include<stdlib.h>

struct ppmPixel{
 int r,g,b;
};

typedef struct ppmPixel PPMPIXEL;

struct ppmImage{
 int magicNumber;
 int width,height,maxval;
 PPMPIXEL** mat;
};

typedef struct ppmImage PPM;

void justaposicao(FILE* f1, FILE* f2, FILE* f3){ // acrescentou-se mais um argumento (FILE* f3), pois vou precisar de mais um ficheiro de saída
   PPM image,image1,resultado;
 fscanf(f1,"P%d\n%d %d\n%d\n",&image.magicNumber,&image.width,&image.height,&image.maxval); // precisa de ler o primeiro ficheiro
  fscanf(f2,"P%d\n%d %d\n%d\n",&image1.magicNumber,&image1.width,&image1.height,&image1.maxval);
  resultado.magicNumber = image.magicNumber; // precisa de transferir o valor P3 para o ficheiro de output
resultado.width = image.width + image1.width;

if(image.height < image1.height){ // se a altura da primeira imagem for menor do que a segunda, então:
  resultado.height = image.height; // a dimensão da altura da nova imagem vai assumir a altura da primeira
}else{
  resultado.height = image1.height; // senão, a  da segunda imagem
}

resultado.maxval = image.maxval; // precisa de transferir o valor máximo 255 para a nova imagem
 fprintf(f3,"P%d\n%d %d\n%d\n",resultado.magicNumber,resultado.width,resultado.height,resultado.maxval); // imprime os parâmetros no novo ficheiro
image.mat= (PPMPIXEL **) malloc(image.height * sizeof(PPMPIXEL *)); // alocar a memória dinamicamente

 for(int i=0;i<image.height;i++){ // alocar memória da imagem
  image.mat[i]= (PPMPIXEL *) malloc(image.width*sizeof(PPMPIXEL));
    for(int j=0;j<image.width;j++){
  PPMPIXEL p;
fscanf(f1,"%d %d %d\n",&p.r, &p.g,&p.b);// ler do ficheiro de entrada os pixeis
image.mat[i][j]=p;
}
}

image1.mat= (PPMPIXEL **) malloc(image1.height * sizeof(PPMPIXEL *)); // alocar a memória da segunda imagem

 for(int i=0;i<image1.height;i++){ // alocar memória da imagem
  image1.mat[i]= (PPMPIXEL *) malloc(image1.width*sizeof(PPMPIXEL));
    for(int j=0;j<image1.width;j++){
      PPMPIXEL g;
fscanf(f2,"%d %d %d\n",&g.r, &g.g,&g.b);// ler do ficheiro de entrada os pixeis
image1.mat[i][j]=g;
}
}

resultado.mat= (PPMPIXEL **) malloc(resultado.height * sizeof(PPMPIXEL *));

 for(int i=0;i<resultado.height;i++){ // mesma coisa para o resultado da imagem obtida
  resultado.mat[i]= (PPMPIXEL *) malloc(resultado.width*sizeof(PPMPIXEL));
 }
 fclose(f1); // fecha os dois ficheiros
fclose(f2);

for (int j =0; j<resultado.height; j++){ // começa por analisar a primeira imagem, percorrendo todas as linhas e colunas
  for (int k = 0; k < image.width; k++){
  resultado.mat[j][k].r=image.mat[j][k].r; // transfere os valores dos pixeis da primeira imagem para resultado, o novo ficheiro, vai receber estes valores
  resultado.mat[j][k].g=image.mat[j][k].g;
  resultado.mat[j][k].b=image.mat[j][k].b;
}
}
for (int j =0; j<resultado.height; j++){ // agora para a segunda imagem, volta a percorer as linhas novamente,mas...
 for (int k = image.width; k < resultado.width; k++){ //...agora vai continuar a partir da última posição da coluna da imagem anterior, ou seja, se a anterior tivesse comprimento 15, a iamgem seguinte vai começar a partir da linha 0 coluna 15 para completar o comprimento
   resultado.mat[j][k].r=image1.mat[j][k - image.width].r; // transfere os valores dos pixeis da segunda imagem para resultado, só que agora, no índice das colunas, temos de descontar k a image1.width, para começar a partir de índice 0 e assim sucessivamente
   resultado.mat[j][k].g=image1.mat[j][k - image.width].g;
   resultado.mat[j][k].b=image1.mat[j][k - image.width].b;
}
}
