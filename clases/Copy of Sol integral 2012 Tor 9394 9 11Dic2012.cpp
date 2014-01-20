#include "support1.cpp"
/* GLOBAL DECLARATIONS */
/* global this */
/* global array_7 */
/* global array_6 */
/* global array_5 */
/* global array_4 */
/* global array_3 */
/* global array_2 */
/* global array_1 */
/* global array_0 */
/* global array */
/* global array_18 */
/* global array_17 */
/* global array_16 */
/* global array_15 */
/* global array_14 */
/* global array_13 */
/* global array_12 */
/* global array_11 */
/* global array_10 */
/* global array_9 */
/* global array_8 */
/* global array_21 */
/* global array_20 */
/* global array_19 */
/* global array_33 */
/* global array_32 */
/* global array_31 */
/* global array_30 */
/* global array_29 */
/* global array_28 */
/* global array_27 */
/* global array_26 */
/* global array_25 */
/* global array_24 */
/* global array_23 */
/* global array_22 */
char simile_identifier[] = "program='AME',version=4.9,edition=enterprise,date=unused,size=241,";
int phasecount = 1;
int paramcount = 7;
int ind=-1;
double ts[2];
double dts[2];
#include "../Functions/procs.cpp"
/* CONSTANT DECLARATIONS */
int array_7[2] = {170, 1};
int array_6[2] = {134, 1};
int array_5[2] = {90, 1};
int array_4[2] = {80, 1};
int array_3[2] = {60, 1};
int array_2[2] = {20, 1};
int array_1[2] = {19, 1};
int array_0[2] = {18, 1};
int array[2] = {10, 1};
double array_18[13] = {0.9728, 0.00591, 0.00677, 612, 1718, 5.5, 0.8456, -2.4386, 722.6, 0.21, -1.0, -3.0, -4.0};
double array_17[13] = {0.66, 0.0036, 0.0064, 230, 1410, 2.65, 0.79, -5.3, 1098, 0.24, -1.5, -3.0, -6.0};
double array_16[13] = {0.66, 0.0036, 0.0064, 230, 1410, 2.65, 0.79, -5.3, 1098, 0.24, -1.9, -3.8, -6.0};
double array_15[13] = {0.74, 0.0043, 0.0061, 229, 1399, 2.85, 0.77, -8.1, 1061, 0.24, -1.9, -3.8, -6.0};
double array_14[13] = {0.63, 0.0043, 0.0061, 219, 1417, 2.79, 0.78, -6.1, 1083, 0.23, -1.8, -3.0, -6.0};
double array_13[13] = {0.65, 0.0033, 0.0063, 278, 1392, 2.69, 0.74, -7.4, 1074, 0.23, -1.6, -3.6, -6.0};
double array_12[13] = {1, 0.0049, 0.0066, 425, 1185, 2.88, 0.86, -4.8, 822, 0.22, -0.7, -3.3, -4.0};
double array_11[13] = {0.74, 0.004, 0.0064, 302, 1369, 2.53, 0.77, -5.5, 1061, 0.25, -1.0, -4.0, -5.0};
double array_10[13] = {0.78, 0.0028, 0.0072, 278, 1358, 2.65, 0.84, -7.5, 891, 0.31, -1.0, -4.0, -5.0};
double array_9[13] = {0.72, 0.0026, 0.0064, 249, 1385, 2.72, 0.74, -8.1, 1125, 0.3, -3.0, -5.0, -8.0};
double array_8[13] = {0.74, 0.0034, 0.0063, 253, 1360, 2.8, 0.8, -9.6, 944, 0.33, -2.4, -5.0, -7.0};
int array_21[3] = {4, 25, 35};
int array_20[3] = {2, 20, 28};
int array_19[3] = {0, 14, 25};
double array_33[7] = {1.51, 47, 32, 20, 125, 5.7, 3847.3};
double array_32[7] = {1.48, 50, 39, 27, 75, 10.6, 4172.3};
double array_31[7] = {1.46, 41, 22, 10, 500, 1.7, 3052.8};
double array_30[7] = {1.44, 38, 16, 8, 800, 1.8, 2627.0};
double array_29[7] = {1.44, 46, 31, 15, 250, 2.8, 3533.1};
double array_28[7] = {1.42, 36, 13, 6, 1500, 1.8, 2390.6};
double array_27[7] = {1.4, 50, 39, 23, 100, 7, 3863.0};
double array_26[7] = {1.37, 46, 33, 13, 150, 1.4, 3404.6};
double array_25[7] = {1.37, 43, 33, 9, 50, 1.4, 3404.6};
double array_24[7] = {1.36, 55, 54, 39, 2, 11, 4567.7};
double array_23[7] = {1.3, 52, 44, 23, 120, 6.4, 3862.5};
double array_22[7] = {1.24, 54, 50, 32, 15, 10.9, 3845.3};
char* inputArcs[] = {"end"};
/* STRUCTURE TYPE DECLARATIONS */

            class Tuber_production_Ftype : public submodeltype {
            public:
                Tuber_production_Ftype () {
                }; /* end(procedure,structor) */
                ~Tuber_production_Ftype () {
                }; /* end(procedure,structor) */
    double DTYf;
    double FTYf;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(DTYf));
        break; /* 1 */
        case 2:
        return(&(FTYf));
        break; /* 2 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,Tuber_production_Ftype) */

            class Total_dry_matter_prod_Ftype : public submodeltype {
            public:
                Total_dry_matter_prod_Ftype () {
                }; /* end(procedure,structor) */
                ~Total_dry_matter_prod_Ftype () {
                }; /* end(procedure,structor) */
    double RUEs_0;
    diffs anon_24;
    double TDMf;
    double dTDM_0;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(RUEs_0));
        break; /* 1 */
        case 2:
        return(&(anon_24));
        break; /* 2 */
        case 3:
        return(&(TDMf));
        break; /* 3 */
        case 4:
        return(&(dTDM_0));
        break; /* 4 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,Total_dry_matter_prod_Ftype) */

        class Frost_limited_productiontype : public submodeltype {
        public:
            Frost_limited_productiontype () {
            }; /* end(procedure,structor) */
            ~Frost_limited_productiontype () {
            }; /* end(procedure,structor) */
    int ptw_for_delayCC;
    int ptw_for_delayCC_last;
    int ptr_for_delayCC;
    double _array__for_delayCC[1000];
    double _array__for_delayCC_last[1000];
    int ptw_for_delayCCf;
    int ptw_for_delayCCf_last;
    int ptr_for_delayCCf;
    double _array__for_delayCCf[1000];
    double _array__for_delayCCf_last[1000];
    double CCRF;
    double CCL;
    diffs anon_25;
    double c1;
    double fay1;
    double delayCCf;
    double ay1;
    diffs anon_26;
    double c2;
    double fay2;
    double ay2;
    diffs anon_27;
    double C3;
    double CCf;
    double fccf;
    double Tcr;
    double Tld;
    double Trg;
    double Tmin_0;
    diffs anon_28;
    double REB;
    double Reb;
    double reba;
    double CC_0;
    double delayCC;
    double dCC;
    Tuber_production_Ftype Tuber_production_F;
    Total_dry_matter_prod_Ftype Total_dry_matter_prod_F;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(ptw_for_delayCC));
        break; /* 1 */
        case 2:
        return(&(ptw_for_delayCC_last));
        break; /* 2 */
        case 3:
        return(&(ptr_for_delayCC));
        break; /* 3 */
        case 4:
        return(&(_array__for_delayCC[step_list(dims, 2)]));
        break; /* 4 */
        case 5:
        return(&(_array__for_delayCC_last[step_list(dims, 2)]));
        break; /* 5 */
        case 6:
        return(&(ptw_for_delayCCf));
        break; /* 6 */
        case 7:
        return(&(ptw_for_delayCCf_last));
        break; /* 7 */
        case 8:
        return(&(ptr_for_delayCCf));
        break; /* 8 */
        case 9:
        return(&(_array__for_delayCCf[step_list(dims, 2)]));
        break; /* 9 */
        case 10:
        return(&(_array__for_delayCCf_last[step_list(dims, 2)]));
        break; /* 10 */
        case 11:
        return(&(CCRF));
        break; /* 11 */
        case 12:
        return(&(CCL));
        break; /* 12 */
        case 13:
        return(&(anon_25));
        break; /* 13 */
        case 14:
        return(&(c1));
        break; /* 14 */
        case 15:
        return(&(fay1));
        break; /* 15 */
        case 16:
        return(&(delayCCf));
        break; /* 16 */
        case 17:
        return(&(ay1));
        break; /* 17 */
        case 18:
        return(&(anon_26));
        break; /* 18 */
        case 19:
        return(&(c2));
        break; /* 19 */
        case 20:
        return(&(fay2));
        break; /* 20 */
        case 21:
        return(&(ay2));
        break; /* 21 */
        case 22:
        return(&(anon_27));
        break; /* 22 */
        case 23:
        return(&(C3));
        break; /* 23 */
        case 24:
        return(&(CCf));
        break; /* 24 */
        case 25:
        return(&(fccf));
        break; /* 25 */
        case 26:
        return(&(Tcr));
        break; /* 26 */
        case 27:
        return(&(Tld));
        break; /* 27 */
        case 28:
        return(&(Trg));
        break; /* 28 */
        case 29:
        return(&(Tmin_0));
        break; /* 29 */
        case 30:
        return(&(anon_28));
        break; /* 30 */
        case 31:
        return(&(REB));
        break; /* 31 */
        case 32:
        return(&(Reb));
        break; /* 32 */
        case 33:
        return(&(reba));
        break; /* 33 */
        case 34:
        return(&(CC_0));
        break; /* 34 */
        case 35:
        return(&(delayCC));
        break; /* 35 */
        case 36:
        return(&(dCC));
        break; /* 36 */
        case 37:
        return(&(Tuber_production_F));
        break; /* 37 */
        case 38:
        return(&(Total_dry_matter_prod_F));
        break; /* 38 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,Frost_limited_productiontype) */

        class Randomizetype : public submodeltype {
        public:
            Randomizetype () {
            }; /* end(procedure,structor) */
            ~Randomizetype () {
            }; /* end(procedure,structor) */
    double rnd_at_init;
    double rnd;
    double rdm;
    double v;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(rnd_at_init));
        break; /* 1 */
        case 2:
        return(&(rnd));
        break; /* 2 */
        case 3:
        return(&(rdm));
        break; /* 3 */
        case 4:
        return(&(v));
        break; /* 4 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,Randomizetype) */

            class NITRIFXNWtype : public submodeltype {
            public:
                NITRIFXNWtype () {
                }; /* end(procedure,structor) */
                ~NITRIFXNWtype () {
                }; /* end(procedure,structor) */
    double NO3ppm;
    double SANC;
    double SNH4;
    double ELNC;
    double min;
    double RP2;
    double phn;
    double min1;
    double A;
    double bb;
    double NH4ppm;
    diffs anon;
    double NO3POOL;
    double dNO3;
    double WFD;
    double RP22;
    double RNTRF;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(NO3ppm));
        break; /* 1 */
        case 2:
        return(&(SANC));
        break; /* 2 */
        case 3:
        return(&(SNH4));
        break; /* 3 */
        case 4:
        return(&(ELNC));
        break; /* 4 */
        case 5:
        return(&(min));
        break; /* 5 */
        case 6:
        return(&(RP2));
        break; /* 6 */
        case 7:
        return(&(phn));
        break; /* 7 */
        case 8:
        return(&(min1));
        break; /* 8 */
        case 9:
        return(&(A));
        break; /* 9 */
        case 10:
        return(&(bb));
        break; /* 10 */
        case 11:
        return(&(NH4ppm));
        break; /* 11 */
        case 12:
        return(&(anon));
        break; /* 12 */
        case 13:
        return(&(NO3POOL));
        break; /* 13 */
        case 14:
        return(&(dNO3));
        break; /* 14 */
        case 15:
        return(&(WFD));
        break; /* 15 */
        case 16:
        return(&(RP22));
        break; /* 16 */
        case 17:
        return(&(RNTRF));
        break; /* 17 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,NITRIFXNWtype) */

            class MIN_HUMUStype : public submodeltype {
            public:
                MIN_HUMUStype () {
                }; /* end(procedure,structor) */
                ~MIN_HUMUStype () {
                }; /* end(procedure,structor) */
    double NHUMi;
    double CHUMi;
    diffs anon_0;
    double NHUM;
    double flow109;
    double flow110;
    double MF;
    double TF;
    double RHMIN;
    diffs anon_1;
    double RHMINacum;
    double flow105;
    double DMINR;
    int DMOD;
    diffs anon_2;
    double HUM;
    double MFTF;
    double flow101;
    double flow102;
    diffs anon_3;
    double Hum_decomp__acum;
    double flow103;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(NHUMi));
        break; /* 1 */
        case 2:
        return(&(CHUMi));
        break; /* 2 */
        case 3:
        return(&(anon_0));
        break; /* 3 */
        case 4:
        return(&(NHUM));
        break; /* 4 */
        case 5:
        return(&(flow109));
        break; /* 5 */
        case 6:
        return(&(flow110));
        break; /* 6 */
        case 7:
        return(&(MF));
        break; /* 7 */
        case 8:
        return(&(TF));
        break; /* 8 */
        case 9:
        return(&(RHMIN));
        break; /* 9 */
        case 10:
        return(&(anon_1));
        break; /* 10 */
        case 11:
        return(&(RHMINacum));
        break; /* 11 */
        case 12:
        return(&(flow105));
        break; /* 12 */
        case 13:
        return(&(DMINR));
        break; /* 13 */
        case 14:
        return(&(DMOD));
        break; /* 14 */
        case 15:
        return(&(anon_2));
        break; /* 15 */
        case 16:
        return(&(HUM));
        break; /* 16 */
        case 17:
        return(&(MFTF));
        break; /* 17 */
        case 18:
        return(&(flow101));
        break; /* 18 */
        case 19:
        return(&(flow102));
        break; /* 19 */
        case 20:
        return(&(anon_3));
        break; /* 20 */
        case 21:
        return(&(Hum_decomp__acum));
        break; /* 21 */
        case 22:
        return(&(flow103));
        break; /* 22 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,MIN_HUMUStype) */

                class IMMOBIXNWtype : public submodeltype {
                public:
                    IMMOBIXNWtype () {
                    }; /* end(procedure,structor) */
                    ~IMMOBIXNWtype () {
                    }; /* end(procedure,structor) */
    diffs anon_4;
    double FOM;
    double grcom;
    diffs anon_5;
    double FON;
    double grnom;
    double RNAC;
    double REST;
    double RNACp;
    double rnac;
    double var1;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(anon_4));
        break; /* 1 */
        case 2:
        return(&(FOM));
        break; /* 2 */
        case 3:
        return(&(grcom));
        break; /* 3 */
        case 4:
        return(&(anon_5));
        break; /* 4 */
        case 5:
        return(&(FON));
        break; /* 5 */
        case 6:
        return(&(grnom));
        break; /* 6 */
        case 7:
        return(&(RNAC));
        break; /* 7 */
        case 8:
        return(&(REST));
        break; /* 8 */
        case 9:
        return(&(RNACp));
        break; /* 9 */
        case 10:
        return(&(rnac));
        break; /* 10 */
        case 11:
        return(&(var1));
        break; /* 11 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,IMMOBIXNWtype) */

                class Type_of_OM_addedtype : public submodeltype {
                public:
                    Type_of_OM_addedtype () {
                    }; /* end(procedure,structor) */
                    ~Type_of_OM_addedtype () {
                    }; /* end(procedure,structor) */
    int Type;
    int OM_CN[2];
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(Type));
        break; /* 1 */
        case 2:
        return(&(OM_CN[step_list(dims, 2)]));
        break; /* 2 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,Type_of_OM_addedtype) */

            class MIN_FOMAtype : public submodeltype {
            public:
                MIN_FOMAtype () {
                }; /* end(procedure,structor) */
                ~MIN_FOMAtype () {
                }; /* end(procedure,structor) */
    diffs anon_6;
    double FPOOLCE;
    double CE;
    double flow1;
    double GRNOMCE;
    double GRNOMLI;
    double LI;
    diffs anon_7;
    double FPOOLLI;
    double flow2;
    diffs anon_8;
    double NCE_acum;
    diffs anon_9;
    double NLI_acum;
    double CA;
    double G1CA;
    diffs anon_10;
    double FPOOLCA;
    double flow6;
    double flow3;
    double flow4;
    double GRNOM;
    diffs anon_11;
    double acumGRNOM;
    double GRNOMCA;
    diffs anon_12;
    double NCA_acum;
    double flow7;
    double G1CE;
    double G1LI;
    double flow107;
    double GRCOM;
    diffs anon_13;
    double acumGRCOM;
    double flow108;
    double _C;
    int CN;
    double _N;
    int FOMi;
    double FONi;
    double FOCi;
    double CNR;
    double CNRF;
    IMMOBIXNWtype IMMOBIXNW;
    Type_of_OM_addedtype Type_of_OM_added;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(anon_6));
        break; /* 1 */
        case 2:
        return(&(FPOOLCE));
        break; /* 2 */
        case 3:
        return(&(CE));
        break; /* 3 */
        case 4:
        return(&(flow1));
        break; /* 4 */
        case 5:
        return(&(GRNOMCE));
        break; /* 5 */
        case 6:
        return(&(GRNOMLI));
        break; /* 6 */
        case 7:
        return(&(LI));
        break; /* 7 */
        case 8:
        return(&(anon_7));
        break; /* 8 */
        case 9:
        return(&(FPOOLLI));
        break; /* 9 */
        case 10:
        return(&(flow2));
        break; /* 10 */
        case 11:
        return(&(anon_8));
        break; /* 11 */
        case 12:
        return(&(NCE_acum));
        break; /* 12 */
        case 13:
        return(&(anon_9));
        break; /* 13 */
        case 14:
        return(&(NLI_acum));
        break; /* 14 */
        case 15:
        return(&(CA));
        break; /* 15 */
        case 16:
        return(&(G1CA));
        break; /* 16 */
        case 17:
        return(&(anon_10));
        break; /* 17 */
        case 18:
        return(&(FPOOLCA));
        break; /* 18 */
        case 19:
        return(&(flow6));
        break; /* 19 */
        case 20:
        return(&(flow3));
        break; /* 20 */
        case 21:
        return(&(flow4));
        break; /* 21 */
        case 22:
        return(&(GRNOM));
        break; /* 22 */
        case 23:
        return(&(anon_11));
        break; /* 23 */
        case 24:
        return(&(acumGRNOM));
        break; /* 24 */
        case 25:
        return(&(GRNOMCA));
        break; /* 25 */
        case 26:
        return(&(anon_12));
        break; /* 26 */
        case 27:
        return(&(NCA_acum));
        break; /* 27 */
        case 28:
        return(&(flow7));
        break; /* 28 */
        case 29:
        return(&(G1CE));
        break; /* 29 */
        case 30:
        return(&(G1LI));
        break; /* 30 */
        case 31:
        return(&(flow107));
        break; /* 31 */
        case 32:
        return(&(GRCOM));
        break; /* 32 */
        case 33:
        return(&(anon_13));
        break; /* 33 */
        case 34:
        return(&(acumGRCOM));
        break; /* 34 */
        case 35:
        return(&(flow108));
        break; /* 35 */
        case 36:
        return(&(_C));
        break; /* 36 */
        case 37:
        return(&(CN));
        break; /* 37 */
        case 38:
        return(&(_N));
        break; /* 38 */
        case 39:
        return(&(FOMi));
        break; /* 39 */
        case 40:
        return(&(FONi));
        break; /* 40 */
        case 41:
        return(&(FOCi));
        break; /* 41 */
        case 42:
        return(&(CNR));
        break; /* 42 */
        case 43:
        return(&(CNRF));
        break; /* 43 */
        case 44:
        return(&(IMMOBIXNW));
        break; /* 44 */
        case 45:
        return(&(Type_of_OM_added));
        break; /* 45 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,MIN_FOMAtype) */

            class UREA_HYDtype : public submodeltype {
            public:
                UREA_HYDtype () {
                }; /* end(procedure,structor) */
                ~UREA_HYDtype () {
                }; /* end(procedure,structor) */
    double AK;
    double SWF;
    double MFU;
    double TFU;
    int UREA;
    double NUREAi;
    double UHYDR;
    double var13;
    double TFF;
    double AKU;
    diffs anon_14;
    double NUREA;
    double flow1_0;
    diffs anon_15;
    double comp2;
    double flow2_0;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(AK));
        break; /* 1 */
        case 2:
        return(&(SWF));
        break; /* 2 */
        case 3:
        return(&(MFU));
        break; /* 3 */
        case 4:
        return(&(TFU));
        break; /* 4 */
        case 5:
        return(&(UREA));
        break; /* 5 */
        case 6:
        return(&(NUREAi));
        break; /* 6 */
        case 7:
        return(&(UHYDR));
        break; /* 7 */
        case 8:
        return(&(var13));
        break; /* 8 */
        case 9:
        return(&(TFF));
        break; /* 9 */
        case 10:
        return(&(AKU));
        break; /* 10 */
        case 11:
        return(&(anon_14));
        break; /* 11 */
        case 12:
        return(&(NUREA));
        break; /* 12 */
        case 13:
        return(&(flow1_0));
        break; /* 13 */
        case 14:
        return(&(anon_15));
        break; /* 14 */
        case 15:
        return(&(comp2));
        break; /* 15 */
        case 16:
        return(&(flow2_0));
        break; /* 16 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,UREA_HYDtype) */

            class FERTILIZERStype : public submodeltype {
            public:
                FERTILIZERStype () {
                }; /* end(procedure,structor) */
                ~FERTILIZERStype () {
                }; /* end(procedure,structor) */
    int amount;
    double NH4_fert;
    double NO3fert;
    double NH4am;
    double NO3am;
    int Fert;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(amount));
        break; /* 1 */
        case 2:
        return(&(NH4_fert));
        break; /* 2 */
        case 3:
        return(&(NO3fert));
        break; /* 3 */
        case 4:
        return(&(NH4am));
        break; /* 4 */
        case 5:
        return(&(NO3am));
        break; /* 5 */
        case 6:
        return(&(Fert));
        break; /* 6 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,FERTILIZERStype) */

        class N_dynamicstype : public submodeltype {
        public:
            N_dynamicstype () {
            }; /* end(procedure,structor) */
            ~N_dynamicstype () {
            }; /* end(procedure,structor) */
    double Nac;
    double flow2_1;
    double var19;
    diffs anon_16;
    double flow205;
    double cd108;
    double NH4o;
    double NNOM;
    diffs anon_17;
    double flow102_0;
    double N_lib_acum;
    double TOTN;
    double NH4u;
    diffs anon_18;
    double NH4POOL;
    double flow4_0;
    NITRIFXNWtype NITRIFXNW;
    MIN_HUMUStype MIN_HUMUS;
    MIN_FOMAtype MIN_FOMA;
    UREA_HYDtype UREA_HYD;
    FERTILIZERStype FERTILIZERS;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(Nac));
        break; /* 1 */
        case 2:
        return(&(flow2_1));
        break; /* 2 */
        case 3:
        return(&(var19));
        break; /* 3 */
        case 4:
        return(&(anon_16));
        break; /* 4 */
        case 5:
        return(&(flow205));
        break; /* 5 */
        case 6:
        return(&(cd108));
        break; /* 6 */
        case 7:
        return(&(NH4o));
        break; /* 7 */
        case 8:
        return(&(NNOM));
        break; /* 8 */
        case 9:
        return(&(anon_17));
        break; /* 9 */
        case 10:
        return(&(flow102_0));
        break; /* 10 */
        case 11:
        return(&(N_lib_acum));
        break; /* 11 */
        case 12:
        return(&(TOTN));
        break; /* 12 */
        case 13:
        return(&(NH4u));
        break; /* 13 */
        case 14:
        return(&(anon_18));
        break; /* 14 */
        case 15:
        return(&(NH4POOL));
        break; /* 15 */
        case 16:
        return(&(flow4_0));
        break; /* 16 */
        case 17:
        return(&(NITRIFXNW));
        break; /* 17 */
        case 18:
        return(&(MIN_HUMUS));
        break; /* 18 */
        case 19:
        return(&(MIN_FOMA));
        break; /* 19 */
        case 20:
        return(&(UREA_HYD));
        break; /* 20 */
        case 21:
        return(&(FERTILIZERS));
        break; /* 21 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,N_dynamicstype) */

        class Weathertype : public submodeltype {
        public:
            Weathertype () {
            }; /* end(procedure,structor) */
            ~Weathertype () {
            }; /* end(procedure,structor) */
    double SoilTemp[365];
    double Tsoi;
    double Irrigation[365];
    double Irri;
    double PET[365];
    double ETo;
    double MinTemp[365];
    double MaxTemp[365];
    double Rainfall[365];
    double Tmax;
    double Radiation[365];
    double Tmin;
    double Rain;
    double PAR;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(SoilTemp[step_list(dims, 2)]));
        break; /* 1 */
        case 2:
        return(&(Tsoi));
        break; /* 2 */
        case 3:
        return(&(Irrigation[step_list(dims, 2)]));
        break; /* 3 */
        case 4:
        return(&(Irri));
        break; /* 4 */
        case 5:
        return(&(PET[step_list(dims, 2)]));
        break; /* 5 */
        case 6:
        return(&(ETo));
        break; /* 6 */
        case 7:
        return(&(MinTemp[step_list(dims, 2)]));
        break; /* 7 */
        case 8:
        return(&(MaxTemp[step_list(dims, 2)]));
        break; /* 8 */
        case 9:
        return(&(Rainfall[step_list(dims, 2)]));
        break; /* 9 */
        case 10:
        return(&(Tmax));
        break; /* 10 */
        case 11:
        return(&(Radiation[step_list(dims, 2)]));
        break; /* 11 */
        case 12:
        return(&(Tmin));
        break; /* 12 */
        case 13:
        return(&(Rain));
        break; /* 13 */
        case 14:
        return(&(PAR));
        break; /* 14 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,Weathertype) */

        class Varietytype : public submodeltype {
        public:
            Varietytype () {
            }; /* end(procedure,structor) */
            ~Varietytype () {
            }; /* end(procedure,structor) */
    double Inputs[13];
    int Var_Name;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(Inputs[step_list(dims, 2)]));
        break; /* 1 */
        case 2:
        return(&(Var_Name));
        break; /* 2 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,Varietytype) */

        class Thermal_timetype : public submodeltype {
        public:
            Thermal_timetype () {
            }; /* end(procedure,structor) */
            ~Thermal_timetype () {
            }; /* end(procedure,structor) */
    int Thermal_conditions;
    double TC[3];
    double W;
    diffs anon_19;
    double Tac;
    double Tb;
    double To;
    double Th;
    double Te;
    double Tav;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(Thermal_conditions));
        break; /* 1 */
        case 2:
        return(&(TC[step_list(dims, 2)]));
        break; /* 2 */
        case 3:
        return(&(W));
        break; /* 3 */
        case 4:
        return(&(anon_19));
        break; /* 4 */
        case 5:
        return(&(Tac));
        break; /* 5 */
        case 6:
        return(&(Tb));
        break; /* 6 */
        case 7:
        return(&(To));
        break; /* 7 */
        case 8:
        return(&(Th));
        break; /* 8 */
        case 9:
        return(&(Te));
        break; /* 9 */
        case 10:
        return(&(Tav));
        break; /* 10 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,Thermal_timetype) */

            class Planting_Datetype : public submodeltype {
            public:
                Planting_Datetype () {
                }; /* end(procedure,structor) */
                ~Planting_Datetype () {
                }; /* end(procedure,structor) */
    int dd;
    int mm;
    int PDate;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(dd));
        break; /* 1 */
        case 2:
        return(&(mm));
        break; /* 2 */
        case 3:
        return(&(PDate));
        break; /* 3 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,Planting_Datetype) */

        class Timetype : public submodeltype {
        public:
            Timetype () {
            }; /* end(procedure,structor) */
            ~Timetype () {
            }; /* end(procedure,structor) */
    int month;
    double day;
    int EDay;
    double DAE;
    double PDay;
    Planting_Datetype Planting_Date;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(month));
        break; /* 1 */
        case 2:
        return(&(day));
        break; /* 2 */
        case 3:
        return(&(EDay));
        break; /* 3 */
        case 4:
        return(&(DAE));
        break; /* 4 */
        case 5:
        return(&(PDay));
        break; /* 5 */
        case 6:
        return(&(Planting_Date));
        break; /* 6 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,Timetype) */

            class Soil_temp_esttype : public submodeltype {
            public:
                Soil_temp_esttype () {
                }; /* end(procedure,structor) */
                ~Soil_temp_esttype () {
                }; /* end(procedure,structor) */
    double k;
    double c;
    double Stemp;
    double Tl;
    int Dl;
    double D;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(k));
        break; /* 1 */
        case 2:
        return(&(c));
        break; /* 2 */
        case 3:
        return(&(Stemp));
        break; /* 3 */
        case 4:
        return(&(Tl));
        break; /* 4 */
        case 5:
        return(&(Dl));
        break; /* 5 */
        case 6:
        return(&(D));
        break; /* 6 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,Soil_temp_esttype) */

        class Soil_parameterstype : public submodeltype {
        public:
            Soil_parameterstype () {
            }; /* end(procedure,structor) */
            ~Soil_parameterstype () {
            }; /* end(procedure,structor) */
    double Po;
    double cl;
    double FC;
    double WP;
    double CL;
    int OM;
    double OMw;
    double OC;
    double ISM;
    int pH;
    double fc;
    double wp;
    int Soil_texture;
    double Hydric[7];
    int Area;
    double Soil_depth;
    double Soil_Vol;
    double SWeight;
    double BD;
    Soil_temp_esttype Soil_temp_est;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(Po));
        break; /* 1 */
        case 2:
        return(&(cl));
        break; /* 2 */
        case 3:
        return(&(FC));
        break; /* 3 */
        case 4:
        return(&(WP));
        break; /* 4 */
        case 5:
        return(&(CL));
        break; /* 5 */
        case 6:
        return(&(OM));
        break; /* 6 */
        case 7:
        return(&(OMw));
        break; /* 7 */
        case 8:
        return(&(OC));
        break; /* 8 */
        case 9:
        return(&(ISM));
        break; /* 9 */
        case 10:
        return(&(pH));
        break; /* 10 */
        case 11:
        return(&(fc));
        break; /* 11 */
        case 12:
        return(&(wp));
        break; /* 12 */
        case 13:
        return(&(Soil_texture));
        break; /* 13 */
        case 14:
        return(&(Hydric[step_list(dims, 2)]));
        break; /* 14 */
        case 15:
        return(&(Area));
        break; /* 15 */
        case 16:
        return(&(Soil_depth));
        break; /* 16 */
        case 17:
        return(&(Soil_Vol));
        break; /* 17 */
        case 18:
        return(&(SWeight));
        break; /* 18 */
        case 19:
        return(&(BD));
        break; /* 19 */
        case 20:
        return(&(Soil_temp_est));
        break; /* 20 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,Soil_parameterstype) */

        class Soil_water_Balancetype : public submodeltype {
        public:
            Soil_water_Balancetype () {
            }; /* end(procedure,structor) */
            ~Soil_water_Balancetype () {
            }; /* end(procedure,structor) */
    double Eo;
    double s;
    diffs anon_20;
    double CS;
    double S;
    double To_0;
    double T;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(Eo));
        break; /* 1 */
        case 2:
        return(&(s));
        break; /* 2 */
        case 3:
        return(&(anon_20));
        break; /* 3 */
        case 4:
        return(&(CS));
        break; /* 4 */
        case 5:
        return(&(S));
        break; /* 5 */
        case 6:
        return(&(To_0));
        break; /* 6 */
        case 7:
        return(&(T));
        break; /* 7 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,Soil_water_Balancetype) */

            class Water_stresstype : public submodeltype {
            public:
                Water_stresstype () {
                }; /* end(procedure,structor) */
                ~Water_stresstype () {
                }; /* end(procedure,structor) */
    diffs anon_21;
    double Ws;
    double CWs;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(anon_21));
        break; /* 1 */
        case 2:
        return(&(Ws));
        break; /* 2 */
        case 3:
        return(&(CWs));
        break; /* 3 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,Water_stresstype) */

            class Total_dry_matter_production_Wtype : public submodeltype {
            public:
                Total_dry_matter_production_Wtype () {
                }; /* end(procedure,structor) */
                ~Total_dry_matter_production_Wtype () {
                }; /* end(procedure,structor) */
    diffs anon_22;
    double dTDM;
    double TDMw;
    double RUEw;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(anon_22));
        break; /* 1 */
        case 2:
        return(&(dTDM));
        break; /* 2 */
        case 3:
        return(&(TDMw));
        break; /* 3 */
        case 4:
        return(&(RUEw));
        break; /* 4 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,Total_dry_matter_production_Wtype) */

            class Tuber_production_Wtype : public submodeltype {
            public:
                Tuber_production_Wtype () {
                }; /* end(procedure,structor) */
                ~Tuber_production_Wtype () {
                }; /* end(procedure,structor) */
    double DTYw;
    double FTYw;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(DTYw));
        break; /* 1 */
        case 2:
        return(&(FTYw));
        break; /* 2 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,Tuber_production_Wtype) */

            class Canopy_Cover_Wtype : public submodeltype {
            public:
                Canopy_Cover_Wtype () {
                }; /* end(procedure,structor) */
                ~Canopy_Cover_Wtype () {
                }; /* end(procedure,structor) */
    double CCw;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(CCw));
        break; /* 1 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,Canopy_Cover_Wtype) */

        class Water_limited_productiontype : public submodeltype {
        public:
            Water_limited_productiontype () {
            }; /* end(procedure,structor) */
            ~Water_limited_productiontype () {
            }; /* end(procedure,structor) */
    double RUEs;
    Water_stresstype Water_stress;
    Total_dry_matter_production_Wtype Total_dry_matter_production_W;
    Tuber_production_Wtype Tuber_production_W;
    Canopy_Cover_Wtype Canopy_Cover_W;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(RUEs));
        break; /* 1 */
        case 2:
        return(&(Water_stress));
        break; /* 2 */
        case 3:
        return(&(Total_dry_matter_production_W));
        break; /* 3 */
        case 4:
        return(&(Tuber_production_W));
        break; /* 4 */
        case 5:
        return(&(Canopy_Cover_W));
        break; /* 5 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,Water_limited_productiontype) */

            class Canopy_covertype : public submodeltype {
            public:
                Canopy_covertype () {
                }; /* end(procedure,structor) */
                ~Canopy_covertype () {
                }; /* end(procedure,structor) */
    double flinti;
    double N;
    double Flint1;
    double Flint2;
    double CC;
    double d;
    double f0;
    double R0;
    double t50;
    double MCC;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(flinti));
        break; /* 1 */
        case 2:
        return(&(N));
        break; /* 2 */
        case 3:
        return(&(Flint1));
        break; /* 3 */
        case 4:
        return(&(Flint2));
        break; /* 4 */
        case 5:
        return(&(CC));
        break; /* 5 */
        case 6:
        return(&(d));
        break; /* 6 */
        case 7:
        return(&(f0));
        break; /* 7 */
        case 8:
        return(&(R0));
        break; /* 8 */
        case 9:
        return(&(t50));
        break; /* 9 */
        case 10:
        return(&(MCC));
        break; /* 10 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,Canopy_covertype) */

            class Total_dry_matter_productiontype : public submodeltype {
            public:
                Total_dry_matter_productiontype () {
                }; /* end(procedure,structor) */
                ~Total_dry_matter_productiontype () {
                }; /* end(procedure,structor) */
    double RUE;
    diffs anon_23;
    double TDM;
    double dW;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(RUE));
        break; /* 1 */
        case 2:
        return(&(anon_23));
        break; /* 2 */
        case 3:
        return(&(TDM));
        break; /* 3 */
        case 4:
        return(&(dW));
        break; /* 4 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,Total_dry_matter_productiontype) */

            class Tuber_productiontype : public submodeltype {
            public:
                Tuber_productiontype () {
                }; /* end(procedure,structor) */
                ~Tuber_productiontype () {
                }; /* end(procedure,structor) */
    double M;
    double A_0;
    double DTY;
    double b;
    double Part;
    double DMcont;
    double FTY;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(M));
        break; /* 1 */
        case 2:
        return(&(A_0));
        break; /* 2 */
        case 3:
        return(&(DTY));
        break; /* 3 */
        case 4:
        return(&(b));
        break; /* 4 */
        case 5:
        return(&(Part));
        break; /* 5 */
        case 6:
        return(&(DMcont));
        break; /* 6 */
        case 7:
        return(&(FTY));
        break; /* 7 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,Tuber_productiontype) */

        class Potential_productiontype : public submodeltype {
        public:
            Potential_productiontype () {
            }; /* end(procedure,structor) */
            ~Potential_productiontype () {
            }; /* end(procedure,structor) */
    Canopy_covertype Canopy_cover;
    Total_dry_matter_productiontype Total_dry_matter_production;
    Tuber_productiontype Tuber_production;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(Canopy_cover));
        break; /* 1 */
        case 2:
        return(&(Total_dry_matter_production));
        break; /* 2 */
        case 3:
        return(&(Tuber_production));
        break; /* 3 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,Potential_productiontype) */

            class Canopy_cover_Ntype : public submodeltype {
            public:
                Canopy_cover_Ntype () {
                }; /* end(procedure,structor) */
                ~Canopy_cover_Ntype () {
                }; /* end(procedure,structor) */
    double CCn;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(CCn));
        break; /* 1 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,Canopy_cover_Ntype) */

            class Total_dry_matter_production_Ntype : public submodeltype {
            public:
                Total_dry_matter_production_Ntype () {
                }; /* end(procedure,structor) */
                ~Total_dry_matter_production_Ntype () {
                }; /* end(procedure,structor) */
    diffs anon_29;
    double dTDM_1;
    double TDMn;
    double RUE_0;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(anon_29));
        break; /* 1 */
        case 2:
        return(&(dTDM_1));
        break; /* 2 */
        case 3:
        return(&(TDMn));
        break; /* 3 */
        case 4:
        return(&(RUE_0));
        break; /* 4 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,Total_dry_matter_production_Ntype) */

            class Tuber_production_Ntype : public submodeltype {
            public:
                Tuber_production_Ntype () {
                }; /* end(procedure,structor) */
                ~Tuber_production_Ntype () {
                }; /* end(procedure,structor) */
    double FTYn;
    double DTYn;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(FTYn));
        break; /* 1 */
        case 2:
        return(&(DTYn));
        break; /* 2 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,Tuber_production_Ntype) */

            class N_stresstype : public submodeltype {
            public:
                N_stresstype () {
                }; /* end(procedure,structor) */
                ~N_stresstype () {
                }; /* end(procedure,structor) */
    double Npot;
    double Npc;
    double NacNpot;
    double GC0;
    int GC250;
    double Ns;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(Npot));
        break; /* 1 */
        case 2:
        return(&(Npc));
        break; /* 2 */
        case 3:
        return(&(NacNpot));
        break; /* 3 */
        case 4:
        return(&(GC0));
        break; /* 4 */
        case 5:
        return(&(GC250));
        break; /* 5 */
        case 6:
        return(&(Ns));
        break; /* 6 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,N_stresstype) */

        class Nitrogen_limited_productiontype : public submodeltype {
        public:
            Nitrogen_limited_productiontype () {
            }; /* end(procedure,structor) */
            ~Nitrogen_limited_productiontype () {
            }; /* end(procedure,structor) */
    Canopy_cover_Ntype Canopy_cover_N;
    Total_dry_matter_production_Ntype Total_dry_matter_production_N;
    Tuber_production_Ntype Tuber_production_N;
    N_stresstype N_stress;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(Canopy_cover_N));
        break; /* 1 */
        case 2:
        return(&(Total_dry_matter_production_N));
        break; /* 2 */
        case 3:
        return(&(Tuber_production_N));
        break; /* 3 */
        case 4:
        return(&(N_stress));
        break; /* 4 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,Nitrogen_limited_productiontype) */

    class Sol_integral_2012_Tor_9394_9type : public submodeltype {
    public:
        Sol_integral_2012_Tor_9394_9type () {
        }; /* end(procedure,structor) */
        ~Sol_integral_2012_Tor_9394_9type () {
        }; /* end(procedure,structor) */
    Frost_limited_productiontype Frost_limited_production;
    Randomizetype Randomize;
    N_dynamicstype N_dynamics;
    Weathertype Weather;
    Varietytype Variety;
    Thermal_timetype Thermal_time;
    Timetype Time;
    Soil_parameterstype Soil_parameters;
    Soil_water_Balancetype Soil_water_Balance;
    Water_limited_productiontype Water_limited_production;
    Potential_productiontype Potential_production;
    Nitrogen_limited_productiontype Nitrogen_limited_production;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(Frost_limited_production));
        break; /* 1 */
        case 2:
        return(&(Randomize));
        break; /* 2 */
        case 3:
        return(&(N_dynamics));
        break; /* 3 */
        case 4:
        return(&(Weather));
        break; /* 4 */
        case 5:
        return(&(Variety));
        break; /* 5 */
        case 6:
        return(&(Thermal_time));
        break; /* 6 */
        case 7:
        return(&(Time));
        break; /* 7 */
        case 8:
        return(&(Soil_parameters));
        break; /* 8 */
        case 9:
        return(&(Soil_water_Balance));
        break; /* 9 */
        case 10:
        return(&(Water_limited_production));
        break; /* 10 */
        case 11:
        return(&(Potential_production));
        break; /* 11 */
        case 12:
        return(&(Nitrogen_limited_production));
        break; /* 12 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
}; /* end(class,Sol_integral_2012_Tor_9394_9type) */

