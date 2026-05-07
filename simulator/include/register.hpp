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
					return out << "(" << static_cast<char>(r.data) << "; " << r.tag << ")";
				case Tag::SH:
					return out << "(" << static_cast<short>(r.data) << "; " << r.tag << ")";
				case Tag::SW:
					return out << "(" << static_cast<int>(r.data) << "; " << r.tag << ")";
				default:
					return out << "(" << r.data << "; " << r.tag << ")";
				}
			}

			void mask_by_tag();
	};

} // namespace Simulator

#endif