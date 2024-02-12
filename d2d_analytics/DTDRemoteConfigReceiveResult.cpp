#include "DTDRemoteConfigReceiveResult.h"

void GDDTDRemoteConfigReceiveResult::_bind_methods() {
    BIND_ENUM_CONSTANT(Failure);
	BIND_ENUM_CONSTANT(Success);
    BIND_ENUM_CONSTANT(Empty);
}