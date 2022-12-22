#include "DSCSPluginTemplate.h"

#include <modloader/plugin.h>
#include <windows.h>

void TestFunction() { MessageBoxA(NULL, "Custom Function Called", "Success!", MB_OK); }

class TemplatePlugin : public BasePlugin
{
public:
    using BasePlugin::BasePlugin;
    void onEnable();
    const PluginInfo getPluginInfo();
};

void TemplatePlugin::onEnable()
{
    modLoader.addSquirrelFunction("DSCSModLoader", "TestFunction", SQUIRREL_AWAY(TestFunction));
}

const PluginInfo TemplatePlugin::getPluginInfo()
{
    PluginInfo info;
    info.apiVersion = { 0, 0, 0 };
    info.version    = { 1, 0, 0 };
    info.name       = "Template Plugin";
    return info;
}

extern "C" __declspec(dllexport) TemplatePlugin* getPlugin(DSCSModLoader& modLoader)
{
    return new TemplatePlugin(modLoader);
}
