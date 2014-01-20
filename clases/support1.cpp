#include	<stdarg.h>
#include        <signal.h>
#include        <setjmp.h>

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> /* for rand procedure used by tcl models */
#include <time.h>

/* Primitives
---------- */
#define	FALSE		0
#define	TRUE		1

#define BOOLEAN         int
/* possibly needed for Unix */

/* component types */
#define	SUBMODEL	0
#define VARIABLE        1
#define COMPARTMENT     2
#define FLOW            3
#define CONDITION       4
#define CREATION        5
#define REPRODUCTION    6
#define IMMIGRATION     7
#define LOSS            8
#define ALARM           9

/* data types */
#define	VALUELESS	0
#define REAL            1
#define INTEGER         2
#define FLAG            3
#define EXTERNAL        4

#define ENUM_BASE       -10

/* source of value */
#define EXOGENOUS       0
#define DERIVED         1
#define TABLE           2
#define INPUT           3
#define SPLIT           4
#define GHOST           5

/* special dimensions */
#define RECORDS        -1
#define MEMBERS        -2
#define SEPARATE       -3
#define START_VM       -4
#define END_VM         -5

/* integration methods */
#define EULER           0
#define RUNGE_KUTTA     1

#define SIMILE_VERSION	"4.9"

#ifdef WIN32
    #ifdef SHARELIB
	#define EXTDEC __declspec( dllexport )
    #else
	#define EXTDEC __declspec( dllimport )
    #endif
    #define EXPORT __declspec( dllexport )
#else
    #define EXTDEC
    #define EXPORT
#endif
#define FINDABLE extern "C"

/* type declaration for structure representing a graph */

typedef struct graph_data_type_t {
   double xlow;
   double xhigh;
   int xspan;
   double ylow;
   double yhigh;
   int yspan;
	int range;
   int xsize; /* assume I can't initialize it here */
   int* points;

   int index;
   struct graph_data_type_t* next;
   /*
   graph_data_type(int newIndex, graph_data_type* prev) {
     index = newIndex;
     next = prev;
   }

   ~graph_data_type() {
     delete(points);
     if (next) {
       delete(next);
     }
   }
   */
} graph_data_type; /* end of graph data type decl */


graph_data_type* find_graph (int index, graph_data_type* use_graph_pointer) {
  while (use_graph_pointer && use_graph_pointer->index != index) {
    use_graph_pointer = use_graph_pointer->next;
  }
  return(use_graph_pointer);
}
/*
class enum_data_type {
public:
  char* host;
  char* name;
  int mem_count;
  char** mems;

  enum_data_type* next;

  enum_data_type(char* newHost, char* newName,
		 int newMC, char** newMems, enum_data_type* prev) {
    host = newHost;
    name = newName;
    mem_count = newMC;
    mems = newMems;
    next = prev;
  }

   ~enum_data_type() {
     delete(mems);
     if (next) {
       delete(next);
     }
   }
}; /* end of enum data type decl */

/* above to be phased out -- we now have... */
typedef struct enum_type_data_t {
  int count;
  char* name;
  char** members;
} enum_type_data; /* end of enum type data type decl */

/* This declares the structure used by the generated code to hold metadata
about model components. It is repeated in the stub ame_cmx.cpp to access fields
outside the dll. */

typedef struct node_data_line_t {
  char name[16];
  int datatype;
  int enum_type_count;
  enum_type_data* enum_type_ptrs;
  int eval;
  int dims[32];
  int path[32];
  int graph;
  double min;
  double max;
  int compclass;
  char *strings[4];
} node_data_line; /* end(class,node_data_line) */

typedef struct connectRecord_t {
  char* TopArc;
  char* TopNode;
  char* SourceNode;
  int DestCount;
  char** Dests;
} connectRecord;

/* this is defined in the stub, which is loaded as a library...well it
   used to be, but now once the stub has loaded the dll it just sends
   over the pointers to all the functions used by the dll (the other
   method didn't work in win98) */

typedef double ame_rand_type(double, double);
typedef BOOLEAN interact_gui_type(void*, BOOLEAN, double);
typedef double graphpoint_type(double, graph_data_type*, int);
typedef void release_graph_data_type(graph_data_type*);
typedef int compare_instance_status_type (const int*, const int*, int);
typedef void get_value_pointer_type(void*, void*, int, int, int*);
typedef void* fetch_instance_type(char*);
typedef void update_submodel_type(char*, void*, double, int);
typedef void advance_submodel_type(char*, void*, double, int);
typedef int eval_submodel_type(char*, void*, double, int, BOOLEAN);
typedef void search_from_type(void*, int, void*);
typedef void* advance_ptr_type(void*, void*);
typedef void* get_remote_value_type(void*, void*, int, int, int*);
typedef int stat_check_type(void*);