class AME_model : public submodeltype {
public:
    AME_model () {
    }; /* end(procedure,structor) */
    ~AME_model () {
    }; /* end(procedure,structor) */
    Sol_integral_2012_Tor_9394_9type Sol_integral_2012_Tor_9394_9;
void* get_pointer (int id, int** dims) {
    switch (id) {
        case 1:
        return(&(Sol_integral_2012_Tor_9394_9));
        break; /* 1 */
    }; /* end(switch,id) */
    return(NULL);
}; /* end(procedure,get_pointer) */
/* EVALUATION PROCEDURE DECLARATION */

void updatemodel (double start_time, int phase) {

/* GLOBAL DECLARATIONS */
/* global this */
/* global array_7 */
/* global array_6 */
/* global array_5 */
/* global array_4 */
/* global array_3 */
/* global array_2 */
/* global array_1 */
/* global array_0 */
/* global array */
/* global array_18 */
/* global array_17 */
/* global array_16 */
/* global array_15 */
/* global array_14 */
/* global array_13 */
/* global array_12 */
/* global array_11 */
/* global array_10 */
/* global array_9 */
/* global array_8 */
/* global array_21 */
/* global array_20 */
/* global array_19 */
/* global array_33 */
/* global array_32 */
/* global array_31 */
/* global array_30 */
/* global array_29 */
/* global array_28 */
/* global array_27 */
/* global array_26 */
/* global array_25 */
/* global array_24 */
/* global array_23 */
/* global array_22 */
/* STRUCTURE POINTER DECLARATIONS */
    NITRIFXNWtype* NITRIFXNWpointer;
    MIN_HUMUStype* MIN_HUMUSpointer;
    IMMOBIXNWtype* IMMOBIXNWpointer;
    MIN_FOMAtype* MIN_FOMApointer;
    UREA_HYDtype* UREA_HYDpointer;
    N_dynamicstype* N_dynamicspointer;
    Thermal_timetype* Thermal_timepointer;
    Soil_water_Balancetype* Soil_water_Balancepointer;
    Water_stresstype* Water_stresspointer;
    Total_dry_matter_production_Wtype* Total_dry_matter_production_Wpointer;
    Water_limited_productiontype* Water_limited_productionpointer;
    Total_dry_matter_productiontype* Total_dry_matter_productionpointer;
    Potential_productiontype* Potential_productionpointer;
    Total_dry_matter_prod_Ftype* Total_dry_matter_prod_Fpointer;
    Frost_limited_productiontype* Frost_limited_productionpointer;
    Total_dry_matter_production_Ntype* Total_dry_matter_production_Npointer;
    Nitrogen_limited_productiontype* Nitrogen_limited_productionpointer;
    Sol_integral_2012_Tor_9394_9type* Sol_integral_2012_Tor_9394_9pointer;


    /* UPDATE FUNCTION VALUES */

if (1>=phase) {
    Sol_integral_2012_Tor_9394_9pointer = &(this->Sol_integral_2012_Tor_9394_9);
        Nitrogen_limited_productionpointer = &(Sol_integral_2012_Tor_9394_9pointer->Nitrogen_limited_production);
            Total_dry_matter_production_Npointer = &(Nitrogen_limited_productionpointer->Total_dry_matter_production_N);
                Frost_limited_productionpointer = &(Sol_integral_2012_Tor_9394_9pointer->Frost_limited_production);
                    Total_dry_matter_prod_Fpointer = &(Frost_limited_productionpointer->Total_dry_matter_prod_F);
                        Potential_productionpointer = &(Sol_integral_2012_Tor_9394_9pointer->Potential_production);
                            Total_dry_matter_productionpointer = &(Potential_productionpointer->Total_dry_matter_production);
                                Water_limited_productionpointer = &(Sol_integral_2012_Tor_9394_9pointer->Water_limited_production);
                                    Total_dry_matter_production_Wpointer = &(Water_limited_productionpointer->Total_dry_matter_production_W);
                                        Water_stresspointer = &(Water_limited_productionpointer->Water_stress);
                                            Soil_water_Balancepointer = &(Sol_integral_2012_Tor_9394_9pointer->Soil_water_Balance);
                                                Thermal_timepointer = &(Sol_integral_2012_Tor_9394_9pointer->Thermal_time);
                                                    N_dynamicspointer = &(Sol_integral_2012_Tor_9394_9pointer->N_dynamics);
                                                        UREA_HYDpointer = &(N_dynamicspointer->UREA_HYD);
                                                            MIN_FOMApointer = &(N_dynamicspointer->MIN_FOMA);
                                                                IMMOBIXNWpointer = &(MIN_FOMApointer->IMMOBIXNW);
                                                                    MIN_HUMUSpointer = &(N_dynamicspointer->MIN_HUMUS);
                                                                        NITRIFXNWpointer = &(N_dynamicspointer->NITRIFXNW);
                                                                            NITRIFXNWpointer->NO3POOL = NITRIFXNWpointer->NO3POOL+stage_incr(&(NITRIFXNWpointer->anon), 1, NITRIFXNWpointer->dNO3);
                                                                            MIN_HUMUSpointer->NHUM = MIN_HUMUSpointer->NHUM+stage_incr(&(MIN_HUMUSpointer->anon_0), 1, MIN_HUMUSpointer->flow110+ -(MIN_HUMUSpointer->flow109));
                                                                            MIN_HUMUSpointer->RHMINacum = MIN_HUMUSpointer->RHMINacum+stage_incr(&(MIN_HUMUSpointer->anon_1), 1, MIN_HUMUSpointer->flow105);
                                                                            MIN_HUMUSpointer->HUM = MIN_HUMUSpointer->HUM+stage_incr(&(MIN_HUMUSpointer->anon_2), 1, MIN_HUMUSpointer->flow101+ -(MIN_HUMUSpointer->flow102));
                                                                            MIN_HUMUSpointer->Hum_decomp__acum = MIN_HUMUSpointer->Hum_decomp__acum+stage_incr(&(MIN_HUMUSpointer->anon_3), 1, MIN_HUMUSpointer->flow103);
                                                                            IMMOBIXNWpointer->FOM = IMMOBIXNWpointer->FOM+stage_incr(&(IMMOBIXNWpointer->anon_4), 1, -(IMMOBIXNWpointer->grcom));
                                                                            IMMOBIXNWpointer->FON = IMMOBIXNWpointer->FON+stage_incr(&(IMMOBIXNWpointer->anon_5), 1, IMMOBIXNWpointer->rnac+ -(IMMOBIXNWpointer->grnom));
                                                                            MIN_FOMApointer->FPOOLCE = MIN_FOMApointer->FPOOLCE+stage_incr(&(MIN_FOMApointer->anon_6), 1, -(MIN_FOMApointer->flow1));
                                                                            MIN_FOMApointer->FPOOLLI = MIN_FOMApointer->FPOOLLI+stage_incr(&(MIN_FOMApointer->anon_7), 1, -(MIN_FOMApointer->flow2));
                                                                            MIN_FOMApointer->NCE_acum = MIN_FOMApointer->NCE_acum+stage_incr(&(MIN_FOMApointer->anon_8), 1, MIN_FOMApointer->flow3);
                                                                            MIN_FOMApointer->NLI_acum = MIN_FOMApointer->NLI_acum+stage_incr(&(MIN_FOMApointer->anon_9), 1, MIN_FOMApointer->flow4);
                                                                            MIN_FOMApointer->FPOOLCA = MIN_FOMApointer->FPOOLCA+stage_incr(&(MIN_FOMApointer->anon_10), 1, -(MIN_FOMApointer->flow6));
                                                                            MIN_FOMApointer->acumGRNOM = MIN_FOMApointer->acumGRNOM+stage_incr(&(MIN_FOMApointer->anon_11), 1, MIN_FOMApointer->flow107);
                                                                            MIN_FOMApointer->NCA_acum = MIN_FOMApointer->NCA_acum+stage_incr(&(MIN_FOMApointer->anon_12), 1, MIN_FOMApointer->flow7);
                                                                            MIN_FOMApointer->acumGRCOM = MIN_FOMApointer->acumGRCOM+stage_incr(&(MIN_FOMApointer->anon_13), 1, MIN_FOMApointer->flow108);
                                                                            UREA_HYDpointer->NUREA = UREA_HYDpointer->NUREA+stage_incr(&(UREA_HYDpointer->anon_14), 1, -(UREA_HYDpointer->flow1_0));
                                                                            UREA_HYDpointer->comp2 = UREA_HYDpointer->comp2+stage_incr(&(UREA_HYDpointer->anon_15), 1, UREA_HYDpointer->flow2_0);
                                                                            N_dynamicspointer->cd108 = N_dynamicspointer->cd108+stage_incr(&(N_dynamicspointer->anon_16), 1, N_dynamicspointer->flow205);
                                                                            N_dynamicspointer->N_lib_acum = N_dynamicspointer->N_lib_acum+stage_incr(&(N_dynamicspointer->anon_17), 1, N_dynamicspointer->flow102_0);
                                                                            N_dynamicspointer->NH4POOL = N_dynamicspointer->NH4POOL+stage_incr(&(N_dynamicspointer->anon_18), 1, N_dynamicspointer->flow4_0+ -(N_dynamicspointer->flow2_1));
                                                                            Thermal_timepointer->Tac = Thermal_timepointer->Tac+stage_incr(&(Thermal_timepointer->anon_19), 1, Thermal_timepointer->Te);
                                                                            Soil_water_Balancepointer->CS = Soil_water_Balancepointer->CS+stage_incr(&(Soil_water_Balancepointer->anon_20), 1, Soil_water_Balancepointer->S+ -(Soil_water_Balancepointer->s));
                                                                            Water_stresspointer->CWs = Water_stresspointer->CWs+stage_incr(&(Water_stresspointer->anon_21), 1, Water_stresspointer->Ws);
                                                                            Total_dry_matter_production_Wpointer->TDMw = Total_dry_matter_production_Wpointer->TDMw+stage_incr(&(Total_dry_matter_production_Wpointer->anon_22), 1, Total_dry_matter_production_Wpointer->dTDM);
                                                                            Total_dry_matter_productionpointer->TDM = Total_dry_matter_productionpointer->TDM+stage_incr(&(Total_dry_matter_productionpointer->anon_23), 1, Total_dry_matter_productionpointer->dW);
                                                                            Total_dry_matter_prod_Fpointer->TDMf = Total_dry_matter_prod_Fpointer->TDMf+stage_incr(&(Total_dry_matter_prod_Fpointer->anon_24), 1, Total_dry_matter_prod_Fpointer->dTDM_0);
                                                                            Frost_limited_productionpointer->c1 = Frost_limited_productionpointer->c1+stage_incr(&(Frost_limited_productionpointer->anon_25), 1, Frost_limited_productionpointer->fay1+ -(Frost_limited_productionpointer->ay1));
                                                                            Frost_limited_productionpointer->c2 = Frost_limited_productionpointer->c2+stage_incr(&(Frost_limited_productionpointer->anon_26), 1, Frost_limited_productionpointer->fay2+ -(Frost_limited_productionpointer->ay2));
                                                                            Frost_limited_productionpointer->C3 = Frost_limited_productionpointer->C3+stage_incr(&(Frost_limited_productionpointer->anon_27), 1, Frost_limited_productionpointer->CCf+ -(Frost_limited_productionpointer->fccf));
                                                                            Frost_limited_productionpointer->REB = Frost_limited_productionpointer->REB+stage_incr(&(Frost_limited_productionpointer->anon_28), 1, Frost_limited_productionpointer->Reb+ -(Frost_limited_productionpointer->reba));
                                                                            Total_dry_matter_production_Npointer->TDMn = Total_dry_matter_production_Npointer->TDMn+stage_incr(&(Total_dry_matter_production_Npointer->anon_29), 1, Total_dry_matter_production_Npointer->dTDM_1);


















}; /* end(cond,1>=phase) */


}; /* end(procedure,updatemodel) */

/* EVALUATION PROCEDURE DECLARATION */

void advancemodel (double start_time, int phase) {

/* GLOBAL DECLARATIONS */
/* global this */
/* global array_7 */
/* global array_6 */
/* global array_5 */
/* global array_4 */
/* global array_3 */
/* global array_2 */
/* global array_1 */
/* global array_0 */
/* global array */
/* global array_18 */
/* global array_17 */
/* global array_16 */
/* global array_15 */
/* global array_14 */
/* global array_13 */
/* global array_12 */
/* global array_11 */
/* global array_10 */
/* global array_9 */
/* global array_8 */
/* global array_21 */
/* global array_20 */
/* global array_19 */
/* global array_33 */
/* global array_32 */
/* global array_31 */
/* global array_30 */
/* global array_29 */
/* global array_28 */
/* global array_27 */
/* global array_26 */
/* global array_25 */
/* global array_24 */
/* global array_23 */
/* global array_22 */
/* STRUCTURE POINTER DECLARATIONS */
    int build0;
    Frost_limited_productiontype* Frost_limited_productionpointer_0;
    Sol_integral_2012_Tor_9394_9type* Sol_integral_2012_Tor_9394_9pointer_0;


    /* UPDATE FUNCTION VALUES */

if (1>=phase) {
    Sol_integral_2012_Tor_9394_9pointer_0 = &(this->Sol_integral_2012_Tor_9394_9);
        Frost_limited_productionpointer_0 = &(Sol_integral_2012_Tor_9394_9pointer_0->Frost_limited_production);
            Frost_limited_productionpointer_0->ptw_for_delayCCf_last = Frost_limited_productionpointer_0->ptw_for_delayCCf;
            Frost_limited_productionpointer_0->ptw_for_delayCC_last = Frost_limited_productionpointer_0->ptw_for_delayCC;
            for ( build0 = 1; 1000>=build0; ++build0 ) {
                Frost_limited_productionpointer_0->_array__for_delayCCf_last[build0-1] = Frost_limited_productionpointer_0->_array__for_delayCCf[build0-1];
                Frost_limited_productionpointer_0->_array__for_delayCC_last[build0-1] = Frost_limited_productionpointer_0->_array__for_delayCC[build0-1];
            }; /* end(for,build0) */



}; /* end(cond,1>=phase) */


}; /* end(procedure,advancemodel) */

/* EVALUATION PROCEDURE DECLARATION */

void int_evalmodel (double start_time, int phase) {

/* GLOBAL DECLARATIONS */
/* global this */
/* global array_7 */
/* global array_6 */
/* global array_5 */
/* global array_4 */
/* global array_3 */
/* global array_2 */
/* global array_1 */
/* global array_0 */
/* global array */
/* global array_18 */
/* global array_17 */
/* global array_16 */
/* global array_15 */
/* global array_14 */
/* global array_13 */
/* global array_12 */
/* global array_11 */
/* global array_10 */
/* global array_9 */
/* global array_8 */
/* global array_21 */
/* global array_20 */
/* global array_19 */
/* global array_33 */
/* global array_32 */
/* global array_31 */
/* global array_30 */
/* global array_29 */
/* global array_28 */
/* global array_27 */
/* global array_26 */
/* global array_25 */
/* global array_24 */
/* global array_23 */
/* global array_22 */
/* STRUCTURE POINTER DECLARATIONS */
    MIN_HUMUStype* MIN_HUMUSpointer_3;
    FERTILIZERStype* FERTILIZERSpointer_1;
    NITRIFXNWtype* NITRIFXNWpointer_3;
    Water_stresstype* Water_stresspointer_2;
    Canopy_covertype* Canopy_coverpointer_2;
    Potential_productiontype* Potential_productionpointer_3;
    Canopy_Cover_Wtype* Canopy_Cover_Wpointer;
    Weathertype* Weatherpointer_0;
    Total_dry_matter_production_Wtype* Total_dry_matter_production_Wpointer_2;
    Water_stresstype* Water_stresspointer_1;
    Water_limited_productiontype* Water_limited_productionpointer_2;
    IMMOBIXNWtype* IMMOBIXNWpointer_2;
    MIN_FOMAtype* MIN_FOMApointer_3;
    N_dynamicstype* N_dynamicspointer_3;
    Sol_integral_2012_Tor_9394_9type* Sol_integral_2012_Tor_9394_9pointer_3;
    Tuber_production_Wtype* Tuber_production_Wpointer;
    Tuber_production_Ftype* Tuber_production_Fpointer;
    Tuber_productiontype* Tuber_productionpointer_0;
    Tuber_production_Ntype* Tuber_production_Npointer;
    N_stresstype* N_stresspointer_0;
    Planting_Datetype* Planting_Datepointer_0;
    Water_stresstype* Water_stresspointer_0;
    Total_dry_matter_production_Wtype* Total_dry_matter_production_Wpointer_1;
    Water_limited_productiontype* Water_limited_productionpointer_1;
    NITRIFXNWtype* NITRIFXNWpointer_2;
    MIN_HUMUStype* MIN_HUMUSpointer_2;
    IMMOBIXNWtype* IMMOBIXNWpointer_1;
    MIN_FOMAtype* MIN_FOMApointer_2;
    Soil_temp_esttype* Soil_temp_estpointer_0;
    UREA_HYDtype* UREA_HYDpointer_2;
    N_dynamicstype* N_dynamicspointer_2;
    Soil_parameterstype* Soil_parameterspointer_1;
    Soil_water_Balancetype* Soil_water_Balancepointer_1;
    Canopy_covertype* Canopy_coverpointer_1;
    Total_dry_matter_productiontype* Total_dry_matter_productionpointer_2;
    Potential_productiontype* Potential_productionpointer_2;
    Total_dry_matter_prod_Ftype* Total_dry_matter_prod_Fpointer_1;
    Canopy_cover_Ntype* Canopy_cover_Npointer;
    Total_dry_matter_production_Ntype* Total_dry_matter_production_Npointer_2;
    Nitrogen_limited_productiontype* Nitrogen_limited_productionpointer_2;
    Timetype* Timepointer_0;
    Thermal_timetype* Thermal_timepointer_2;
    int build0;
    Canopy_covertype* Canopy_coverpointer_0;
    Soil_parameterstype* Soil_parameterspointer_0;
    Soil_water_Balancetype* Soil_water_Balancepointer_0;
    FERTILIZERStype* FERTILIZERSpointer_0;
    NITRIFXNWtype* NITRIFXNWpointer_1;
    IMMOBIXNWtype* IMMOBIXNWpointer_0;
    MIN_HUMUStype* MIN_HUMUSpointer_1;
    MIN_FOMAtype* MIN_FOMApointer_1;
    UREA_HYDtype* UREA_HYDpointer_1;
    N_dynamicstype* N_dynamicspointer_1;
    Thermal_timetype* Thermal_timepointer_1;
    Randomizetype* Randomizepointer_0;
    Total_dry_matter_production_Wtype* Total_dry_matter_production_Wpointer_0;
    Water_limited_productiontype* Water_limited_productionpointer_0;
    Total_dry_matter_productiontype* Total_dry_matter_productionpointer_1;
    Potential_productiontype* Potential_productionpointer_1;
    Total_dry_matter_prod_Ftype* Total_dry_matter_prod_Fpointer_0;
    Total_dry_matter_production_Ntype* Total_dry_matter_production_Npointer_1;
    Nitrogen_limited_productiontype* Nitrogen_limited_productionpointer_1;
    Frost_limited_productiontype* Frost_limited_productionpointer_2;
    int loop_3;
    Weathertype* Weatherpointer;
    Sol_integral_2012_Tor_9394_9type* Sol_integral_2012_Tor_9394_9pointer_2;
    int loop_2;
    int loop_1;
    int loop_0;
    int loop;
    FERTILIZERStype* FERTILIZERSpointer;
    Planting_Datetype* Planting_Datepointer;
    Timetype* Timepointer;
    Randomizetype* Randomizepointer;
    NITRIFXNWtype* NITRIFXNWpointer_0;
    UREA_HYDtype* UREA_HYDpointer_0;
    N_stresstype* N_stresspointer;
    Soil_temp_esttype* Soil_temp_estpointer;
    Soil_parameterstype* Soil_parameterspointer;
    MIN_HUMUStype* MIN_HUMUSpointer_0;
    Thermal_timetype* Thermal_timepointer_0;
    Canopy_covertype* Canopy_coverpointer;
    Total_dry_matter_productiontype* Total_dry_matter_productionpointer_0;
    Tuber_productiontype* Tuber_productionpointer;
    Potential_productiontype* Potential_productionpointer_0;
    Frost_limited_productiontype* Frost_limited_productionpointer_1;
    Varietytype* Varietypointer;
    Total_dry_matter_production_Ntype* Total_dry_matter_production_Npointer_0;
    Nitrogen_limited_productiontype* Nitrogen_limited_productionpointer_0;
    Type_of_OM_addedtype* Type_of_OM_addedpointer;
    MIN_FOMAtype* MIN_FOMApointer_0;
    N_dynamicstype* N_dynamicspointer_0;
    Sol_integral_2012_Tor_9394_9type* Sol_integral_2012_Tor_9394_9pointer_1;


    /* UPDATE FUNCTION VALUES */

if (-2>=phase) {
    Sol_integral_2012_Tor_9394_9pointer_1 = &(this->Sol_integral_2012_Tor_9394_9);
        N_dynamicspointer_0 = &(Sol_integral_2012_Tor_9394_9pointer_1->N_dynamics);
            MIN_FOMApointer_0 = &(N_dynamicspointer_0->MIN_FOMA);
                Type_of_OM_addedpointer = &(MIN_FOMApointer_0->Type_of_OM_added);
                    Nitrogen_limited_productionpointer_0 = &(Sol_integral_2012_Tor_9394_9pointer_1->Nitrogen_limited_production);
                        Total_dry_matter_production_Npointer_0 = &(Nitrogen_limited_productionpointer_0->Total_dry_matter_production_N);
                            Varietypointer = &(Sol_integral_2012_Tor_9394_9pointer_1->Variety);
                                Frost_limited_productionpointer_1 = &(Sol_integral_2012_Tor_9394_9pointer_1->Frost_limited_production);
                                    Potential_productionpointer_0 = &(Sol_integral_2012_Tor_9394_9pointer_1->Potential_production);
                                        Tuber_productionpointer = &(Potential_productionpointer_0->Tuber_production);
                                            Total_dry_matter_productionpointer_0 = &(Potential_productionpointer_0->Total_dry_matter_production);
                                                Canopy_coverpointer = &(Potential_productionpointer_0->Canopy_cover);
                                                    Thermal_timepointer_0 = &(Sol_integral_2012_Tor_9394_9pointer_1->Thermal_time);
                                                        MIN_HUMUSpointer_0 = &(N_dynamicspointer_0->MIN_HUMUS);
                                                            Soil_parameterspointer = &(Sol_integral_2012_Tor_9394_9pointer_1->Soil_parameters);
                                                                Soil_temp_estpointer = &(Soil_parameterspointer->Soil_temp_est);
                                                                    N_stresspointer = &(Nitrogen_limited_productionpointer_0->N_stress);
                                                                        UREA_HYDpointer_0 = &(N_dynamicspointer_0->UREA_HYD);
                                                                            NITRIFXNWpointer_0 = &(N_dynamicspointer_0->NITRIFXNW);
                                                                                Randomizepointer = &(Sol_integral_2012_Tor_9394_9pointer_1->Randomize);
                                                                                    Timepointer = &(Sol_integral_2012_Tor_9394_9pointer_1->Time);
                                                                                        Planting_Datepointer = &(Timepointer->Planting_Date);
                                                                                            FERTILIZERSpointer = &(N_dynamicspointer_0->FERTILIZERS);
                                                                                                MIN_HUMUSpointer_0->DMINR = 8.3*pow(10,-5);
                                                                                                MIN_HUMUSpointer_0->DMOD = 1;
                                                                                                //Type_of_OM_addedpointer->Type = 4;
                                                                                                MIN_FOMApointer_0->_C = 60;
                                                                                                //MIN_FOMApointer_0->FOMi = 2000;
                                                                                                MIN_FOMApointer_0->FOCi = (double)(MIN_FOMApointer_0->FOMi*MIN_FOMApointer_0->_C)/100;
                                                                                                //FERTILIZERSpointer->amount = 100;
                                                                                                //FERTILIZERSpointer->Fert = 1;
                                                                                                UREA_HYDpointer_0->UREA = (FERTILIZERSpointer->Fert==1?FERTILIZERSpointer->amount:0);
                                                                                                UREA_HYDpointer_0->NUREAi = UREA_HYDpointer_0->UREA;
                                                                                                FERTILIZERSpointer->NH4_fert = (FERTILIZERSpointer->Fert==2?0.225:(FERTILIZERSpointer->Fert==3?0.15:0));
                                                                                                FERTILIZERSpointer->NH4am = FERTILIZERSpointer->NH4_fert*FERTILIZERSpointer->amount;
                                                                                                FERTILIZERSpointer->NO3fert = (FERTILIZERSpointer->Fert==2?0.775:0);
                                                                                                FERTILIZERSpointer->NO3am = FERTILIZERSpointer->NO3fert*FERTILIZERSpointer->amount;
                                                                                                Varietypointer->Var_Name = 4;
                                                                                                //Thermal_timepointer_0->Thermal_conditions = 1;
                                                                                                //Planting_Datepointer->dd = 22;
                                                                                                //Planting_Datepointer->mm = 10;
                                                                                                Planting_Datepointer->PDate = (Planting_Datepointer->mm==1?Planting_Datepointer->dd:(Planting_Datepointer->mm==2?Planting_Datepointer->dd+31:(Planting_Datepointer->mm==3?Planting_Datepointer->dd+59:(Planting_Datepointer->mm==4?Planting_Datepointer->dd+90:(Planting_Datepointer->mm==5?Planting_Datepointer->dd+120:(Planting_Datepointer->mm==6?Planting_Datepointer->dd+151:(Planting_Datepointer->mm==7?Planting_Datepointer->dd+181:(Planting_Datepointer->mm==8?Planting_Datepointer->dd+212:(Planting_Datepointer->mm==9?Planting_Datepointer->dd+243:(Planting_Datepointer->mm==10?Planting_Datepointer->dd+273:(Planting_Datepointer->mm==11?Planting_Datepointer->dd+304:Planting_Datepointer->dd+334)))))))))));
                                                                                                //Timepointer->EDay = 40;
                                                                                                //Randomizepointer->v = 0.2;
                                                                                                //Soil_temp_estpointer->Dl = 40;
                                                                                                //Soil_parameterspointer->OM = 2;
                                                                                                Soil_parameterspointer->OC = 0.58*Soil_parameterspointer->OM;
                                                                                                //Soil_parameterspointer->ISM = 100;
                                                                                                //Soil_parameterspointer->pH = 6;
                                                                                                NITRIFXNWpointer_0->phn = Soil_parameterspointer->pH*0.05;
                                                                                                UREA_HYDpointer_0->AK = -1.12+1.31*Soil_parameterspointer->OC+0.203*Soil_parameterspointer->pH-0.155*Soil_parameterspointer->OC*Soil_parameterspointer->pH;
                                                                                                UREA_HYDpointer_0->AKU = (UREA_HYDpointer_0->AK<0.25?0.25:UREA_HYDpointer_0->AK);
                                                                                                //Soil_parameterspointer->Soil_texture = 8;
                                                                                                Soil_parameterspointer->Area = 10000;
                                                                                                //Soil_parameterspointer->Soil_depth = 0.5;
                                                                                                Soil_temp_estpointer->D = Soil_parameterspointer->Soil_depth*100;
                                                                                                Soil_parameterspointer->Soil_Vol = Soil_parameterspointer->Area*Soil_parameterspointer->Soil_depth;
                                                                                                //Canopy_coverpointer->N = 4.7;
                                                                                                N_stresspointer->GC0 = 0.6;
                                                                                                N_stresspointer->GC250 = 1;
                                                                                                for ( loop = 1; 7>=loop; ++loop ) {
                                                                                                    Soil_parameterspointer->Hydric[loop-1] = (Soil_parameterspointer->Soil_texture==1?array_22[loop-1]:(Soil_parameterspointer->Soil_texture==2?array_23[loop-1]:(Soil_parameterspointer->Soil_texture==3?array_24[loop-1]:(Soil_parameterspointer->Soil_texture==4?array_25[loop-1]:(Soil_parameterspointer->Soil_texture==5?array_26[loop-1]:(Soil_parameterspointer->Soil_texture==6?array_27[loop-1]:(Soil_parameterspointer->Soil_texture==7?array_28[loop-1]:(Soil_parameterspointer->Soil_texture==8?array_29[loop-1]:(Soil_parameterspointer->Soil_texture==9?array_30[loop-1]:(Soil_parameterspointer->Soil_texture==10?array_31[loop-1]:(Soil_parameterspointer->Soil_texture==11?array_32[loop-1]:array_33[loop-1])))))))))));
                                                                                                }; /* end(for,loop) */

                                                                                                Soil_temp_estpointer->k = Soil_parameterspointer->Hydric[5-1];
                                                                                                Soil_temp_estpointer->c = Soil_parameterspointer->Hydric[6-1];
                                                                                                Soil_parameterspointer->cl = Soil_parameterspointer->Hydric[3-1]-0.5*(Soil_parameterspointer->Hydric[3-1]-Soil_parameterspointer->Hydric[4-1]);
                                                                                                Soil_parameterspointer->CL = (double)(Soil_parameterspointer->Soil_Vol*Soil_parameterspointer->cl)/1000;
                                                                                                Soil_parameterspointer->FC = (double)(Soil_parameterspointer->Soil_Vol*Soil_parameterspointer->Hydric[3-1])/1000;
                                                                                                Soil_parameterspointer->WP = (double)(Soil_parameterspointer->Soil_Vol*Soil_parameterspointer->Hydric[4-1])/1000;
                                                                                                Soil_parameterspointer->fc = Soil_parameterspointer->Hydric[3-1];
                                                                                                Soil_parameterspointer->wp = Soil_parameterspointer->Hydric[4-1];
                                                                                                Soil_parameterspointer->BD = Soil_parameterspointer->Hydric[1-1]*1000;
                                                                                                Soil_parameterspointer->Po = (double)(100*(2.65-(double)(Soil_parameterspointer->BD)/1000))/2.65;
                                                                                                Soil_parameterspointer->SWeight = (double)(Soil_parameterspointer->Soil_Vol*Soil_parameterspointer->BD)/1000;
                                                                                                Soil_parameterspointer->OMw = (double)(Soil_parameterspointer->OM)/100*Soil_parameterspointer->SWeight;
                                                                                                MIN_HUMUSpointer_0->NHUMi = (double)(Soil_parameterspointer->OMw*1000)/10;
                                                                                                MIN_HUMUSpointer_0->CHUMi = Soil_parameterspointer->OMw*1000;
                                                                                                for ( loop_0 = 1; 3>=loop_0; ++loop_0 ) {
                                                                                                    Thermal_timepointer_0->TC[loop_0-1] = (Thermal_timepointer_0->Thermal_conditions==1?array_19[loop_0-1]:(Thermal_timepointer_0->Thermal_conditions==2?array_20[loop_0-1]:array_21[loop_0-1]));
                                                                                                }; /* end(for,loop_0) */

                                                                                                Thermal_timepointer_0->Tb = Thermal_timepointer_0->TC[1-1];
                                                                                                Thermal_timepointer_0->To = Thermal_timepointer_0->TC[2-1];
                                                                                                Thermal_timepointer_0->Th = Thermal_timepointer_0->TC[3-1];
                                                                                                for ( loop_1 = 1; 13>=loop_1; ++loop_1 ) {
                                                                                                    Varietypointer->Inputs[loop_1-1] = (Varietypointer->Var_Name==1?array_8[loop_1-1]:(Varietypointer->Var_Name==2?array_9[loop_1-1]:(Varietypointer->Var_Name==3?array_10[loop_1-1]:(Varietypointer->Var_Name==4?array_11[loop_1-1]:(Varietypointer->Var_Name==5?array_12[loop_1-1]:(Varietypointer->Var_Name==6?array_13[loop_1-1]:(Varietypointer->Var_Name==7?array_14[loop_1-1]:(Varietypointer->Var_Name==8?array_15[loop_1-1]:(Varietypointer->Var_Name==9?array_16[loop_1-1]:(Varietypointer->Var_Name==10?array_17[loop_1-1]:array_18[loop_1-1]))))))))));
                                                                                                }; /* end(for,loop_1) */

                                                                                                //Canopy_coverpointer->d = Varietypointer->Inputs[4-1];
                                                                                                //Canopy_coverpointer->f0 = Varietypointer->Inputs[2-1];
                                                                                                //Canopy_coverpointer->R0 = Varietypointer->Inputs[3-1];
                                                                                                //Canopy_coverpointer->t50 = Varietypointer->Inputs[5-1];
                                                                                                //Canopy_coverpointer->MCC = Varietypointer->Inputs[1-1];
                                                                                                //Total_dry_matter_productionpointer_0->RUE = Varietypointer->Inputs[6-1];
                                                                                                //Tuber_productionpointer->M = Varietypointer->Inputs[7-1];
                                                                                                //Tuber_productionpointer->A_0 = Varietypointer->Inputs[9-1];
                                                                                                //Tuber_productionpointer->b = Varietypointer->Inputs[8-1];
                                                                                                //Tuber_productionpointer->DMcont = Varietypointer->Inputs[10-1];
                                                                                                //Frost_limited_productionpointer_1->Tcr = Varietypointer->Inputs[11-1];
                                                                                                //Frost_limited_productionpointer_1->Tld = Varietypointer->Inputs[12-1];
                                                                                                //Frost_limited_productionpointer_1->Trg = Varietypointer->Inputs[13-1];
                                                                                                Total_dry_matter_production_Npointer_0->RUE_0 = Varietypointer->Inputs[6-1];
                                                                                                for ( loop_2 = 1; 2>=loop_2; ++loop_2 ) {
                                                                                                    Type_of_OM_addedpointer->OM_CN[loop_2-1] = (Type_of_OM_addedpointer->Type==1?array[loop_2-1]:(Type_of_OM_addedpointer->Type==2?array_0[loop_2-1]:(Type_of_OM_addedpointer->Type==3?array_1[loop_2-1]:(Type_of_OM_addedpointer->Type==4?array_2[loop_2-1]:(Type_of_OM_addedpointer->Type==5?array_3[loop_2-1]:(Type_of_OM_addedpointer->Type==6?array_4[loop_2-1]:(Type_of_OM_addedpointer->Type==7?array_5[loop_2-1]:(Type_of_OM_addedpointer->Type==8?array_6[loop_2-1]:array_7[loop_2-1]))))))));
                                                                                                }; /* end(for,loop_2) */

                                                                                                MIN_FOMApointer_0->CN = Type_of_OM_addedpointer->OM_CN[1-1];
                                                                                                MIN_FOMApointer_0->_N = (double)(MIN_FOMApointer_0->_C)/MIN_FOMApointer_0->CN;























}; /* end(cond,-2>=phase) */

if (-1>=phase) {
    Sol_integral_2012_Tor_9394_9pointer_2 = &(this->Sol_integral_2012_Tor_9394_9);
        Weatherpointer = &(Sol_integral_2012_Tor_9394_9pointer_2->Weather);
//          for ( loop_3 = 1; 365>=loop_3; ++loop_3 ) {
//              collect(&(Weatherpointer->SoilTemp[loop_3-1]), 7, 1, loop_3);
//              collect(&(Weatherpointer->Irrigation[loop_3-1]), 6, 1, loop_3);
//              collect(&(Weatherpointer->PET[loop_3-1]), 5, 1, loop_3);
//              collect(&(Weatherpointer->MinTemp[loop_3-1]), 4, 1, loop_3);
//              collect(&(Weatherpointer->MaxTemp[loop_3-1]), 3, 1, loop_3);
//              collect(&(Weatherpointer->Rainfall[loop_3-1]), 2, 1, loop_3);
//              collect(&(Weatherpointer->Radiation[loop_3-1]), 1, 1, loop_3);
//          }; /* end(for,loop_3) */



}; /* end(cond,-1>=phase) */

if (0>=phase) {
    Sol_integral_2012_Tor_9394_9pointer_2 = &(this->Sol_integral_2012_Tor_9394_9);
        Frost_limited_productionpointer_2 = &(Sol_integral_2012_Tor_9394_9pointer_2->Frost_limited_production);
            Nitrogen_limited_productionpointer_1 = &(Sol_integral_2012_Tor_9394_9pointer_2->Nitrogen_limited_production);
                Total_dry_matter_production_Npointer_1 = &(Nitrogen_limited_productionpointer_1->Total_dry_matter_production_N);
                    Total_dry_matter_prod_Fpointer_0 = &(Frost_limited_productionpointer_2->Total_dry_matter_prod_F);
                        Potential_productionpointer_1 = &(Sol_integral_2012_Tor_9394_9pointer_2->Potential_production);
                            Total_dry_matter_productionpointer_1 = &(Potential_productionpointer_1->Total_dry_matter_production);
                                Water_limited_productionpointer_0 = &(Sol_integral_2012_Tor_9394_9pointer_2->Water_limited_production);
                                    Total_dry_matter_production_Wpointer_0 = &(Water_limited_productionpointer_0->Total_dry_matter_production_W);
                                        Randomizepointer_0 = &(Sol_integral_2012_Tor_9394_9pointer_2->Randomize);
                                            Thermal_timepointer_1 = &(Sol_integral_2012_Tor_9394_9pointer_2->Thermal_time);
                                                N_dynamicspointer_1 = &(Sol_integral_2012_Tor_9394_9pointer_2->N_dynamics);
                                                    UREA_HYDpointer_1 = &(N_dynamicspointer_1->UREA_HYD);
                                                        MIN_FOMApointer_1 = &(N_dynamicspointer_1->MIN_FOMA);
                                                            MIN_HUMUSpointer_1 = &(N_dynamicspointer_1->MIN_HUMUS);
                                                                IMMOBIXNWpointer_0 = &(MIN_FOMApointer_1->IMMOBIXNW);
                                                                    NITRIFXNWpointer_1 = &(N_dynamicspointer_1->NITRIFXNW);
                                                                        FERTILIZERSpointer_0 = &(N_dynamicspointer_1->FERTILIZERS);
                                                                            Soil_water_Balancepointer_0 = &(Sol_integral_2012_Tor_9394_9pointer_2->Soil_water_Balance);
                                                                                Soil_parameterspointer_0 = &(Sol_integral_2012_Tor_9394_9pointer_2->Soil_parameters);
                                                                                    Canopy_coverpointer_0 = &(Potential_productionpointer_1->Canopy_cover);
                                                                                        Frost_limited_productionpointer_2->C3 = Canopy_coverpointer_0->f0;
                                                                                        MIN_HUMUSpointer_1->HUM = MIN_HUMUSpointer_1->CHUMi;
                                                                                        MIN_HUMUSpointer_1->NHUM = MIN_HUMUSpointer_1->NHUMi;
                                                                                        Soil_water_Balancepointer_0->CS = Soil_parameterspointer_0->ISM;
                                                                                        NITRIFXNWpointer_1->NO3POOL = FERTILIZERSpointer_0->NO3am;
                                                                                        UREA_HYDpointer_1->NUREA = UREA_HYDpointer_1->NUREAi;
                                                                                        IMMOBIXNWpointer_0->FOM = MIN_FOMApointer_1->FOMi;
                                                                                        MIN_FOMApointer_1->FPOOLCE = MIN_FOMApointer_1->FOMi*0.7;
                                                                                        MIN_FOMApointer_1->FPOOLLI = MIN_FOMApointer_1->FOMi*0.1;
                                                                                        MIN_FOMApointer_1->FPOOLCA = MIN_FOMApointer_1->FOMi*0.2;
                                                                                        MIN_HUMUSpointer_1->RHMINacum = 0;
                                                                                        MIN_HUMUSpointer_1->Hum_decomp__acum = 0;
                                                                                        MIN_FOMApointer_1->NCE_acum = 0;
                                                                                        MIN_FOMApointer_1->NLI_acum = 0;
                                                                                        MIN_FOMApointer_1->acumGRNOM = 0;
                                                                                        MIN_FOMApointer_1->NCA_acum = 0;
                                                                                        MIN_FOMApointer_1->acumGRCOM = 0;
                                                                                        UREA_HYDpointer_1->comp2 = 0;
                                                                                        N_dynamicspointer_1->cd108 = 0;
                                                                                        N_dynamicspointer_1->N_lib_acum = 0;
                                                                                        N_dynamicspointer_1->NH4POOL = 0;
                                                                                        Thermal_timepointer_1->Tac = 1.0E-05;
                                                                                        Randomizepointer_0->rnd_at_init = ame_rand(0.0001, 0.9999);
                                                                                        Randomizepointer_0->rnd = 2*Randomizepointer_0->rnd_at_init-1;
                                                                                        Randomizepointer_0->rdm = (double)(log((double)(1+Randomizepointer_0->rnd)/(1-Randomizepointer_0->rnd)))/1.82;
                                                                                        Total_dry_matter_production_Wpointer_0->TDMw = 0;
                                                                                        Total_dry_matter_productionpointer_1->TDM = 1.0E-37;
                                                                                        Total_dry_matter_prod_Fpointer_0->TDMf = 0;
                                                                                        Frost_limited_productionpointer_2->c1 = 0;
                                                                                        Frost_limited_productionpointer_2->ptw_for_delayCCf_last = 0;
                                                                                        Frost_limited_productionpointer_2->c2 = 0;
                                                                                        Frost_limited_productionpointer_2->REB = 1;
                                                                                        Frost_limited_productionpointer_2->ptw_for_delayCC_last = 0;
                                                                                        Total_dry_matter_production_Npointer_1->TDMn = 0;
                                                                                        for ( build0 = 1; 1000>=build0; ++build0 ) {
                                                                                            Frost_limited_productionpointer_2->_array__for_delayCCf_last[build0-1] = 0;
                                                                                            Frost_limited_productionpointer_2->_array__for_delayCC_last[build0-1] = 0;
                                                                                        }; /* end(for,build0) */






















}; /* end(cond,0>=phase) */
if (1>=phase) {
    Sol_integral_2012_Tor_9394_9pointer_2 = &(this->Sol_integral_2012_Tor_9394_9);
        Frost_limited_productionpointer_2 = &(Sol_integral_2012_Tor_9394_9pointer_2->Frost_limited_production);
            Thermal_timepointer_2 = &(Sol_integral_2012_Tor_9394_9pointer_2->Thermal_time);
                Timepointer_0 = &(Sol_integral_2012_Tor_9394_9pointer_2->Time);
                    Nitrogen_limited_productionpointer_2 = &(Sol_integral_2012_Tor_9394_9pointer_2->Nitrogen_limited_production);
                        Total_dry_matter_production_Npointer_2 = &(Nitrogen_limited_productionpointer_2->Total_dry_matter_production_N);
                            Weatherpointer = &(Sol_integral_2012_Tor_9394_9pointer_2->Weather);
                                Canopy_cover_Npointer = &(Nitrogen_limited_productionpointer_2->Canopy_cover_N);
                                    Total_dry_matter_prod_Fpointer_1 = &(Frost_limited_productionpointer_2->Total_dry_matter_prod_F);
                                        Potential_productionpointer_2 = &(Sol_integral_2012_Tor_9394_9pointer_2->Potential_production);
                                            Total_dry_matter_productionpointer_2 = &(Potential_productionpointer_2->Total_dry_matter_production);
                                                Canopy_coverpointer_1 = &(Potential_productionpointer_2->Canopy_cover);
                                                    Soil_water_Balancepointer_1 = &(Sol_integral_2012_Tor_9394_9pointer_2->Soil_water_Balance);
                                                        Soil_parameterspointer_1 = &(Sol_integral_2012_Tor_9394_9pointer_2->Soil_parameters);
                                                            N_dynamicspointer_2 = &(Sol_integral_2012_Tor_9394_9pointer_2->N_dynamics);
                                                                UREA_HYDpointer_2 = &(N_dynamicspointer_2->UREA_HYD);
                                                                    Soil_temp_estpointer_0 = &(Soil_parameterspointer_1->Soil_temp_est);
                                                                        MIN_FOMApointer_2 = &(N_dynamicspointer_2->MIN_FOMA);
                                                                            IMMOBIXNWpointer_1 = &(MIN_FOMApointer_2->IMMOBIXNW);
                                                                                MIN_HUMUSpointer_2 = &(N_dynamicspointer_2->MIN_HUMUS);
                                                                                    NITRIFXNWpointer_2 = &(N_dynamicspointer_2->NITRIFXNW);
                                                                                        Water_limited_productionpointer_1 = &(Sol_integral_2012_Tor_9394_9pointer_2->Water_limited_production);
                                                                                            Total_dry_matter_production_Wpointer_1 = &(Water_limited_productionpointer_1->Total_dry_matter_production_W);
                                                                                                Water_stresspointer_0 = &(Water_limited_productionpointer_1->Water_stress);
                                                                                                    Planting_Datepointer_0 = &(Timepointer_0->Planting_Date);
                                                                                                        N_stresspointer_0 = &(Nitrogen_limited_productionpointer_2->N_stress);
                                                                                                            Tuber_production_Npointer = &(Nitrogen_limited_productionpointer_2->Tuber_production_N);
                                                                                                                Tuber_productionpointer_0 = &(Potential_productionpointer_2->Tuber_production);
                                                                                                                    Tuber_production_Fpointer = &(Frost_limited_productionpointer_2->Tuber_production_F);
                                                                                                                        Tuber_production_Wpointer = &(Water_limited_productionpointer_1->Tuber_production_W);
                                                                                                                            Frost_limited_productionpointer_2->ptw_for_delayCC = (Frost_limited_productionpointer_2->ptw_for_delayCC_last==1000?1:Frost_limited_productionpointer_2->ptw_for_delayCC_last+1);
                                                                                                                            Frost_limited_productionpointer_2->ptr_for_delayCC = Frost_limited_productionpointer_2->ptw_for_delayCC-1-1000*(int)(floor((double)(Frost_limited_productionpointer_2->ptw_for_delayCC-1-1)/1000));
                                                                                                                            Frost_limited_productionpointer_2->reba = Frost_limited_productionpointer_2->REB;
                                                                                                                            Frost_limited_productionpointer_2->ay2 = Frost_limited_productionpointer_2->c2;
                                                                                                                            Frost_limited_productionpointer_2->ptw_for_delayCCf = (Frost_limited_productionpointer_2->ptw_for_delayCCf_last==1000?1:Frost_limited_productionpointer_2->ptw_for_delayCCf_last+1);
                                                                                                                            Frost_limited_productionpointer_2->ptr_for_delayCCf = Frost_limited_productionpointer_2->ptw_for_delayCCf-1-1000*(int)(floor((double)(Frost_limited_productionpointer_2->ptw_for_delayCCf-1-1)/1000));
                                                                                                                            Frost_limited_productionpointer_2->ay1 = Frost_limited_productionpointer_2->c1;
                                                                                                                            N_stresspointer_0->Npc = 1.35+4.05*exp(-0.26*Total_dry_matter_productionpointer_2->TDM);
                                                                                                                            N_stresspointer_0->Npot = (double)(N_stresspointer_0->Npc*Total_dry_matter_productionpointer_2->TDM)/100;
                                                                                                                            Water_limited_productionpointer_1->RUEs = (Thermal_timepointer_2->Tac<Canopy_coverpointer_1->t50-0*Canopy_coverpointer_1->d?Total_dry_matter_productionpointer_2->RUE:Total_dry_matter_productionpointer_2->RUE*(1-(double)(Thermal_timepointer_2->Tac-Canopy_coverpointer_1->t50+0*Canopy_coverpointer_1->d)/(2*Canopy_coverpointer_1->d)));
                                                                                                                            Total_dry_matter_prod_Fpointer_1->RUEs_0 = Water_limited_productionpointer_1->RUEs;
                                                                                                                            Canopy_coverpointer_1->flinti = (double)(Canopy_coverpointer_1->MCC*Canopy_coverpointer_1->N*Canopy_coverpointer_1->f0*exp(Canopy_coverpointer_1->R0*Thermal_timepointer_2->Tac))/(Canopy_coverpointer_1->N*Canopy_coverpointer_1->f0*exp(Canopy_coverpointer_1->R0*Thermal_timepointer_2->Tac)+1-Canopy_coverpointer_1->N*Canopy_coverpointer_1->f0);
                                                                                                                            Canopy_coverpointer_1->Flint1 = Canopy_coverpointer_1->flinti;
                                                                                                                            Canopy_coverpointer_1->Flint2 = 0.5-(double)(Thermal_timepointer_2->Tac-Canopy_coverpointer_1->t50)/Canopy_coverpointer_1->d;
                                                                                                                            Canopy_coverpointer_1->CC = (Canopy_coverpointer_1->Flint2<=0?0:(Canopy_coverpointer_1->Flint1<Canopy_coverpointer_1->Flint2?Canopy_coverpointer_1->Flint1:(Canopy_coverpointer_1->Flint2>0?Canopy_coverpointer_1->Flint2:Canopy_coverpointer_1->Flint1)));
                                                                                                                            Frost_limited_productionpointer_2->CC_0 = Canopy_coverpointer_1->CC;
                                                                                                                            Frost_limited_productionpointer_2->CCf = (Frost_limited_productionpointer_2->CC_0+Frost_limited_productionpointer_2->ay2-Frost_limited_productionpointer_2->ay1>0?Frost_limited_productionpointer_2->CC_0+Frost_limited_productionpointer_2->ay2-Frost_limited_productionpointer_2->ay1:0);
                                                                                                                            Tuber_productionpointer_0->Part = (double)(Tuber_productionpointer_0->M)/(1+pow((double)(Thermal_timepointer_2->Tac)/Tuber_productionpointer_0->A_0,Tuber_productionpointer_0->b));
                                                                                                                            Tuber_production_Wpointer->DTYw = Total_dry_matter_production_Wpointer_1->TDMw*Tuber_productionpointer_0->Part;
                                                                                                                            Tuber_production_Wpointer->FTYw = (double)(Tuber_production_Wpointer->DTYw)/Tuber_productionpointer_0->DMcont;
                                                                                                                            Tuber_productionpointer_0->DTY = Total_dry_matter_productionpointer_2->TDM*Tuber_productionpointer_0->Part;
                                                                                                                            Tuber_productionpointer_0->FTY = (double)(Tuber_productionpointer_0->DTY)/Tuber_productionpointer_0->DMcont;
                                                                                                                            Tuber_production_Fpointer->DTYf = Total_dry_matter_prod_Fpointer_1->TDMf*Tuber_productionpointer_0->Part;
                                                                                                                            Tuber_production_Fpointer->FTYf = (double)(Tuber_production_Fpointer->DTYf)/Tuber_productionpointer_0->DMcont;
                                                                                                                            Tuber_production_Npointer->DTYn = Total_dry_matter_production_Npointer_2->TDMn*Tuber_productionpointer_0->Part;
                                                                                                                            Tuber_production_Npointer->FTYn = (double)(Tuber_production_Npointer->DTYn)/Tuber_productionpointer_0->DMcont;
                                                                                                                            NITRIFXNWpointer_2->NH4ppm = (double)(N_dynamicspointer_2->NH4POOL)/Soil_parameterspointer_1->SWeight*1000;
                                                                                                                            IMMOBIXNWpointer_1->var1 = (IMMOBIXNWpointer_1->FOM<5?0:IMMOBIXNWpointer_1->FOM);
                                                                                                                            MIN_FOMApointer_2->FONi = (double)(IMMOBIXNWpointer_1->FOM*MIN_FOMApointer_2->_N)/100;
                                                                                                                            NITRIFXNWpointer_2->NO3ppm = (double)(NITRIFXNWpointer_2->NO3POOL)/Soil_parameterspointer_1->SWeight*1000;
                                                                                                                            N_dynamicspointer_2->Nac = (double)(NITRIFXNWpointer_2->NO3POOL)/1000;
                                                                                                                            N_stresspointer_0->NacNpot = (double)(N_dynamicspointer_2->Nac)/N_stresspointer_0->Npot;
                                                                                                                            N_stresspointer_0->Ns = (N_stresspointer_0->NacNpot>1?1:(N_stresspointer_0->GC250-N_stresspointer_0->GC0)*N_stresspointer_0->NacNpot+N_stresspointer_0->GC0);
                                                                                                                            Canopy_cover_Npointer->CCn = Canopy_coverpointer_1->CC*N_stresspointer_0->Ns;
                                                                                                                            N_dynamicspointer_2->TOTN = (NITRIFXNWpointer_2->NO3POOL>0?NITRIFXNWpointer_2->NO3POOL:0);
                                                                                                                            MIN_FOMApointer_2->CNR = (double)(MIN_FOMApointer_2->FOCi)/(N_dynamicspointer_2->TOTN+MIN_FOMApointer_2->FONi);
                                                                                                                            MIN_FOMApointer_2->CNRF = exp((double)(-0.963*(MIN_FOMApointer_2->CNR-25))/25);
                                                                                                                            Soil_water_Balancepointer_1->s = Soil_water_Balancepointer_1->CS;
                                                                                                                            NITRIFXNWpointer_2->WFD = 1-(double)(Soil_water_Balancepointer_1->s-Soil_parameterspointer_1->FC)/(Soil_parameterspointer_1->Po-Soil_parameterspointer_1->FC);
                                                                                                                            MIN_HUMUSpointer_2->MF = (Soil_water_Balancepointer_1->s>Soil_parameterspointer_1->FC?(double)(Soil_water_Balancepointer_1->s-Soil_parameterspointer_1->FC)/(Soil_parameterspointer_1->Po-Soil_parameterspointer_1->FC):(Soil_water_Balancepointer_1->s<=Soil_parameterspointer_1->FC&&Soil_water_Balancepointer_1->s>Soil_parameterspointer_1->WP?1-0.5*((double)(Soil_water_Balancepointer_1->s-Soil_parameterspointer_1->WP)/(Soil_parameterspointer_1->FC-Soil_parameterspointer_1->WP)):0));
                                                                                                                            UREA_HYDpointer_2->SWF = MIN_HUMUSpointer_2->MF+0.2;
                                                                                                                            UREA_HYDpointer_2->MFU = (UREA_HYDpointer_2->SWF>1?1:(UREA_HYDpointer_2->SWF<0?0:UREA_HYDpointer_2->SWF));
                                                                                                                            Frost_limited_productionpointer_2->fccf = Frost_limited_productionpointer_2->C3;
                                                                                                                            Timepointer_0->day = fmod(glob_element(ts, 1)+Planting_Datepointer_0->PDate-1,365)+1;
                                                                                                                            Weatherpointer->Tsoi = Weatherpointer->SoilTemp[(int)(Timepointer_0->day)-1];
                                                                                                                            Weatherpointer->Irri = Weatherpointer->Irrigation[(int)(Timepointer_0->day)-1];
                                                                                                                            Weatherpointer->ETo = Weatherpointer->PET[(int)(Timepointer_0->day)-1];
                                                                                                                            Soil_water_Balancepointer_1->Eo = Canopy_coverpointer_1->MCC*Weatherpointer->ETo*exp(-0.7*4*Canopy_coverpointer_1->CC);
                                                                                                                            Soil_water_Balancepointer_1->To_0 = (Canopy_coverpointer_1->CC==0?0.0001:(double)(1.1*Weatherpointer->ETo*(1-exp(-0.7*4*Canopy_coverpointer_1->CC)))/(1-exp(-0.7*4*Canopy_coverpointer_1->MCC)));
                                                                                                                            Soil_water_Balancepointer_1->T = (Soil_water_Balancepointer_1->s>Soil_parameterspointer_1->CL?Soil_water_Balancepointer_1->To_0:(Soil_water_Balancepointer_1->s<Soil_parameterspointer_1->WP?0:(double)(Soil_water_Balancepointer_1->To_0*(Soil_parameterspointer_1->WP-Soil_water_Balancepointer_1->s))/(Soil_parameterspointer_1->WP-Soil_parameterspointer_1->CL)));
                                                                                                                            Water_stresspointer_0->Ws = (1-(double)(Soil_water_Balancepointer_1->T)/Soil_water_Balancepointer_1->To_0-0.8<0?0:1-(double)(Soil_water_Balancepointer_1->T)/Soil_water_Balancepointer_1->To_0-0.8);
                                                                                                                            Total_dry_matter_production_Wpointer_1->RUEw = ((double)(Water_limited_productionpointer_1->RUEs*(0.8-Water_stresspointer_0->Ws))/0.8<0?0:(double)(Water_limited_productionpointer_1->RUEs*(0.8-Water_stresspointer_0->Ws))/0.8);
                                                                                                                            Weatherpointer->Tmax = Weatherpointer->MaxTemp[(int)(Timepointer_0->day)-1];
                                                                                                                            Weatherpointer->Tmin = Weatherpointer->MinTemp[(int)(Timepointer_0->day)-1];
                                                                                                                            Thermal_timepointer_2->Tav = (double)(Weatherpointer->Tmax+Weatherpointer->Tmin)/2;
                                                                                                                            Thermal_timepointer_2->W = (Thermal_timepointer_2->Tav>=Thermal_timepointer_2->Tb&&Thermal_timepointer_2->Tav<Thermal_timepointer_2->To?1-pow((double)(Thermal_timepointer_2->Tav-Thermal_timepointer_2->To)/(Thermal_timepointer_2->To-Thermal_timepointer_2->Tb),2):(Thermal_timepointer_2->Tav>=Thermal_timepointer_2->To&&Thermal_timepointer_2->Tav<=Thermal_timepointer_2->Th?-((double)(Thermal_timepointer_2->Tav-Thermal_timepointer_2->Th)/(Thermal_timepointer_2->Th-Thermal_timepointer_2->To)):0));
                                                                                                                            Soil_temp_estpointer_0->Tl = 1.25*Thermal_timepointer_2->Tav;
                                                                                                                            Soil_temp_estpointer_0->Stemp = (double)(2)/3.1416*(Thermal_timepointer_2->Tav-Soil_temp_estpointer_0->Tl)*exp((double)(-((double)(Soil_temp_estpointer_0->k)/(Soil_parameterspointer_1->BD*Soil_temp_estpointer_0->c))*pow(3.1416,2)*1.0E+10)/pow(Soil_temp_estpointer_0->Dl,2))*sin((double)(3.1416*Soil_temp_estpointer_0->D)/Soil_temp_estpointer_0->Dl)+Thermal_timepointer_2->Tav+(double)(Soil_temp_estpointer_0->Tl-Thermal_timepointer_2->Tav)/Soil_temp_estpointer_0->Dl*Soil_temp_estpointer_0->D;
                                                                                                                            MIN_HUMUSpointer_2->TF = (Soil_temp_estpointer_0->Stemp<5?0:(Soil_temp_estpointer_0->Stemp>35?1:(double)(Soil_temp_estpointer_0->Stemp-5)/30));
                                                                                                                            NITRIFXNWpointer_2->min = min(NITRIFXNWpointer_2->WFD,MIN_HUMUSpointer_2->TF);
                                                                                                                            NITRIFXNWpointer_2->min1 = min(NITRIFXNWpointer_2->min,NITRIFXNWpointer_2->phn);
                                                                                                                            MIN_HUMUSpointer_2->RHMIN = MIN_HUMUSpointer_2->NHUM*MIN_HUMUSpointer_2->DMINR*MIN_HUMUSpointer_2->TF*MIN_HUMUSpointer_2->MF*MIN_HUMUSpointer_2->DMOD;
                                                                                                                            MIN_HUMUSpointer_2->flow109 = MIN_HUMUSpointer_2->RHMIN;
                                                                                                                            MIN_HUMUSpointer_2->flow105 = MIN_HUMUSpointer_2->RHMIN;
                                                                                                                            MIN_HUMUSpointer_2->flow102 = MIN_HUMUSpointer_2->RHMIN*10;
                                                                                                                            MIN_HUMUSpointer_2->flow103 = MIN_HUMUSpointer_2->flow102;
                                                                                                                            MIN_HUMUSpointer_2->MFTF = MIN_HUMUSpointer_2->MF*MIN_HUMUSpointer_2->TF;
                                                                                                                            MIN_FOMApointer_2->G1CA = MIN_FOMApointer_2->CNRF*MIN_HUMUSpointer_2->MFTF*0.8;
                                                                                                                            MIN_FOMApointer_2->CA = MIN_FOMApointer_2->G1CA*MIN_FOMApointer_2->FPOOLCA;
                                                                                                                            MIN_FOMApointer_2->flow6 = MIN_FOMApointer_2->CA;
                                                                                                                            MIN_FOMApointer_2->G1CE = MIN_FOMApointer_2->CNRF*MIN_HUMUSpointer_2->MFTF*0.05;
                                                                                                                            MIN_FOMApointer_2->CE = MIN_FOMApointer_2->G1CE*MIN_FOMApointer_2->FPOOLCE;
                                                                                                                            MIN_FOMApointer_2->flow1 = MIN_FOMApointer_2->CE;
                                                                                                                            MIN_FOMApointer_2->G1LI = MIN_FOMApointer_2->CNRF*MIN_HUMUSpointer_2->MFTF*0.0095;
                                                                                                                            MIN_FOMApointer_2->LI = MIN_FOMApointer_2->G1LI*MIN_FOMApointer_2->FPOOLLI;
                                                                                                                            MIN_FOMApointer_2->flow2 = MIN_FOMApointer_2->LI;
                                                                                                                            MIN_FOMApointer_2->GRCOM = MIN_FOMApointer_2->CA+MIN_FOMApointer_2->CE+MIN_FOMApointer_2->LI;
                                                                                                                            IMMOBIXNWpointer_1->grcom = MIN_FOMApointer_2->GRCOM;
                                                                                                                            MIN_FOMApointer_2->flow108 = MIN_FOMApointer_2->GRCOM;
                                                                                                                            UREA_HYDpointer_2->TFF = (double)(Soil_temp_estpointer_0->Stemp)/40+0.2;
                                                                                                                            UREA_HYDpointer_2->TFU = (UREA_HYDpointer_2->TFF<0?0:UREA_HYDpointer_2->TFF);
                                                                                                                            UREA_HYDpointer_2->UHYDR = UREA_HYDpointer_2->AKU*min(UREA_HYDpointer_2->MFU,UREA_HYDpointer_2->TFU)*UREA_HYDpointer_2->NUREA*0.01;
                                                                                                                            UREA_HYDpointer_2->flow1_0 = UREA_HYDpointer_2->UHYDR;
                                                                                                                            UREA_HYDpointer_2->flow2_0 = UREA_HYDpointer_2->flow1_0;
                                                                                                                            N_dynamicspointer_2->NH4u = UREA_HYDpointer_2->flow1_0;
                                                                                                                            UREA_HYDpointer_2->var13 = (double)(UREA_HYDpointer_2->AKU*min(UREA_HYDpointer_2->MFU,UREA_HYDpointer_2->TFU)*UREA_HYDpointer_2->NUREAi)/100;
                                                                                                                            Frost_limited_productionpointer_2->Tmin_0 = Weatherpointer->Tmin;
                                                                                                                            Frost_limited_productionpointer_2->CCRF = (Frost_limited_productionpointer_2->Tmin_0<Frost_limited_productionpointer_2->Tcr?(Frost_limited_productionpointer_2->Tmin_0>Frost_limited_productionpointer_2->Trg?(double)(Frost_limited_productionpointer_2->Trg-Frost_limited_productionpointer_2->Tmin_0)/(Frost_limited_productionpointer_2->Trg-Frost_limited_productionpointer_2->Tcr):0):1);
                                                                                                                            Frost_limited_productionpointer_2->Reb = (Frost_limited_productionpointer_2->CCRF<Frost_limited_productionpointer_2->REB?Frost_limited_productionpointer_2->CCRF:Frost_limited_productionpointer_2->REB);
                                                                                                                            Frost_limited_productionpointer_2->CCL = (Frost_limited_productionpointer_2->Tmin_0<Frost_limited_productionpointer_2->Tld?1:(Frost_limited_productionpointer_2->Tmin_0<Frost_limited_productionpointer_2->Tcr?1-(double)(Frost_limited_productionpointer_2->Tld-Frost_limited_productionpointer_2->Tmin_0)/(Frost_limited_productionpointer_2->Tld-Frost_limited_productionpointer_2->Tcr):0));
                                                                                                                            Weatherpointer->Rain = Weatherpointer->Rainfall[(int)(Timepointer_0->day)-1];
                                                                                                                            Soil_water_Balancepointer_1->S = (Weatherpointer->Rain+Weatherpointer->Irri+Soil_water_Balancepointer_1->CS-Soil_water_Balancepointer_1->Eo-Soil_water_Balancepointer_1->T<=0.9*Soil_parameterspointer_1->WP?0.9*Soil_parameterspointer_1->WP:(Weatherpointer->Rain+Weatherpointer->Irri+Soil_water_Balancepointer_1->CS-Soil_water_Balancepointer_1->Eo-Soil_water_Balancepointer_1->T>=Soil_parameterspointer_1->FC?Soil_parameterspointer_1->FC:Weatherpointer->Rain+Weatherpointer->Irri+Soil_water_Balancepointer_1->CS-Soil_water_Balancepointer_1->Eo-Soil_water_Balancepointer_1->T));
                                                                                                                            Weatherpointer->PAR = Weatherpointer->Radiation[(int)(Timepointer_0->day)-1]*0.5;
                                                                                                                            Total_dry_matter_productionpointer_2->dW = (double)(Total_dry_matter_productionpointer_2->RUE*Canopy_coverpointer_1->CC*Weatherpointer->PAR)/100;
                                                                                                                            Total_dry_matter_prod_Fpointer_1->dTDM_0 = (double)(Frost_limited_productionpointer_2->CCf*Weatherpointer->PAR*Total_dry_matter_prod_Fpointer_1->RUEs_0)/100;
                                                                                                                            Total_dry_matter_production_Npointer_2->dTDM_1 = (double)(Canopy_cover_Npointer->CCn*Weatherpointer->PAR*Total_dry_matter_production_Npointer_2->RUE_0)/100;
                                                                                                                            Timepointer_0->month = (Timepointer_0->day<=31?1:(Timepointer_0->day>31&&Timepointer_0->day<=59?2:(Timepointer_0->day>59&&Timepointer_0->day<=90?3:(Timepointer_0->day>90&&Timepointer_0->day<=120?4:(Timepointer_0->day>120&&Timepointer_0->day<=151?5:(Timepointer_0->day>151&&Timepointer_0->day<=181?6:(Timepointer_0->day>181&&Timepointer_0->day<=212?7:(Timepointer_0->day>212&&Timepointer_0->day<=243?8:(Timepointer_0->day>243&&Timepointer_0->day<=273?9:(Timepointer_0->day>273&&Timepointer_0->day<=304?10:(Timepointer_0->day>304&&Timepointer_0->day<=334?11:12)))))))))));
                                                                                                                            Timepointer_0->PDay = glob_element(ts, 1);
                                                                                                                            Timepointer_0->DAE = (Timepointer_0->PDay>=Timepointer_0->EDay?glob_element(ts, 1)-Timepointer_0->EDay:0);
                                                                                                                            Thermal_timepointer_2->Te = (Timepointer_0->DAE<=0?0:(Timepointer_0->DAE>0&&Thermal_timepointer_2->Tav<Thermal_timepointer_2->Tb?0:(Thermal_timepointer_2->Tav>=Thermal_timepointer_2->Tb&&Thermal_timepointer_2->Tav<=Thermal_timepointer_2->Th?(Thermal_timepointer_2->Tav-Thermal_timepointer_2->Tb)*Thermal_timepointer_2->W:0)));

                                                                                                                            for ( build0 = 1; 1000>=build0; ++build0 ) {
                                                                                                                                Frost_limited_productionpointer_2->_array__for_delayCC[build0-1] = (build0==Frost_limited_productionpointer_2->ptw_for_delayCC?Frost_limited_productionpointer_2->CC_0:Frost_limited_productionpointer_2->_array__for_delayCC_last[build0-1]);
                                                                                                                                Frost_limited_productionpointer_2->_array__for_delayCCf[build0-1] = (build0==Frost_limited_productionpointer_2->ptw_for_delayCCf?Frost_limited_productionpointer_2->CCf:Frost_limited_productionpointer_2->_array__for_delayCCf_last[build0-1]);
                                                                                                                            }; /* end(for,build0) */
                                                                                                                            double borrar1=Frost_limited_productionpointer_2->_array__for_delayCC[0];
                                                                                                                            Frost_limited_productionpointer_2->delayCCf = Frost_limited_productionpointer_2->_array__for_delayCCf[Frost_limited_productionpointer_2->ptr_for_delayCCf-1];
                                                                                                                            Frost_limited_productionpointer_2->fay1 = (Frost_limited_productionpointer_2->CCL>0?Frost_limited_productionpointer_2->delayCCf*Frost_limited_productionpointer_2->CCL:0);
                                                                                                                            Frost_limited_productionpointer_2->delayCC = Frost_limited_productionpointer_2->_array__for_delayCC[Frost_limited_productionpointer_2->ptr_for_delayCC-1];
//                                                                                                                            ind++;
                                                                                                                            //Frost_limited_productionpointer_2->delayCC = Frost_limited_productionpointer_2->_array__for_delayCC[ind];
                                                                                                                                                                                                                                                        FILE *stream1=NULL;

                                                                                                                            Frost_limited_productionpointer_2->dCC = Frost_limited_productionpointer_2->CC_0-Frost_limited_productionpointer_2->delayCC;
                                                                                                                            Frost_limited_productionpointer_2->fay2 = (Frost_limited_productionpointer_2->dCC>0?Frost_limited_productionpointer_2->dCC*Frost_limited_productionpointer_2->REB:(double)(Frost_limited_productionpointer_2->dCC*1)/Frost_limited_productionpointer_2->REB);






























}; /* end(cond,1>=phase) */

if (0>=phase) {
    Sol_integral_2012_Tor_9394_9pointer_3 = &(this->Sol_integral_2012_Tor_9394_9);
        N_dynamicspointer_3 = &(Sol_integral_2012_Tor_9394_9pointer_3->N_dynamics);
            MIN_FOMApointer_3 = &(N_dynamicspointer_3->MIN_FOMA);
                IMMOBIXNWpointer_2 = &(MIN_FOMApointer_3->IMMOBIXNW);
                    Water_limited_productionpointer_2 = &(Sol_integral_2012_Tor_9394_9pointer_3->Water_limited_production);
                        Water_stresspointer_1 = &(Water_limited_productionpointer_2->Water_stress);
                            Water_stresspointer_1->CWs = Water_stresspointer_1->Ws;
                            IMMOBIXNWpointer_2->FON = MIN_FOMApointer_3->FONi;






}; /* end(cond,0>=phase) */

if (1>=phase) {
    Sol_integral_2012_Tor_9394_9pointer_2 = &(this->Sol_integral_2012_Tor_9394_9);
        Water_limited_productionpointer_1 = &(Sol_integral_2012_Tor_9394_9pointer_2->Water_limited_production);
            Total_dry_matter_production_Wpointer_2 = &(Water_limited_productionpointer_1->Total_dry_matter_production_W);
                Weatherpointer_0 = &(Sol_integral_2012_Tor_9394_9pointer_2->Weather);
                    Canopy_Cover_Wpointer = &(Water_limited_productionpointer_1->Canopy_Cover_W);
                        Potential_productionpointer_3 = &(Sol_integral_2012_Tor_9394_9pointer_2->Potential_production);
                            Canopy_coverpointer_2 = &(Potential_productionpointer_3->Canopy_cover);
                                Water_stresspointer_2 = &(Water_limited_productionpointer_1->Water_stress);
                                    N_dynamicspointer_2 = &(Sol_integral_2012_Tor_9394_9pointer_2->N_dynamics);
                                        MIN_FOMApointer_2 = &(N_dynamicspointer_2->MIN_FOMA);
                                            NITRIFXNWpointer_3 = &(N_dynamicspointer_2->NITRIFXNW);
                                                FERTILIZERSpointer_1 = &(N_dynamicspointer_2->FERTILIZERS);
                                                    IMMOBIXNWpointer_1 = &(MIN_FOMApointer_2->IMMOBIXNW);
                                                        MIN_HUMUSpointer_3 = &(N_dynamicspointer_2->MIN_HUMUS);
                                                            IMMOBIXNWpointer_1->REST = (IMMOBIXNWpointer_1->var1>0?MIN_FOMApointer_2->GRCOM*(0.02-(double)(IMMOBIXNWpointer_1->FON)/IMMOBIXNWpointer_1->var1):0);
                                                            IMMOBIXNWpointer_1->RNACp = min(IMMOBIXNWpointer_1->REST,N_dynamicspointer_2->TOTN);
                                                            IMMOBIXNWpointer_1->RNAC = (IMMOBIXNWpointer_1->RNACp<0?0:IMMOBIXNWpointer_1->RNACp);
                                                            IMMOBIXNWpointer_1->rnac = IMMOBIXNWpointer_1->RNAC;
                                                            MIN_FOMApointer_2->GRNOMCE = (IMMOBIXNWpointer_1->FOM>=5?(double)(MIN_FOMApointer_2->CE*IMMOBIXNWpointer_1->FON)/IMMOBIXNWpointer_1->FOM:0);
                                                            MIN_FOMApointer_2->flow3 = MIN_FOMApointer_2->GRNOMCE;
                                                            MIN_FOMApointer_2->GRNOMLI = (IMMOBIXNWpointer_1->FOM>=5?(double)(MIN_FOMApointer_2->LI*IMMOBIXNWpointer_1->FON)/IMMOBIXNWpointer_1->FOM:0);
                                                            MIN_FOMApointer_2->flow4 = MIN_FOMApointer_2->GRNOMLI;
                                                            MIN_FOMApointer_2->GRNOMCA = (IMMOBIXNWpointer_1->FOM>=5?(double)(MIN_FOMApointer_2->CA*IMMOBIXNWpointer_1->FON)/IMMOBIXNWpointer_1->FOM:0);
                                                            MIN_FOMApointer_2->GRNOM = MIN_FOMApointer_2->GRNOMCA+MIN_FOMApointer_2->GRNOMCE+MIN_FOMApointer_2->GRNOMLI;
                                                            MIN_HUMUSpointer_3->flow110 = MIN_FOMApointer_2->GRNOM*0.2;
                                                            MIN_HUMUSpointer_3->flow101 = (double)(MIN_FOMApointer_2->GRNOM*0.2)/0.04;
                                                            IMMOBIXNWpointer_1->grnom = MIN_FOMApointer_2->GRNOM;
                                                            MIN_FOMApointer_2->flow107 = MIN_FOMApointer_2->GRNOM;
                                                            N_dynamicspointer_2->NNOM = 0.8*MIN_FOMApointer_2->GRNOM+MIN_HUMUSpointer_3->RHMIN-IMMOBIXNWpointer_1->RNAC;
                                                            N_dynamicspointer_2->NH4o = N_dynamicspointer_2->NNOM;
                                                            N_dynamicspointer_2->var19 = N_dynamicspointer_2->NH4o+N_dynamicspointer_2->NH4u+FERTILIZERSpointer_1->NH4am;
                                                            NITRIFXNWpointer_3->SNH4 = N_dynamicspointer_2->var19;
                                                            NITRIFXNWpointer_3->SANC = 1-exp(-0.01363*NITRIFXNWpointer_3->SNH4);
                                                            NITRIFXNWpointer_3->ELNC = min(NITRIFXNWpointer_3->min,NITRIFXNWpointer_3->SANC);
                                                            NITRIFXNWpointer_3->RP2 = exp(2.302*NITRIFXNWpointer_3->ELNC);
                                                            NITRIFXNWpointer_3->RP22 = (NITRIFXNWpointer_3->RP2<0.05?0.05:(NITRIFXNWpointer_3->RP2>1?1:NITRIFXNWpointer_3->RP2));
                                                            NITRIFXNWpointer_3->A = min(NITRIFXNWpointer_3->RP22,NITRIFXNWpointer_3->min1);
                                                            NITRIFXNWpointer_3->bb = (double)(NITRIFXNWpointer_3->A*40*NITRIFXNWpointer_3->NH4ppm)/(NITRIFXNWpointer_3->NH4ppm+90);
                                                            NITRIFXNWpointer_3->RNTRF = (NITRIFXNWpointer_3->bb>0.8?0.8:NITRIFXNWpointer_3->bb);
                                                            NITRIFXNWpointer_3->dNO3 = NITRIFXNWpointer_3->RNTRF;
                                                            N_dynamicspointer_2->flow2_1 = NITRIFXNWpointer_3->RNTRF;
                                                            N_dynamicspointer_2->flow205 = NITRIFXNWpointer_3->RNTRF;
                                                            N_dynamicspointer_2->flow4_0 = N_dynamicspointer_2->var19;
                                                            N_dynamicspointer_2->flow102_0 = N_dynamicspointer_2->NNOM;
                                                            MIN_FOMApointer_2->flow7 = MIN_FOMApointer_2->GRNOMCA;
                                                            Canopy_Cover_Wpointer->CCw = (Water_stresspointer_2->CWs>75?0:(double)(75-Water_stresspointer_2->CWs)/75*Canopy_coverpointer_2->CC);
                                                            Total_dry_matter_production_Wpointer_2->dTDM = (double)(Total_dry_matter_production_Wpointer_2->RUEw*Canopy_Cover_Wpointer->CCw*Weatherpointer_0->PAR)/100;














}; /* end(cond,1>=phase) */


}; /* end(procedure,int_evalmodel) */

/* EVALUATION PROCEDURE DECLARATION */

void ext_evalmodel (double start_time, int phase) {

/* GLOBAL DECLARATIONS */
/* global this */
/* global array_7 */
/* global array_6 */
/* global array_5 */
/* global array_4 */
/* global array_3 */
/* global array_2 */
/* global array_1 */
/* global array_0 */
/* global array */
/* global array_18 */
/* global array_17 */
/* global array_16 */
/* global array_15 */
/* global array_14 */
/* global array_13 */
/* global array_12 */
/* global array_11 */
/* global array_10 */
/* global array_9 */
/* global array_8 */
/* global array_21 */
/* global array_20 */
/* global array_19 */
/* global array_33 */
/* global array_32 */
/* global array_31 */
/* global array_30 */
/* global array_29 */
/* global array_28 */
/* global array_27 */
/* global array_26 */
/* global array_25 */
/* global array_24 */
/* global array_23 */
/* global array_22 */
/* STRUCTURE POINTER DECLARATIONS */


    /* UPDATE FUNCTION VALUES */


}; /* end(procedure,ext_evalmodel) */

