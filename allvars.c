#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "allvars.h"

 GRID **pg;                       /* this is for mother particles */

 int ngx;                               /* grid number in each dimension */
 int ngy;
 int gadget_file_num;
 double boxsize;
 double grid_disx;
 double grid_disy;
 double total_mass;
 double rho_total;
 double total_mass_ddm;
 #ifdef DECAY_DARK_MATTER
 double total_mass_dm;
 #endif
 long int total_part_num;

 GADGET_HEAD g_head;
