
#ifndef NOAH_NOAH_ADDRESS_H
#define NOAH_NOAH_ADDRESS_H

#include <noah/bip39/utils.h>
#include <vector>
#include <utility>
#include <cstdint>
#include <string>
#include "noah.h"
#include "noah/public_key.h"
#include "noah/private_key.h"

namespace noah {

namespace data {
using address_data = noah::FixedData<20>;

class NOAH_TX_API address {
public:
    address() = default;
    address(const char *hex);
    address(const std::string &hex);
    address(const std::vector<uint8_t> &data);
    address(std::vector<uint8_t> &&data);
    address(const noah::pubkey_t &pub_key);
    address(const noah::privkey_t &priv_key);
    const std::string to_string() const;
    const std::string to_string_no_prefix() const;

    const uint8_t *data() const;
    uint8_t *data();
    const std::vector<uint8_t> &get() const;
    std::vector<uint8_t> &get();

    bool operator==(const noah::data::address& other) const noexcept ;
    bool operator==(const noah::Data& other) const noexcept ;
    bool operator!=(const noah::data::address& other) const noexcept ;
    bool operator!=(const noah::Data& other) const noexcept ;

    explicit operator std::string() const noexcept;
private:
    address_data m_data;
};


} // data

// Aliases
using address_t = noah::data::address;
} // noah

// hack
namespace std {
template <>
struct hash<noah::address_t>
{
  std::size_t operator()(const noah::address_t& k) const
  {
      // Compute individual hash values for first,
      // second and third and combine them using XOR
      // and bit shifting:

      std::size_t out = 0;
      for(const auto& item: k.get()) {
          out ^= std::hash<uint8_t>()(item);
      }

      return out;
  }
};
}

NOAH_TX_API std::ostream &operator << (std::ostream &out, const noah::address_t &address);

#endif //NOAH_NOAH_ADDRESS_H
