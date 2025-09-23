#include "../cpu/cpu_exec.h"

#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


static int is_batch_mode = 0;

static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args) {
  if (args == NULL) {
    cpu_exec(1);
    return 0;
  }
  if (strcmp(args, "batch_mode") == 0) {
    cpu_exec(-1);
    return 0;
  }
  for (int i = 0; i < atoi(args); i++) {
    cpu_exec(1);
  }
  return 0;
}

static int cmd_q(char *args){
    process_end = 1;
    return -1;
}

static int cmd_si(char *args) {
  if (args == NULL) {
    cpu_exec(1);
    printf("execute 1 step\n");
    return 0;
  }

  printf("execute %s  step\n", args);
  cpu_exec(atoi(args));
  return 0;
}

static int cmd_batch_mode(char * args) {
  cpu_exec(-1);
  return -1;
}


static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
//   { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  { "si", "Execute n times instruction and stop", cmd_si },
  { "batch_mode", "Run process with batch mode", cmd_batch_mode},
//   { "info", "Display information about the program state", cmd_info },
//   {"x", "Examine memory at a given address", cmd_x },
//   {"p", "evalutation expression that you gave", cmd_p},
//   {"w", "generate a new watchpoint", cmd_w},
//   {"alive_wp", "print all watchpoint that alive", cmd_print_alive_wp},
//   {"free_wp", "print all watchpoint that free", cmd_print_free_wp},
//   {"d", "delete watchpoint that alive", cmd_d},


};

#define NR_CMD 4


void run_batch_mode(){
  is_batch_mode = 1;
}



void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c((char *)"batch_mode");
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

