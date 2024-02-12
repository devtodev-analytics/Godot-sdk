#include "core/config/engine.h"
#include "DTDAccrualType.h"

void GDDTDAccrualType::_bind_methods() {
    BIND_ENUM_CONSTANT(Earned);
	BIND_ENUM_CONSTANT(Bought);
}