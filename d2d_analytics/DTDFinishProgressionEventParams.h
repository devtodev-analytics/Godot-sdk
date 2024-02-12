#pragma once

#include "core/object/ref_counted.h"
#include "core/string/ustring.h"
#include "DTDInt64Resources.h"

class GDDTDFinishProgressionEventParams: public RefCounted {
    GDCLASS(GDDTDFinishProgressionEventParams, RefCounted);

private:
    bool successfulCompletion = false;
    int32_t duration = 0;
	Ref<GDDTDInt64Resources> spent;
    Ref<GDDTDInt64Resources> earned;

protected:
    static void _bind_methods();

public:
    void SetSuccessfulCompletion(const bool &successfulCompletion);
    void SetDuration(const int32_t &duration);
    void SetSpentResources(const Ref<GDDTDInt64Resources> &spent);
    void SetEarnedResources(const Ref<GDDTDInt64Resources> &earned);

    bool GetSuccessfulCompletion() const;
    int32_t GetDuration() const;
    Ref<GDDTDInt64Resources> GetSpentResources() const;
    Ref<GDDTDInt64Resources> GetEarnedResources() const;
};