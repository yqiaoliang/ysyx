#include "./src/sCPU.h"

int main(int argc, char * argv[]){

    sim_init();
    nvboard_init();
    // nvboard_bind_all_pins(sCPU);
    process_end = 0;


    sCPU->rst = 1;
    sCPU->clk = 0;
    step_and_dump_wave();
    step_and_dump_wave();

    
    // char *bin_path;
    // bin_path = argv[1];
    // char command[512];
    // sprintf(command, 
    //         "tail -n +2 %s | sed -e 's/.*: //' | tr -d '\\n' | sed -e 's/\\(..\\)/\\1 /g' | xxd -r -p > temp.bin", 
    //         bin_path);
    // system(command);


    int loaded = load_bin_to_ram_ex(argv[1], RAM, MEM_LEN, 1);


    sCPU->rst = 0; 
    sdb_mainloop();

    sim_exit();
    nvboard_quit();
    if (process_end == 1) {
        if (sCPU->gpr_files[10] == 0) printf("GOOD END\n");
        else printf("BAD END\n");
    }

    
    return 0;
}