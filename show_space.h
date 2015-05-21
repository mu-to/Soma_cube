#ifndef _show_space_h
#define _show_space_h

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

#endif