typedef void showMess_type(char*);

/* These are for passing procedure addresses in the shim to the shank */

// typedef void get_value_pointer_type(void*, char*, int, int*);
// (its same as above)

/* Defined in the shank, used by the shim */
EXTDEC char* load_model(char*, char*, long int*);
EXTDEC void* use_array_for_params(char*, void*);
EXTDEC int clear_time_point_elts(char*);
EXTDEC int set_wrap(char*, double);
EXTDEC void* create_time_point(char*, double, void*);
EXTDEC int set_record_list(char*, int*, int);
EXTDEC int set_param_array_elt(char*, double, int*);
EXTDEC int set_time_point_elt(char*, double, double, int*);
EXTDEC get_value_pointer_type get_value_pointer;
EXTDEC int get_node_count(long int);
EXTDEC node_data_line* get_data_line(long int, int);
EXTDEC long int get_node_model_id(char*);
EXTDEC void release_graph_data(graph_data_type*);
EXTDEC double graphpoint(double, graph_data_type*, int);
EXTDEC double rand_fract();
EXTDEC graph_data_type** get_graph_base(long int);
EXTDEC node_data_line* searchinfo(char*, long int*, char*,
				  int*, int*, enum_type_data**);
EXTDEC long int fetch_top_instance(long int, char*);

EXTDEC int reset(long int, long int, int);
EXTDEC int execute(long int, long int, int, double, double*);
EXTDEC int setstep(long int, double, int);
EXTDEC char* myexit(long int, long int);

EXTDEC void* get_ptr(long int, long int, int**, int**);
EXTDEC char* getNodeId(long int, char*);

EXTDEC void proc_pointers_for_shank(interact_gui_type*, showMess_type*,
				    char*, connectRecord***, int**);
// use of regularData class
EXTDEC long int createRegularData (void);
EXTDEC void deleteRegularData (long int);
EXTDEC int rdSetToNodeValue(long int, long int, long int, char*);
EXTDEC int rdDimensionality(long int);
EXTDEC int rdDatatype(long int);
EXTDEC int rdBound(long int, int);
EXTDEC void* rdLocateElement(long int old, int* indices);


/* Every dll has a variable to hold the id of the model type instance it
   represents */
void* myClassPtr;


graph_data_type** graph_data_pointer;

/* Pointers to functions in the stub: */
ame_rand_type* ame_rand_ref;
graphpoint_type* graphpoint_ref;
release_graph_data_type* release_graph_data_ref;
compare_instance_status_type* compare_instance_status;
get_value_pointer_type* get_value_pointer_ref;
fetch_instance_type* fetch_instance_ref;
update_submodel_type* update_submodel_ref;
advance_submodel_type* advance_submodel_ref;
eval_submodel_type* eval_submodel_ref;
search_from_type* search_from_ref;
advance_ptr_type* advance_ptr_ref;
get_remote_value_type* get_remote_value;
stat_check_type* stat_check;
showMess_type* showMess;

int stop(int code) {
  throw code;
}

int lazy = 1024;
void abort_check (void* instId) {
  if (!lazy--) {
    lazy=1024;
    if (stat_check(instId)) {
      throw -101;
    }
  }
}

/*
 * Unix version: does not have min & max defined
 */
int min(int a, int b) {
  return a<b?a:b;
}
double min(int a, double b) {
  return a<b?a:b;
}
double min(double a, int b) {
  return a<b?a:b;
}
double min(double a, double b) {
  return a<b?a:b;
}
int max(int a, int b) {
  return a>b?a:b;
}
double max(int a, double b) {
  return a>b?a:b;
}
double max(double a, int b) {
  return a>b?a:b;
}
double max(double a, double b) {
  return a>b?a:b;
}

/* Pass on calls to stub functions made directly by built model */

double ame_rand(double lo, double hi) {
  return (*ame_rand_ref)(lo, hi);
}

double graphpoint(double xval, int indx) {
  return (*graphpoint_ref)(xval, *graph_data_pointer, indx);
}
/*
void release_graph_data(graph_data_type* graph) {
  (*release_graph_data_ref)(graph);
}
*/
void* fetch_instance(char* inst) {
  return (*fetch_instance_ref)(inst);
}

void update_submodel(char* id, void* inst, double time, int step) {
  (*update_submodel_ref)(id, inst, time, step);
}

