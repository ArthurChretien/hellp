#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "pong.h"




void print_struct(struct s_pos my_s) {

  printf("(%.2f, %.2f, %.2f)\n", my_s.x, my_s.y, my_s.z);
  
}

void pong(struct s_pos prev_pos, struct s_pos pos, int n) {


  // fonction part 1 
  struct s_pos velocity;

  velocity.x = pos.x - prev_pos.x;
  velocity.y = pos.y - prev_pos.y;
  velocity.z = pos.z - prev_pos.z;
  printf("The velocity vector of the ball is:\n");
  print_struct(velocity);

  // end fonction part 1



  // fonction part 2

  struct s_pos final_pos;

  final_pos.x = pos.x + n * velocity.x;
  final_pos.y = pos.y + n * velocity.y;
  final_pos.z = pos.z + n * velocity.z;
  printf("At time t + %d, ball coordinates will be:\n", n);
  print_struct(final_pos);
  // end fonction part 2

  // fonction part 3


  if ((velocity.z == 0 && pos.z != 0) || (pos.z / velocity.z >= 0)) {
    printf("The ball won't reach the paddle.\n");
  }
  else {
    float angle;

    angle = 90 - (acos(fabsf(velocity.z)/sqrt(pow(velocity.x, 2) + pow(velocity.y, 2) + pow(velocity.z, 2))))* 180 / M_PI;
    printf("The incidence angle is:\n%.2f degrees\n", angle);
  }
  // end fonction part 3
}


int main(int ac, char **av) {

  struct s_pos prev_pos;
  struct s_pos pos;
  int n;

  if (ac != 8) {
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
      printf("USAGE\n");
      printf("\t./101pong x0 y0 z0 x1 y1 z1 n\n\n");
      printf("DESCRIPTION\n");
      printf("\tx0\tball abscissa at time t - 1\n");
      printf("\ty0\tball ordonate at time t - 1\n");
      printf("\tz0\tball altitude at time t - 1\n");
      printf("\tx1\tball abscissa at time t\n");
      printf("\ty1\tball ordonate at time t\n");
      printf("\tz1\tball altitude at time t\n");
      printf("\tn\ttime shift (greater than or equal to zero, integer)\n");
    }
    else {
      return (84);
    }
  }
  else {
    prev_pos.x = atof(av[1]);
    prev_pos.y = atof(av[2]);
    prev_pos.z = atof(av[3]);
    pos.x = atof(av[4]);
    pos.y = atof(av[5]);
    pos.z = atof(av[6]);
    if ((n = atoi(av[7])) < 0) {
      return (84);
    }
    pong(prev_pos, pos, n);
  }
  return (0);  
}
