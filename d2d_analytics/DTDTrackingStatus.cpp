#include "core/config/engine.h"

#include "DTDTrackingStatus.h"

void GDDTDTrackingStatus::_bind_methods() {
    BIND_ENUM_CONSTANT(Unknown);
	BIND_ENUM_CONSTANT(Enable);
	BIND_ENUM_CONSTANT(Disable);
}