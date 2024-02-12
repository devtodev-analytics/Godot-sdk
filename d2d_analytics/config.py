def can_build(env, platform):
    return True

def configure(env):
    if env["platform"] == "iphone" or env["platform"] == "ios":
        env.Append(FRAMEWORKPATH=[
            '#modules/d2d_analytics/native/ios'
        ])
        env.Append(CPPPATH=['#core'])
        env.Append(LINKFLAGS=[
            '-ObjC',
            '-framework', 'AdSupport',
            '-framework', 'AppTrackingTransparency',
            '-framework', 'DTDAnalytics'
        ])
    elif env["platform"] == "osx" or env["platform"] == "macos":
        env.Append(LIBPATH=["#modules/d2d_analytics/native/macos"])
        env.Append(LIBS=["libDTDAnalytics.dylib"])
        env.Append(RPATH=["."])
