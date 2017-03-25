#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "allvars.h"
#include "proto.h"
#include "define.h"


int main()
{
    
  init_all();
  state("Initilzation done ...");
  
  load_gedget_part_to_array();
  state("Loading Gadget done ...");
  
  grid_density();
  state("Calculating density map done ...");
  
  write_file();
  state("Output done ...");
  
  free(pg);

  return 1;
}   /* end main */
