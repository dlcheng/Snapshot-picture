#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "allvars.h"
#include "proto.h"
#include "define.h"


void assign_part(float *pos, float mass, unsigned int id)
{
#ifdef NGP
  int i, j;
  int flag;

  i = (int) (pos[0] / grid_disx);
  if(i > ngx-1)
    i = 0;

  j = (int) (pos[1] / grid_disy);
  if(j > ngy-1)
    j = 0;

  flag = slicing(pos[2]);
  
  if(flag)
    {
#ifdef DECAY_DARK_MATTER      
    if(id < g_head.Original_num)
      pg[i][j].rho_ddm += mass;
    else
      pg[i][j].rho_dm  += mass;
#else
    pg[i][j].rho_ddm += mass;
#endif    
    }

#ifdef DECAY_DARK_MATTER
  if(id < g_head.Original_num)
     total_mass_ddm += mass;
  else
     total_mass_dm += mass;
#else
  total_mass_ddm += mass;
#endif

#endif
}    /* end assign_part */

int slicing(double z)
{
  int flag = 0;
  double zmax = boxsize * 0.55;
  double zmin = boxsize * 0.45;

  if(z >= zmin && z <= zmax)
    flag = 1;

  return flag;
}    /* end slicing */
