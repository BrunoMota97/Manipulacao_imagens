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

void horizontal(FILE* f1,FILE* f2){
PPM image;
fscanf(f1,"P%d\n%d %d\n%d\n",&image.magicNumber,&image.width,&image.height,&image.maxval);
fprintf(f2,"P%d\n%d %d\n%d\n",image.magicNumber,image.width,image.height,image.maxval);

image.mat= (PPMPIXEL **) malloc(image.height * sizeof(PPMPIXEL *));

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
   for(int k=image.width-1;k>=0;k--){
     fprintf(f2,"%d",image.mat[k][j].r);


}
}
for(int k=image.width-1;k>=0;k--){
  for(int j=0;k<image.height;k++){
    fprintf(f2,"%d",image.mat[j][k].r);
