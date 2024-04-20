#ifndef MCC_MODULE_WATCHER_H
#define MCC_MODULE_WATCHER_H

#include "module_definition.h"
#include "../../../core/ISystem.h"

class ICModuleWatcher : public ISystem {
public:
    typedef void(*invoke_t)(__int64 pModule);

    virtual ModuleInfo& getModuleStatus(ModuleInfo::eTitle title) const = 0;
};

extern ICModuleWatcher* g_pModuleWatcher;

inline ICModuleWatcher* ModuleWatcher() {return g_pModuleWatcher;}

#endif //MCC_MODULE_WATCHER_H