#ifndef _search_h
#define _search_h

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


void first_set(Pazzle *paz, Cube c, int p_num){
  int i,x,y,z;
  for(i=0;i<c.c_num;i++){
    paz->space[c.ex_x[p_num][i]+1][c.ex_y[p_num][i]+1][c.ex_z[p_num][i]+1] = c.symbol;
  }

  //show_space(paz->space);
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

#endif
