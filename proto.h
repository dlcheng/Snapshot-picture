#ifndef ALLVAR_H
 #include "allvars.h"
#endif

void assign_part(float *pos, float mass, unsigned int id);
int slicing(double z);

void init_all();

void detect_and_link_gadget_file();
void load_gedget_part_to_array();
void wrap_pos(float *pos);
void check_gadget_file(char *file_name);

GRID ** alloc_2d_array();
void free_2d_array(GRID ** array);

void write_file();

void grid_density();

void warn_and_end(char *s);
void state(char *s);
