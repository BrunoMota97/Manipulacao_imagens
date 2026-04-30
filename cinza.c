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

void cinza(FILE* f1,FILE* f2){
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
  for(int k=0;k<image.width;k++){
grey=image.mat[j][k].r*0.2126 + image.mat[j][k].g*0.7125 + image.mat[j][k].b*0.0722 + 0.5;
image.mat[j][k].r=grey;
image.mat[j][k].g=grey,
image.mat[j][k].b=grey;
  }
for(int j=0;j<image.height;j++){
  for(int k=0;k<image.width;k++){
    fprintf(f2,"%d",image.mat[j][k].r);
    fprintf(f2,"%d",image.mat[j][k].g);
    fprintf(f2,"%d",image.mat[j][k].b);

  }

fclose(f2);
free(image.mat);

}
}



}

int main(int argc, char* argv[]){
 FILE* f1;
 FILE* f2;

 if(argc > 1){
 f1 = fopen(argv[1], "r"); // lê a primeira imagem

 if(f1 == NULL){
 printf(" <file>: No such file or directory");
 exit(1);
}
 }
 else{
   f1= stdin;
 }


 if(argc > 2){
 f2 = fopen(argv[2], "w"); // escreve no ficheiro de saída
 }
 else{
 f2 = stdout;
 }

cinza(f1,f2);
 return 0;
}
