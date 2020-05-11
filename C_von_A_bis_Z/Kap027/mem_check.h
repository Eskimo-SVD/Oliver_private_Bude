/* mem_check.h */
#ifndef MEM_CHECK_H
#define MEM_CHECK_H
#define DEBUG_FILE "Debug"

static int count_malloc=0;
static int count_free  =0;
FILE *f;

#define malloc(size) \
        malloc(size);\
        printf("malloc in Zeile %d der Datei %s (%d Bytes) \n"\
        ,__LINE__,__FILE__, size);\
        count_malloc++;

#define free(x)\
        free(x); \
        x=NULL;\
        printf("free in Zeile %d der Datei %s\n",__LINE__,__FILE__);\
        count_free++;

#define return EXIT_SUCCESS; \
        f=fopen(DEBUG_FILE, "w");\
        fprintf(f, "Anzahl malloc : %d\n",count_malloc);\
        fprintf(f, "Anzahl free   : %d\n",count_free);\
        fclose(f);\
        printf("Datei : %s erstellt\n", DEBUG_FILE);\
        return EXIT_SUCCESS;

#endif

