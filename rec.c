#include <stdio.h>
#include <stdlib.h>

typedef struct ppmPixel{
 int r,g,b;
}PPMPIXEL;

typedef struct ppmImage{
 int magicNumber;
 int width,height,maxval;
 PPMPIXEL** mat;
}PPM;

void execute(FILE* f1, FILE* f2, int x1, int y1, int x2, int y2){
 PPM image;
 fscanf(f1,"P%d %d %d %d",&image.magicNumber,&image.width,&image.height,&image.maxval);
  if(x2>=image.width && y2>=image.height){ // é preciso considerar que o segundo ponto pode estar fora das dimensões da imagem
   x2=image.width-1;
   y2=image.height-1;
 }else if(x2>=image.width){
     x2=image.width-1;
 }else if(y2>=image.height){
    y2=image.height-1;
 }

 fprintf(f2,"P%d\n%d %d\n%d\n",image.magicNumber,x2-x1+1,y2-y1+1,image.maxval);
 image.mat= (PPMPIXEL **) malloc(image.height * sizeof(PPMPIXEL *));
 for(int i=0;i<image.height;i++){
  image.mat[i]= (PPMPIXEL *) malloc(image.width*sizeof(PPMPIXEL));
  for(int j=0;j<image.width;j++){
  PPMPIXEL p;
  fscanf(f1,"%d %d %d",&p.r,&p.g,&p.b);
  image.mat[i][j]=p;
  }
 }
 fclose(f1);
 for (int j = y1; j <= y2; j++){ // vai percorrer de uma ordenada à outra
  for (int k = x1; k <= x2; k++){ // semelhantemente para as ordenadas dos dois pontos
  fprintf (f2,"%d %d %d\n", image.mat[j][k].r,image.mat[j][k].g,image.mat[j][k].b);
  }
  }
 fclose(f2);
 free(image.mat);
}
