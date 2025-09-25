#include "difftest.h"
#include <dlfcn.h>
#include <cassert>
#include "../cpu/cpu_exec.h"
#include "../memory/mem.h"


char * ref_so_file;
typedef struct {
  uint32_t gpr[32];
  uint32_t pc;
} DUT_CPU_state;

DUT_CPU_state sCPU_state;


void printf_gpr_files(VsCPU * sCPU) {
    printf("runtime %d \n", runtime);
    printf("pc: 0x%0x\n", sCPU->pc_o);
    printf("inst: 0x%0x\n", sCPU->out_inst);
    
    printf("0 zero 0x%0x\n", sCPU->gpr_files[0]);
    printf("1 ra   0x%0x\n", sCPU->gpr_files[1]);
    printf("2 sp   0x%0x\n", sCPU->gpr_files[2]);
    printf("3 gp   0x%0x\n", sCPU->gpr_files[3]);
    printf("4 tp   0x%0x\n", sCPU->gpr_files[4]);
    printf("5 t0   0x%0x\n", sCPU->gpr_files[5]);
    printf("6 t1   0x%0x\n", sCPU->gpr_files[6]);
    printf("7 t2   0x%0x\n", sCPU->gpr_files[7]);
    printf("8 s0/fp 0x%0x\n", sCPU->gpr_files[8]);
    printf("9 s1   0x%0x\n", sCPU->gpr_files[9]);
    printf("10 a0  0x%0x\n", sCPU->gpr_files[10]);
    printf("11 a1  0x%0x\n", sCPU->gpr_files[11]);
    printf("12 a2  0x%0x\n", sCPU->gpr_files[12]);
    printf("13 a3  0x%0x\n", sCPU->gpr_files[13]);
    printf("14 a4  0x%0x\n", sCPU->gpr_files[14]);
    printf("15 a5  0x%0x\n", sCPU->gpr_files[15]);
}


void (*ref_difftest_memcpy)(uint32_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;

bool checkregs(DUT_CPU_state *ref_r, uint32_t pc);


void init_difftest(char *ref_so_file, long img_size, int port) {
  assert(ref_so_file != NULL);

  void* handle = dlopen(ref_so_file, RTLD_LAZY);
  assert(handle != NULL);

  ref_difftest_memcpy = (void (*)(uint32_t, void*, size_t, bool))dlsym(handle, "difftest_memcpy");
  assert(ref_difftest_memcpy != NULL);
  
  ref_difftest_regcpy = (void (*)(void*, bool))dlsym(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy != NULL);
  
  ref_difftest_exec = (void (*)(uint64_t))dlsym(handle, "difftest_exec");
  assert(ref_difftest_exec != NULL);
  
  ref_difftest_raise_intr = (void (*)(uint64_t))dlsym(handle, "difftest_raise_intr");
  assert(ref_difftest_raise_intr != NULL);
  
  void (*ref_difftest_init)(int) = (void (*)(int))dlsym(handle, "difftest_init");
  assert(ref_difftest_init != NULL);

  sCPU_state.pc = sCPU->pc_o;
  memcpy(sCPU_state.gpr, sCPU->gpr_files, sizeof(sCPU_state.gpr));


  ref_difftest_init(port);
  ref_difftest_memcpy(0x80000000, RAM, img_size, DIFFTEST_TO_REF);
  ref_difftest_regcpy(&sCPU_state, DIFFTEST_TO_REF);
}

void difftest_step(){
  DUT_CPU_state ref_r;


  ref_difftest_exec(1);
  ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);

  checkregs(&ref_r, sCPU->pc_o);
}


bool checkregs(DUT_CPU_state *ref_r, uint32_t pc) {
  printf_gpr_files(sCPU);
  if (ref_r->pc != sCPU->next_pc_o) {
    printf("current pc: 0x%0x \n", sCPU->pc_o);
    printf("ERROR ref pc: 0x%0x, sCPU pc: 0x%0x\n", ref_r->pc, sCPU->next_pc_o);
    printf_gpr_files(sCPU);
    process_end = 1;
    return false;
  }
  for(int i = 0; i < 32; i++) {
    if (ref_r->gpr[i] != sCPU->gpr_files[i]) {
      printf("\n");
      printf("ERROR occur at pc: %0x inst: 0x%0x\n", sCPU->pc_o, sCPU->out_inst);
      printf("at gpr_id: %d ref_gpr of %d, nemu gpr of %d\n", i, ref_r->gpr[i], sCPU->gpr_files[i]);
      printf("\n");
      printf_gpr_files(sCPU);
      process_end = 1;
      return false;
      
    }
  }

  return true;
}