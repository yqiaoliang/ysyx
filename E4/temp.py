import sys
import binascii

def convert_logisim_hex_to_bin(hex_file, bin_file):
    with open(hex_file, 'r') as f_hex, open(bin_file, 'wb') as f_bin:
        # 跳过第一行标题
        next(f_hex)
        
        for line in f_hex:
            # 分割地址和数据部分
            if ':' in line:
                addr_part, data_part = line.split(':', 1)
            else:
                data_part = line
                
            # 移除空格和换行符
            data_part = data_part.replace(' ', '').strip()
            
            # 将每个32位字拆分为4个字节（小端序）
            for i in range(0, len(data_part), 8):
                word = data_part[i:i+8]
                if len(word) < 8:
                    continue
                
                # 将32位字拆分为4个字节（小端序）
                byte3 = word[0:2]  # 最高字节
                byte2 = word[2:4]
                byte1 = word[4:6]
                byte0 = word[6:8]  # 最低字节
                
                # 以小端序写入文件
                f_bin.write(binascii.unhexlify(byte0))
                f_bin.write(binascii.unhexlify(byte1))
                f_bin.write(binascii.unhexlify(byte2))
                f_bin.write(binascii.unhexlify(byte3))

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python logisim_hex_to_bin.py <input.hex> <output.bin>")
        sys.exit(1)
    
    convert_logisim_hex_to_bin(sys.argv[1], sys.argv[2])
    print(f"Successfully converted {sys.argv[1]} to {sys.argv[2]}")