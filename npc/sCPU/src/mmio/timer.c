#include "map.h" 
#include "../sCPU.h"

#define CONFIG_RTC_MMIO 0xa0000048

static uint32_t *rtc_port_base = NULL;

// static int boot_time = 0;

// static uint64_t get_time_internal() {
//   struct timeval now;
//   gettimeofday(&now, NULL);
//   uint64_t us = now.tv_sec * 1000000 + now.tv_usec;
//   return us;
// }

// uint64_t get_time() {
//   if (boot_time == 0) boot_time = get_time_internal();
//   uint64_t now = get_time_internal();
//   return now - boot_time;
// }

uint64_t get_time_() {return 0;}

static void rtc_io_handler(uint32_t offset, int len, bool is_write) {
  assert(offset == 0 || offset == 4);
  
  if (!is_write && offset == 4) {
    uint64_t us = get_time_();

    // rtc_port_base[0] = (uint32_t)us;
    rtc_port_base[1] = us >> 32;
  }
  else if (!is_write && offset == 0) {
    uint64_t us = get_time_();
    rtc_port_base[0] = (uint32_t)us;
  }
}


void init_timer() {
  rtc_port_base = (uint32_t *)new_space(8);
  add_mmio_map("rtc", CONFIG_RTC_MMIO, rtc_port_base, 8, rtc_io_handler);
}
