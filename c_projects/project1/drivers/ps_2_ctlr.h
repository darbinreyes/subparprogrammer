#ifndef __PS_2_CTLR_H__
#define __PS_2_CTLR_H__

// ##############################################################
// CONTROLLER STATUS REGISTER START##############################################################
// ##############################################################


/*

#defines that are useful for testing values read from P/S 2 controller status register.


Misc. Notes
===

[From the spec.](http://bochs.sourceforge.net/techspec/8042.TXT)
>System Flag - This flag is monitored by the system during the  reset
>    routing. If it  is a 0,  the reset was  caused by a  power on.   The
>    controler sets this bit to  0 at power on and  it is set to 1  after
>    succesful self  test.   This bit  can be  changed by  writing to the
>    system flag bit in the command byte ( 64h ).

*/
#define BUF_IS_EMPTY (0) // bit 0 // bit 1
#define BUF_IS_FULL (1)

#define SYS_FLAG_RESET_WAS_PWR_ON (0) // bit 2
#define SYS_FLAG_SELF_TEST_SUCCESS (1)



/*TEMP

TODO: bit 3 - command/data - verify in code
===osdev

Command/data (0 = data written to input buffer is data for PS/2 device, 1 = data
written to input buffer is data for PS/2 controller command)

===bochs8042.txt

Bit 3 : Command  /  Data  -  The   keyboard  controler's input buffer may be
    addressed as either  I/O addres 60h  or 64h. Address  60h is defined
    as the data port,  abd address 64h is  defined as the command  port.
    Writing to address 64h sets this  bits to 1; writing to address  60h
    sets this bit  to 0. The  controller uses this  bit to determine  if
    the byte  is its  input buffer  should be  interpreted as  a command
    byte or a data byte.

===osdev SMSC 8042 datasheet

Command/data
0: Data Byte
1: Command Byte

INPUT BUFFER:
The input buffer is an 8-bit write-only register at I/O address hex 60 or 64. Writing to address hex 60
sets a flag that indicates a data write; writing to address hex 64 sets a flag that indicates a command
write. Data written to I/O address hex 60 are sent to the keyboard (unless the keyboard controller is
expecting a data byte) following the controller's input buffer only if the input buffer full bit in the status
register is set to 0.

===My interpretation.

When we send a command to the PS/2 controller, this bit is set.
It means that, if the command involves data bytes to be sent after
the command itself, then those data bytes will be written to I/O port 60.
Normally, as long as we don't write to I/O port 0x64, all writes to I/O port
0x60 go to the KDB device itself.

===



*/
#define IO_PORT_0x60_W_IS_FOR_DEV (0)
#define IO_PORT_0x60_W_IS_FOR_CTRL (1)




/*TEMP

TODO: bit 4 - inhibit switch - verify in code
===osdev

Unknown (chipset specific)
May be "keyboard lock" (more likely unused on modern systems)

===bochs8042.txt

Bit 4 : Inhibit Switch - This bit is updated whenever data is placed in  the
    keyboard controler's output  buffer. It reflects  the states of  the
    keyboard-inhibit switch. A 0 indicates the keyboard is inhibited.

===osdev SMSC 8042 datasheet

Inhibit Switch
0: Keyboard is Inhibited
1: Keyboard is Not Inhibited

===My interpretation.

0=keyboard is disabled. (Don't send any scan codes please).
1=keyboard is enabled.

*/
#define PS_2_DEV_IS_DISABLED (0)
#define PS_2_DEV_IS_ENABLED (1)




/*TEMP

TODO: bit 5 - transmit timeout - 1=did timeout, 0=not
- "transmission started by the KDB controller = transmission started by the PS/2
 controller "

===osdev

Unknown (chipset specific)
May be "receive time-out" or "second PS/2 port output buffer full"


===bochs8042.txt

Bit 5 : Transmit Time-Out - A 1 indicated that a transmition started by  the
    keyboard  controller  was  not  properly  completed. If the transmit
    byte was not clocked out  within the specified timelimit, this  will
    be the only error.

===osdev SMSC 8042 datasheet

Transmit Time Out
0: No Transmit Time Out Error
1: Transmit Time Out Error

===My interpretation.

- the controller sent a byte out but it was not consumed fast
 enough
timed out
*/
#define CTLR_SEND_TIMED_OUT_NO  (0)
#define CTLR_SEND_TIMED_OUT_YES (1)

/*TEMP

TODO: bit 6 - receive timeout - 1=did timeout, 0=not
- "transmission was started by the keyboard device itself"

===osdev

Time-out error (0 = no error, 1 = time-out error)

===bochs8042.txt

Bit 6 : Receive Time-Out - A  1 indicated that a transmition was started  by
    the  keyboard  but  did  not  finish  within  the programmed receive
    time-out delay.

===osdev SMSC 8042 datasheet

Receive Time Out
0: No Receive Time Out Error
1: Receive Time Out Error


===My interpretation.

- the controller was
told that it would receive a byte soon, but it was not received within the
expected time limit.

*/
#define CTLR_RECV_TIMED_OUT_NO  (0)
#define CTLR_RECV_TIMED_OUT_YES (1)


/*TEMP

TODO: bit 7 - Parity error - 0=controller received data from the KBD device with odd parity (this is the expected parity, a properly working keyboard device always sends data with odd parity, therefore any data with even parity is necessarily an error.)
===osdev

Parity error
(0 = no error, 1 = parity error)

===bochs8042.txt

Bit 7 :  Parity Error -

A 0 indicated  the last byte  of data received from
    keyboard  hadd  odd  parity.

A  1  indicated the last byte had even
    parity. The keyboard should send data whith odd parity.

===osdev SMSC 8042 datasheet

Parity Error
0: Odd Parity (No Error)
1: Even Parity (Error)

===My interpretation.
*/

