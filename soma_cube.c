#include<stdio.h>
#include<stdlib.h>

typedef struct{
  char symbol;
  int p_num;
  int c_num;
  int **ex_x; //[12][4]
  int **ex_y; //[12][4]
  int **ex_z; //[12][4]
}Cube;

typedef struct{
  char ***space; //[5][5][5]
  Cube stack_cubes[7];
  int stack_num;
}Pazzle;


// ------------------- prototype -----------------------------


Cube init_cube(char c);
Pazzle init_pazzle(void);
void push(Pazzle *paz, Cube c);
Cube pop(Pazzle *paz);
void show_space(char ***space);
void first_set(Pazzle *paz, Cube c, int p_num);
void search(Pazzle *paz, int *sol_num);


// ------------------- main ---------------------------------


int main(void){
  int i,sol_num;
  Cube l,t,v,a,b,p,z;
  Pazzle paz;

  sol_num = 0;
  l = init_cube('l'); t = init_cube('t');
  v = init_cube('v'); a = init_cube('a');
  b = init_cube('b'); p = init_cube('p');
  z = init_cube('z');

  for(i=0;i<2;i++){  
    paz = init_pazzle();  

    push(&paz, t); push(&paz, v);
    push(&paz, a); push(&paz, b); 
    push(&paz, p); push(&paz, z);

    first_set(&paz, l, i);
 
    search(&paz, &sol_num);
  }

  printf("answers= %d\n",sol_num);

  return 0;
}


// ------------------------- function --------------------------


