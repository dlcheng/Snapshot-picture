#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "allvars.h"
#include "proto.h"
#include "define.h"

void grid_density()
{
  int i, j;

  double grid_vol = grid_disx * grid_disy * boxsize * 0.1;

  for(i=0; i<ngx; i++)
  	for(j=0; j<ngy; j++)
  		{
  		 pg[i][j].rho_ddm /= grid_vol;
#ifdef DECAY_DARK_MATTER  		 
  	     pg[i][j].rho_dm  /= grid_vol;
#endif  	     
        }

}  /* end grid_density */