/*
 * AccessRegister
 * Handle a register read or write of `size` to register at `address`
 * Use functions regWrite32 or regRead32 to implement this behavior
 *
 * @param[in] bool      bWrite
 *     boolean, true for write, false for read
 * @param[in] uint64_t  addr
 *     Base register address to read from or write to, in bytes
 * @param[in] uint32_t  size
 *     user-provided size in bits, expect 32 or 64
 * @param[inout] void     *pValue
 *     Pointer to value to be read or written
 *     Expect a u32 or u64 based on size
 *
 * @return 0 for success, -1 for errors
 */

// typedef uint8_t bool;

// Write a 32-bit value to register at address
extern void     regWrite32(uint64_t addr, uint32_t value);
// Read a 32-bit value from register at address
extern uint32_t regRead32 (uint64_t addr);

int32_t AccessRegister(bool bWrite, uint64_t addr, uint32_t size, void *pValue)
{
    // Complete this function...

  if (pValue == NULL)
    return -1; // error

  if (size != 32 && size != 64)
    return -1; // error

  if (bWrite) { //  reg write
    if (size == 32)
        regWrite32(addr, *((uint32_t *)pValue));
    else { // size  == 64
         regWrite32(addr, *((uint32_t *)pValue));
        regWrite32(addr + 4, *( ( (uint32_t *) pValue ) + 1));
    }
  } else { // reg read
    if (size == 32)
     *((uint32_t *) pValue) = regRead32(addr);
    else { // size == 64
      *((uint32_t *) pValue) = regRead32(addr);
      *( ( (uint32_t *) pValue ) + 1) = regRead32(addr + 4);
    }
  }

  return 0;
  //
}