Cube init_cube(char s){
  int i,j,num;
  Cube c;

  c.symbol = s;

  c.ex_x = (int**)malloc(sizeof(int*) * 12);
  c.ex_y = (int**)malloc(sizeof(int*) * 12);
  c.ex_z = (int**)malloc(sizeof(int*) * 12);
  for(i=0;i<12;i++){
    c.ex_x[i] = (int*)malloc(sizeof(int) * 4);
    c.ex_y[i] = (int*)malloc(sizeof(int) * 4);
    c.ex_z[i] = (int*)malloc(sizeof(int) * 4);
    for(j=0;j<4;j++){
      c.ex_x[i][j] = -1;
      c.ex_y[i][j] = -1;
      c.ex_z[i][j] = -1;
    }
  }

  num = 0;
  switch (s){

  case 'l': //base cube
    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 0; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 2; c.ex_y[num][2] = 0; c.ex_z[num][2] = 0;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 1; c.ex_z[num][3] = 0; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 1; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 1; c.ex_z[num][2] = 0;
    c.ex_x[num][3] = 2; c.ex_y[num][3] = 1; c.ex_z[num][3] = 0; num++;

    //mirror
    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 0; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 2; c.ex_y[num][2] = 0; c.ex_z[num][2] = 0;
    c.ex_x[num][3] = 2; c.ex_y[num][3] = 1; c.ex_z[num][3] = 0; num++;

    c.ex_x[num][0] = 2; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 1; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 1; c.ex_z[num][2] = 0;
    c.ex_x[num][3] = 2; c.ex_y[num][3] = 1; c.ex_z[num][3] = 0; num++;

    //not found
    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 1;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 0; c.ex_z[num][1] = 1;
    c.ex_x[num][2] = 2; c.ex_y[num][2] = 0; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 1; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 1;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 1; c.ex_z[num][1] = 1;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 1; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 2; c.ex_y[num][3] = 1; c.ex_z[num][3] = 1; num++;

    c.p_num = num;
    c.c_num = 4;
    break;
  case 't':
    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 0; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 2; c.ex_y[num][2] = 0; c.ex_z[num][2] = 0;
    c.ex_x[num][3] = 1; c.ex_y[num][3] = 1; c.ex_z[num][3] = 0; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 1; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 1; c.ex_z[num][2] = 0;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 2; c.ex_z[num][3] = 0; num++;

    c.ex_x[num][0] = 1; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 1; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 1; c.ex_z[num][2] = 0;
    c.ex_x[num][3] = 2; c.ex_y[num][3] = 1; c.ex_z[num][3] = 0; num++;

    c.ex_x[num][0] = 1; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 1; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 1; c.ex_z[num][2] = 0;
    c.ex_x[num][3] = 1; c.ex_y[num][3] = 2; c.ex_z[num][3] = 0; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 0; c.ex_z[num][1] = 1;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 1; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 0; c.ex_z[num][3] = 2; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 0; c.ex_z[num][1] = 1;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 0; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 0; c.ex_z[num][3] = 2; num++;

    c.ex_x[num][0] = 1; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 0; c.ex_z[num][1] = 1;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 0; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 1; c.ex_y[num][3] = 0; c.ex_z[num][3] = 2; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 1; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 0; c.ex_z[num][1] = 1;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 1; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 1; c.ex_z[num][3] = 2; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 1; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 0; c.ex_z[num][1] = 1;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 1; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 2; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 1; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 0; c.ex_z[num][1] = 1;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 0; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 2; c.ex_y[num][3] = 0; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 0; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 2; c.ex_y[num][2] = 0; c.ex_z[num][2] = 0;
    c.ex_x[num][3] = 1; c.ex_y[num][3] = 0; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 1; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 2; c.ex_z[num][2] = 0;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 1; c.ex_z[num][3] = 1; num++;

    c.p_num = num;
    c.c_num = 4;
    break;
  case 'v':
    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 0; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 1; c.ex_z[num][2] = 0; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 0; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 1; c.ex_z[num][2] = 0; num++;

    c.ex_x[num][0] = 1; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 1; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 1; c.ex_z[num][2] = 0; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 1; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 1; c.ex_z[num][2] = 0; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 1; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 0; c.ex_z[num][2] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 0; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 0; c.ex_z[num][2] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 1; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 1; c.ex_z[num][2] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 0; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 0; c.ex_z[num][2] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 0; c.ex_z[num][1] = 1;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 1; c.ex_z[num][2] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 0; c.ex_z[num][1] = 1;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 0; c.ex_z[num][2] = 1; num++;

    c.ex_x[num][0] = 1; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 0; c.ex_z[num][1] = 1;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 0; c.ex_z[num][2] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 1; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 0; c.ex_z[num][1] = 1;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 1; c.ex_z[num][2] = 1; num++;

    c.p_num = num;
    c.c_num = 3;
    break;
  case 'a':
    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 1; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 0; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 1; c.ex_y[num][3] = 0; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 0; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 0; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 1; c.ex_y[num][3] = 1; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 1; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 1; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 1; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 1; c.ex_y[num][3] = 1; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 1; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 1; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 0; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 1; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 0; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 1; c.ex_z[num][2] = 0;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 0; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 1; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 1; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 0; c.ex_z[num][2] = 0;
    c.ex_x[num][3] = 1; c.ex_y[num][3] = 0; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 1; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 1; c.ex_z[num][2] = 0;
    c.ex_x[num][3] = 1; c.ex_y[num][3] = 1; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 0; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 1; c.ex_z[num][2] = 0;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 1; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 1; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 0; c.ex_z[num][1] = 1;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 0; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 1; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 0; c.ex_z[num][1] = 1;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 1; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 1; c.ex_y[num][3] = 1; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 1; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 1; c.ex_z[num][1] = 1;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 1; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 1; c.ex_y[num][3] = 0; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 1; c.ex_y[num][0] = 1; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 1; c.ex_z[num][1] = 1;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 0; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 0; c.ex_z[num][3] = 1; num++;

    c.p_num = num;
    c.c_num = 4;
    break;
  case 'b':
    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 0; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 0; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 1; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 1; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 1; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 1; c.ex_y[num][3] = 1; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 1; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 1; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 1; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 1; c.ex_y[num][3] = 0; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 1; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 1; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 0; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 0; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 1; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 1; c.ex_z[num][2] = 0;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 0; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 1; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 1; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 1; c.ex_z[num][2] = 0;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 1; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 0; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 1; c.ex_z[num][2] = 0;
    c.ex_x[num][3] = 1; c.ex_y[num][3] = 1; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 0; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 1; c.ex_z[num][2] = 0;
    c.ex_x[num][3] = 1; c.ex_y[num][3] = 0; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 0; c.ex_z[num][1] = 1;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 0; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 1; c.ex_y[num][3] = 1; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 1; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 1; c.ex_z[num][1] = 1;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 0; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 1; c.ex_y[num][3] = 0; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 1; c.ex_y[num][0] = 1; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 1; c.ex_z[num][1] = 1;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 1; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 0; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 1; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 0; c.ex_z[num][1] = 1;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 1; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 1; c.ex_z[num][3] = 1; num++;

    c.p_num = num;
    c.c_num = 4;
    break;
  case 'p':
    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 0; c.ex_z[num][1] = 1;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 1; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 1; c.ex_y[num][3] = 0; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 1; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 1; c.ex_z[num][1] = 1;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 1; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 0; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 1; c.ex_y[num][0] = 1; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 1; c.ex_z[num][1] = 1;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 0; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 1; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 1; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 0; c.ex_z[num][1] = 1;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 0; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 1; c.ex_y[num][3] = 1; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 0; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 1; c.ex_z[num][2] = 0;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 0; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 1; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 1; c.ex_z[num][2] = 0;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 1; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 1; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 1; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 1; c.ex_z[num][2] = 0;
    c.ex_x[num][3] = 1; c.ex_y[num][3] = 1; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 0; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 1; c.ex_z[num][2] = 0;
    c.ex_x[num][3] = 1; c.ex_y[num][3] = 0; c.ex_z[num][3] = 1; num++;

    c.p_num = num;
    c.c_num = 4;
    break;
  case 'z':
    c.ex_x[num][0] = 1; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 2; c.ex_y[num][1] = 0; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 0; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 0; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 1; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 1; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 2; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 0; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 0; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 2; c.ex_y[num][3] = 0; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 2; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 1; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 1; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 0; c.ex_z[num][3] = 1; num++;

    c.ex_x[num][0] = 1; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 2; c.ex_y[num][1] = 0; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 1; c.ex_z[num][2] = 0;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 1; c.ex_z[num][3] = 0; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 1; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 1; c.ex_z[num][2] = 0;
    c.ex_x[num][3] = 1; c.ex_y[num][3] = 2; c.ex_z[num][3] = 0; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 0; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 1; c.ex_z[num][2] = 0;
    c.ex_x[num][3] = 2; c.ex_y[num][3] = 1; c.ex_z[num][3] = 0; num++;

    c.ex_x[num][0] = 1; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 1; c.ex_z[num][1] = 0;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 1; c.ex_z[num][2] = 0;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 2; c.ex_z[num][3] = 0; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 0; c.ex_z[num][1] = 1;
    c.ex_x[num][2] = 1; c.ex_y[num][2] = 0; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 1; c.ex_y[num][3] = 0; c.ex_z[num][3] = 2; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 1; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 1; c.ex_z[num][1] = 1;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 0; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 0; c.ex_z[num][3] = 2; num++;

    c.ex_x[num][0] = 1; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 1; c.ex_y[num][1] = 0; c.ex_z[num][1] = 1;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 0; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 0; c.ex_z[num][3] = 2; num++;

    c.ex_x[num][0] = 0; c.ex_y[num][0] = 0; c.ex_z[num][0] = 0;
    c.ex_x[num][1] = 0; c.ex_y[num][1] = 0; c.ex_z[num][1] = 1;
    c.ex_x[num][2] = 0; c.ex_y[num][2] = 1; c.ex_z[num][2] = 1;
    c.ex_x[num][3] = 0; c.ex_y[num][3] = 1; c.ex_z[num][3] = 2; num++;

    c.p_num = num;
    c.c_num = 4;
    break;
  }
  
  return c;
}

