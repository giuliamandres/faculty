#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct student
{
  char name[36];
  char code1[3];
  char code2[3];
  char code3[3];
  char code4[3];
}STUDENT;


int main(int argc, char const *argv[]) {

  FILE *f = fopen(argv[1], "r");

  if(f == NULL)
    printf("Error opening the file\n");


  char buffer[36];
  fgets(buffer, 36, f);
  buffer[strlen(buffer)-1] = '\0';

  int i = 0;
  STUDENT s[5000];

  while (!feof(f))
  {
    buffer[strlen(buffer)-1] = '\0';
    strcpy(s[i].name, buffer);
    fgets(buffer, 36, f);
    sscanf(buffer, "%s %s %s %s", s[i].code1, s[i].code2, s[i].code3, s[i].code4);
    i++;
    fgets(buffer,36,f);

  }

  int left = 0, right = 4999, found = 0, m, count = 0;

  while ((left <= right) && (!found))
  {
    m = (left + right) / 2;
    if(strcmp(s[m].name, "MATEI STEFAN") == 0)
      {
        count++;
        found = 1;
      }
      else
      {
        count++;

        if(strcmp(s[m].name, "MATEI STEFAN") < 0)
          {
            left = m + 1;
          }
          else
          {
            right = m - 1;
          }
      }


  }

  if(found)
    printf("Student was found at index %d\n", m + 1);
  printf("Number of comparisons : %d\n", count);

  char optional[3];
  fgets(optional, 3, stdin);

  for(int i = 0; i < 5000; i++)
  {
    if(strcmp(s[i].code1, optional) == 0 || strcmp(s[i].code2, optional) == 0 || strcmp(s[i].code3, optional) == 0 || strcmp(s[i].code4, optional) == 0)
    {
      printf("%s\n", s[i].name);
    }
  }

  fclose(f);
  return 0;
}
