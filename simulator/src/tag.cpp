#include "../include/tag.hpp"

namespace Simulator {
    std::ostream &operator<<(std::ostream &out, const Tag &tag) {
        switch (tag) {
            case Tag::UB:
                return out << "UB";
            case Tag::UH:
                return out << "UH";
            case Tag::UW:
                return out << "UW";
            case Tag::SB:
                return out << "SB";
            case Tag::SH:
                return out << "SH";
            case Tag::SW:
                return out << "SW";
            default:
                break;
        }
        return out << "";
    }

    bool is_unsigned(Tag &tag) { return (static_cast<uint8_t>(tag) & 0b100u) == 0; }

    int tag_bits(Tag &tag) {
        switch (tag) {
            case Tag::SB:
            case Tag::UB:
                return 8;
            case Tag::SH:
            case Tag::UH:
                return 16;
            case Tag::SW:
            case Tag::UW:
                return 32;
        }
    }
} // namespace Simulator