#include "core/config/engine.h"
#include "DTDInt64Resources.h"

void GDDTDInt64Resources::AddValue(const String &key, const int64_t &value) {
    values[key] = value;
}

HashMap<String, int64_t> GDDTDInt64Resources::getIntegerValues() const {
    return values;
}

void GDDTDInt64Resources::_bind_methods() {
    ClassDB::bind_method(D_METHOD("AddValue", "key", "value"), &GDDTDInt64Resources::AddValue);
}