void advance_submodel(char* id, void* inst, double time, int step) {
  (*advance_submodel_ref)(id, inst, time, step);
}

void int_eval_submodel(char* id, void* inst, double time, int step) {
  int error;
  error = (*eval_submodel_ref)(id, inst, time, step, 0);
  if (error) {
    throw error;
  }
}

void ext_eval_submodel(char* id, void* inst, double time, int step) {
  int error;
  error = (*eval_submodel_ref)(id, inst, time, step, 1);
  if (error) {
    throw error;
  }
}

void search_from(void* top, int section, void* found) {
  (*search_from_ref)(top, section, found);
}

/* try doing this one locally */
void* advance_ptr(void* mType, void* mInst) {
  return (*advance_ptr_ref)(mType, mInst);
}

/* class definition and handling procedure for extra variables used in
   complicated integration methods */

class diffs {
public:
  diffs () {
    current_offset = 1; // CAMBIO
    cumulative_value = 1;        //CAMBIO
  }
  ~diffs () {
  }
  double current_offset, cumulative_value;
};

double stage_incr (diffs*, int, double);
double step_incr (int, double);
//int at_time_step ();
int loses (double, int);

/* abstract base class for submodels, with extractor virtual function */
class submodeltype {
public:
  virtual void* get_pointer(int id, int** dims) = 0;
};

/* Fn template for deleting a linked list of models -- if non-null,
calls itself for the on pointer before deleting instance

template <class SMClass>
void delete_list (SMClass *ptr) {
  if (ptr) {
    delete_list(ptr->next);
    delete ptr;
  }
}

Above version is very elegant and recursive, but sadly causes stack
overflow for that very reason when deleting very long lists of
submodels. So instead...
*/

template <class SMClass>
void delete_list (SMClass *ptr) {
  SMClass *next_ptr;

  while (ptr) {
    next_ptr = ptr->next;
    delete ptr;
    ptr = next_ptr;
  }
}

double glob_element (double* arrptr, int phase) {
  double data=arrptr[phase];
  return arrptr[phase];
}

template <class DestClass>
void collect (DestClass* dest, int record_id, int id_count, ...) {
  va_list argptr;
  int curIndices[32];
  int length;

  va_start(argptr, id_count);
  for (length=0; length<id_count; length++) {
    curIndices[length] = va_arg(argptr, int);
  }
  va_end(argptr);

  (*get_value_pointer_ref)(myClassPtr, dest, record_id, id_count, curIndices);
}

template <class SMClass>
BOOLEAN prune (SMClass **metaptr, int id_count, ...) {
  int status = 1, length;
  SMClass *submodelptr;
  va_list argptr;
  int *curIndices;

  curIndices = new int[id_count];
  va_start(argptr, id_count);
  for (length=0; length<id_count; length++) {
    curIndices[length] = va_arg(argptr, int);
  }
  va_end(argptr);

  while (*metaptr &&
	 (status = (*compare_instance_status)((*metaptr)->instanceid,
				   curIndices, id_count)) == -1) {
    submodelptr = *metaptr;
    *metaptr = submodelptr->next;
    delete submodelptr;
  };
  delete curIndices;
  return !status;
}

template <class SMClass>
int init_pop (SMClass*** meta, double crNode, int ptCount, int channelId) {
  SMClass* submodelptr;
  int lastIndx;

  lastIndx = ptCount + max(0,(int)crNode);
  while (ptCount<lastIndx) {
    ++ptCount;
    if (prune(*meta, 1, ptCount)) {
      // from cond construct -- note new indx
      submodelptr = **meta;
      submodelptr->new_instance = 0;
      **meta = submodelptr->next;
    } else { /* Instance exists */
      submodelptr = new SMClass;
      submodelptr->instanceid[0] = ptCount;
      submodelptr->new_instance = 1;
    }; /* end(cond,Instance exists) */
    submodelptr->parentId = 0; // all new
    submodelptr->channelId = channelId; // (val from i_p_m)
    // from cond construct
    submodelptr->next = **meta;
    **meta = submodelptr;
    *meta = &(submodelptr->next);
  }; /* end(while,loop) */
  return lastIndx;
}

template <class SMClass>
void init_pop_member (SMClass *new_one, int index, int parent, int channel) {
  new_one->instanceid[0] = index;
  new_one->parentId = parent;
  new_one->channelId = channel;
  new_one->new_instance = 1;
  new_one->next = 0;
}

int* arrange_indices(int id_count, ...) {
  int length;
  va_list argptr;
  int *curIndices;

  curIndices = new int[id_count+1];
  va_start(argptr, id_count);
  for (length=0; length<id_count; length++) {
    curIndices[length] = va_arg(argptr, int);
  }
  va_end(argptr);
  curIndices[length] = 0;
  return curIndices;
}