Pazzle init_pazzle(void){
  int i,j,k;
  Pazzle paz;

  paz.space = (char***)malloc(sizeof(char**) * 5);
  for(i=0;i<5;i++){
    paz.space[i] = (char**)malloc(sizeof(char*) * 5);
    for(j=0;j<5;j++){
      paz.space[i][j] = (char*)malloc(sizeof(char) * 5);
      for(k=0;k<5;k++){
	paz.space[i][j][k] = '.';
      }
    }
  }

  paz.stack_num = 0;

  return paz;
}

void push(Pazzle *paz, Cube c){
  if(paz->stack_num < 7){
    paz->stack_cubes[paz->stack_num] = c;
    paz->stack_num++;
  }
  else
    printf("stack is full\n");
}

Cube pop(Pazzle *paz){
  if(paz->stack_num > 0){
    paz->stack_num--;
    return paz->stack_cubes[paz->stack_num];
  }
  else
    printf("stack is empty\n");
}

void show_space(char ***space){
  int x,y,z;

  for(y=3;y>=1;y--){
    printf("\n");
    for(z=3;z>=1;z--){
      if(z==3) printf("   ");
      else if(z==2) printf("  ");
      else printf(" ");
      for(x=1;x<=3;x++){
	printf("%c   ",space[x][y][z]);
      }
      printf("\n");
    }
  }
  printf("\n\n");
}

