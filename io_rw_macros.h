#ifndef IO_RW_MACROS_H
#define IO_RW_MACROS_H

#ifdef __cplusplus

#define IORD_8DIRECT(base, offset)  *(reinterpret_cast<volatile uint8_t*>((base) + (offset)))
#define IORD_16DIRECT(base, offset) *(reinterpret_cast<volatile uint16_t*>((base) + (offset)))
#define IORD_32DIRECT(base, offset) *(reinterpret_cast<volatile uint32_t*>((base) + (offset)))
#define IORD_64DIRECT(base, offset) *(reinterpret_cast<volatile uint64_t*>((base) + (offset)))

#define IOWR_8DIRECT(base, offset, value)  *(reinterpret_cast<volatile uint8_t*>((base) + (offset))) = (value)
#define IOWR_16DIRECT(base, offset, value) *(reinterpret_cast<volatile uint16_t*>((base) + (offset))) = (value)
#define IOWR_32DIRECT(base, offset, value) *(reinterpret_cast<volatile uint32_t*>((base) + (offset))) = (value)
#define IOWR_64DIRECT(base, offset, value) *(reinterpret_cast<volatile uint64_t*>((base) + (offset))) = (value)

#else

#define IORD_8DIRECT(base, offset) *((volatile uint8_t *)((base) + (offset)))
#define IORD_16DIRECT(base, offset) *((volatile uint16_t *)((base) + (offset)))
#define IORD_32DIRECT(base, offset) *((volatile uint32_t *)((base) + (offset)))
#define IORD_64DIRECT(base, offset) *((volatile uint64_t *)((base) + (offset)))

#define IOWR_8DIRECT(base, offset, value) *((volatile uint8_t *)((base) + (offset))) = (value)
#define IOWR_16DIRECT(base, offset, value) *((volatile uint16_t *)((base) + (offset))) = (value)
#define IOWR_32DIRECT(base, offset, value) *((volatile uint32_t *)((base) + (offset))) = (value)
#define IOWR_64DIRECT(base, offset, value) *((volatile uint64_t *)((base) + (offset))) = (value)

#endif

#endif // IO_RW_MACROS_H
