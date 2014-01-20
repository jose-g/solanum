/* version needs its own special procedure because any other might change
   and cause a crash before version mismatch is detected */

FINDABLE EXPORT double get_version() {
  double simile_version;
  sscanf(strstr(simile_identifier,"version="), "version=%lf", &simile_version);
  return(simile_version);
}

FINDABLE EXPORT void* do_createmodel(void) {
  return (void*)new AME_model;
}

FINDABLE EXPORT void do_updatemodel(void* handle, double time, int phase) {
  ((AME_model *)handle)->updatemodel(time, phase);
}

FINDABLE EXPORT void do_advancemodel(void* handle, double time, int phase) {
  ((AME_model *)handle)->advancemodel(time, phase);
}

jmp_buf env;

static void exit_sighandler(int x){
  longjmp(env, x);
}

FINDABLE EXPORT int do_evalmodel(void* handle, double time, int phase, BOOLEAN exo) {
  int error;

  /* Dont want a crash while running model to terminate Simile, so add
   handler. This has to be done on reset cos using the handler in some OS
   causes it to be unset, and a reset can restart a crashed model. */
  if (phase <= 0) {
    signal(SIGSEGV,exit_sighandler);
  }

  dts[0] = phase; // so external code can access it
  error = setjmp(env);
  if (error) {
    return -error;
  } else {
    try {
      if (exo) {
	((AME_model *)handle)->ext_evalmodel(time, phase);
      } else {
	((AME_model *)handle)->int_evalmodel(time, phase);
      }
    }
    catch (int error) {
      return error;
    }
    return 0;
  }
}

FINDABLE EXPORT void do_exitmodel(void* handle) {
  ((AME_model *)handle)->do_exitmodel();
  delete (AME_model *)handle;
}

/* setstep: the model class instances contain an array of doubles called
dts representing the time steps at the various phases. This function reaches
in and sets one of them. Returns phase count. Node that ts[0] is set to
the integration step being done: 0 for Euler, 1-4 for the four stages of RK

Also uses to get phase count */

FINDABLE EXPORT int do_setstep(double time, int phase) {
  if (phase>0) { /* lazy */
//    dts[phase] = time;
     dts[phase] = 1;
  } else {
    ts[-phase] = time;
  }
  return(phasecount);
}

//int at_time_step () {
//  return glob_element(dts,0)<=1;
//}
//
int loses (double prob, int phase) {
  int kills_per_step;
  if (prob<=0 || glob_element(ts,0)<0) {
    return 0;
  } else if (prob>=1) {
    return 1;
  } else {
    kills_per_step=glob_element(ts,0)?4:1;
    return ame_rand(0,1)>pow(1-prob,glob_element(dts,phase)/kills_per_step);
  }
}

double step_incr (int step, double v) {
//  dts[1]=0;
  return v*glob_element(dts, step);
}

double stage_incr (diffs *extras, int step, double v) {
  double dv, old_offset;

  dv = step_incr(step, v);
  switch (int(glob_element(ts, 0))) {
  case 1:
    extras->cumulative_value = dv/6;
    return (extras->current_offset = dv/2);
  case 2:
    extras->cumulative_value += dv/3;
    old_offset = extras->current_offset;
    return (extras->current_offset = dv/2) - old_offset;
  case 3:
    extras->cumulative_value += dv/3;
    old_offset = extras->current_offset;
    return (extras->current_offset = dv) - old_offset;
  case 4:
    extras->cumulative_value += dv/6;
    return extras->cumulative_value - extras->current_offset;
  default:
    return dv;
  };
};

FINDABLE EXPORT void* burrow_to(void* level, int** id_meta, int** dim_list) {
  while (**id_meta>0) { /* 0 means end of tree, -1 means vm level,
-2 means nested separate-dll submodel */
    level = ((submodeltype*)level)->get_pointer(step_list(id_meta,1),dim_list);
  }
  return(level);
};

