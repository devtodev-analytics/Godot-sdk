#pragma once

#include "core/object/ref_counted.h"

class GDDTDReferralProperty: public RefCounted
{
    GDCLASS(GDDTDReferralProperty, RefCounted);

protected:
    static void _bind_methods(); 
    HashMap<String, String> map = HashMap<String ,String>();

public:
    GDDTDReferralProperty();
    ~GDDTDReferralProperty();

    void AddSource(const String &value);
    void AddCampaign(const String &value);
    void AddContent(const String &value);
    void AddMedium(const String &value);
    void AddTerm(const String &value);

    HashMap<String ,String> getReferralData() const;
};