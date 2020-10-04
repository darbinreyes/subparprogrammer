#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#include "../mylibc/mylibc.h"

/*

Commands that can be sent to a PS/2 keyboard.

*/
typedef
enum _ps2_kbd_cmd {
// If expects data, send after command.
// IMPORTANT: May have to insert a wait time before sending expected data. And before checking for the response.
// "Response: default" means "Response: 0xFA=ACK/0xFE=RESEND.""
SET_LEDS = 0xED, // Expects Data: Yes. Response: default.
ECHO = 0xEE, // Expects Data: No. Response: 0xEE=echo/0xFE=RESEND.
GET_SET_SCAN_CODE_SET = 0xF0, // Expects Data: Yes. 0x00=Get scan code set number. Response:  ACK, then the scan code set number. // See spec. for other responses.
IDENTIFY_KBD = 0xF2, // Expects Data: No. Response:  ACK, then 0, 1, or 2 bytes identifying the keyboard. // [x] Tested, received (0xAB, 0x41) = "MF2 keyboard with translation enabled in the PS/2 controller". // See spec. for other responses, e.g. 0x00="standard PS/2 mouse".
// TODO: "typematic rate and delay", "make/release", "autorepeat" related commands.
ENABLE_SCANNING = 0xF4, // Expects Data: No. Response: default.
DISABLE_SCANNING = 0xF5, // Expects Data: No. Response: default.
SET_DEFAULTS = 0xF6, // Expects Data: No. Response: default.
RESEND_CMD = 0xFE, // Expects Data: No. Response: 0xXX="Previously sent byte"/0xFE=RESEND.
RESET_AND_SELF_TEST = 0xFF // Expects Data: No. Response: 0xAA=self-test passed, 0xFC||0xFD=self-test failed, 0xFE=RESEND.
} ps2_kbd_cmd;

/*

Responses from a PS/2 keyboard.

*/
typedef
enum _ps2_kbd_rsp_t {
KEY_DETECT_OR_BUF_ERR_0 = 0x00,
SELF_TEST_PASSED = 0xAA,
ECHO_RSP = 0xEE,
ACK = 0xFA,
SELF_TEST_FAILED = 0xFC, // [] Test // else response may be 0xFD.
RESEND_RSP = 0xFE, // [] TODO: If used, limit retries to 3.
KEY_DETECT_OR_BUF_ERR_1 = 0xFF
} ps2_kbd_rsp_t;


// unsigned char send_kbd_cmd (unsigned char cmd);
unsigned char send_cmd (unsigned char cmd);

//unsigned char receive_kbd_byte (void);
unsigned char rcv_data (void);

#endif