/* This is called only when we create the type, to return model constants */
FINDABLE EXPORT int get_count(void* useClassPtr, void* ame_rand_ptr,
		       void* graphpoint_ptr,
		       void* release_graph_data_ptr,
		       void* compare_instance_status_ptr,
		       void* get_value_pointer_ptr,
		       void* fetch_instance_ptr,
		       void* update_submodel_ptr,
		       void* advance_submodel_ptr,
		       void* eval_submodel_ptr,
		       void* search_from_ptr,
		       void* advance_ptr_ptr,
		       void* get_remote_value_ptr,
		       void* stat_check_ptr,
		       void* showMess_ptr,
		       void* graph_ptr, int* phases, node_data_line** data_ptr,
		       int* arc_count, char*** arc_id_list) {

  /* Stub is telling us... */
  myClassPtr = useClassPtr;

  /* ...and also giving us function pointers to save us using the linker... */
  ame_rand_ref = (ame_rand_type*)ame_rand_ptr;
  graphpoint_ref = (graphpoint_type*)graphpoint_ptr;
  release_graph_data_ref = (release_graph_data_type*)release_graph_data_ptr;
  compare_instance_status = (compare_instance_status_type*)compare_instance_status_ptr;
  get_value_pointer_ref = (get_value_pointer_type*)get_value_pointer_ptr;
  fetch_instance_ref = (fetch_instance_type*)fetch_instance_ptr;
  update_submodel_ref = (update_submodel_type*)update_submodel_ptr;
  advance_submodel_ref = (advance_submodel_type*)advance_submodel_ptr;
  eval_submodel_ref = (eval_submodel_type*)eval_submodel_ptr;
  search_from_ref = (search_from_type*)search_from_ptr;
  advance_ptr_ref = (advance_ptr_type*)advance_ptr_ptr;
  get_remote_value = (get_remote_value_type*)get_remote_value_ptr;
  stat_check = (stat_check_type*)stat_check_ptr;
  showMess = (showMess_type*)showMess_ptr;

  graph_data_pointer = (graph_data_type**)graph_ptr;

  /* ...and we are telling stub... */
  *phases = phasecount;
  *data_ptr = nodedata;
  *arc_count = (sizeof inputArcs)/sizeof(char*)-1; /* don't include filler */
  *arc_id_list = inputArcs;
  return((sizeof nodedata)/sizeof(node_data_line));
}

/**********************************************************************/

/*
con la LoadLibrary e la pstub sono inutili, facciamo rifermento direttamente alle orinali!
extern "C" double __stdcall GetVersion()
{
  return(get_version());
}
extern "C" void* __stdcall DoCreateModel(void)
{
return (void*)new AME_model;
}
*/

/* GetNodeCount.... in realta' torna la stessa cosa di get_count...
  ... ma per il momento e' troppo pesante e quindi questa
e' piu' comoda per ora!!

--- dichiaramole __declspacc come piace a lui cosi' il simile+MinchW non rompe ----
*/
#ifdef WIN32
extern "C" __declspec( dllexport )
/*extern "C"  __stdcall */

int GetNodeCount(void* useClassPtr)
{
return((sizeof nodedata)/sizeof(node_data_line));
}

struct pass_data_line {
  char   name[16];
  int    datatype;
  int    eval;
  int    dims[32];
  int    path[32];
  int    graph;
  double min;
  double def;
  double max;
  int    compclass;
  char   caption[256];
};

extern "C" __declspec( dllexport )
/*extern "C" __stdcall */ int GetNodeData(int n,struct pass_data_line *PassStruct)
{
int i;
strcpy(PassStruct->name ,nodedata[n].name);
PassStruct->datatype =nodedata[n].datatype;
PassStruct->eval =nodedata[n].eval;
for(i=0;i<32;i++)
{
PassStruct->dims[i] =nodedata[n].dims[i];
PassStruct->path[i] =nodedata[n].path[i];
}
PassStruct->graph =nodedata[n].graph;
PassStruct->min =nodedata[n].min;
/* PassStruct->def =nodedata[n].def; */
PassStruct->max =nodedata[n].max;
PassStruct->compclass =nodedata[n].compclass;
strcpy(PassStruct->caption ,nodedata[n].strings[0]);
return n;
}
#endif

