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
  * drivers
    * manage HW busses
    * control HW busses
    * provide platform specific services. 
* UEFI Driver Model
  * info. required by implementors of bus drivers + device drivers.
  * booting a UEFI-compliant OS.
* generic interface, can apply to buses + devices.
* UEFI Spec. decribes how to implement
  * PCI bus drivers
  * PCI device driver
  * USB bus drivers
  * USB device drivers
  * SCSI drivers.
  * UEFI drivers can be stored in PCI option ROMs + retains support for legacy option ROMs.
* UEFI spec. 
  * 1 goal = small driver executable images. 
  * To support > 1 proc. arch.'s, driver must contain 1 "driver object file" per proc. arch.
    * This space issue is address by EFI Byte Code VM.
      *  Driver can be compile into 1 EFI Byte Code executable.
      * UEFI spec. compliant FW requires EFI Byte Code interpretor.
      * EFI Byte Code executables also reduce space by compression support. Spec. defines algorithms for comp./decomp. .
      * Reduces storage used by UEFI drivers on ROMs.
    * Spec. use cases include implementing
    * UEFI-compliant platform FW
    * drivers producing standard protocol interfaces
    * OS loaders for UEFI compliant OS's.

## 1.2 Organization 
* Org. of the spec.
* Intro.
* Boot manager - loads drivers and apps.
* System Table - pass to every driver and app. - def. GUID-based partition format
* Block transition table - rules for block i/o with power fail safety
* Boot services - def. of services available in pre-OS env.
* Runtime services - def. of services available in both pre-OS and post-OS boot.
* Protocols - 
  * description of UEFI image already loaded into memory
  * construction and management of device paths
  * services that apply to bus and device 
  * i/o of text information.
  * services for loading files, def. of file system formats, removable media.
  * def. of PCI bus drivers, PCI option ROMs, PCI root bridge i/o, PCI i/o protocol.
  * SCSI, ext-SCSI-pass-thru, abstracted access to SCSI host controller.
  * iSCSI = SCSI over TCP/IP
  * USB bus and USB device driver.
  * services to support source level debugger in UEFI env.
  * services for compression/decompression, standard EFI decompression used at boot time.
  * services for adding/removing ACPI table info.
  * string services = multi-lang. string comparisons, regex protocol.
* EFI BC VM - def. of EFI BC V-CPU, EBC object file mem. layout, how to transition from native code to EBC and back.
* FW flashing services.
* Network Protocols -
  * SNP, PXE, BIS, HTTP protocols - access to network devices.
  * unformatted + async network i/o services, comm. with devices supported by MNP driver.
  * VLAN, EAP, Wi-Fi. Interfaces for VLAN configs.
  * Bluetooth services.
  * TCP, IP, PIPsec, FTP, GTLS, and config.
  * ARP, DHCP, DNS, HTTP, REST services.
  * UDP, MFTP services.

# next pg. 3 - table row = Secure Boot.

