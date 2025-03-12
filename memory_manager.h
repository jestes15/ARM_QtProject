#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <exception>
#include <memory>
#include <optional>
#include <stdexcept>


// Linux Header Files
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#include "io_addr_macros.h"
#include "io_rw_macros.h"


// Enumerations for Memory Regions
enum MEM_REGIONS
{
    FPGA_SLAVES_MEM_REGION,
    PERIPH_MEM_REGION,
    LW_FPGA_SLAVES_MEM_REGION
};

// Enumerations for memory_manager errors
enum MEMORY_MANAGER_ERRORS
{
    MEM_REGION_NOT_VALID
};

// Common Address Space Regions
#define FPGASLAVES 0xC0000000
#define PERIPH 0xFC000000
#define LWFPGASLAVES 0xFF200000

// Common Address Space Spans
#define FPGASLAVES_SPAN 0x3C000000
#define PERIPH_SPAN 0x04000000
#define LWFPGASLAVES_SPAN 0x00200000

class memory_manager
{
private:
    std::shared_ptr<uint8_t> fpga_slaves_base;
    std::shared_ptr<uint8_t> periph_base;
    std::shared_ptr<uint8_t> lw_fpga_slaves_base;
    int file_descriptor;

public:
    memory_manager();
    ~memory_manager();

    std::optional<uint8_t> or_register(MEM_REGIONS memory_region, uint64_t offset, uint64_t value);
    std::optional<uint8_t> and_register(MEM_REGIONS memory_region, uint64_t offset, uint64_t value);
    std::optional<uint8_t> xor_register(MEM_REGIONS memory_region, uint64_t offset, uint64_t value);
    std::optional<uint8_t> not_register(MEM_REGIONS memory_region, uint64_t offset);

    std::optional<uint8_t> or_register(MEM_REGIONS memory_region, uint32_t offset, uint32_t value);
    std::optional<uint8_t> and_register(MEM_REGIONS memory_region, uint32_t offset, uint32_t value);
    std::optional<uint8_t> xor_register(MEM_REGIONS memory_region, uint32_t offset, uint32_t value);
    std::optional<uint8_t> not_register(MEM_REGIONS memory_region, uint32_t offset);

    // Bitwise Instructions
    std::optional<uint8_t> bic_register(MEM_REGIONS memory_region, uint64_t offset, uint64_t value);
    std::optional<uint8_t> bis_register(MEM_REGIONS memory_region, uint64_t offset, uint64_t value);

    std::optional<uint8_t> bic_register(MEM_REGIONS memory_region, uint32_t offset, uint32_t value);
    std::optional<uint8_t> bis_register(MEM_REGIONS memory_region, uint32_t offset, uint32_t value);

    // std::optional<uint8_t> ror_register();
    // std::optional<uint8_t> rol_register();

    std::optional<uint8_t> write_to_register(MEM_REGIONS memory_region, uint64_t offset, uint64_t value);
    std::optional<uint64_t> read_from_register(MEM_REGIONS memory_region, uint64_t offset);
    std::optional<uint8_t> clear_register(MEM_REGIONS memory_region, uint64_t offset);

    std::optional<uint8_t> write_to_register(MEM_REGIONS memory_region, uint32_t offset, uint32_t value);
    std::optional<uint64_t> read_from_register(MEM_REGIONS memory_region, uint32_t offset);
    std::optional<uint8_t> clear_register(MEM_REGIONS memory_region, uint32_t offset);
};

#endif // MEMORY_MANAGER_H
