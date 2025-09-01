#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// 计算Intel HEX校验和
uint8_t calculate_checksum(uint8_t len, uint16_t addr, uint8_t type, uint8_t *data) {
    uint8_t sum = len + (addr >> 8) + (addr & 0xFF) + type;
    for (int i = 0; i < len; i++) {
        sum += data[i];
    }
    return ~sum + 1; // 取反加1得到校验和
}

// 将32位指令拆分为4个字节（小端序）
void split_instruction(uint32_t inst, uint8_t *bytes) {
    bytes[0] = inst & 0xFF;         // 最低位字节
    bytes[1] = (inst >> 8) & 0xFF;
    bytes[2] = (inst >> 16) & 0xFF;
    bytes[3] = (inst >> 24) & 0xFF; // 最高位字节
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "用法: %s <输入txt文件> <输出hex文件>\n", argv[0]);
        return 1;
    }

    FILE *txt_file = fopen(argv[1], "r");
    FILE *hex_file = fopen(argv[2], "w");
    if (!txt_file || !hex_file) {
        perror("无法打开文件");
        return 1;
    }

    char line[256];
    uint32_t prev_addr = 0;
    uint8_t data_buf[16]; // 最多16字节数据 per line
    int data_count = 0;

    while (fgets(line, sizeof(line), txt_file)) {
        // 跳过空行和注释行
        if (line[0] == '\n' || line[0] == ';' || line[0] == '#') continue;
        
        // 解析地址和指令
        uint32_t addr, inst;
        if (sscanf(line, "%x: %x", &addr, &inst) != 2) {
            continue; // 跳过不符合格式的行
        }

        // 将32位指令拆分为4个字节（小端序）
        uint8_t bytes[4];
        split_instruction(inst, bytes);

        // 检查地址是否连续，不连续则先写入之前的数据
        if (prev_addr != 0 && addr != prev_addr + 4) {
            // 写入缓冲的数据
            if (data_count > 0) {
                uint8_t checksum = calculate_checksum(data_count, prev_addr - data_count, 0, data_buf);
                fprintf(hex_file, ":%02X%04X00", data_count, prev_addr - data_count);
                for (int i = 0; i < data_count; i++) {
                    fprintf(hex_file, "%02X", data_buf[i]);
                }
                fprintf(hex_file, "%02X\n", checksum);
                data_count = 0;
            }
        }

        // 将当前指令的4个字节加入缓冲区
        for (int i = 0; i < 4; i++) {
            data_buf[data_count++] = bytes[i];
            // 缓冲区满16字节则写入
            if (data_count == 16) {
                uint8_t checksum = calculate_checksum(16, addr - 12 + i - 3, 0, data_buf);
                fprintf(hex_file, ":%02X%04X00", 16, addr - 12 + i - 3);
                for (int j = 0; j < 16; j++) {
                    fprintf(hex_file, "%02X", data_buf[j]);
                }
                fprintf(hex_file, "%02X\n", checksum);
                data_count = 0;
            }
        }

        prev_addr = addr + 4;
    }

    // 写入剩余数据
    if (data_count > 0) {
        uint8_t checksum = calculate_checksum(data_count, prev_addr - data_count, 0, data_buf);
        fprintf(hex_file, ":%02X%04X00", data_count, prev_addr - data_count);
        for (int i = 0; i < data_count; i++) {
            fprintf(hex_file, "%02X", data_buf[i]);
        }
        fprintf(hex_file, "%02X\n", checksum);
    }

    // 写入文件结束记录
    fprintf(hex_file, ":00000001FF\n");

    fclose(txt_file);
    fclose(hex_file);
    printf("转换完成，已生成 %s\n", argv[2]);

    return 0;
}
