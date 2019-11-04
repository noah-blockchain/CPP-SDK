
#ifndef NOAH_NOAH_HASH_H
#define NOAH_NOAH_HASH_H

#include <noah/bip39/utils.h>
#include "noah_tx_core.h"
#include "noah/eth/Common.h"

namespace noah {
namespace data {

class NOAH_TX_API noah_hash {
private:
    using data_t = noah::Data;
public:
public:
    noah_hash() = default;
    noah_hash(const char* hex);
    noah_hash(const std::string& hex);
    noah_hash(const std::vector<uint8_t> &data);
    noah_hash(std::vector<uint8_t> &&data);

    bool operator==(const noah::data::noah_hash& other) const noexcept ;
    bool operator==(const noah::Data& other) const noexcept ;
    bool operator!=(const noah::data::noah_hash& other) const noexcept ;
    bool operator!=(const noah::Data& other) const noexcept ;
    uint8_t operator[](size_t element) const noexcept;

    uint8_t at(size_t idx) const;

    const dev::bytes& get() const;
    dev::bytes& get();

    explicit operator const std::vector<uint8_t>&() const;
    explicit operator std::string() const;

    std::string to_string() const;
    std::string to_string_no_prefix() const;

private:
    data_t m_data;
};

}

using hash_t = noah::data::noah_hash;

}

NOAH_TX_API std::ostream& operator << (std::ostream &os, const noah::hash_t &hash);

#endif //NOAH_NOAH_HASH_H
