UEFI_Spec_2_8_A_Feb14.pdf.

# 1 - Introduction

* UEFI = interface between OS and Platform FIRMWARE.
* interface = tables + boot-time runtime service calls for OS loader + OS.
* standard environment for booting OS
* definition of set of interface and structure implemented by the platform firmware. + set of interface and structures available to the OS for booting.
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
* UEFI Spec. describes how to implement
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
      * UEFI spec. compliant FW requires EFI Byte Code interpreter.
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
* Secure boot + driver signing - describes secure boot + fw signatures for authenticated fw execution.
* HII - mechanism for user input. data + system config. API
* User ID - services to describe current platform user.
* Security Tech. - services for crypto. hashing and key management.
* Misc. Protocols - timestamps. Reset notification protocol.
* Appendices -
* Index -

## 1.3 Goals 

* Make new features easier to support. Reduce need to for OS code changes.
* UEFI = alt. boot environment to support above.
* Main properties of spec.
  * Coherent, scalable platform environment - FW describes platform features, new features easier to add.
  * Abstraction for the OS - interface to platform capabilities. OS code involves less platform specific code.
  * legacy free, device abstraction - OS loader abstraction from device specific code. 
  * option ROM abstraction - UEFI driver model.
  * sharable sys. partition - mass storage devices, between  FW devs, OEM, OS vendors, third parties.
* Support for legacy compatibility.
* Additional properties 
  * path to transition from legacy devices.
  * support for both legacy OS and EFI-compat. OS on same platform.
  * OS neutral value add easier to implement - modular feature addition.
  * Builds on existing adequate standards - e.g. ACPI.
  
## 1.4 Target Audience 

...

## 1.5 UEFI Design Overview 

* Reuse of existing interface e.g. ACPI
* System partition - sharable between vendors. - FW devices file format.
* Boot services - interface to system+devices. handles + protocol.
* Runtime services - interface to resources needed by the OS.

* Fig. 1. 
  * Note OS loader lives on the EFI sys. partition.
  * reuse of SMBIOS, like ACPI

* Many ways to boot, e.g. remote boot via network.
  
## 1.6 UEFI Driver Model 

* Goals of the model.
* Implementation of bus and device drivers. - protocol services  and boot services.
* Faster boot through selective device enumeration.

* // remark - Clearly the first work to be done by platform FW for the purpose of booting must be initialization of the CPU and main memory, for, these the minimum resources resources required by general program execution - CPU time and main memory. Hence in very early init. the use of "cache as RAM".

### 1.6.2 Legacy Option ROM Issues 

...

## 1.7 Migration Requirements 

...

### 1.7.1 Legacy Operating System Support 
* // remark - One of the most important tests of system FW is that it boots a particular OS, e.g. windows server.
*// remark - Wasn't MS one of the main contributors to the redfish spec.?

### 1.7.2 Supporting the UEFI Specification on a Legacy Platform 

* This spec. can be implemented on legacy platforms.

## 1.8 Conventions Used in this Document

...

## 2 - Overview 

* Extension mechanism - UEFI drivers+applications
* Fig. 2 Booting sequence
  * Platform init. -> Driver and App. loading -> Boot from list of OS loaders -> Handoff to OS loader.
* UEFI combines all FW menus into one.


## 2.1 Boot Manager

* UEFI defined NVRAM variables point to files to be loaded. // Boot order variables.

### 2.1.1 UEFI Images 

* UEFI images = executable files.
* UEFI apps are unloaded from memory upon return from entry point. UEFI drivers are unloaded if an error occurs.
* UEFI_BOOT_SERVICES.LoadImage()

### 2.1.2 UEFI Applications 

* return from entry point equivalent to UEFI_BOOT_SERVICES.Exit()
* Image handles.
* Load Options.

### 2.1.3 UEFI OS Loaders

* EFI_BOOT_SERVICES.ExitBootServices() // gBS, gST

### 2.1.4 UEFI Drivers 

## 2.2 Firmware Core 

### 2.2.1 UEFI Services 

### 2.2.2 Runtime Services  
* Get/SetVariable()
* ResetSystem()

## 2.3 Calling Conventions 

* EFIAPI
* Datatypes - BOOLEAN, UINTN(N=native width).

## 2.4 Protocols 

* Devices handles support protocols.
* EFI_BOOT_SERVICE.HandleProtocol()/OpenProtocol()
* Protocol GUID
* Protocol Interface Structure.
* EFI_BOOT_SERVICES.InstallProtocolInterface() - protocol registration.

## 2.5 UEFI Driver Model 




# next pg. 14 

