UEFI_Spec_2_8_A_Feb14.pdf.

# 1 - Introduction

* UEFI = interface between OS and Platform FIRMWARE.
* interface = tables + boot-time runtime service calls for OS loader + OS.
* standard enviromen for booting OS
* definition of set of interface and structure implemented by the platform firmware. + set of interface and structures avialable to the OS for booting.
* Spec. defines a way for OS and platform firmware to communicate for OS boot.
  * Spec. defines the interface, firmware devs fill in the details under the hood.
* OS's written to specific processor + chipsets are enabled to run on different system designs. New platform features may be implemented without need to change OS boot code.
* Spec. provides a path to phase out legacy devices and firmware ( a.k.a. BIOS)
* Spec. is design for platforms from mobile devices to servers.
* Provides core services + protocol interfaces.
* Enables extensibility and OEM customization.

## 1.1 UEFI Driver Model Extensions 

* boot devices + protocol interfaces.
* UEFI driver model replaces "PC-AT style option ROMs".
* UEFI drivers DON'T replace OS-specific drivers. They are intended to provides basic access to boot devices in the **pre-boot** environment.
* driver = modular piece of code. UEFI driver model supports the execution of this code. Specifically execution in pre-boot environment.




# next pg. 1 "The UEFI Driver Model is designed to ... ."