    /* FREE ALL DATA STRUCTURES */

void do_exitmodel () {

/*  */
/*     namespace delete AME_model */
/*  */

}; /* end(procedure,dummy) */
}; /* end(class,AME_model) */
char Sol_integral_2012_Tor_9394_9_name[] = "Sol integral 2012 Tor 9394 9";
char Frost_limited_production_name[] = "Frost limited production";
char CCRF_name[] = "CCRF";
char CCRF_spec[] = "if Tmin < Tcr  then (if Tmin > Trg then (Trg -Tmin)/(Trg-Tcr) else 0) else 1";
char CCRF_comment[] = "Canopy Cover regrowht frost\n\
\n\
olde version called as GCRF";
char CCL_name[] = "CCL";
char CCL_spec[] = "if Tmin<Tld then 1 elseif Tmin<Tcr then (1-(Tld-Tmin)/(Tld-Tcr)) else 0";
char CCL_comment[] = "Canopy Cover Loss\n\
\n\
old version called Ground cover loss";
char c1_name[] = "c1";
char c1_spec[] = "0";
char fay1_name[] = "fay1";
char delayCCf_name[] = "delayCCf";
char ay1_name[] = "ay1";
char c2_name[] = "c2";
char c2_spec[] = "0";
char fay2_name[] = "fay2";
char fay2_spec[] = "if dCC > 0 then dCC * REB else dCC * 1 / REB";
char ay2_name[] = "ay2";
char C3_name[] = "C3";
char C3_spec[] = "f0";
char CCf_name[] = "CCf";
char fccf_name[] = "fccf";
char Tcr_name[] = "Tcr";
char Tcr_spec[] = "element([Inputs],11)";
char Tcr_comment[] = "Critical temperature (°C)\n\
\n\
poner: \n\
element([Coef_fr],1)";
char Tld_name[] = "Tld";
char Tld_spec[] = "element([Inputs],12)";
char Tld_comment[] = "Leaves dead temperature (°C)\n\
\n\
element([Coef_fr],2)";
char Trg_name[] = "Trg";
char Trg_spec[] = "element([Inputs],13)";
char Trg_comment[] = "Regrowth ... (°C)\n\
\n\
element([Coef_fr],3)";
char Tmin_0_name[] = "Tmin";
char Tmin_0_spec[] = "Tmin";
char REB_name[] = "REB";
char REB_spec[] = "1";
char REB_comment[] = "Cumulative Regrowht factor";
char Reb_name[] = "Reb";
char reba_name[] = "reba";
char reba_spec[] = "REB";
char CC_0_name[] = "CC";
char CC_0_spec[] = "CC";
char delayCC_name[] = "delayCC";
char delayCC_spec[] = "delay(CC,1)";
char dCC_name[] = "dCC";
char Tuber_production_F_name[] = "Tuber production F";
char DTYf_name[] = "DTYf";
char DTYf_spec[] = "TDMf*Part";
char FTYf_name[] = "FTYf";
char FTYf_spec[] = "DTYf/DMcont";
char Total_dry_matter_prod_F_name[] = "Total dry matter prod F";
char RUEs_0_name[] = "RUEs";
char RUEs_0_spec[] = "RUEs";
char TDMf_name[] = "TDMf";
char TDMf_spec[] = "0";
char dTDM_0_name[] = "dTDM";
char Randomize_name[] = "Randomize";
char rnd_name[] = "rnd";
char rnd_spec[] = "2*rand_const(0.0001,0.9999)-1";
char rnd_comment[] = "Random variable";
char rdm_name[] = "rdm";
char rdm_spec[] = "log((1+rnd)/(1-rnd))/1.82";
char rdm_comment[] = "Random constant";
char v_name[] = "v";
char v_spec[] = "0.2";
char v_comment[] = "Variability";
char N_dynamics_name[] = "N dynamics";
char Nac_name[] = "Nac";
char Nac_spec[] = "NO3POOL/1000";
char Nac_comment[] = "N actual in (t/ha)";
char flow2_1_name[] = "flow2";
char flow2_1_spec[] = "RNTRF";
char var19_name[] = "var19";
char var19_spec[] = "NH4o+NH4u+NH4am";
char flow205_name[] = "flow205";
char flow205_spec[] = "RNTRF";
char cd108_name[] = "cd108";
char cd108_spec[] = "0";
char NH4o_name[] = "NH4o";
char NH4o_spec[] = "NNOM";
char NH4o_comment[] = "kgha-1 N en forma amoniacal prov org matter NNOM";
char NNOM_name[] = "NNOM";
char NNOM_spec[] = "(0.8*GRNOM)+RHMIN-RNAC";
char NNOM_comment[] = "kgha-1d-1 net N released from organic sources";
char flow102_0_name[] = "flow102";
char flow102_0_spec[] = "NNOM";
char N_lib_acum_name[] = "N lib acum";
char N_lib_acum_spec[] = "0";
char N_lib_acum_comment[] = "kgha-1 N-  como NH4+";
char TOTN_name[] = "TOTN";
char TOTN_spec[] = "if NO3POOL > 0 then NO3POOL else 0";
char TOTN_comment[] = "Total mineral N (kgha-1)\n\
Soil extractable mineral N";
char NH4u_name[] = "NH4u";
char NH4u_spec[] = "flow1";
char NH4u_comment[] = "N (en forma amoniacal) released by hydrolysis (kgha-1d-1)";
char NH4POOL_name[] = "NH4POOL";
char NH4POOL_spec[] = "0";
char NH4POOL_comment[] = "Soil ammonium pool (N kgha-1)";
char flow4_0_name[] = "flow4";
char flow4_0_spec[] = "var19";
char NITRIFXNW_name[] = "NITRIFX";
char NO3ppm_name[] = "NO3ppm";
char NO3ppm_spec[] = "(NO3POOL/SWeight)*1000";
char SANC_name[] = "SANC";
char SANC_spec[] = "1-exp(-0.01363*SNH4)";
char SANC_comment[] = "effect supply of NH4 on nitrificax capacity";
char SNH4_name[] = "SNH4";
char SNH4_spec[] = "var19";
char SNH4_comment[] = "kgha-1 N-NH4 soil";
char ELNC_name[] = "ELNC";
char ELNC_spec[] = "min(min,SANC)";
char ELNC_comment[] = "environmental limit on nitrificax capacity";
char min_name[] = "min";
char RP2_name[] = "RP2";
char RP2_spec[] = "exp(2.302*ELNC)";
char RP2_comment[] = "var";
char phn_name[] = "phn";
char phn_spec[] = "pH*0.05";
char phn_comment[] = "effect of soil pH on nitrificax\n\
\n\
Por justificar";
char min1_name[] = "min1";
char min1_spec[] = "min(min,phn)";
char A_name[] = "A";
char A_spec[] = "min(RP22,min1)";
char A_comment[] = "factor  x relative nitrificax rate";
char bb_name[] = "bb";
char bb_spec[] = "A*40*NH4ppm/(NH4ppm+90)";
char bb_comment[] = "maximum rate of nitrificax (kg N ha-1d-1)";
char NH4ppm_name[] = "NH4ppm";
char NH4ppm_spec[] = "(NH4POOL/SWeight)*1000";
char NH4ppm_comment[] = "ppm soil NH4";
char NO3POOL_name[] = "NO3POOL";
char NO3POOL_spec[] = "NO3am";
char NO3POOL_comment[] = "Soil nitrate in kg N ha-1";
char dNO3_name[] = "dNO3";
char dNO3_spec[] = "RNTRF";
char dNO3_comment[] = "NO3 kgha-1d-1";
char WFD_name[] = "WFD";
char WFD_spec[] = "1-(s-FC)/(Po-FC)";
char RP22_name[] = "RP22";
char RP22_spec[] = "if RP2<0.05 then 0.05 elseif RP2>1 then 1 else RP2";
char RNTRF_name[] = "RNTRF";
char RNTRF_comment[] = "amount of N-NH4 nitrified  kgha-1d-1";
char MIN_HUMUS_name[] = "MIN HUMUS";
char NHUMi_name[] = "NHUMi";
char NHUMi_spec[] = "OMw*1000/10";
char NHUMi_comment[] = "N assoc stable humic frax (kgha-1)\n\
Asum C/N=10";
char CHUMi_name[] = "CHUMi";
char CHUMi_spec[] = "OMw*1000";
char CHUMi_comment[] = "C assoc stable hum frax (kgha-1)\n\
Asum C/N=10";
char NHUM_name[] = "NHUM";
char NHUM_spec[] = "NHUMi";
char NHUM_comment[] = "kgha-1 N assoc stable humic frax";
char flow109_name[] = "flow109";
char flow109_spec[] = "RHMIN";
char flow110_name[] = "flow110";
char flow110_spec[] = "GRNOM*0.2";
char MF_name[] = "MF";
char MF_spec[] = "if s>FC then(s-FC)/(Po-FC)elseif s<=FC and s>WP then 1-0.5*((s-WP)/(FC-WP))else 0";
char MF_comment[] = "moisture factor";
char TF_name[] = "TF";
char TF_spec[] = "if Stemp<5 then 0 elseif Stemp>35 then 1 else (Stemp-5)/30";
char TF_comment[] = "temperature factor";
char RHMIN_name[] = "RHMIN";
char RHMIN_comment[] = "N released from humus (kgha-1)";
char RHMINacum_name[] = "RHMINacum";
char RHMINacum_spec[] = "0";
char RHMINacum_comment[] = "kgha-1 N";
char flow105_name[] = "flow105";
char DMINR_name[] = "DMINR";
char DMINR_spec[] = "8.3 *(pow(10,-5))";
char DMINR_comment[] = "humic frax decay rate";
char DMOD_name[] = "DMOD";
char DMOD_spec[] = "1";
char DMOD_comment[] = "(0-1) factor decrease to rate of mineralix\n\
special cases (volcanic soil: less than 1), virgin soils (more than 1)";
char HUM_name[] = "HUM";
char HUM_comment[] = "kgha-1 stable humic frax material in layer \n\
kgha-1 organic carbon";
char MFTF_name[] = "MFTF";
char flow101_name[] = "flow101";
char flow101_spec[] = "(GRNOM*0.2)/0.04";
char flow102_name[] = "flow102";
char flow102_spec[] = "RHMIN*10";
char flow102_comment[] = "kgha-1 decay soil organic carbon\n\
De mantener la relacion C/N = 10";
char Hum_decomp__acum_name[] = "Hum decomp \n\
acum";
char Hum_decomp__acum_spec[] = "0";
char Hum_decomp__acum_comment[] = "kgha-1";
char flow103_name[] = "flow103";
char flow103_spec[] = "flow102";
char MIN_FOMA_name[] = "MIN FOMA";
char FPOOLCE_name[] = "FPOOLCE";
char FPOOLCE_spec[] = "FOMi*0.7";
char CE_name[] = "CE";
char CE_spec[] = "G1CE*FPOOLCE";
char flow1_name[] = "flow1";
char flow1_spec[] = "CE";
char GRNOMCE_name[] = "GRNOMCE";
char GRNOMCE_spec[] = "if FOM>=5 then CE*FON/FOM else 0";
char GRNOMLI_name[] = "GRNOMLI";
char GRNOMLI_spec[] = "if FOM>=5 then LI*FON/FOM else 0";
char LI_name[] = "LI";
char LI_spec[] = "G1LI*FPOOLLI";
char FPOOLLI_name[] = "FPOOLLI";
char FPOOLLI_spec[] = "FOMi*0.1";
char flow2_name[] = "flow2";
char flow2_spec[] = "LI";
char NCE_acum_name[] = "NCE acum";
char NCE_acum_spec[] = "0";
char NCE_acum_comment[] = "kgha-1 ciclo";
char NLI_acum_name[] = "NLI acum";
char NLI_acum_spec[] = "0";
char NLI_acum_comment[] = "kgha-1 ciclo";
char CA_name[] = "CA";
char CA_spec[] = "G1CA*FPOOLCA";
char CA_comment[] = "kgha-1d-1 amount of org mat decay";
char G1CA_name[] = "G1CA";
char G1CA_spec[] = "CNRF*MFTF*0.8";
char G1CA_comment[] = "proportion d-1 of org mat decay";
char FPOOLCA_name[] = "FPOOLCA";
char FPOOLCA_spec[] = "FOMi*0.2";
char FPOOLCA_comment[] = "kgha-1 fresh organic mat relat carbohydrates";
char flow6_name[] = "flow6";
char flow3_name[] = "flow3";
char flow3_spec[] = "GRNOMCE";
char flow4_name[] = "flow4";
char flow4_spec[] = "GRNOMLI";
char GRNOM_name[] = "GRNOM";
char GRNOM_spec[] = "GRNOMCA+GRNOMCE+GRNOMLI";
char GRNOM_comment[] = "kgha-1d-1  gross release of N from org mat decomp";
char acumGRNOM_name[] = "acumGRNOM";
char acumGRNOM_spec[] = "0";
char acumGRNOM_comment[] = "kgha-1 ciclo";
char GRNOMCA_name[] = "GRNOMCA";
char GRNOMCA_spec[] = "if FOM>=5 then CA*FON/FOM else 0";
char GRNOMCA_comment[] = "kgha-1d-1 de N released from org mat ad carb";
char NCA_acum_name[] = "NCA acum";
char NCA_acum_spec[] = "0";
char NCA_acum_comment[] = "kgha-1 ciclo";
char flow7_name[] = "flow7";
char flow7_spec[] = "GRNOMCA";
char G1CE_name[] = "G1CE";
char G1CE_spec[] = "CNRF*MFTF*0.05";
char G1LI_name[] = "G1LI";
char G1LI_spec[] = "CNRF*MFTF*0.0095";
char flow107_name[] = "flow107";
char flow107_spec[] = "GRNOM";
char GRCOM_name[] = "GRCOM";
char GRCOM_spec[] = "CA+CE+LI";
char GRCOM_comment[] = "kgha-1d-1 gross release of C from org mat decomp\n\
amount of decaying organic matter";
char acumGRCOM_name[] = "acumGRCOM";
char acumGRCOM_spec[] = "0";
char acumGRCOM_comment[] = "kgha-1 ciclo";
char flow108_name[] = "flow108";
char flow108_spec[] = "GRCOM";
char _C_name[] = "%C";
char _C_spec[] = "60";
char _C_comment[] = "% C org matt added\n\
Asumiendo como en la ecuacion que CN es 60";
char CN_name[] = "CN";
char CN_spec[] = "element([OM_CN],1)";
char CN_comment[] = "CN ratio org matt added";
char _N_name[] = "%N";
char _N_spec[] = "_C/CN";
char _N_comment[] = "% N org matt added\n\
Se puede tener dato de %C o % N  y dato de CN";
char FOMi_name[] = "FOMi";
char FOMi_spec[] = "2000";
char FOMi_comment[] = "kgha-1  org matter added";
char FONi_name[] = "FONi";
char FONi_comment[] = "kgha-1 de organic N prov organic matter ad";
char FOCi_name[] = "FOCi";
char FOCi_comment[] = "kgha-1 de organic carbon prov organic matter ad";
char CNR_name[] = "CNR";
char CNR_comment[] = "C/N ratio calculated";
char CNRF_name[] = "CNRF";
char CNRF_spec[] = "exp(-0.963*(CNR-25)/25)";
char CNRF_comment[] = "C/N ratio factor for decomposition rate\n\
falta poner restrix negativa";
char IMMOBIXNW_name[] = "IMMOBIX";
char FOM_name[] = "FOM";
char FOM_spec[] = "FOMi";
char FOM_comment[] = "kgha-1 organic matter added";
char grcom_name[] = "grcom";
char grcom_spec[] = "GRCOM";
char FON_name[] = "FON";
char FON_spec[] = "FONi";
char FON_comment[] = "kgha-1 organic N prov organic matter add";
char grnom_name[] = "grnom";
char grnom_spec[] = "GRNOM";
char RNAC_name[] = "RNAC";
char RNAC_spec[] = "if RNACp <0 then 0 else RNACp";
char RNAC_comment[] = "kgha-1d-1 N immobilized assoc organic decay";
char REST_name[] = "REST";
char REST_spec[] = "if var1 >0 then GRCOM*(0.02-(FON/var1)) else 0";
char RNACp_name[] = "RNACp";
char RNACp_spec[] = "min(REST,TOTN)";
char RNACp_comment[] = "kgh-1d-1 N  immobilized assoc decay residues";
char rnac_name[] = "rnac";
char rnac_spec[] = "RNAC";
char var1_name[] = "var1";
char var1_spec[] = "if FOM< 5 then 0 else FOM";
char Type_of_OM_added_name[] = "Type of OM added";
char Type_name[] = "Type";
char Type_spec[] = "4";
char Type_comment[] = "Choose one:\n\
\n\
1==Humus 	10\n\
2==Alfalfa hay	18\n\
3==Grass clippings 	19\n\
4==Rotted manure 	20\n\
5==Corn stalks	60\n\
6==Cereal straw 	80\n\
7==Farm manure 	90\n\
8==Alder sawdust 	134\n\
9==Newspaper	170";
char OM_CN_name[] = "OM CN";
char OM_CN_spec[] = "if Type==1 then [10,1] elseif Type==2 then [18,1] elseif Type==3 then [19,1] elseif Type==4 then [20,1] elseif Type==5 then [60,1] elseif Type==6 then [80,1] elseif Type==7 then [90,1] elseif Type==8 then [134,1]  else [170,1]";
char UREA_HYD_name[] = "UREA HYD";
char AK_name[] = "AK";
char AK_spec[] = "-1.12+(1.31*OC)+(0.203*pH)-(0.155*OC*pH)";
char AK_comment[] = "proportion  of urea which hydrolyzes\n\
max hydrolysis rate";
char SWF_name[] = "SWF";
char SWF_comment[] = "Soil water factor x urea hyd";
char MFU_name[] = "MFU";
char TFU_name[] = "TFU";
char UREA_name[] = "UREA";
char UREA_spec[] = "if Fert==1 then amount else 0";
char UREA_comment[] = "kgha-1";
char NUREAi_name[] = "NUREAi";
char NUREAi_spec[] = "UREA";
char NUREAi_comment[] = "kgha-1 N linked to urea";
char UHYDR_name[] = "UHYDR";
char UHYDR_spec[] = "AKU*min(MFU,TFU)*NUREA*0.01";
char UHYDR_comment[] = "Urea hydrolysis rate (kg N urea ha-1d-1)";
char var13_name[] = "var13";
char var13_spec[] = "AKU*min(MFU,TFU)*NUREAi/100";
char TFF_name[] = "TFF";
char TFF_spec[] = "(Stemp/40)+0.2";
char TFF_comment[] = "Temp factor x urea hyd";
char AKU_name[] = "AKU";
char AKU_spec[] = "if AK < 0.25 then 0.25 else AK";
char NUREA_name[] = "NUREA";
char flow1_0_name[] = "flow1";
char flow1_0_spec[] = "UHYDR";
char comp2_name[] = "comp2";
char comp2_spec[] = "0";
char flow2_0_name[] = "flow2";
char flow2_0_spec[] = "flow1";
char FERTILIZERS_name[] = "FERTILIZERS";
char amount_name[] = "amount";
char amount_spec[] = "100";
char amount_comment[] = "amount of fertilizer applied (kgha-1)";
char NH4_fert_name[] = "NH4 fert";
char NH4_fert_spec[] = "if Fert==2 then 0.225 elseif Fert==3 then 0.15 else 0";
char NO3fert_name[] = "NO3fert";
char NO3fert_spec[] = "if Fert==2 then 0.775 else 0";
char NH4am_name[] = "NH4am";
char NH4am_spec[] = "NH4_fert*amount";
char NH4am_comment[] = "N-NH4 en fert (kgha-1)";
char NO3am_name[] = "NO3am";
char NO3am_spec[] = "NO3fert*amount";
char NO3am_comment[] = "N-NO3 en fert(kgha-1)";
char Fert_name[] = "Fert";
char Fert_spec[] = "1";
char Fert_comment[] = "Choose one\n\
1= Urea\n\
2= Nitrato de amonio\n\
3= Fosfato monoamonico";
char Weather_name[] = "Weather";
char SoilTemp_name[] = "SoilTemp";
char SoilTemp_spec[] = "makearray(1,365)";
char SoilTemp_comment[] = "Soil Temperature (oC)";
char Tsoi_name[] = "Tsoi";
char Tsoi_spec[] = "element([SoilTemp],day)";
char Irrigation_name[] = "Irrigation";
char Irrigation_spec[] = "makearray(1,365)";
char Irri_name[] = "Irri";
char Irri_spec[] = "element([Irrigation],day)";
char Irri_comment[] = "Irrigation (mm)";
char PET_name[] = "PET";
char PET_spec[] = "makearray(1,365)";
char PET_comment[] = "Potential Evapo Transpiration";
char ETo_name[] = "ETo";
char ETo_comment[] = "Reference evapotranspiration";
char MinTemp_name[] = "MinTemp";
char MinTemp_spec[] = "makearray(1,365)";
char MaxTemp_name[] = "MaxTemp";
char MaxTemp_spec[] = "makearray(1,365)";
char Rainfall_name[] = "Rainfall";
char Rainfall_spec[] = "makearray(1,365)";
char Tmax_name[] = "Tmax";
char Tmax_spec[] = "element([MaxTemp],day)";
char Radiation_name[] = "Radiation";
char Radiation_spec[] = "makearray(1,365)";
char Radiation_comment[] = "Global radiation";
char Tmin_name[] = "Tmin";
char Tmin_spec[] = "element([MinTemp],day)";
char Rain_name[] = "Rain";
char Rain_spec[] = "element([Rainfall],day)";
char Rain_comment[] = "Rainfall (mm)";
char PAR_name[] = "PAR";
char PAR_spec[] = "element([Radiation],day)*0.5";
char PAR_comment[] = "Photosynthetically active  radiation";
char Variety_name[] = "Variety ";
char Inputs_name[] = "Inputs";
char Inputs_spec[] = "if Var_Name==1 then[0.74,0.0034,0.0063,253,1360,2.8,0.8,-9.6,944,0.33,-2.4,-5.0,-7.0]elseif Var_Name==2 then[0.72,0.0026,0.0064,249,1385,2.72,0.74,-8.1,1125,0.3,-3.0,-5.0,-8.0]elseif Var_Name==3 then[0.78,0.0028,0.0072,278,1358,2.65,0.84,-7.5,891,0.31,-1.0,-4.0,-5.0]elseif Var_Name==4 then[0.74,0.004,0.0064,302,1369,2.53,0.77,-5.5,1061,0.25,-1.0,-4.0,-5.0]elseif \
Var_Name==5 then[1,0.0049,0.0066,425,1185,2.88,0.86,-4.8,822,0.22,-0.7,-3.3,-4.0]elseif Var_Name==6 then[0.65,0.0033,0.0063,278,1392,2.69,0.74,-7.4,1074,0.23,-1.6,-3.6,-6.0]elseif Var_Name==7 then[0.63,0.0043,0.0061,219,1417,2.79,0.78,-6.1,1083,0.23,-1.8,-3.0,-6.0]elseif Var_Name==8 then[0.74,0.0043,0.0061,229,1399,2.85,0.77,-8.1,1061,0.24,-1.9,-3.8,-6.0]elseif \
Var_Name==9 then[0.66,0.0036,0.0064,230,1410,2.65,0.79,-5.3,1098,0.24,-1.9,-3.8,-6.0]elseif Var_Name==10 then[0.66,0.0036,0.0064,230,1410,2.65,0.79,-5.3,1098,0.24,-1.5,-3.0,-6.0]else[0.9728,0.00591,0.00677,612,1718,5.5,0.8456,-2.4386,722.6,0.21,-1.0,-3.0,-4.0]";
char Inputs_comment[] = "Cultivar,\n\
Choose one:\n\
  1 = Ajahuiri\n\
  2 = Luki\n\
  3 = Gendarme\n\
  4 = Waycha\n\
  5 = Alpha\n\
  6 = Condori\n\
  7 = Tunari\n\
  8 = Sajama\n\
  9 = Illimani\n\
  10 = Totorena\n\
  11 = Canchan CSO (cobveg) 2006 (new included by CB)";
