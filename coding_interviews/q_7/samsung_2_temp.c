input : 1, 00000000

output : 00000001

unsigned int set_bit(unsigned int v, unsigned int bit_num) {
    v |= (0x1 << bit_num);
    return v;
}

unsigned int toggle_bit(unsigned int v, unsigned int bit_num) {
    unsigned int t;
    //v |= (0x1 << bit_num);
    t = v & (0x1 << bit_num);
    // 0 0 | 0
    // 0 1 | 1
    // 1 0 | 1
    // 1 1 | 0
    if (t == 0) {
        v |= (0x1 << bit_num);
    } else {
        v &= ~(0x1 << bit_num);
    }

    return v;
}

/*

camera driver

log perf. info.

mobile.

raw to other format

de-noising.

send command.

timestamp.

watch for spike.

how to log.

Galaxy Devices.

*/
// clang-format.exe <file>

/*

/
/src
   / *.cpp
   / file1.cpp
   / file2.cpp
   / *.py
/include
   / *.h

*/
exclude_list = ["file1.cpp", "file2.cpp"]
for file in files:
    if (file.suffix == .cpp or file.suffix == .h) and file not in exclude_list:
        run_Command("clang-format.exe", file);

