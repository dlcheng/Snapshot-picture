#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "allvars.h"
#include "proto.h"
#include "define.h"


GRID ** alloc_2d_array()
{
 int i;

  GRID ** pointer = (GRID **) malloc(ngx * sizeof(GRID *));

  for(i=0; i<ngy ; i++)
    pointer[i] = (GRID *) malloc(ngy * sizeof(GRID));

  return pointer;
}                              /* end create_3d_array */

void free_2d_array(GRID ** array)
{
 int i;

 for(i=0; i<ngy; i++)
   free(array[i]);

 free(array);
}                               /* end free_3d_array */