char Var_Name_name[] = "Var_Name";
char Var_Name_spec[] = "4";
char Var_Name_comment[] = "Cultivar,\n\
Choose one:\n\
  1 = Ajahuiri\n\
  2 = Luki\n\
  3 = Gendarme\n\
  4 = Waycha\n\
  5 = Alpha\n\
  6 = Condori\n\
  7 = Tunari\n\
  8 = Sajama\n\
  9 = Illimani\n\
  10 = Totorena";
char Thermal_time_name[] = "Thermal time";
char Thermal_conditions_name[] = "Thermal conditions";
char Thermal_conditions_spec[] = "1";
char Thermal_conditions_comment[] = "Choose :\n\
\n\
1==Cold\n\
2==Temperate\n\
3==Warm";
char TC_name[] = "TC";
char TC_spec[] = "if Thermal_conditions==1 then[0,14,25]elseif Thermal_conditions==2 then[2,20,28]else[4,25,35]";
char TC_comment[] = "\n\
\n\
\n\
if Condition==1 then [0,14,25]     antes era (0,18,26)\n\
elseif Condition==2 then [2,20,28]\n\
else [4,25,35]";
char W_name[] = "W";
char W_spec[] = "if Tav>=Tb and Tav<To then 1-((Tav-To)/(To-Tb))^2 elseif Tav>=To and Tav<=Th then-((Tav-Th)/(Th-To))else 0";
char W_comment[] = "Conditional of ef.temp";
char Tac_name[] = "Tac";
char Tac_spec[] = "1.0E-05";
char Tac_comment[] = "Accumulated effective daily temperature (C)";
char Tb_name[] = "Tb";
char Tb_spec[] = "element([TC],1)";
char Tb_comment[] = "Base Temperature, (0-4 C)\n\
\n\
element([Inputs],7)";
char To_name[] = "To";
char To_spec[] = "element([TC],2)";
char To_comment[] = "Optimum temperature for phenological development, (20 C)";
char Th_name[] = "Th";
char Th_spec[] = "element([TC],3)";
char Th_comment[] = "Maximum temperature for phenological development, (28-32 C)";
char Te_name[] = "Te";
char Te_comment[] = "Effective daily temperature (C)";
char Tav_name[] = "Tav\n\
";
char Tav_spec[] = "(Tmax+Tmin)/2";
char Tav_comment[] = "Air temperature average (ºC)";
char Time_name[] = "Time";
char month_name[] = "month";
char month_spec[] = "if day<=31 then 1 elseif day>31&&day<=59 then 2 elseif day>59&&day<=90 then 3 elseif day>90&&day<=120 then 4 elseif day>120&&day<=151 then 5 elseif day>151&&day<=181 then 6 elseif day>181&&day<=212 then 7 elseif day>212&&day<=243 then 8 elseif day>243&&day<=273 then 9 elseif day>273&&day<=304 then 10 \
elseif day>304&&day<=334 then 11 else 12";
char month_comment[] = "Simulation's month, (mo)";
char day_name[] = "day";
char day_spec[] = "fmod(time()+PDate-1,365)+1";
char day_comment[] = "Simulation's day, (d)";
char EDay_name[] = "EDay";
char EDay_spec[] = "40";
char EDay_comment[] = "Emergence Day, (d)";
char DAE_name[] = "DAE";
char DAE_spec[] = "if PDay>=EDay then time()-EDay else 0";
char DAE_comment[] = "Days after emergence, (d)";
char PDay_name[] = "PDay";
char PDay_spec[] = "time()";
char PDay_comment[] = "Days after planting, (d)";
char Planting_Date_name[] = "Planting Date";
char dd_name[] = "dd";
char dd_spec[] = "22";
char dd_comment[] = "Planting Date - Day";
char mm_name[] = "mm";
char mm_spec[] = "10";
char mm_comment[] = "Planting Date - Month";
char PDate_name[] = "PDate";
char PDate_spec[] = "if mm==1 then dd \n\
elseif mm==2 then dd+31 \n\
elseif mm==3 then dd+59\n\
elseif mm==4 then dd+90\n\
elseif mm==5 then dd+120\n\
elseif mm==6 then dd+151\n\
elseif mm==7 then dd+181 \n\
elseif mm==8 then dd+212 \n\
elseif mm==9 then dd+243 \n\
elseif mm==10 then dd+273 \n\
elseif mm==11 then dd+304 \n\
else dd+334";
char PDate_comment[] = "Acumulated Planting Date, (d)";
char Soil_parameters_name[] = "Soil parameters";
char Po_name[] = "Po";
char Po_spec[] = "100*(2.65-(BD/1000))/2.65";
char Po_comment[] = "Porosidad (%)";
char cl_name[] = "cl";
char cl_spec[] = "element([Hydric],3)- 0.5*(element([Hydric],3)-element([Hydric],4))";
char cl_comment[] = "Critical depletion level (%vol)";
char FC_name[] = "FC";
char FC_spec[] = "Soil_Vol*element([Hydric],3)/1000";
char FC_comment[] = "Field capacity (mm)";
char WP_name[] = "WP";
char WP_spec[] = "Soil_Vol*element([Hydric],4)/1000";
char WP_comment[] = "Wilting point (mm)";
char CL_name[] = "CL";
char CL_comment[] = "Critical depletion level (mm)";
char OM_name[] = "OM";
char OM_spec[] = "2";
char OM_comment[] = "Organic matter (%)\n\
\n\
Input";
char OMw_name[] = "OMw";
char OMw_spec[] = "OM/100*SWeight";
char OMw_comment[] = "Organic matter (t/ha)";
char OC_name[] = "OC";
char OC_spec[] = "0.58*OM";
char OC_comment[] = "soil organic carbon (%)\n\
falta agregar el C q se libera de mat org add";
char ISM_name[] = "ISM";
char ISM_spec[] = "100";
char ISM_comment[] = "Initial Soil water Moisture (mm)";
char pH_name[] = "pH";
char pH_spec[] = "6";
char fc_name[] = "fc";
char fc_spec[] = "element([Hydric],3)";
char fc_comment[] = "Field capacity (%vol) or  (m3/m3)";
char wp_name[] = "wp";
char wp_spec[] = "element([Hydric],4)";
char wp_comment[] = "Wilting point (%vol) or (m3/m3)";
char Soil_texture_name[] = "Soil texture";
char Soil_texture_spec[] = "8";
char Soil_texture_comment[] = "\n\
Choose one:\n\
\n\
1==Silty Clay\n\
2==Silty Clay Loam\n\
3==Clay\n\
4==Silt\n\
5==Silty Loam\n\
6==Clay Loam\n\
7==Sand\n\
8==Loam\n\
9==Loamy Sand\n\
10==Sandy Loam\n\
11==Sandy Clay\n\
12==Sandy Clay Loam";
char Hydric_name[] = "Hydric";
char Hydric_spec[] = "if Soil_texture==1 then [1.24,54,50,32,15, 10.9, 3845.3]\n\
elseif Soil_texture==2 then [1.30,52,44,23,120, 6.4, 3862.5]\n\
elseif Soil_texture==3 then [1.36,55,54,39,2,11,4567.7]\n\
elseif Soil_texture==4 then [1.37,43,33,9,50,1.4, 3404.6]\n\
elseif Soil_texture==5 then [1.37,46,33,13,150, 1.4,3404.6]\n\
elseif Soil_texture==6 then [1.40,50,39,23,100,7, 3863.0]\n\
elseif Soil_texture==7 then [1.42,36,13,6,1500,1.8, 2390.6]\n\
elseif Soil_texture==8 then [1.44,46,31,15,250,2.8, 3533.1]\n\
elseif Soil_texture==9 then [1.44,38,16,8,800, 1.8,2627.0]\n\
elseif Soil_texture==10 then [1.46,41,22,10,500,1.7,3052.8]\n\
elseif Soil_texture==11 then [1.48,50,39,27,75, 10.6, 4172.3]\n\
else [1.51,47,32,20,125,5.7,3847.3]";
char Hydric_comment[] = "BD, Bulk density  (g/cm3)\n\
SAT, Soil saturation (%vol)	\n\
FC, Field capacity (%vol)\n\
WP, Wilting point (%vol)\n\
Ksat, Saturated hydraulic conductivity (mm/day)\n\
Included for  Soil Temperature (Separata)\n\
k. thermal conductivity (W*m-1*K-1)\n\
C, thermal capacity (J*kg-1*K-1)\n\
\n\
\n\
1==Silty Clay\n\
2==Silty Clay Loam\n\
3==Clay\n\
4==Silt\n\
5==Silty Loam\n\
6==Clay Loam\n\
7==Sand\n\
8==Loam\n\
9==Loamy Sand\n\
10==Sandy Loam\n\
11==Sandy Clay\n\
12==Sandy Clay Loam";
char Area_name[] = "Area";
char Area_spec[] = "10000";
char Area_comment[] = "Field area (m2) or 1 ha.";
char Soil_depth_name[] = "Soil depth";
char Soil_depth_spec[] = "0.5";
char Soil_depth_comment[] = "Soil depth (m) or rooting zone.";
char Soil_Vol_name[] = "Soil Vol";
char Soil_Vol_spec[] = "Area*Soil_depth";
char Soil_Vol_comment[] = "Soil volumen (m3)";
char SWeight_name[] = "SWeight";
char SWeight_spec[] = "(Soil_Vol*BD)/1000";
char SWeight_comment[] = "Soil weight (t/ha)";
char BD_name[] = "BD";
char BD_spec[] = "element([Hydric],1)*1000";
char BD_comment[] = "Bulk density (Kg/m3)";
char Soil_temp_est_name[] = "Soil temp est";
char k_name[] = "k";
char k_spec[] = "element([Hydric],5)";
char c_name[] = "c";
char c_spec[] = "element([Hydric],6)";
char Stemp_name[] = "Stemp";
char Stemp_spec[] = "2/3.1416*(Tav-Tl)*exp(-(k/(BD*c))*3.1416^2*1.0E+10/Dl^2)*sin(3.1416*D/Dl)+Tav+(Tl-Tav)/Dl*D";
char Stemp_comment[] = "Soil temperature (ºC)\n\
\n\
No considerar epoca donde no hay cultivo (invierno)\n\
Jose hara que no muestre resultados para esta etapa.";
char Tl_name[] = "Tl";
char Tl_spec[] = "1.25*Tav";
char Tl_comment[] = "Temparure at maximun depth (ºC)\n\
\n\
Dato empirico, probablemente variable.";
char Dl_name[] = "Dl";
char Dl_spec[] = "40";
char Dl_comment[] = "Maximun soil depth (cm)";
char D_name[] = "D";
char D_spec[] = "Soil_depth*100";
char D_comment[] = "Soil depth (cm)\n\
\n\
Se ha trabajado hasta 40 cm.";
char Soil_water_Balance_name[] = "Soil water Balance";
char Eo_name[] = "Eo";
char Eo_spec[] = "MCC*ETo*exp(-0.7*4*CC)";
char Eo_comment[] = "Potential evaporation of the soil (mm/d)";
char s_name[] = "s";
char s_spec[] = "CS";
char s_comment[] = "Daily avaliable soil water (mm).";
char CS_name[] = "CS";
char CS_spec[] = "ISM";
char CS_comment[] = "Cumulated soil water content (mm)";
char S_name[] = "S";
char S_comment[] = "Dayli change in soil moisture content (mm/d).";
char To_0_name[] = "To";
char To_0_spec[] = "if CC==0 then (0.0001) else (1.1*ETo*(1-exp(-0.7*4*CC))/(1-exp(-0.7*4*MCC)))";
char To_0_comment[] = "Potential transpiration of the crop (mm/d)";
char T_name[] = "T";
char T_comment[] = "Actual transpiration";
char Water_limited_production_name[] = "Water limited production";
char RUEs_name[] = "RUEs";
char Water_stress_name[] = "Water stress";
char Ws_name[] = "Ws";
char Ws_spec[] = "if (1-(T/To))-0.8 <0 then 0 else (1-(T/To))-0.8";
char Ws_comment[] = "Water Stress Index";
char CWs_name[] = "CWs";
char CWs_spec[] = "Ws";
char CWs_comment[] = "Cummulative water stress index";
char Total_dry_matter_production_W_name[] = "Total dry matter production W";
char dTDM_name[] = "dTDM";
char TDMw_name[] = "TDMw";
char TDMw_spec[] = "0";
char TDMw_comment[] = "Total dry matter under water stress";
char RUEw_name[] = "RUEw";
char RUEw_spec[] = "if RUEs*(0.8-Ws)/0.8<0 then 0 else RUEs*(0.8-Ws)/0.8";
char RUEw_comment[] = "Radiation Use Efficiency under water stress\n\
\n\
if RUE*(0.8-WS)/0.8<0 then 0 else RUE*(0.8-WS)/0.8 reemplaza a 1";
char Tuber_production_W_name[] = "Tuber production W";
char DTYw_name[] = "DTYw";
char DTYw_comment[] = "Tuber dry matter under water stress";
char FTYw_name[] = "FTYw";
char FTYw_comment[] = "Tuber fresh matter under water stress";
char Canopy_Cover_W_name[] = "Canopy Cover W";
char CCw_name[] = "CCw";
char CCw_spec[] = "if CWs >75 then 0 else (75-CWs)/75*CC";
char CCw_comment[] = "Canopy Cover under Water stress\n\
\n\
if CWS>50 then 0 else(50-CWS)/50*CC reemplaza  a 1";
char Potential_production_name[] = "Potential production";
char Canopy_cover_name[] = "Canopy cover";
char flinti_name[] = "flinti";
char N_name[] = "N";
char N_spec[] = "4.7";
char N_comment[] = "N, plant density (pl/m2)\n\
\n\
47619 pl/ha";
char Flint1_name[] = "Flint1";
char Flint1_spec[] = "flinti";
char Flint1_comment[] = "Growth phase";
char Flint2_name[] = "Flint2";
char Flint2_comment[] = "Senescence phase";
char CC_name[] = "CC";
char CC_spec[] = "if Flint2<=0 then 0 elseif Flint1<Flint2 then Flint1 elseif Flint2>0 then Flint2 else Flint1";
char CC_comment[] = "Canopy Cover";
char d_name[] = "d";
char d_spec[] = "element([Inputs],4)";
char d_comment[] = "Twice the duration from t0.5 to the end of light intercep (oCd)";
char f0_name[] = "f0";
char f0_spec[] = "element([Inputs],2)";
char f0_description[] = "f0";
char f0_comment[] = "Initial fraction of light interception, (MJ / d)";
char R0_name[] = "R0";
char R0_spec[] = "element([Inputs],3)";
char R0_description[] = "R0";
char R0_comment[] = "Rate of relative increase of light interception, (oC-1 * d-1)";
char t50_name[] = "t50";
char t50_spec[] = "element([Inputs],5)";
char t50_comment[] = "Time when the fraction of l.i. is reduced to 50%of its maximum value attained at MCC (oCd).";
char MCC_name[] = "MCC";
char MCC_spec[] = "element([Inputs],1)";
char MCC_description[] = "fcl";
char MCC_comment[] = "Maximum canopy Cover (Maximum fraction of light intercepted)";
char Total_dry_matter_production_name[] = "Total dry matter production";
char RUE_name[] = "RUE";
char RUE_spec[] = "element([Inputs],6)";
char RUE_comment[] = "Average Radiation Use Efficiency, (g * MJ-1)";
char TDM_name[] = "TDM";
char TDM_spec[] = "1.0E-37";
char TDM_comment[] = "Total Dry Matter, (tn * ha-1)";
char dW_name[] = "dW";
char dW_comment[] = "Daily weight of total dry matter, (tn * ha-1)";
char Tuber_production_name[] = "Tuber production";
char M_name[] = "M";
char M_spec[] = "element([Inputs],7)";
char M_comment[] = "Max value of HI";
char A_0_name[] = "A";
char A_0_spec[] = "element([Inputs],9)";
char A_0_comment[] = "Asymptotic HI";
char DTY_name[] = "DTY";
char DTY_comment[] = "Dry tuber yield, (tn * ha-1)";
char b_name[] = "b";
char b_spec[] = "element([Inputs],8)";
char b_comment[] = "Slope HI";
char Part_name[] = "Part";
char Part_comment[] = "Partition dynamics";
char DMcont_name[] = "DMcont";
char DMcont_spec[] = "element([Inputs],10)";
char DMcont_comment[] = "Dry matter content";
char FTY_name[] = "FTY";
char FTY_spec[] = "DTY/DMcont";
char FTY_comment[] = "Fresh Tuber Yield, (tn * ha-1)";
char Nitrogen_limited_production_name[] = "Nitrogen limited production";
char Canopy_cover_N_name[] = "Canopy cover N";
char CCn_name[] = "CCn";
char CCn_comment[] = "Canopy growth under nitrogen stress\n\
\n\
CC*Nstress reemplaza a 1";
char Total_dry_matter_production_N_name[] = "Total dry matter production N";
char dTDM_1_name[] = "dTDM";
char TDMn_name[] = "TDMn";
char TDMn_spec[] = "0";
char TDMn_comment[] = "Total dry matter under nitrogen stress (tons/he)";
char RUE_0_name[] = "RUE";
char RUE_0_spec[] = "element([Inputs],6)";
char Tuber_production_N_name[] = "Tuber production N";
char FTYn_name[] = "FTYn";
char FTYn_comment[] = "Tuber fresh matter under nitrogen stress (tons/he)";
char DTYn_name[] = "DTYn";
char DTYn_spec[] = "TDMn*Part";
char DTYn_comment[] = "Tuber dry matter under nitrogen stress (tons/he)";
char N_stress_name[] = "N stress";
char Npot_name[] = "Npot";
char Npot_spec[] = "Npc*TDM/100";
char Npot_comment[] = "N potential (t/ha)";
char Npc_name[] = "Npc";
char Npc_spec[] = "(1.35+4.05*exp(-0.26*TDM))";
char Npc_comment[] = "N potential concentration (%) \n\
\n\
Potential nitrogen (tons/he)";
char NacNpot_name[] = "NacNpot\n\
";
char NacNpot_comment[] = "antes era Ndispacum/PotN";
char GC0_name[] = "GC0";
char GC0_spec[] = "0.6";
char GC250_name[] = "GC250";
char GC250_spec[] = "1";
char Ns_name[] = "Ns";
char Ns_spec[] = "if NacNpot>1 then 1 else(GC250-GC0)*NacNpot+GC0";
int nodecount = 283;
node_data_line nodedata[] = {{"node00000", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 0}, 0, 0, 0, SUBMODEL, {Sol_integral_2012_Tor_9394_9_name, NULL, NULL, NULL}},
     {"node00012", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 1, 0}, 0, 0, 0, SUBMODEL, {Frost_limited_production_name, NULL, NULL, NULL}},
     {"node01815", REAL, 0, NULL, DERIVED, {0},
     {1, 1, 11, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {CCRF_name, CCRF_spec, NULL, CCRF_comment}},
     {"node01817", REAL, 0, NULL, DERIVED, {0},
     {1, 1, 12, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {CCL_name, CCL_spec, NULL, CCL_comment}},
     {"node01819", REAL, 0, NULL, DERIVED, {0},
     {1, 1, 14, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {c1_name, c1_spec, NULL, NULL}},
     {"arc00706", REAL, 0, NULL, DERIVED, {0},
     {1, 1, 15, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {fay1_name, NULL, NULL, NULL}},
     {"node01823", REAL, 0, NULL, DERIVED, {0},
     {1, 1, 16, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {delayCCf_name, NULL, NULL, NULL}},
     {"arc00815", REAL, 0, NULL, DERIVED, {0},
     {1, 1, 17, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {ay1_name, NULL, NULL, NULL}},
     {"node01827", REAL, 0, NULL, DERIVED, {0},
     {1, 1, 19, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {c2_name, c2_spec, NULL, NULL}},
     {"arc01019", REAL, 0, NULL, DERIVED, {0},
     {1, 1, 20, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {fay2_name, fay2_spec, NULL, NULL}},
     {"arc01023", REAL, 0, NULL, DERIVED, {0},
     {1, 1, 21, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {ay2_name, NULL, NULL, NULL}},
     {"node01833", REAL, 0, NULL, DERIVED, {0},
     {1, 1, 23, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {C3_name, C3_spec, NULL, NULL}},
     {"arc01029", REAL, 0, NULL, DERIVED, {0},
     {1, 1, 24, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {CCf_name, NULL, NULL, NULL}},
     {"arc01031", REAL, 0, NULL, DERIVED, {0},
     {1, 1, 25, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {fccf_name, NULL, NULL, NULL}},
     {"node01846", REAL, 0, NULL, DERIVED, {0},
     {1, 1, 26, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {Tcr_name, Tcr_spec, NULL, Tcr_comment}},
     {"node01848", REAL, 0, NULL, DERIVED, {0},
     {1, 1, 27, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {Tld_name, Tld_spec, NULL, Tld_comment}},
     {"node01850", REAL, 0, NULL, DERIVED, {0},
     {1, 1, 28, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {Trg_name, Trg_spec, NULL, Trg_comment}},
     {"node01852", REAL, 0, NULL, DERIVED, {0},
     {1, 1, 29, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {Tmin_0_name, Tmin_0_spec, NULL, NULL}},
     {"node01855", REAL, 0, NULL, DERIVED, {0},
     {1, 1, 31, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {REB_name, REB_spec, NULL, REB_comment}},
     {"arc01979", REAL, 0, NULL, DERIVED, {0},
     {1, 1, 32, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {Reb_name, NULL, NULL, NULL}},
     {"arc01983", REAL, 0, NULL, DERIVED, {0},
     {1, 1, 33, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {reba_name, reba_spec, NULL, NULL}},
     {"node01861", REAL, 0, NULL, DERIVED, {0},
     {1, 1, 34, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {CC_0_name, CC_0_spec, NULL, NULL}},
     {"node01864", REAL, 0, NULL, DERIVED, {0},
     {1, 1, 35, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {delayCC_name, delayCC_spec, NULL, NULL}},
     {"node01866", REAL, 0, NULL, DERIVED, {0},
     {1, 1, 36, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {dCC_name, NULL, NULL, NULL}},
     {"node01844", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 1, 37, 0}, 0, 0, 0, SUBMODEL, {Tuber_production_F_name, NULL, NULL, NULL}},
     {"node01868", REAL, 0, NULL, DERIVED, {0},
     {1, 1, 37, 1, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {DTYf_name, DTYf_spec, NULL, NULL}},
     {"node01870", REAL, 0, NULL, DERIVED, {0},
     {1, 1, 37, 2, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {FTYf_name, FTYf_spec, NULL, NULL}},
     {"node01845", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 1, 38, 0}, 0, 0, 0, SUBMODEL, {Total_dry_matter_prod_F_name, NULL, NULL, NULL}},
     {"node01875", REAL, 0, NULL, DERIVED, {0},
     {1, 1, 38, 1, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {RUEs_0_name, RUEs_0_spec, NULL, NULL}},
     {"node01877", REAL, 0, NULL, DERIVED, {0},
     {1, 1, 38, 3, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {TDMf_name, TDMf_spec, NULL, NULL}},
     {"arc00422", REAL, 0, NULL, DERIVED, {0},
     {1, 1, 38, 4, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {dTDM_0_name, NULL, NULL, NULL}},
     {"node00007", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 2, 0}, 0, 0, 0, SUBMODEL, {Randomize_name, NULL, NULL, NULL}},
     {"node01387", REAL, 0, NULL, DERIVED, {0},
     {1, 2, 2, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {rnd_name, rnd_spec, NULL, rnd_comment}},
     {"node01389", REAL, 0, NULL, DERIVED, {0},
     {1, 2, 3, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {rdm_name, rdm_spec, NULL, rdm_comment}},
     {"node01391", REAL, 0, NULL, DERIVED, {0},
     {1, 2, 4, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {v_name, v_spec, NULL, v_comment}},
     {"node00002", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 3, 0}, 0, 0, 0, SUBMODEL, {N_dynamics_name, NULL, NULL, NULL}},
     {"node00120", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 1, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {Nac_name, Nac_spec, NULL, Nac_comment}},
     {"arc01540", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 2, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {flow2_1_name, flow2_1_spec, NULL, NULL}},
     {"node00127", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 3, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {var19_name, var19_spec, NULL, NULL}},
     {"arc00892", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 5, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {flow205_name, flow205_spec, NULL, NULL}},
     {"node00130", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 6, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {cd108_name, cd108_spec, NULL, NULL}},
     {"node00135", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 7, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {NH4o_name, NH4o_spec, NULL, NH4o_comment}},
     {"node00137", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 8, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {NNOM_name, NNOM_spec, NULL, NNOM_comment}},
     {"arc01359", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 10, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {flow102_0_name, flow102_0_spec, NULL, NULL}},
     {"node00140", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 11, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {N_lib_acum_name, N_lib_acum_spec, NULL, N_lib_acum_comment}},
     {"node00143", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 12, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {TOTN_name, TOTN_spec, NULL, TOTN_comment}},
     {"node00147", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 13, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {NH4u_name, NH4u_spec, NULL, NH4u_comment}},
     {"node00149", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 15, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {NH4POOL_name, NH4POOL_spec, NULL, NH4POOL_comment}},
     {"arc01543", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 16, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {flow4_0_name, flow4_0_spec, NULL, NULL}},
     {"node00133", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 3, 17, 0}, 0, 0, 0, SUBMODEL, {NITRIFXNW_name, NULL, NULL, NULL}},
     {"node00263", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 17, 1, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {NO3ppm_name, NO3ppm_spec, NULL, NULL}},
     {"node00368", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 17, 2, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {SANC_name, SANC_spec, NULL, SANC_comment}},
     {"node00370", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 17, 3, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {SNH4_name, SNH4_spec, NULL, SNH4_comment}},
     {"node00372", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 17, 4, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {ELNC_name, ELNC_spec, NULL, ELNC_comment}},
     {"node00374", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 17, 5, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {min_name, NULL, NULL, NULL}},
     {"node00376", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 17, 6, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {RP2_name, RP2_spec, NULL, RP2_comment}},
     {"node00378", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 17, 7, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {phn_name, phn_spec, NULL, phn_comment}},
     {"node00380", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 17, 8, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {min1_name, min1_spec, NULL, NULL}},
     {"node00382", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 17, 9, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {A_name, A_spec, NULL, A_comment}},
     {"node00384", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 17, 10, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {bb_name, bb_spec, NULL, bb_comment}},
     {"node00386", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 17, 11, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {NH4ppm_name, NH4ppm_spec, NULL, NH4ppm_comment}},
     {"node00388", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 17, 13, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {NO3POOL_name, NO3POOL_spec, NULL, NO3POOL_comment}},
     {"arc00932", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 17, 14, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {dNO3_name, dNO3_spec, NULL, dNO3_comment}},
     {"node00392", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 17, 15, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {WFD_name, WFD_spec, NULL, NULL}},
     {"node00394", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 17, 16, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {RP22_name, RP22_spec, NULL, NULL}},
     {"node00396", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 17, 17, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {RNTRF_name, NULL, NULL, RNTRF_comment}},
     {"node00134", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 3, 18, 0}, 0, 0, 0, SUBMODEL, {MIN_HUMUS_name, NULL, NULL, NULL}},
     {"node00407", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 18, 1, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {NHUMi_name, NHUMi_spec, NULL, NHUMi_comment}},
     {"node00409", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 18, 2, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {CHUMi_name, CHUMi_spec, NULL, CHUMi_comment}},
     {"node00411", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 18, 4, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {NHUM_name, NHUM_spec, NULL, NHUM_comment}},
     {"arc00953", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 18, 5, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {flow109_name, flow109_spec, NULL, NULL}},
     {"arc00955", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 18, 6, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {flow110_name, flow110_spec, NULL, NULL}},
     {"node00517", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 18, 7, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {MF_name, MF_spec, NULL, MF_comment}},
     {"node00524", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 18, 8, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {TF_name, TF_spec, NULL, TF_comment}},
     {"node00526", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 18, 9, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {RHMIN_name, NULL, NULL, RHMIN_comment}},
     {"node00528", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 18, 11, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {RHMINacum_name, RHMINacum_spec, NULL, RHMINacum_comment}},
     {"arc01078", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 18, 12, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {flow105_name, NULL, NULL, NULL}},
     {"node00532", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 18, 13, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {DMINR_name, DMINR_spec, NULL, DMINR_comment}},
     {"node00534", INTEGER, 0, NULL, DERIVED, {0},
     {1, 3, 18, 14, 0}, 0, -268435455, 268435455, VARIABLE, {DMOD_name, DMOD_spec, NULL, DMOD_comment}},
     {"node00536", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 18, 16, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {HUM_name, NULL, NULL, HUM_comment}},
     {"node00538", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 18, 17, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {MFTF_name, NULL, NULL, NULL}},
     {"arc01091", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 18, 18, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {flow101_name, flow101_spec, NULL, NULL}},
     {"arc01094", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 18, 19, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {flow102_name, flow102_spec, NULL, flow102_comment}},
     {"node00544", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 18, 21, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {Hum_decomp__acum_name, Hum_decomp__acum_spec, NULL, Hum_decomp__acum_comment}},
     {"arc01198", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 18, 22, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {flow103_name, flow103_spec, NULL, NULL}},
     {"node00145", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 3, 19, 0}, 0, 0, 0, SUBMODEL, {MIN_FOMA_name, NULL, NULL, NULL}},
     {"node00550", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 2, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {FPOOLCE_name, FPOOLCE_spec, NULL, NULL}},
     {"node00552", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 3, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {CE_name, CE_spec, NULL, NULL}},
     {"arc01373", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 4, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {flow1_name, flow1_spec, NULL, NULL}},
     {"node00556", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 5, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {GRNOMCE_name, GRNOMCE_spec, NULL, NULL}},
     {"node00558", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 6, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {GRNOMLI_name, GRNOMLI_spec, NULL, NULL}},
     {"node00560", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 7, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {LI_name, LI_spec, NULL, NULL}},
     {"node00562", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 9, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {FPOOLLI_name, FPOOLLI_spec, NULL, NULL}},
     {"arc01383", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 10, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {flow2_name, flow2_spec, NULL, NULL}},
     {"node00566", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 12, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {NCE_acum_name, NCE_acum_spec, NULL, NCE_acum_comment}},
     {"node00568", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 14, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {NLI_acum_name, NLI_acum_spec, NULL, NLI_acum_comment}},
     {"node00571", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 15, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {CA_name, CA_spec, NULL, CA_comment}},
     {"node00573", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 16, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {G1CA_name, G1CA_spec, NULL, G1CA_comment}},
     {"node00576", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 18, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {FPOOLCA_name, FPOOLCA_spec, NULL, FPOOLCA_comment}},
     {"arc01395", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 19, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {flow6_name, NULL, NULL, NULL}},
     {"arc01388", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 20, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {flow3_name, flow3_spec, NULL, NULL}},
     {"arc01400", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 21, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {flow4_name, flow4_spec, NULL, NULL}},
     {"node00583", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 22, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {GRNOM_name, GRNOM_spec, NULL, GRNOM_comment}},
     {"node00585", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 24, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {acumGRNOM_name, acumGRNOM_spec, NULL, acumGRNOM_comment}},
     {"node00588", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 25, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {GRNOMCA_name, GRNOMCA_spec, NULL, GRNOMCA_comment}},
     {"node00590", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 27, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {NCA_acum_name, NCA_acum_spec, NULL, NCA_acum_comment}},
     {"arc01412", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 28, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {flow7_name, flow7_spec, NULL, NULL}},
     {"node00594", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 29, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {G1CE_name, G1CE_spec, NULL, NULL}},
     {"node00596", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 30, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {G1LI_name, G1LI_spec, NULL, NULL}},
     {"arc01407", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 31, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {flow107_name, flow107_spec, NULL, NULL}},
     {"node00602", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 32, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {GRCOM_name, GRCOM_spec, NULL, GRCOM_comment}},
     {"node00604", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 34, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {acumGRCOM_name, acumGRCOM_spec, NULL, acumGRCOM_comment}},
     {"arc01428", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 35, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {flow108_name, flow108_spec, NULL, NULL}},
     {"node00610", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 36, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {_C_name, _C_spec, NULL, _C_comment}},
     {"node00612", INTEGER, 0, NULL, DERIVED, {0},
     {1, 3, 19, 37, 0}, 0, -268435455, 268435455, VARIABLE, {CN_name, CN_spec, NULL, CN_comment}},
     {"node00614", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 38, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {_N_name, _N_spec, NULL, _N_comment}},
     {"node00616", INTEGER, 0, NULL, DERIVED, {0},
     {1, 3, 19, 39, 0}, 0, -268435455, 268435455, VARIABLE, {FOMi_name, FOMi_spec, NULL, FOMi_comment}},
     {"node00618", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 40, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {FONi_name, NULL, NULL, FONi_comment}},
     {"node00620", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 41, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {FOCi_name, NULL, NULL, FOCi_comment}},
     {"node00622", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 42, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {CNR_name, NULL, NULL, CNR_comment}},
     {"node00624", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 43, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {CNRF_name, CNRF_spec, NULL, CNRF_comment}},
     {"node00626", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 3, 19, 44, 0}, 0, 0, 0, SUBMODEL, {IMMOBIXNW_name, NULL, NULL, NULL}},
     {"node00628", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 44, 2, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {FOM_name, FOM_spec, NULL, FOM_comment}},
     {"arc01468", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 44, 3, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {grcom_name, grcom_spec, NULL, NULL}},
     {"node00632", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 44, 5, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {FON_name, FON_spec, NULL, FON_comment}},
     {"arc01471", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 44, 6, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {grnom_name, grnom_spec, NULL, NULL}},
     {"node00636", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 44, 7, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {RNAC_name, RNAC_spec, NULL, RNAC_comment}},
     {"node00638", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 44, 8, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {REST_name, REST_spec, NULL, NULL}},
     {"node00640", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 44, 9, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {RNACp_name, RNACp_spec, NULL, RNACp_comment}},
     {"arc01488", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 44, 10, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {rnac_name, rnac_spec, NULL, NULL}},
     {"node00652", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 19, 44, 11, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {var1_name, var1_spec, NULL, NULL}},
     {"node01931", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 3, 19, 45, 0}, 0, 0, 0, SUBMODEL, {Type_of_OM_added_name, NULL, NULL, NULL}},
     {"node01932", INTEGER, 0, NULL, DERIVED, {0},
     {1, 3, 19, 45, 1, 0}, 0, -268435455, 268435455, VARIABLE, {Type_name, Type_spec, NULL, Type_comment}},
     {"node01934", INTEGER, 0, NULL, DERIVED, {2, 0},
     {1, 3, 19, 45, 2, 0}, 0, -268435455, 268435455, VARIABLE, {OM_CN_name, OM_CN_spec, NULL, NULL}},
     {"node00146", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 3, 20, 0}, 0, 0, 0, SUBMODEL, {UREA_HYD_name, NULL, NULL, NULL}},
     {"node00859", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 20, 1, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {AK_name, AK_spec, NULL, AK_comment}},
     {"node00861", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 20, 2, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {SWF_name, NULL, NULL, SWF_comment}},
     {"node00863", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 20, 3, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {MFU_name, NULL, NULL, NULL}},
     {"node00865", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 20, 4, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {TFU_name, NULL, NULL, NULL}},
     {"node00867", INTEGER, 0, NULL, DERIVED, {0},
     {1, 3, 20, 5, 0}, 0, -268435455, 268435455, VARIABLE, {UREA_name, UREA_spec, NULL, UREA_comment}},
     {"node00869", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 20, 6, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {NUREAi_name, NUREAi_spec, NULL, NUREAi_comment}},
     {"node00871", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 20, 7, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {UHYDR_name, UHYDR_spec, NULL, UHYDR_comment}},
     {"node00873", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 20, 8, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {var13_name, var13_spec, NULL, NULL}},
     {"node00875", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 20, 9, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {TFF_name, TFF_spec, NULL, TFF_comment}},
     {"node00877", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 20, 10, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {AKU_name, AKU_spec, NULL, NULL}},
     {"node00879", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 20, 12, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {NUREA_name, NULL, NULL, NULL}},
     {"arc01525", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 20, 13, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {flow1_0_name, flow1_0_spec, NULL, NULL}},
     {"node00883", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 20, 15, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {comp2_name, comp2_spec, NULL, NULL}},
     {"arc01529", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 20, 16, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {flow2_0_name, flow2_0_spec, NULL, NULL}},
     {"node00153", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 3, 21, 0}, 0, 0, 0, SUBMODEL, {FERTILIZERS_name, NULL, NULL, NULL}},
     {"node00889", INTEGER, 0, NULL, DERIVED, {0},
     {1, 3, 21, 1, 0}, 0, -268435455, 268435455, VARIABLE, {amount_name, amount_spec, NULL, amount_comment}},
     {"node00891", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 21, 2, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {NH4_fert_name, NH4_fert_spec, NULL, NULL}},
     {"node00893", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 21, 3, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {NO3fert_name, NO3fert_spec, NULL, NULL}},
     {"node00897", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 21, 4, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {NH4am_name, NH4am_spec, NULL, NH4am_comment}},
     {"node00899", REAL, 0, NULL, DERIVED, {0},
     {1, 3, 21, 5, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {NO3am_name, NO3am_spec, NULL, NO3am_comment}},
     {"node01102", INTEGER, 0, NULL, DERIVED, {0},
     {1, 3, 21, 6, 0}, 0, -268435455, 268435455, VARIABLE, {Fert_name, Fert_spec, NULL, Fert_comment}},
     {"node00003", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 4, 0}, 0, 0, 0, SUBMODEL, {Weather_name, NULL, NULL, NULL}},
     {"node01105", REAL, 0, NULL, TABLE, {365, 0},
     {1, 4, 1, 0}, 7, -1.0E+100, 1.0E+100, VARIABLE, {SoilTemp_name, SoilTemp_spec, NULL, SoilTemp_comment}},
     {"node01106", REAL, 0, NULL, DERIVED, {0},
     {1, 4, 2, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {Tsoi_name, Tsoi_spec, NULL, NULL}},
     {"node01111", REAL, 0, NULL, TABLE, {365, 0},
     {1, 4, 3, 0}, 6, -1.0E+100, 1.0E+100, VARIABLE, {Irrigation_name, Irrigation_spec, NULL, NULL}},
     {"node01112", REAL, 0, NULL, DERIVED, {0},
     {1, 4, 4, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {Irri_name, Irri_spec, NULL, Irri_comment}},
     {"node01116", REAL, 0, NULL, TABLE, {365, 0},
     {1, 4, 5, 0}, 5, -1.0E+100, 1.0E+100, VARIABLE, {PET_name, PET_spec, NULL, PET_comment}},
     {"node01117", REAL, 0, NULL, DERIVED, {0},
     {1, 4, 6, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {ETo_name, NULL, NULL, ETo_comment}},
     {"node01120", REAL, 0, NULL, TABLE, {365, 0},
     {1, 4, 7, 0}, 4, -1.0E+100, 1.0E+100, VARIABLE, {MinTemp_name, MinTemp_spec, NULL, NULL}},
     {"node01121", REAL, 0, NULL, TABLE, {365, 0},
     {1, 4, 8, 0}, 3, -1.0E+100, 1.0E+100, VARIABLE, {MaxTemp_name, MaxTemp_spec, NULL, NULL}},
     {"node01122", REAL, 0, NULL, TABLE, {365, 0},
     {1, 4, 9, 0}, 2, -1.0E+100, 1.0E+100, VARIABLE, {Rainfall_name, Rainfall_spec, NULL, NULL}},
     {"node01123", REAL, 0, NULL, DERIVED, {0},
     {1, 4, 10, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {Tmax_name, Tmax_spec, NULL, NULL}},
     {"node01125", REAL, 0, NULL, TABLE, {365, 0},
     {1, 4, 11, 0}, 1, -1.0E+100, 1.0E+100, VARIABLE, {Radiation_name, Radiation_spec, NULL, Radiation_comment}},
     {"node01126", REAL, 0, NULL, DERIVED, {0},
     {1, 4, 12, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {Tmin_name, Tmin_spec, NULL, NULL}},
     {"node01128", REAL, 0, NULL, DERIVED, {0},
     {1, 4, 13, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {Rain_name, Rain_spec, NULL, Rain_comment}},
     {"node01130", REAL, 0, NULL, DERIVED, {0},
     {1, 4, 14, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {PAR_name, PAR_spec, NULL, PAR_comment}},
     {"node00004", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 5, 0}, 0, 0, 0, SUBMODEL, {Variety_name, NULL, NULL, NULL}},
     {"node01140", REAL, 0, NULL, DERIVED, {13, 0},
     {1, 5, 1, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {Inputs_name, Inputs_spec, NULL, Inputs_comment}},
     {"node01142", INTEGER, 0, NULL, DERIVED, {0},
     {1, 5, 2, 0}, 0, -268435455, 268435455, VARIABLE, {Var_Name_name, Var_Name_spec, NULL, Var_Name_comment}},
     {"node00005", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 6, 0}, 0, 0, 0, SUBMODEL, {Thermal_time_name, NULL, NULL, NULL}},
     {"node01144", INTEGER, 0, NULL, DERIVED, {0},
     {1, 6, 1, 0}, 0, -268435455, 268435455, VARIABLE, {Thermal_conditions_name, Thermal_conditions_spec, NULL, Thermal_conditions_comment}},
     {"node01146", REAL, 0, NULL, DERIVED, {3, 0},
     {1, 6, 2, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {TC_name, TC_spec, NULL, TC_comment}},
     {"node01150", REAL, 0, NULL, DERIVED, {0},
     {1, 6, 3, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {W_name, W_spec, NULL, W_comment}},
     {"node01152", REAL, 0, NULL, DERIVED, {0},
     {1, 6, 5, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {Tac_name, Tac_spec, NULL, Tac_comment}},
     {"node01155", REAL, 0, NULL, DERIVED, {0},
     {1, 6, 6, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {Tb_name, Tb_spec, NULL, Tb_comment}},
     {"node01157", REAL, 0, NULL, DERIVED, {0},
     {1, 6, 7, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {To_name, To_spec, NULL, To_comment}},
     {"node01359", REAL, 0, NULL, DERIVED, {0},
     {1, 6, 8, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {Th_name, Th_spec, NULL, Th_comment}},
     {"arc02556", REAL, 0, NULL, DERIVED, {0},
     {1, 6, 9, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {Te_name, NULL, NULL, Te_comment}},
     {"node01362", REAL, 0, NULL, DERIVED, {0},
     {1, 6, 10, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {Tav_name, Tav_spec, NULL, Tav_comment}},
     {"node00006", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 7, 0}, 0, 0, 0, SUBMODEL, {Time_name, NULL, NULL, NULL}},
     {"node01367", INTEGER, 0, NULL, DERIVED, {0},
     {1, 7, 1, 0}, 0, -268435455, 268435455, VARIABLE, {month_name, month_spec, NULL, month_comment}},
     {"node01369", REAL, 0, NULL, DERIVED, {0},
     {1, 7, 2, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {day_name, day_spec, NULL, day_comment}},
     {"node01373", INTEGER, 0, NULL, DERIVED, {0},
     {1, 7, 3, 0}, 0, -268435455, 268435455, VARIABLE, {EDay_name, EDay_spec, NULL, EDay_comment}},
     {"node01375", REAL, 0, NULL, DERIVED, {0},
     {1, 7, 4, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {DAE_name, DAE_spec, NULL, DAE_comment}},
     {"node01371", REAL, 0, NULL, DERIVED, {0},
     {1, 7, 5, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {PDay_name, PDay_spec, NULL, PDay_comment}},
     {"node01372", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 7, 6, 0}, 0, 0, 0, SUBMODEL, {Planting_Date_name, NULL, NULL, NULL}},
     {"node01381", INTEGER, 0, NULL, DERIVED, {0},
     {1, 7, 6, 1, 0}, 0, -268435455, 268435455, VARIABLE, {dd_name, dd_spec, NULL, dd_comment}},
     {"node01383", INTEGER, 0, NULL, DERIVED, {0},
     {1, 7, 6, 2, 0}, 0, -268435455, 268435455, VARIABLE, {mm_name, mm_spec, NULL, mm_comment}},
     {"node01385", INTEGER, 0, NULL, DERIVED, {0},
     {1, 7, 6, 3, 0}, 0, -268435455, 268435455, VARIABLE, {PDate_name, PDate_spec, NULL, PDate_comment}},
     {"node00008", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 8, 0}, 0, 0, 0, SUBMODEL, {Soil_parameters_name, NULL, NULL, NULL}},
     {"node01394", REAL, 0, NULL, DERIVED, {0},
     {1, 8, 1, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {Po_name, Po_spec, NULL, Po_comment}},
     {"node01404", REAL, 0, NULL, DERIVED, {0},
     {1, 8, 2, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {cl_name, cl_spec, NULL, cl_comment}},
     {"node01407", REAL, 0, NULL, DERIVED, {0},
     {1, 8, 3, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {FC_name, FC_spec, NULL, FC_comment}},
     {"node01409", REAL, 0, NULL, DERIVED, {0},
     {1, 8, 4, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {WP_name, WP_spec, NULL, WP_comment}},
     {"node01411", REAL, 0, NULL, DERIVED, {0},
     {1, 8, 5, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {CL_name, NULL, NULL, CL_comment}},
     {"node01413", INTEGER, 0, NULL, DERIVED, {0},
     {1, 8, 6, 0}, 0, -268435455, 268435455, VARIABLE, {OM_name, OM_spec, NULL, OM_comment}},
     {"node01415", REAL, 0, NULL, DERIVED, {0},
     {1, 8, 7, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {OMw_name, OMw_spec, NULL, OMw_comment}},
     {"node01417", REAL, 0, NULL, DERIVED, {0},
     {1, 8, 8, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {OC_name, OC_spec, NULL, OC_comment}},
     {"node01419", REAL, 0, NULL, DERIVED, {0},
     {1, 8, 9, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {ISM_name, ISM_spec, NULL, ISM_comment}},
     {"node01421", INTEGER, 0, NULL, DERIVED, {0},
     {1, 8, 10, 0}, 0, -268435455, 268435455, VARIABLE, {pH_name, pH_spec, NULL, NULL}},
     {"node01426", REAL, 0, NULL, DERIVED, {0},
     {1, 8, 11, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {fc_name, fc_spec, NULL, fc_comment}},
     {"node01424", REAL, 0, NULL, DERIVED, {0},
     {1, 8, 12, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {wp_name, wp_spec, NULL, wp_comment}},
     {"node01427", INTEGER, 0, NULL, DERIVED, {0},
     {1, 8, 13, 0}, 0, -268435455, 268435455, VARIABLE, {Soil_texture_name, Soil_texture_spec, NULL, Soil_texture_comment}},
     {"node01429", REAL, 0, NULL, DERIVED, {7, 0},
     {1, 8, 14, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {Hydric_name, Hydric_spec, NULL, Hydric_comment}},
     {"node01431", INTEGER, 0, NULL, DERIVED, {0},
     {1, 8, 15, 0}, 0, -268435455, 268435455, VARIABLE, {Area_name, Area_spec, NULL, Area_comment}},
     {"node01433", REAL, 0, NULL, DERIVED, {0},
     {1, 8, 16, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {Soil_depth_name, Soil_depth_spec, NULL, Soil_depth_comment}},
     {"node01535", REAL, 0, NULL, DERIVED, {0},
     {1, 8, 17, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {Soil_Vol_name, Soil_Vol_spec, NULL, Soil_Vol_comment}},
     {"node01537", REAL, 0, NULL, DERIVED, {0},
     {1, 8, 18, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {SWeight_name, SWeight_spec, NULL, SWeight_comment}},
     {"node01406", REAL, 0, NULL, DERIVED, {0},
     {1, 8, 19, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {BD_name, BD_spec, NULL, BD_comment}},
     {"node01400", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 8, 20, 0}, 0, 0, 0, SUBMODEL, {Soil_temp_est_name, NULL, NULL, NULL}},
     {"node01544", REAL, 0, NULL, DERIVED, {0},
     {1, 8, 20, 1, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {k_name, k_spec, NULL, NULL}},
     {"node01546", REAL, 0, NULL, DERIVED, {0},
     {1, 8, 20, 2, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {c_name, c_spec, NULL, NULL}},
     {"node01654", REAL, 0, NULL, DERIVED, {0},
     {1, 8, 20, 3, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {Stemp_name, Stemp_spec, NULL, Stemp_comment}},
     {"node01656", REAL, 0, NULL, DERIVED, {0},
     {1, 8, 20, 4, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {Tl_name, Tl_spec, NULL, Tl_comment}},
     {"node01658", INTEGER, 0, NULL, DERIVED, {0},
     {1, 8, 20, 5, 0}, 0, -268435455, 268435455, VARIABLE, {Dl_name, Dl_spec, NULL, Dl_comment}},
     {"node01660", REAL, 0, NULL, DERIVED, {0},
     {1, 8, 20, 6, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {D_name, D_spec, NULL, D_comment}},
     {"node00009", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 9, 0}, 0, 0, 0, SUBMODEL, {Soil_water_Balance_name, NULL, NULL, NULL}},
     {"node01663", REAL, 0, NULL, DERIVED, {0},
     {1, 9, 1, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {Eo_name, Eo_spec, NULL, Eo_comment}},
     {"arc00609", REAL, 0, NULL, DERIVED, {0},
     {1, 9, 2, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {s_name, s_spec, NULL, s_comment}},
     {"node01667", REAL, 0, NULL, DERIVED, {0},
     {1, 9, 4, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {CS_name, CS_spec, NULL, CS_comment}},
     {"arc00712", REAL, 0, NULL, DERIVED, {0},
     {1, 9, 5, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {S_name, NULL, NULL, S_comment}},
     {"node01671", REAL, 0, NULL, DERIVED, {0},
     {1, 9, 6, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {To_0_name, To_0_spec, NULL, To_0_comment}},
     {"node01673", REAL, 0, NULL, DERIVED, {0},
     {1, 9, 7, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {T_name, NULL, NULL, T_comment}},
     {"node00010", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 10, 0}, 0, 0, 0, SUBMODEL, {Water_limited_production_name, NULL, NULL, NULL}},
     {"node01688", REAL, 0, NULL, DERIVED, {0},
     {1, 10, 1, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {RUEs_name, NULL, NULL, NULL}},
     {"node01687", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 10, 2, 0}, 0, 0, 0, SUBMODEL, {Water_stress_name, NULL, NULL, NULL}},
     {"arc02798", REAL, 0, NULL, DERIVED, {0},
     {1, 10, 2, 2, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {Ws_name, Ws_spec, NULL, Ws_comment}},
     {"node01704", REAL, 0, NULL, DERIVED, {0},
     {1, 10, 2, 3, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {CWs_name, CWs_spec, NULL, CWs_comment}},
     {"node01690", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 10, 3, 0}, 0, 0, 0, SUBMODEL, {Total_dry_matter_production_W_name, NULL, NULL, NULL}},
     {"arc02122", REAL, 0, NULL, DERIVED, {0},
     {1, 10, 3, 2, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {dTDM_name, NULL, NULL, NULL}},
     {"node01712", REAL, 0, NULL, DERIVED, {0},
     {1, 10, 3, 3, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {TDMw_name, TDMw_spec, NULL, TDMw_comment}},
     {"node01715", REAL, 0, NULL, DERIVED, {0},
     {1, 10, 3, 4, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {RUEw_name, RUEw_spec, NULL, RUEw_comment}},
     {"node01691", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 10, 4, 0}, 0, 0, 0, SUBMODEL, {Tuber_production_W_name, NULL, NULL, NULL}},
     {"node01722", REAL, 0, NULL, DERIVED, {0},
     {1, 10, 4, 1, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {DTYw_name, NULL, NULL, DTYw_comment}},
     {"node01726", REAL, 0, NULL, DERIVED, {0},
     {1, 10, 4, 2, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {FTYw_name, NULL, NULL, FTYw_comment}},
     {"node01692", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 10, 5, 0}, 0, 0, 0, SUBMODEL, {Canopy_Cover_W_name, NULL, NULL, NULL}},
     {"node01732", REAL, 0, NULL, DERIVED, {0},
     {1, 10, 5, 1, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {CCw_name, CCw_spec, NULL, CCw_comment}},
     {"node00011", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 11, 0}, 0, 0, 0, SUBMODEL, {Potential_production_name, NULL, NULL, NULL}},
     {"node01737", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 11, 1, 0}, 0, 0, 0, SUBMODEL, {Canopy_cover_name, NULL, NULL, NULL}},
     {"node01752", REAL, 0, NULL, DERIVED, {0},
     {1, 11, 1, 1, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {flinti_name, NULL, NULL, NULL}},
     {"node01754", REAL, 0, NULL, DERIVED, {0},
     {1, 11, 1, 2, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {N_name, N_spec, NULL, N_comment}},
     {"node01757", REAL, 0, NULL, DERIVED, {0},
     {1, 11, 1, 3, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {Flint1_name, Flint1_spec, NULL, Flint1_comment}},
     {"node01761", REAL, 0, NULL, DERIVED, {0},
     {1, 11, 1, 4, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {Flint2_name, NULL, NULL, Flint2_comment}},
     {"node01764", REAL, 0, NULL, DERIVED, {0},
     {1, 11, 1, 5, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {CC_name, CC_spec, NULL, CC_comment}},
     {"node01766", REAL, 0, NULL, DERIVED, {0},
     {1, 11, 1, 6, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {d_name, d_spec, NULL, d_comment}},
     {"node01768", REAL, 0, NULL, DERIVED, {0},
     {1, 11, 1, 7, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {f0_name, f0_spec, f0_description, f0_comment}},
     {"node01770", REAL, 0, NULL, DERIVED, {0},
     {1, 11, 1, 8, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {R0_name, R0_spec, R0_description, R0_comment}},
     {"node01772", REAL, 0, NULL, DERIVED, {0},
     {1, 11, 1, 9, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {t50_name, t50_spec, NULL, t50_comment}},
     {"node01776", REAL, 0, NULL, DERIVED, {0},
     {1, 11, 1, 10, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {MCC_name, MCC_spec, MCC_description, MCC_comment}},
     {"node01738", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 11, 2, 0}, 0, 0, 0, SUBMODEL, {Total_dry_matter_production_name, NULL, NULL, NULL}},
     {"node01782", REAL, 0, NULL, DERIVED, {0},
     {1, 11, 2, 1, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {RUE_name, RUE_spec, NULL, RUE_comment}},
     {"node01785", REAL, 0, NULL, DERIVED, {0},
     {1, 11, 2, 3, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {TDM_name, TDM_spec, NULL, TDM_comment}},
     {"arc02496", REAL, 0, NULL, DERIVED, {0},
     {1, 11, 2, 4, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {dW_name, NULL, NULL, dW_comment}},
     {"node01739", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 11, 3, 0}, 0, 0, 0, SUBMODEL, {Tuber_production_name, NULL, NULL, NULL}},
     {"node01795", REAL, 0, NULL, DERIVED, {0},
     {1, 11, 3, 1, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {M_name, M_spec, NULL, M_comment}},
     {"node01797", REAL, 0, NULL, DERIVED, {0},
     {1, 11, 3, 2, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {A_0_name, A_0_spec, NULL, A_0_comment}},
     {"node01799", REAL, 0, NULL, DERIVED, {0},
     {1, 11, 3, 3, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {DTY_name, NULL, NULL, DTY_comment}},
     {"node01801", REAL, 0, NULL, DERIVED, {0},
     {1, 11, 3, 4, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {b_name, b_spec, NULL, b_comment}},
     {"node01803", REAL, 0, NULL, DERIVED, {0},
     {1, 11, 3, 5, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {Part_name, NULL, NULL, Part_comment}},
     {"node01809", REAL, 0, NULL, DERIVED, {0},
     {1, 11, 3, 6, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {DMcont_name, DMcont_spec, NULL, DMcont_comment}},
     {"node01811", REAL, 0, NULL, DERIVED, {0},
     {1, 11, 3, 7, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {FTY_name, FTY_spec, NULL, FTY_comment}},
     {"node00013", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 12, 0}, 0, 0, 0, SUBMODEL, {Nitrogen_limited_production_name, NULL, NULL, NULL}},
     {"node01886", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 12, 1, 0}, 0, 0, 0, SUBMODEL, {Canopy_cover_N_name, NULL, NULL, NULL}},
     {"node01896", REAL, 0, NULL, DERIVED, {0},
     {1, 12, 1, 1, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {CCn_name, NULL, NULL, CCn_comment}},
     {"node01887", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 12, 2, 0}, 0, 0, 0, SUBMODEL, {Total_dry_matter_production_N_name, NULL, NULL, NULL}},
     {"arc01099", REAL, 0, NULL, DERIVED, {0},
     {1, 12, 2, 2, 0}, 0, -1.0E+100, 1.0E+100, FLOW, {dTDM_1_name, NULL, NULL, NULL}},
     {"node01907", REAL, 0, NULL, DERIVED, {0},
     {1, 12, 2, 3, 0}, 0, -1.0E+100, 1.0E+100, COMPARTMENT, {TDMn_name, TDMn_spec, NULL, TDMn_comment}},
     {"node01905", REAL, 0, NULL, DERIVED, {0},
     {1, 12, 2, 4, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {RUE_0_name, RUE_0_spec, NULL, NULL}},
     {"node01888", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 12, 3, 0}, 0, 0, 0, SUBMODEL, {Tuber_production_N_name, NULL, NULL, NULL}},
     {"node01915", REAL, 0, NULL, DERIVED, {0},
     {1, 12, 3, 1, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {FTYn_name, NULL, NULL, FTYn_comment}},
     {"node01913", REAL, 0, NULL, DERIVED, {0},
     {1, 12, 3, 2, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {DTYn_name, DTYn_spec, NULL, DTYn_comment}},
     {"node01889", VALUELESS, 0, NULL, SPLIT, {0},
     {1, 12, 4, 0}, 0, 0, 0, SUBMODEL, {N_stress_name, NULL, NULL, NULL}},
     {"node00101", REAL, 0, NULL, DERIVED, {0},
     {1, 12, 4, 1, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {Npot_name, Npot_spec, NULL, Npot_comment}},
     {"node01919", REAL, 0, NULL, DERIVED, {0},
     {1, 12, 4, 2, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {Npc_name, Npc_spec, NULL, Npc_comment}},
     {"node01921", REAL, 0, NULL, DERIVED, {0},
     {1, 12, 4, 3, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {NacNpot_name, NULL, NULL, NacNpot_comment}},
     {"node01923", REAL, 0, NULL, DERIVED, {0},
     {1, 12, 4, 4, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {GC0_name, GC0_spec, NULL, NULL}},
     {"node01925", INTEGER, 0, NULL, DERIVED, {0},
     {1, 12, 4, 5, 0}, 0, -268435455, 268435455, VARIABLE, {GC250_name, GC250_spec, NULL, NULL}},
     {"node01927", REAL, 0, NULL, DERIVED, {0},
     {1, 12, 4, 6, 0}, 0, -1.0E+100, 1.0E+100, VARIABLE, {Ns_name, Ns_spec, NULL, NULL}}};
#include "support2.cpp"
