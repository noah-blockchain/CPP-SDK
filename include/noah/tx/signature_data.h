#ifndef NOAH_SIGNATURE_DATA_H
#define NOAH_SIGNATURE_DATA_H

#include <vector>
#include "noah/eth/RLP.h"
#include "noah/address.h"
#include "noah/tx/signature.h"
#include "noah/noah_tx_core.h"

namespace noah {

class NOAH_TX_API signature_data {
public:
    virtual dev::bytes encode() = 0;
    virtual void decode(const dev::RLP &data) = 0;
    virtual ~signature_data() = default;
};

class NOAH_TX_API signature_single_data: public virtual noah::signature_data {
public:
    void set_signature(const noah::signature &sig);
    void set_signature(noah::signature &&sig);
    void set_signature(const uint8_t *data);
    void set_signature(dev::bytes &&v, dev::bytes &&r, dev::bytes &&s);
    void set_signature(const dev::bytes &v, const dev::bytes &r, const dev::bytes &s);
    void set_signature(dev::bytes &&data);
    void set_signature(const dev::bytes &data);
    const dev::bytes & get_v() const;
    const dev::bytes & get_r() const;
    const dev::bytes & get_s() const;

    dev::bytes encode() override;
    void decode(const dev::RLP &data) override;
private:
    dev::bytes m_v, m_r, m_s;
};

class NOAH_TX_API signature_multi_data: public virtual noah::signature_data {
public:
    signature_multi_data &set_signatures(const noah::data::address &address, std::vector<noah::signature_single_data> &&signs);
    dev::bytes encode() override;
    void decode(const dev::RLP &data) override;

private:
    boah::data::address m_address;
    std::vector<noah::signature_single_data> m_signs;
};

}

#endif //NOAH_SIGNATURE_DATA_H
