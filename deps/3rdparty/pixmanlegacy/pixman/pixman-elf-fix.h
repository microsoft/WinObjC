#ifndef __ASSEMBLER__

/* The pixman-cpu.c file uses the Elf32_auxv_t data structure, but the elf.h
 * file that Google provides is missing the definition, so here it is. */
#ifndef PIXMAN_ELF_FIX_H
#define PIXMAN_ELF_FIX_H

typedef struct {
    int a_type;

    union {
        long int  a_val;
        void     *a_ptr;
        void    (*a_fcn)(void);
    } a_un;

} Elf32_auxv_t;

#endif /* PIXMAN_ELF_FIX_H */

#endif /* __ASSEMBLER__ */
