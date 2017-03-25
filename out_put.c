#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "allvars.h"
#include "proto.h"
#include "define.h"

void write_file()
{
  int i, j;

  char file_name_ddm[500];
  FILE *fp_ddm;
  double mean_rho_ddm = total_mass_ddm / pow(boxsize, 3);
#ifdef DECAY_DARK_MATTER
  char file_name_dm[500];  
  FILE *fp_dm;  
  double mean_rho_dm  = total_mass_dm  / pow(boxsize, 3);
#endif  

#ifdef DECAY_DARK_MATTER  
  sprintf(file_name_ddm, "%s%s%.3f%s", OUTPUT_PATH, "pic_ddm_z_", g_head.Redshift, ".txt");
  sprintf(file_name_dm,  "%s%s%.3f%s", OUTPUT_PATH, "pic_dm_z_",  g_head.Redshift, ".txt");
#else
  sprintf(file_name_ddm, "%s%s%.3f%s", OUTPUT_PATH, "pic_cdm_z_", g_head.Redshift, ".txt");
#endif  

#ifdef DECAY_DARK_MATTER
  if((fp_ddm = fopen(file_name_ddm, "w+")) == NULL || (fp_dm = fopen(file_name_dm, "w+")) == NULL)    
    warn_and_end("Fail to open output files.");
#else
  if((fp_ddm = fopen(file_name_ddm, "w+")) == NULL)    
    warn_and_end("Fail to open output files.");
#endif  
    
 /* to plot the map in x-y plane,
    the overdensity of each species is defined by their own mean density. */   
  for(i=0; i<ngx; i++)
    for(j=0; j<ngy; j++)
      {	
       double delta_ddm = pg[i][j].rho_ddm/mean_rho_ddm - 1.0;
#ifdef DECAY_DARK_MATTER       
       double delta_dm  = pg[i][j].rho_dm /mean_rho_dm  - 1.0;
#endif       
       if(j != ngy - 1)
         {
          fprintf(fp_ddm, "%.6e\t", delta_ddm);
#ifdef DECAY_DARK_MATTER          
          fprintf(fp_dm,  "%.6e\t", delta_dm);
#endif          
         }
       else 
         {
          fprintf(fp_ddm, "%.6e\n", delta_ddm);
#ifdef DECAY_DARK_MATTER          
          fprintf(fp_dm,  "%.6e\n", delta_dm);
#endif          
         }  
      }

  fclose(fp_ddm);	
#ifdef DECAY_DARK_MATTER  
  fclose(fp_dm);
#endif  

}    /* end write file */	
