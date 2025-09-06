// #include "gui.h"
#include "riscv_sim.h"
#include <am.h>
#include <klib-macros.h>
#include <assert.h>
#include <stdio.h>

#define N 32

void draw(Color_my_E4 *color){
    // color->color_buf[0] = 0xFFFFFFFF;
    // io_write(AM_GPU_FBDRAW, 0, 0, color->color_buf, 32, 32, false);
    // int w = io_read(AM_GPU_CONFIG).width / N;
    // int h = io_read(AM_GPU_CONFIG).height / N;
    // int w = 256; int h = 256;
    // int block_size = w * h;
    // assert((uint32_t)block_size <= LENGTH(color->color_buf));


    // for (int i = 0; i < N; i++){
    //     for (int j = 0; j < N; j++){
    //         io_write(AM_GPU_FBDRAW, 0, i, color->color_buf, w, h, false);
    //     }
    // }

    // io_write(AM_GPU_FBDRAW, 0, 0, NULL, 0, 0, true);



    int width = 256, height = 256;
    static uint32_t buf[256]; // 一行的像素缓存
    // printf("colorpix_len: %d \n", color->colorpix);
    for (int y = 0; y < height; y++) {
        // for (int i = 0; i < width; i++) buf[i] = *(uint32_t*)(colorpix+y*width*4+i*4);
        for (int i = 0; i < width; i++) buf[i] = color->color_buf[y * width + i];
        io_write(AM_GPU_FBDRAW, 0, y, buf, width, 1, false);
    }
    io_write(AM_GPU_FBDRAW, 0, 0, NULL, 0, 0, true);
}