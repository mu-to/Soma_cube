#include<stdio.h>
#include<stdlib.h>
#include"search.h"
#include"show_space.h"


// ------------------- prototype -----------------------------


Cube init_cube(char c);
Pazzle init_pazzle(void);


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