BOOLEAN import_boolean(int level, void* topInstPtr, int arcId, int* indices) {
  BOOLEAN* gotValue;
  gotValue = (BOOLEAN*)(*get_remote_value)(myClassPtr, topInstPtr, level,
					arcId, indices);
  delete(indices);
  if (gotValue) {
    return *gotValue;
  } else {
    return 0;
  }
}

int import_int(int level, void* topInstPtr, int arcId, int* indices) {
  int* gotValue;
  gotValue = (int*)(*get_remote_value)(myClassPtr, topInstPtr, level,
				    arcId, indices);
  delete(indices);
  if (gotValue) {
    return *gotValue;
  } else {
    return 0;
  }
}

double import_real(int level, void* topInstPtr, int arcId, int* indices) {
  double* gotValue;
  gotValue = (double*)(*get_remote_value)(myClassPtr, topInstPtr, level,
				       arcId, indices);
  delete(indices);
  if (gotValue) {
    return *gotValue;
  } else {
    return 0.0;
  }
}

void* import_ptr(int level, void* topInstPtr,
		 int arcId, int* indices) {
  void** gotValue;
  gotValue = (void**)(*get_remote_value)(myClassPtr, topInstPtr, level,
				      arcId, indices);
  delete(indices);
  if (gotValue) {
    return *gotValue;
  } else {
    return NULL;
  }
}
/*
void insert_graph_data(
   graph_data_type *graph_data_pointer,
   double xlow,
   double xhigh,
   int xspan,
   double ylow,
   double yhigh,
   int yspan,
	int range,
   int size,
   int *array_data) {

   graph_data_pointer->xlow = xlow;
   graph_data_pointer->xhigh = xhigh;
   graph_data_pointer->xspan = xspan;
   graph_data_pointer->ylow = ylow;
   graph_data_pointer->yhigh = yhigh;
   graph_data_pointer->yspan = yspan;
   graph_data_pointer->range = range;
   graph_data_pointer->xsize = size;
   graph_data_pointer->points = array_data;
}
*/

void setup_graph_data(
   int index,
   double xlow,
   double xhigh,
   int xspan,
   double ylow,
   double yhigh,
   int yspan,
	int range,
   int xsize, ...) {

   va_list argptr;
   int length,right;
   int *array_data;
   graph_data_type* graphptr;

   //   array_data = (int *)(malloc(xsize*sizeof(int)));
   array_data = new int[xsize];

   va_start(argptr, xsize);
   right = va_arg(argptr, int);

   for (length=0;length<xsize;length++) {
	array_data[length] = right;
	right = va_arg(argptr,int);
   }
   va_end(argptr);

   graphptr = new graph_data_type;
   graphptr->index = index;
   graphptr->next = *graph_data_pointer;
   *graph_data_pointer = graphptr;

   graphptr->xlow = xlow;
   graphptr->xhigh = xhigh;
   graphptr->xspan = xspan;
   graphptr->ylow = ylow;
   graphptr->yhigh = yhigh;
   graphptr->yspan = yspan;
   graphptr->range = range;
   graphptr->xsize = xsize;
   graphptr->points = array_data;
}
/*
enum_data_type** enum_data_pointer;

void setup_enum_type_data(
   char *host, int mem_count, char* name, ...) {

   char* right;
   va_list argptr;
   int length;
   char** array_data;

   //   array_data = (int *)(malloc(xsize*sizeof(int)));
   array_data = new char*[mem_count];

   va_start(argptr, name);
   right = va_arg(argptr, char*);

   for (length=0;length<mem_count;length++) {
	array_data[length] = right;
	right = va_arg(argptr, char*);
   }
   va_end(argptr);

   *enum_data_pointer = new enum_data_type(host, name, mem_count, array_data,
					   *enum_data_pointer);
}

/* Some c++ do not allow either abs to be overloaded with doubles, or fabs
   with ints, so translate to myabs which works for both */

int myabs(int a) {
  return abs(a);
}
double myabs(double a) {
  return fabs(a);
}

/* Do same for pow, just in case -- absolute power corrupts absolutely --
actually not, cos an int to an int can also be a float if 2nd is -ve */

int step_list(int **dim_list, int unused) {
  return *(*dim_list)++;
}

void discard_instance(void* instanceId) {
}

int following(int lo) {
  return lo+1;
}

int preceding(int lo) {
  return lo-1;
}

int first(int lo) {
  return lo==1;
}