void first_set(Pazzle *paz, Cube c, int p_num){
  int i,x,y,z;
  for(i=0;i<c.c_num;i++){
    paz->space[c.ex_x[p_num][i]+1][c.ex_y[p_num][i]+1][c.ex_z[p_num][i]+1] = c.symbol;
  }
}

void search(Pazzle *paz, int *sol_num){
  int flag;
  int i,p,x,y,z,mv_x,mv_y,mv_z;
  Cube tmp_c;

  tmp_c = pop(paz);

  for(p=0;p<tmp_c.p_num;p++){
    for(mv_z=0;mv_z<3;mv_z++){
      for(mv_y=0;mv_y<3;mv_y++){
	for(mv_x=0;mv_x<3;mv_x++){
	  flag = 1;
	  for(i=0;i<tmp_c.c_num;i++){
	    if (tmp_c.ex_x[p][i]+1+mv_x > 3 || tmp_c.ex_y[p][i]+1+mv_y > 3 || tmp_c.ex_z[p][i]+1+mv_z > 3){
	      flag = 0;
	      goto OUT;
	    }
	    else if(paz->space[tmp_c.ex_x[p][i]+1+mv_x][tmp_c.ex_y[p][i]+1+mv_y][tmp_c.ex_z[p][i]+1+mv_z] != '.'){
	      flag = 0;
	      goto OUT;
	    }
	  }
	OUT:
	  if(flag == 1){ //合法手
	    for(i=0;i<tmp_c.c_num;i++){
	      paz->space[tmp_c.ex_x[p][i]+1+mv_x][tmp_c.ex_y[p][i]+1+mv_y][tmp_c.ex_z[p][i]+1+mv_z] = tmp_c.symbol;
	    }
	    if(paz->stack_num==0){ // 解を発見
	      *sol_num += 1;
	    }
	    else{
	      search(paz,sol_num);
	    }

	    for(i=0;i<tmp_c.c_num;i++){
	      paz->space[tmp_c.ex_x[p][i]+1+mv_x][tmp_c.ex_y[p][i]+1+mv_y][tmp_c.ex_z[p][i]+1+mv_z] = '.';
	    }

	  }
	}
      }
    }
  }

  push(paz, tmp_c);

}

