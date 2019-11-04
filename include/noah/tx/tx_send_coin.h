#ifndef NOAH_TX_SEND_COIN_H
#define NOAH_TX_SEND_COIN_H

#include <noah/eth/RLP.h>
#include "noah/address.h"
#include "tx_data.h"

namespace noah {

class NOAH_TX_API tx_send_coin: public virtual noah::tx_data {
public:
    explicit tx_send_coin(std::shared_ptr<noah::tx> tx);
    uint16_t type() const override;
    dev::bytes encode() override;
    tx_send_coin& set_coin(const std::string &coin);

    tx_send_coin& set_coin(std::string &&coin);
    tx_send_coin& set_coin(const char* coin);
    tx_send_coin& set_to(const noah::data::address &address);
    tx_send_coin& set_to(const std::string &address);
    tx_send_coin& set_to(const char* address);
    tx_send_coin& set_value(const dev::bigdec18 &normalized);
    tx_send_coin& set_value(const std::string &normalized);
    tx_send_coin& set_value(const dev::bigint &raw);
    std::string get_coin() const;

    noah::data::address get_to() const;
    dev::bigdec18 get_value() const;

protected:
    void decode_internal(dev::RLP rlp) override;

private:
    std::string m_coin;
    noah::data::address m_to;
    dev::bigint m_value;
};

}

#endif //NOAH_TX_SEND_COIN_H
