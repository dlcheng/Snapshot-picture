#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "allvars.h"
#include "proto.h"
#include "define.h"

void init_all()
{
  int i, j;

  ngx = NGX;
  ngy = NGY;
  
  pg  = alloc_2d_array(); 
 
  for(i = 0; i < ngx; i++)
    for(j = 0; j < ngy; j++)
      {
        pg[i][j].rho_ddm = 0;
#ifdef DECAY_DARK_MATTER        
        pg[i][j].rho_dm = 0;
#endif        
	    }
	    
  detect_and_link_gadget_file();
  
  grid_disx = boxsize / (double) ngx;
  grid_disy = boxsize / (double) ngy;  

  total_mass =  (3e10 * MPCTOM /(8.0 * Pi * G0) / SUNTOKG) * pow(boxsize, 3) * g_head.Omega0;
  rho_total  = total_mass / pow(boxsize, 3);                   /* the mean density of matter */
  total_mass_ddm = 0.0;
#ifdef DECAY_DARK_MATTER  
  total_mass_dm  = 0.0;
#endif  
  
  printf("Omega_m = %.2f, Boxsize = %.1f[Mpc/h]\n", g_head.Omega0, g_head.BoxSize/1e3);
  printf("total_mass = %.3e, Total_num = %ld\n", total_mass, total_part_num);
#ifdef DECAY_DARK_MATTER  
  printf("Original_num of particles = %d\n", g_head.Original_num);
#endif

}    /* end init_all */
