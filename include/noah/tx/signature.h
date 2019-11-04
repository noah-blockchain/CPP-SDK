
#ifndef NOAH_SIGNATURE_H
#define NOAH_SIGNATURE_H

#include <noah/eth/Common.h>

namespace noah {

typedef enum {
  single = (uint8_t) 0x01,
  multi = (uint8_t) 0x02
} signature_type;

typedef struct {
  dev::bytes r, s, v;
  bool success = false;
} signature;

}

#endif //NOAH_SIGNATURE_H
