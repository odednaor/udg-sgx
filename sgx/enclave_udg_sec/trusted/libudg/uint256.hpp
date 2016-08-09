//
// Created by nsamson on 7/3/16.
//

#ifndef UDG_UINT256_HPP
#define UDG_UINT256_HPP

#include <stdint.h>
#include <string>
#include <cstddef>
#include <algorithm>
#include "intconv.hpp"
#include "byte_array.hpp"
#include "ethereum/rlp.hpp"

namespace udg {

	/**
	 *	Represents a 256-bit integer.
	 */
    class uint256_t : public rlp::RLPConvertable {
        uint64_t data[4];

    public:

        const static uint256_t ZERO;
        const static uint256_t ONE;
        /**
         *
         * @param begin
         * @param end
         */
        template <typename ForwardIterator>
        uint256_t(ForwardIterator begin, ForwardIterator end);

        /**
         * Copies the input and uses it as the value of the integer.
         * @param inp becomes the value of the uint256_t
         */
        uint256_t(const uint64_t& inp);

        /**
         * Creates an empty integer (represents 0)
         */
        uint256_t();

        /**
         * Converts a hex string (e.g. "0x05a5a5a") into the equivalent integer.
         * @param str a hex string
         */
        uint256_t(const std::string& str);

        /**
         * Subtracts 1 from the current integer in-place
         * @return this integer, decremented.
         */
        uint256_t& decrement();

        /**
         * Adds 1 to the current integer in-place
         * @return this integer, incremented
         */
        uint256_t& increment();

        uint256_t add(const uint256_t& that) const;
        uint256_t sub(const uint256_t& that) const;
        uint256_t bneg() const;
        uint256_t neg() const;


        operator uint64_t() const;

        bool operator ==(const uint256_t& that) const;
        bool operator !=(const uint256_t& that) const;
        bool operator >(const uint256_t& that) const;
        bool operator <(const uint256_t& that) const;
        bool operator <=(const uint256_t& that) const;
        bool operator >=(const uint256_t& that) const;

        uint256_t& operator ++();
        uint256_t& operator --();

        uint256_t operator +(const uint256_t& that) const;
        uint256_t operator -(const uint256_t& that) const;
        uint256_t operator -() const;
        uint256_t operator ~() const;

        h256 be_serialize() const;
        h256 to_hash() const;

        bool bit_set(uint8_t index) const;

        uint256_t(const uint256_t&);
        uint256_t& operator=(uint256_t);

        void swap(uint256_t&);

    };



    template <typename ForwardIterator>
    uint256_t::uint256_t(ForwardIterator begin, ForwardIterator end) {
        std::fill(this->data, this->data + 4, 0);
        uint8_t* data_ptr = reinterpret_cast<uint8_t*>(this->data);
        std::reverse_copy(begin, end, data_ptr);
    }

}

#endif //UDG_UINT256_HPP
