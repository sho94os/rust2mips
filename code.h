// Code definitions
#ifndef __code_h__
#define __code_h__

#include <stdbool.h>
#include <stdio.h>

extern void yyerror(const char* msg);


typedef
enum {
      ATRIB, LABEL, GOTO,
      PLUS, MINUS, DIVI, MULTI, MODUL,
      IFE, IFNE, IFG, IFGE, IFL, IFLE,
      PRINT, PRINTS, READ,
      EXIT
} OpKind;


typedef
struct {
    enum { STR, INT, EMPTY } kind;
    union {
	int value;
	char* name;
    } u;
} Atom;


typedef
struct {
    OpKind op;
    Atom* a1;
    Atom* a2;
    Atom* a3;
    Atom* a4;
} Instr;


typedef
struct _InstrList {
    Instr* i;
    struct _InstrList* next;
} InstrList;



Instr* mk_instr(OpKind kind, Atom* a1, Atom* a2, Atom* a3, Atom* a4);
InstrList* mk_instr_list(Instr* i, InstrList* next);
InstrList* mk_append(InstrList* l1, InstrList* l2);
void add_instr(Instr* instr, InstrList* list);
bool list_is_empty(InstrList* list);
Atom* mk_atom_empty();
Atom* mk_atom_int(int v);
Atom* mk_atom_str(char* v);
void print_3AC(InstrList* list);
void print_MIPS(InstrList* list, FILE* output);



#endif
