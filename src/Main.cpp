#include "RE/Starfield.h"

SFSEPluginLoad(const SFSE::LoadInterface* sfse)
{
    SFSE::Init(sfse);

    // Once all plugins and mods are loaded, then the ~ console is ready and can
    // be printed to
    SFSE::GetMessagingInterface()->RegisterListener([](SFSE::MessagingInterface::Message* message) {
        if (message->type == SFSE::MessagingInterface::kPostLoad)
            RE::RTTI::ConsoleLog::GetSingleton()->Print("Hello, world!");
    });
    
    return true;
}
