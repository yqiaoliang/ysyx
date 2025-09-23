#include <stdint.h> 
#include <cstddef>
#include <stdbool.h>


enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };

// typedef void (*difftest_memcpy_t)(uint32_t, void*, size_t, bool);
// typedef void (*difftest_regcpy_t)(void*, bool);
// typedef void (*difftest_exec_t)(uint64_t);
extern char * ref_so_file;
void init_difftest(char *ref_so_file, long img_size, int port);
void difftest_step();