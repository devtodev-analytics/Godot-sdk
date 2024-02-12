#pragma once

#include "core/object/ref_counted.h"

class GDDTDSocialNetwork: public RefCounted
{
    GDCLASS(GDDTDSocialNetwork, RefCounted);

    private:
        inline static const String className = "GDDTDSocialNetwork";

    protected:
        static void _bind_methods(); 
        static Ref<GDDTDSocialNetwork> PredefineNetwork(String name);
        String name;

    public:
        GDDTDSocialNetwork();
        GDDTDSocialNetwork(String name);
        String GetName();

        static Ref<GDDTDSocialNetwork> Facebook();
        static Ref<GDDTDSocialNetwork> Vkontakte();
        static Ref<GDDTDSocialNetwork> Twitter();
        static Ref<GDDTDSocialNetwork> Googleplus();
        static Ref<GDDTDSocialNetwork> Whatsapp();
        static Ref<GDDTDSocialNetwork> Viber();
        static Ref<GDDTDSocialNetwork> Evernote();
        static Ref<GDDTDSocialNetwork> Googlemail();
        static Ref<GDDTDSocialNetwork> Linkedin();
        static Ref<GDDTDSocialNetwork> Pinterest();
        static Ref<GDDTDSocialNetwork> Reddit();
        static Ref<GDDTDSocialNetwork> Renren();
        static Ref<GDDTDSocialNetwork> Tumblr();
        static Ref<GDDTDSocialNetwork> Qzone();
        static Ref<GDDTDSocialNetwork> CustomNetwork(String name);
};