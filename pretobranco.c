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

void horizontal(FILE* f1,FILE* f2,int parametro){
PPM image;
fscanf(f1,"P%d\n%d %d\n%d\n",&image.magicNumber,&image.width,&image.height,&image.maxval);
fprintf(f2,"P%d\n%d %d\n%d\n",image.magicNumber,image.width,image.height,image.maxval);


for(int i=0;i<image.height;i++){ // alocar memória da imagem
 image.mat[i]= (PPMPIXEL *) malloc(image.width*sizeof(PPMPIXEL));
   for(int j=0;j<image.width;j++){
     PPMPIXEL g;
fscanf(f1,"%d %d %d\n",&g.r, &g.g,&g.b);// ler do ficheiro de entrada os pixeis
image.mat[i][j]=g;
}
}
fclose(f1);

for(int j=0;j<image.height;j++){
  for(int j=0;j<image.width;j++){
    grey=image.mat[j][k].r*0.2126 + image.mat[j][k].g*0.7125 + image.mat[j][k].b*0.0722 + 0.5;

    if(grey > parametro){
      grey=image.maxval;
    }else{
      grey=0;
    }
    image.mat[j][k].r=grey;
 image.mat[j][k].g=grey;
 image.mat[j][k].b=grey;
  }
}
fclose(f2);
free(image.mat);
}
int main(int argc, char* argv[]){
 FILE* f1;
 FILE* f2;
int parametro=atoi(argv[1]);
 if(argc > 2){
 f1 = fopen(argv[2], "r"); // lê a primeira imagem

 if(f1 == NULL){
 printf(" <file>: No such file or directory");
 exit(1);
}
 }
 else{
   f1= stdin;
 }


 if(argc > 3){
 f2 = fopen(argv[3], "w"); // escreve no ficheiro de saída
 }
 else{
 f2 = stdout;
 }

pretobranco(f1,f2,parametro);
 return 0;
}
