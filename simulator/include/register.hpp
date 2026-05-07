#ifndef REGISTER_HPP
#define REGISTER_HPP

#include "includes.hpp"
#include "tag.hpp"

namespace Simulator {
	struct Register {
			uint32_t data;
			Tag tag;

			friend std::ostream &operator<<(std::ostream &out, const Register &r) noexcept {
				switch (r.tag) {
				case Tag::SB:
					return out << "(" << static_cast<int32_t>(static_cast<int8_t>(r.data)) << "; " << r.tag << ")";
				case Tag::SH:
					return out << "(" << static_cast<int32_t>(static_cast<int16_t>(r.data)) << "; " << r.tag << ")";
				case Tag::SW:
					return out << "(" << static_cast<int32_t>(r.data) << "; " << r.tag << ")";
				default:
					return out << "(" << r.data << "; " << r.tag << ")";
				}
			}

			void mask_by_tag();
	};

} // namespace Simulator

#endif