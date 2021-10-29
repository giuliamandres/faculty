#include <stdio.h>

int main(int argc, char const *argv[]) {

  FILE *f = fopen("gradient.ppm","w");

  if(f == NULL)
  {
    printf("Error opennig the file\n");
    return -1;
  }

  int no_rows = 1000;
  int no_col = 1000;
  int maxvalue = 255;
  fprintf(f, "%s\n%d %d\n%d\n", "P3", no_rows, no_col, maxvalue);

  for(int j=0; j<no_col; j++)
  {
    int poz = 0;
    for(int i=0 ;i<= maxvalue; i++)
    {
      if(poz % 40 == 0 && poz != 1000 && poz != 0) //we need to eliminate 24 pixels (1024-1000) so we substract 1 pixel every 40 positions (40x24=960)
      {
        fprintf(f,"%d %d %d %d %d %d %d %d %d ", i,i,i,i,i,i,i,i,i); //we put 3 pixels instead of 4

      }
      else
      {
        fprintf(f,"%d %d %d %d %d %d %d %d %d %d %d %d ", i,i,i,i,i,i,i,i,i,i,i,i); //we print 4 pixels because 256x4=1024
      }
      poz = poz + 4;
    }
    fprintf(f,"\n");
  }
  
  fclose(f);
  return 0;
}
