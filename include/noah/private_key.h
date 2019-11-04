
#include <noah/bip39/utils.h>
#include <noah/bip39/HDKeyEncoder.h>
#include <secp256k1.h>
#include <secp256k1_recovery.h>
#include <secp256k1_ecdh.h>

#include "noah_tx_core.h"
#include "public_key.h"
#include "noah/tx/secp256k1_raii.h"

#ifndef NOAH_NOAH_PRIVATE_KEY_H
#define NOAH_NOAH_PRIVATE_KEY_H

namespace noah {
namespace data {

class NOAH_TX_API private_key : public noah::FixedData<32> {
public:
    static private_key from_mnemonic(const std::string &mnem, uint32_t derive_index = 0);
    static private_key from_mnemonic(const char *mnemonic, uint32_t derive_index = 0);

    private_key();
    private_key(const char *hexString);
    private_key(const uint8_t *data);
    private_key(std::vector<uint8_t> &&data);
    private_key(const std::vector<uint8_t> &data);
    private_key(const uint8_t *data, size_t len);
    noah::pubkey_t get_public_key(bool compressed = false) const;

    std::string to_string() const;

    bool operator==(const private_key& other) const noexcept;
    bool operator!=(const private_key& other) const noexcept;
    explicit operator std::string() const;
};

} // data

using privkey_t = noah::data::private_key;
} // noah

#endif //NOAH_NOAH_PRIVATE_KEY_H
