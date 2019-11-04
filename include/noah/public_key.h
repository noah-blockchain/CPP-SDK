#ifndef NOAH_NOAH_PUBLIC_KEY_H
#define NOAH_NOAH_PUBLIC_KEY_H

#include <noah/bip39/utils.h>
#include <vector>
#include "noah/eth/Common.h"
#include "noah/hash.h"
#include "noah.h"

namespace noah {
namespace data {

class NOAH_TX_API public_key {
private:
    using data_t = noah::Data;
public:
    public_key() = default;
    public_key(const char* hex);
    public_key(const std::string& hex);
    public_key(const std::vector<uint8_t> &data);
    public_key(std::vector<uint8_t> &&data);

    bool operator==(const noah::data::public_key& other) const noexcept ;
    bool operator==(const noah::Data& other) const noexcept ;
    bool operator!=(const noah::data::public_key& other) const noexcept ;
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

using pubkey_t = noah::data::public_key;
}



#endif //NOAH_NOAH_PUBLIC_KEY_H
