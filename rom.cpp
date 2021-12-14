#include "rom.h"

#include <fstream>

namespace Gb
{

Rom::Rom(const std::string& filename)
    : filename(filename)
{
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    data = std::vector<uint8_t>(std::istreambuf_iterator<char>(file), {});
}

Rom::McConfiguration Rom::getMcConfiguration() const
{
    McConfiguration config;

    auto cartridgeType = data.at(Gb::MemoryLocations::CARTRIDGE_TYPE);
    auto romSize = data.at(Gb::MemoryLocations::ROM_SIZE);
    auto ramSize = data.at(Gb::MemoryLocations::RAM_SIZE);

    switch(cartridgeType) {
    case 0x00:
        config.type = McConfiguration::Type::ROM_ONLY;
        config.hasRom = true;
        break;

    case 0x01:
        config.type = McConfiguration::Type::MBC1;
        config.hasRom = true;
        break;

    case 0x02:
        config.type = McConfiguration::Type::MBC1;
        config.hasRom = true;
        config.hasRam = true;
        break;

    case 0x03:
        config.type = McConfiguration::Type::MBC1;
        config.hasRom = true;
        config.hasRam = true;
        config.hasBattery = true;
        break;

    case 0x05:
        config.type = McConfiguration::Type::MBC2;
        config.hasRom = true;
        break;

    case 0x06:
        config.type = McConfiguration::Type::MBC2;
        config.hasRom = true;
        config.hasBattery = true;
        break;

    case 0x08:
        config.type = McConfiguration::Type::ROM_ONLY;
        config.hasRom = true;
        config.hasRam = true;
        break;

    case 0x09:
        config.type = McConfiguration::Type::ROM_ONLY;
        config.hasRom = true;
        config.hasRam = true;
        config.hasBattery = true;
        break;

    case 0x0B:
        config.type = McConfiguration::Type::ROM_ONLY;
        config.hasRom = true;
        config.hasMetamapper = true;
        break;

    case 0x0C:
        config.type = McConfiguration::Type::ROM_ONLY;
        config.hasRom = true;
        config.hasMetamapper = true;
        config.hasSRam = true;
        break;

    case 0x0D:
        config.type = McConfiguration::Type::ROM_ONLY;
        config.hasRom = true;
        config.hasMetamapper = true;
        config.hasSRam = true;
        config.hasBattery = true;
        break;

    case 0x0F:
        config.type = McConfiguration::Type::MBC3;
        config.hasRom = true;
        config.hasTimer = true;
        config.hasBattery = true;
        break;

    case 0x10:
        config.type = McConfiguration::Type::MBC3;
        config.hasRom = true;
        config.hasRam = true;
        config.hasTimer = true;
        config.hasBattery = true;
        break;

    case 0x11:
        config.type = McConfiguration::Type::MBC3;
        config.hasRom = true;
        break;

    case 0x12:
        config.type = McConfiguration::Type::MBC3;
        config.hasRom = true;
        config.hasRam = true;
        break;

    case 0x13:
        config.type = McConfiguration::Type::MBC3;
        config.hasRom = true;
        config.hasRam = true;
        config.hasBattery = true;
        break;

    case 0x19:
        config.type = McConfiguration::Type::MBC5;
        config.hasRom = true;
        break;

    case 0x1A:
        config.type = McConfiguration::Type::MBC5;
        config.hasRom = true;
        config.hasRam = true;
        break;

    case 0x1B:
        config.type = McConfiguration::Type::MBC5;
        config.hasRom = true;
        config.hasRam = true;
        config.hasBattery = true;
        break;

    case 0x1C:
        config.type = McConfiguration::Type::MBC5;
        config.hasRom = true;
        config.hasRumble = true;
        break;

    case 0x1D:
        config.type = McConfiguration::Type::MBC5;
        config.hasRom = true;
        config.hasSRam = true;
        config.hasRumble = true;
        break;

    case 0x1E:
        config.type = McConfiguration::Type::MBC5;
        config.hasRom = true;
        config.hasSRam = true;
        config.hasBattery = true;
        config.hasRumble = true;
        break;

    case 0x1F:
        config.type = McConfiguration::Type::OTHER;
        break;

    case 0xFD:
        config.type = McConfiguration::Type::OTHER;
        break;

    case 0xFE:
        config.type = McConfiguration::Type::OTHER;
        break;

    case 0xFF:
        config.type = McConfiguration::Type::OTHER;
        break;

    default:
        break;
    }

    switch(romSize) {
    case 0x00:
        config.romConfiguration.banks = 2;
        config.romConfiguration.kBytes = 32;
        break;
    case 0x01:
        config.romConfiguration.banks = 4;
        config.romConfiguration.kBytes = 64;
        break;
    case 0x02:
        config.romConfiguration.banks = 8;
        config.romConfiguration.kBytes = 128;
        break;
    case 0x03:
        config.romConfiguration.banks = 16;
        config.romConfiguration.kBytes = 256;
        break;
    case 0x04:
        config.romConfiguration.banks = 32;
        config.romConfiguration.kBytes = 512;
        break;
    case 0x05:
        config.romConfiguration.banks = 64;
        config.romConfiguration.kBytes = 1024;
        break;
    case 0x06:
        config.romConfiguration.banks = 128;
        config.romConfiguration.kBytes = 2048;
        break;
    case 0x52:
        config.romConfiguration.banks = 72;
        config.romConfiguration.kBytes = 1152;
        break;
    case 0x53:
        config.romConfiguration.banks = 80;
        config.romConfiguration.kBytes = 1280;
        break;
    case 0x54:
        config.romConfiguration.banks = 96;
        config.romConfiguration.kBytes = 1536;
        break;
    default:
        break;
    }

    switch(ramSize) {
    case 0x00:
        break;
    case 0x01:
        config.ramConfiguration.banks = 1;
        config.ramConfiguration.kBytes = 2;
        break;
    case 0x02:
        config.ramConfiguration.banks = 1;
        config.ramConfiguration.kBytes = 8;
        break;
    case 0x03:
        config.ramConfiguration.banks = 4;
        config.ramConfiguration.kBytes = 32;
        break;
    case 0x04:
        config.ramConfiguration.banks = 16;
        config.ramConfiguration.kBytes = 128;
        break;
    default:
        break;
    }

    return config;
}

Rom::AttributeValuePairs Rom::getAttributeValuePairs() const
{
    auto bytesToString = [this](std::size_t start, std::size_t end)
    {
        std::string result;
        for(; start <= end; ++start)
        {
            result.push_back(static_cast<char>(data.at(start)));
        }
        return result;
    };

    AttributeValuePairs attributeValuePairs;

    // Filename
    attributeValuePairs.emplace_back(std::make_pair("Filename", filename));
    attributeValuePairs.emplace_back(std::make_pair("Game title", bytesToString(Gb::MemoryLocations::TITLE_START,
                                                                                Gb::MemoryLocations::TITLE_END)));

    // Gameboy color game
    // Super gameboy game

    // Memory controller

    // RAM Banks
    // RAM Banks
    // ROM Kilobytes
    // RAM Kilobytes

    // Battery
    // Timer
    // SRAM
    // Metamapper

    return attributeValuePairs;
}

}
