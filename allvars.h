#ifndef ALLVAR_H
#define ALLVAR_H

typedef struct grid GRID;
typedef struct gadget_head GADGET_HEAD;

struct gadget_head
{  
  unsigned int Npart[6];
  double Massarr[6];
  double Time;
  double Redshift;
  int FlagSfr;
  int FlagFeedback;
  int Nall[6];
  int  FlagCooling;
  int NumFiles;
  double BoxSize;
  double Omega0;
  double OmegaLambda;
  double HubbleParam;
  int FlagAge;
  int FlagMetals;
  int NallHW[6];
  int Flag_entr_ics;
#ifndef DECAY_DARK_MATTER
  char unused[60];         
#else
  unsigned int Original_num;                 /* the original particle number before decay */
  double Original_soften_length;             /* original particle's softening length  */
  char fill[48];                             /* new unused */
#endif
}; 

struct grid
{
  float rho_ddm;                             /* the density of ddm particles */
#ifdef DECAY_DARK_MATTER  
  float rho_dm;                              /* the density of dm particles  */
#endif  
};


extern GRID **pg;                            /* this is for mother particles */

extern int ngx;                              /* grid number in each dimension */
extern int ngy;
extern int gadget_file_num;
extern double boxsize;
extern double grid_disx;
extern double grid_disy;
extern double total_mass;
extern double rho_total;
extern double total_mass_ddm;
#ifdef DECAY_DARK_MATTER
extern double total_mass_dm;
#endif
extern long int total_part_num;

extern GADGET_HEAD g_head;

#endif
