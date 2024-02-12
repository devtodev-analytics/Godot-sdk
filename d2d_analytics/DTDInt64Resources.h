#pragma once

#include "core/object/ref_counted.h"
#include "core/string/ustring.h"

class GDDTDInt64Resources: public RefCounted 
{
    GDCLASS(GDDTDInt64Resources, RefCounted);

private:
    HashMap<String, int64_t> values;
    
protected:
    static void _bind_methods();

public:
    void AddValue(const String &key, const int64_t &value);
    HashMap<String, int64_t> getIntegerValues() const;
};