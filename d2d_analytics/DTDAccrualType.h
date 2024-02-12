#pragma once

#include "core/object/ref_counted.h"

class GDDTDAccrualType: public RefCounted 
{ 
    GDCLASS(GDDTDAccrualType, RefCounted);

    public:
        enum AccrualType
            {   
                Earned = 0, 
                Bought = 1
            };

    protected:        
        static void _bind_methods();
};

VARIANT_ENUM_CAST(GDDTDAccrualType::AccrualType);