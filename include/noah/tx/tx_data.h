#ifndef NOAH_TX_DATA_H
#define NOAH_TX_DATA_H

#include <memory>
#include "tx.h"
#include "noah/noah_tx_core.h"

namespace noah {

// Data for concrete transaction
class NOAH_TX_API tx_data: public std::enable_shared_from_this<noah::tx_data> {
public:
    tx_data() = default;
    explicit tx_data(std::shared_ptr<noah::tx> tx) : m_tx(std::move(tx)) { }
    virtual ~tx_data() = default;
    virtual uint16_t type() const = 0;
    virtual dev::bytes encode() = 0;

    void decode(const char* hexEncoded) {
        noah::Data given(hexEncoded);
        decode_internal(dev::RLP(given.get()));
    }
    void decode(const dev::bytes &data) {
        decode_internal(dev::RLP(data));
    }

    std::shared_ptr<noah::tx> build() {
        tx()->m_data = encode();
        tx()->m_data_raw = shared_from_this();
        tx()->m_type = type();

        return tx();
    }

protected:
    virtual void decode_internal(dev::RLP rlp) {};

    std::shared_ptr<noah::tx> tx() {
        return m_tx;
    }
private:
    std::shared_ptr<noah::tx> m_tx;
};


}

#endif //NOAH_TX_DATA_H
