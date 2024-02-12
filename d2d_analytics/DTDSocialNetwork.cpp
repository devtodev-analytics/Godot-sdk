#include "private/platform/PlatformHub.h"
#include "DTDSocialNetwork.h"

GDDTDSocialNetwork::GDDTDSocialNetwork() {
    ERR_FAIL_MSG("GDDTDSocialNetwork can’t be created directly. Use static methods.");
}

GDDTDSocialNetwork::GDDTDSocialNetwork(String name) {
    this->name = name;
}

Ref<GDDTDSocialNetwork> GDDTDSocialNetwork::CustomNetwork(String name) {
    return memnew(GDDTDSocialNetwork(name));
}

Ref<GDDTDSocialNetwork> GDDTDSocialNetwork::Facebook() {
    return CustomNetwork("fb");
}

Ref<GDDTDSocialNetwork> GDDTDSocialNetwork::Vkontakte() {
    return CustomNetwork("vk");
}

Ref<GDDTDSocialNetwork> GDDTDSocialNetwork::Twitter() {
    return CustomNetwork("tw");
}

Ref<GDDTDSocialNetwork> GDDTDSocialNetwork::Googleplus() {
    return CustomNetwork("gp");
}

Ref<GDDTDSocialNetwork> GDDTDSocialNetwork::Whatsapp() {
    return CustomNetwork("wp");
}

Ref<GDDTDSocialNetwork> GDDTDSocialNetwork::Viber() {
    return CustomNetwork("vb");
}

Ref<GDDTDSocialNetwork> GDDTDSocialNetwork::Evernote() {
    return CustomNetwork("en");
}

Ref<GDDTDSocialNetwork> GDDTDSocialNetwork::Googlemail() {
    return CustomNetwork("gm");
}

Ref<GDDTDSocialNetwork> GDDTDSocialNetwork::Linkedin() {
    return CustomNetwork("in");
}
  
Ref<GDDTDSocialNetwork> GDDTDSocialNetwork::Pinterest() {
    return CustomNetwork("pi");
}

Ref<GDDTDSocialNetwork> GDDTDSocialNetwork::Reddit() {
    return CustomNetwork("rt");
}

Ref<GDDTDSocialNetwork> GDDTDSocialNetwork::Renren() {
    return CustomNetwork("rr");
}

Ref<GDDTDSocialNetwork> GDDTDSocialNetwork::Tumblr() {
    return CustomNetwork("tb");
}

Ref<GDDTDSocialNetwork> GDDTDSocialNetwork::Qzone() {
    return CustomNetwork("qq");
}


String GDDTDSocialNetwork::GetName() {
    return name;
}

void GDDTDSocialNetwork::_bind_methods() {
    ClassDB::bind_static_method(className, D_METHOD("Facebook"), &GDDTDSocialNetwork::Facebook);
    ClassDB::bind_static_method(className, D_METHOD("Vkontakte"), &GDDTDSocialNetwork::Vkontakte);
    ClassDB::bind_static_method(className, D_METHOD("Twitter"), &GDDTDSocialNetwork::Twitter);
    ClassDB::bind_static_method(className, D_METHOD("Googleplus"), &GDDTDSocialNetwork::Googleplus);
    ClassDB::bind_static_method(className, D_METHOD("Whatsapp"), &GDDTDSocialNetwork::Whatsapp);
    ClassDB::bind_static_method(className, D_METHOD("Viber"), &GDDTDSocialNetwork::Viber);
    ClassDB::bind_static_method(className, D_METHOD("Evernote"), &GDDTDSocialNetwork::Evernote);
    ClassDB::bind_static_method(className, D_METHOD("Googlemail"), &GDDTDSocialNetwork::Googlemail);
    ClassDB::bind_static_method(className, D_METHOD("Linkedin"), &GDDTDSocialNetwork::Linkedin);
    ClassDB::bind_static_method(className, D_METHOD("Pinterest"), &GDDTDSocialNetwork::Pinterest);
    ClassDB::bind_static_method(className, D_METHOD("Reddit"), &GDDTDSocialNetwork::Reddit);
    ClassDB::bind_static_method(className, D_METHOD("Renren"), &GDDTDSocialNetwork::Renren);
    ClassDB::bind_static_method(className, D_METHOD("Tumblr"), &GDDTDSocialNetwork::Tumblr);
    ClassDB::bind_static_method(className, D_METHOD("Qzone"), &GDDTDSocialNetwork::Qzone);
    ClassDB::bind_static_method(className, D_METHOD("CustomNetwork", "name"), &GDDTDSocialNetwork::CustomNetwork);
}