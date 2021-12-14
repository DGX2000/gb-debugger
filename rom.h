#ifndef ROM_H
#define ROM_H

#include <cstdint>
#include <string>
#include <vector>

namespace Gb::MemoryLocations {
constexpr std::size_t TITLE_START = 0x134;
constexpr std::size_t TITLE_END = 0x142;

constexpr std::size_t GBC_FLAG = 0x143;
constexpr std::size_t SGB_FLAG = 0x146;

constexpr std::size_t LICENSE_CODE_HIGH_NIBBLE = 0x144;
constexpr std::size_t LICENSE_CODE_LOW_NIBBLE = 0x145;

constexpr std::size_t CARTRIDGE_TYPE = 0x147;

constexpr std::size_t ROM_SIZE = 0x148;
constexpr std::size_t RAM_SIZE = 0x149;

constexpr std::size_t DESTINATION_CODE = 0x14A;
constexpr std::size_t OLD_LICENSEE_CODE = 0x14B;

constexpr std::size_t MASK_ROM_VERSION = 0x14C;
constexpr std::size_t COMPLEMENT_CHECK = 0x14D;

constexpr std::size_t CHECKSUM_START = 0x14E;
constexpr std::size_t CHECKSUM_END = 0x14F;
}


namespace Gb
{
struct Rom
{
    Rom(const std::string& filename);

    struct McConfiguration
    {
        struct RomConfiguration
        {
            unsigned int banks{0};
            unsigned int kBytes{0};
        };

        struct RamConfiguration
        {
            unsigned int banks{0};
            unsigned int kBytes{0};
        };

        enum class Type { ROM_ONLY, MBC1, MBC2, MBC3, MBC5, OTHER };

        Type type;

        RomConfiguration romConfiguration;
        RamConfiguration ramConfiguration;

        bool hasBattery{false};
        bool hasMetamapper{false};
        bool hasRam{false};
        bool hasRom{false};
        bool hasRumble{false};
        bool hasSRam{false};
        bool hasTimer{false};
    };

    McConfiguration getMcConfiguration() const;

    using AttributeValuePairs = std::vector<std::pair<std::string, std::string>>;
    AttributeValuePairs getAttributeValuePairs() const;

    std::vector<uint8_t> data;
    std::string filename;
};
}

#endif // ROM_H
