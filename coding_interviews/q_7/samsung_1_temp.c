// converts big endian to little endian

void big2little(uint32* in, uint32* out) {
    int i;
    unsigned char *tin, *tout;

    tin = (unsigned char *) in;
    tout = (unsigned char *) out;

    for (i = sizeof(uint32) - 1; i >= 0; i--) {
        tout = tin[i];
        tout++;
    }

}

// converts integers to strings

void itoa(const int input, char *output) {
    int tinput, d, sf;

    tinput = input;

    if (tinput < 0) {
        *output = '-';
        output++;
        tinput -= tinput;
    }

    int width = math.log10(tinput) + 1;
    int tw = width;

    /*

    input 72 ...

    72 % 10 == 2

    72/10 == 7

    TODO: Handle - sign

    Assuming output is large enough buffer.

    72/10
    */

    output[width+1] = '\0';


    while (tinput > 0) {

        int d = tinput % 10;

        output[width] = d + '0'; // d [0,9]

        width--;

        tinput /= 10;

    }



}


void main() {

   uint32 myVal = 0x12345678;
   uint32 output = 0x0;

   big2little(&myVal, &output);

   char myOut[11];

   itoa(-1234, myOut);

   printf("%s\n", myOut);

}


