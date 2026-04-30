#include <stdio.h>
#include <stdlib.h>

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

void moldura(FILE* f1, FILE* f2,int a,PPMPIXEL aux){
   PPM image;
 PPM resultado;

 fscanf(f1,"P%d\n%d %d\n%d\n",&image.magicNumber,&image.width,&image.height,&image.maxval);
 // valores da imagem final(P3, dimensões e valor máximo)
resultado.magicNumber = image.magicNumber;
resultado.width = 2*a+image.width; // a = largura da moldura, mas como quero contar com a extremidade, é duas vezes mais o comprimento
resultado.height = 2*a + image.height; // analogamente ao anterior
resultado.maxval = image.maxval;

 fprintf(f2,"P%d\n%d %d\n%d\n",resultado.magicNumber,resultado.width,resultado.height,resultado.maxval); // escreve no ficheiro de saida(f2) as informações lidas do ficheiro de entrada

image.mat= (PPMPIXEL **) malloc(image.height * sizeof(PPMPIXEL *));

for(int i=0;i<image.height;i++){ // alocar memória da imagem
  image.mat[i]= (PPMPIXEL *) malloc(image.width*sizeof(PPMPIXEL));
  for(int j=0;j<image.width;j++){
   PPMPIXEL p;
    fscanf(f1,"%d %d %d",&p.r,&p.g,&p.b);
  image.mat[i][j]=p;
  }
 }

resultado.mat= (PPMPIXEL **) malloc(resultado.height * sizeof(PPMPIXEL *));

 for(int i=0;i<resultado.height;i++){ // mesma coisa para o resultado da imagem obtida
  resultado.mat[i]= (PPMPIXEL *) malloc(resultado.width*sizeof(PPMPIXEL));
 }
 fclose(f1);


 for (int j =0; j<resultado.height; j++){
  for (int k = 0; k < resultado.width; k++){
    if(j<a || k<a || j>image.height-1-a || k>image.width-1-a){
  resultado.mat[j][k].r=aux.r; // a combinação RGB é imprimida nesse pixel
   resultado.mat[j][k].g=aux.g;
   resultado.mat[j][k].b=aux.b;
 }else{
   resultado.mat[j][k]=image.mat[j-a][k-a]; // a combinação RGB é imprimida nesse pixel
 }




int main(int argc, char* argv[]){
 FILE* f1;
 FILE* f2;
 PPMPIXEl aux;
 aux.r= atoi(argv[1]);
aux.g= atoi(argv[2]);
aux.b= atoi(argv[3]);
 if(argc > 4){
 f1 = fopen(argv[4], "r"); // lê a primeira imagem

 if(f1 == NULL){
 printf(" <file>: No such file or directory");
 exit(1);
}
 }
 else{
   f1= stdin;
 }


 if(argc > 5){
 f2 = fopen(argv[5], "w"); // escreve no ficheiro de saída
 }
 else{
 f2 = stdout;
 }

moldura(f1,f2,espessura,r,g,b);
 return 0;
}
