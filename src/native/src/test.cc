#include <test.h>
#include <iostream>
#include <Windows.h>

void Test(const Napi::CallbackInfo &info)
{
    std::cout << "Native addon test" << std::endl;
}

Napi::Object InitModule(Napi::Env env, Napi::Object exports)
{
#if defined(WIN32)
    // a fix for the console not being bound to the process
    AttachConsole(ATTACH_PARENT_PROCESS);
    FILE *newEndpoint; // just a placeholder to reopen all std* streams
    freopen_s(&newEndpoint, "CON", "w", stdout);
    freopen_s(&newEndpoint, "CON", "w", stderr);
    freopen_s(&newEndpoint, "CON", "r", stdin);
#endif

    exports.Set(Napi::String::New(env, "test"),
                Napi::Function::New(env, Test));

    return exports;
}

NODE_API_MODULE(netsim, InitModule)
