#include "DTDRemoteConfigChangeResult.h"

void GDDTDRemoteConfigChangeResult::_bind_methods() {
    BIND_ENUM_CONSTANT(Failure);
	BIND_ENUM_CONSTANT(Success);
}