#define PARITY_ODD  (0)
#define PARITY_EVEN (1)
#define IS_PARARITY_ERR(par) ( (par) != (PARITY_ODD) )




// ##############################################################
// CONTROLLER STATUS REGISTER END##############################################################
// ##############################################################



// ##############################################################
// CONTROLLER COMMANDS START##############################################################
// ##############################################################

/*

Commands that can be sent to a PS/2 controller.


===osdev



===bochs8042.txt

===osdev SMSC 8042 datasheet



===My interpretation.


*/
// from bochs8042.txt
#define CTLR_CMD_R_CURRENT_CMD_BYTE 0x20 // read byte from I/O port 0x60
/*
Write Command Byte of Keyboard Controller (See bochs8042.txt for details)
BIT BIT DEFINITIONS (SMSC datasheet)
  7 Reserved
  6 IBM PC Compatible Mode
  5 IBM PC Mode
  4 Disable Keyboard
  3 Inhibit Override
  2 System Flag
  1 Reserved
  0 Enable Output Buffer Full Interrupt
*/
#define CTLR_CMD_W_CURRENT_CMD_BYTE 0x60 // write byte to I/O port 0x60
/*
bochs8042.txt - "Response with 0x55 = No Errors"
Self-test
BIT BIT DEFINITIONS (SMSC datasheet)
 00 No Error Detected
 01 K/B Clock Line is Stuck Low
 02 K/B Clock Line is Stuck High
 03 K/B Data Line is Stuck Low
 04 K/B Data Line is Stuck High
*/
#define CTLR_CMD_SELF_TEST 0xAA
#define CTLR_CMD_RESPONSE_SELF_TEST_NO_ERR 0x55

/*

bochs8042.txt
===

Response to interface test:
00 No error detected. // Are these byte values or bit values?
01 The 'keyboard clock' line is stuck low.
02 The 'keyboard clock' line is stuck high.
03 The 'keyboard data' line is stuck low.
04 The 'keyboard data' line is stuck high.

SMSC datasheet
===
Interface Test

*/
#define CTLR_CMD_INTERFACE_TEST 0xAB
#define CTLR_CMD_RESPONSE_INTERFACE_TEST_NO_ERR(resp) ( ( (resp) & BIT0 ) == 0 )

// ##############################################################
// TODO START##############################################################
// ##############################################################

/*

bochs8042.txt
===
Diagnostic Dump  - Sends 16  bytes of the  controller's RAM the  current
    state if the  input port, the  curent stae of  the output port,  and the
    controller's programm status word to the system.

*/
#define CTLR_CMD_DIAG_DMP 0xAC
// TODO: Response data definitions

/*

bochs8042.txt
===
ADh Disable Keyboard Feature - This commands send bit 4 of the  controller's
    commnds byte.  This disables  tje keyboard  interface by  diriving clock
    line low. Data will not be sent or received.

*/
#define CTLR_CMD_DISABLE_KBD 0xAD

/*

bochs8042.txt
===

Enable  Keyboard Interface  - This  command clear  bit 4  of the command
    byte, which release the keyboard interface.

*/
#define CTLR_CMD_ENABLE_KBD 0xAE


/*

bochs8042.txt
===
C0h Read Input Port  - This commands the  controller to read its  input port
    and place the  data in its  output buffer. This  command should be  used
    only if the output buffer is empty.

*/
// TODO: Probably won't use.
#define CTLR_CMD_R_INPUT_PORT 0xC0

#define CTLR_CMD_R_OUTPUT_PORT 0xD0

#define CTLR_CMD_W_OUTPUT_PORT 0xD1

#define CTLR_CMD_R_TEST_INPUTS 0xE0

/*


osdev "8042"
===

Pulse output line low for 6 ms.
Bits 0 to 3 are used as a mask
(0 = pulse line, 1 = don't pulse line) and correspond to 4 different output lines.
Note: Bit 0 corresponds to the "reset" line.
The other output lines don't have a standard/defined purpose.

bochs8042.txt
===
F0h - FFh
Pulse  Output port - Bits  0 through 3 of  the controller's output
      port may be  pulsed low for  approximately 6 microsecunds.  Bits 0
      through 3 of this command indicate which bits are to be pulsed.  A
      0 indicates that the bit should  be pulsed, and a 1 indicates  the
      bit should not be modified.

SMSC datasheet
===
"0xF0-0xFF Pulse Output Port"

*/
#define CTLR_CMD_PULSE_OUTPUT_PORT(pulse_bits) ( (0xF0 & ( (pulse_bits) & 0x0F )  ) )


// ##############################################################
// TODO END##############################################################
// ##############################################################

// ##############################################################
// CONTROLLER COMMANDS END ##############################################################
// ##############################################################


typedef
struct _ps2_ctrl_stat_t {
/*

PS/2 controller status register bit definitions.

*/
unsigned char obuf_is_full:1;
unsigned char ibuf_is_full:1;
unsigned char sys_fw_post_passed:1;
unsigned char ibuf_dev_or_ctlr:1;
unsigned char rsvd:2;
unsigned char time_out_err:1;
unsigned char parity_err:1;
} ps2_ctrl_stat_t;


#endif