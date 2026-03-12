#ifndef REGISTER_HPP
#define REGISTER_HPP

#include "includes.hpp"
#include "tag.hpp"

namespace Simulator {
    struct Register {
			uint32_t data;
			Tag tag;

			friend std::ostream &operator<<(std::ostream &out, const Register &r) noexcept {
				return out << "(" << r.data << "; " << r.tag << ")";
			}

            void mask_by_tag();
	};

    
}

#endif