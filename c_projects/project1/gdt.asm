; Our global descriptor table (GDT)
; this is configure a basic flat model of memory with 2 overlapping
; segments: a code segment and a data segment, after the standard null
; descriptor.

gdt_start:

gdt_null: ; the mandatory null descriptor