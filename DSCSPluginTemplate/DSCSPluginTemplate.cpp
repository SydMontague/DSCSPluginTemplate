#include "DSCSPluginTemplate.h"
#include <windows.h>
#include <modloader/plugin.h>

void TestFunction() {
	MessageBoxA(NULL, "Custom Function Called", "Success!", MB_OK);
}

class TemplatePlugin : public BasePlugin {
public:
	using BasePlugin::BasePlugin;
	void onEnable();
	PluginInfo getPluginInfo();

};

void TemplatePlugin::onEnable() {
	this->modLoader->addSquirrelFunction("DSCSModLoader", "TestFunction", SQUIRREL_AWAY(TestFunction));
}

PluginInfo TemplatePlugin::getPluginInfo() {
	PluginInfo info;
	info.apiVersion = { 0, 0, 0 };
	info.version = { 1, 0, 0 };
	info.name = "Template Plugin";
	return info;
}

extern "C" __declspec(dllexport) TemplatePlugin * getPlugin(DSCSModLoader * modLoader) {
	return new TemplatePlugin(modLoader);
}
