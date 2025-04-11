#include <Windows.h>
#include <iostream>

#include <il2chad/il2chad.hpp>

DWORD WINAPI ThreadProc(LPVOID lpParam) {
    AllocConsole();
    freopen_s(reinterpret_cast<FILE **>(stdout), "CONOUT$", "w", stdout);
    bool init = il2chad::initialize(
            {"Assembly-CSharp.dll", "UnityEngine.CoreModule.dll", "UnityEngine.InputLegacyModule.dll"});

    if (!init) {
        printf("il2chad: init failed");
        return -1;
    }

    // Let's test all functionality:
    printf("KJMONHENJEN::HHPOJBFICAH offset: %zu\n",
           il2chad::metadata::get_field_offset("", "KJMONHENJEN", "HHPOJBFICAH")); // always present
    printf("ScreenToWorldPoint address: %p\n",
           il2chad::metadata::get_method_address("UnityEngine", "Camera", "ScreenToWorldPoint", 1));
    printf("Main Camera: %p\n", il2chad::unity::camera::get_main());

    auto wts_out = world_to_screen_point(il2chad::unity::camera::get_main(), {0, 0, 0}, 0);
    printf("WorldToScreen({0, 0, 0}): %f %f %f\n", wts_out.x, wts_out.y, wts_out.z);

    auto stw_out = screen_to_world_point(il2chad::unity::camera::get_main(), {0, 0, 0}, 0);
    printf("ScreenToWorld({0, 0, 0}): %f %f %f\n", stw_out.x, stw_out.y, stw_out.z);


    // unity::time tests
    printf("Time.time: %f\n", il2chad::unity::time::get_time());
    printf("Time.unscaledTime: %f\n", il2chad::unity::time::get_unscaled_time());
    printf("Time.deltaTime: %f\n", il2chad::unity::time::get_delta_time());
    printf("Time.unscaledDeltaTime: %f\n", il2chad::unity::time::get_unscaled_delta_time());
    printf("Time.fixedDeltaTime: %f\n", il2chad::unity::time::get_fixed_delta_time());
    printf("Time.timeScale: %f\n", il2chad::unity::time::get_time_scale());
    printf("Time.realtimeSinceStartup: %f\n", il2chad::unity::time::get_realtime_since_startup());
    printf("Time.frameCount: %d\n", il2chad::unity::time::get_frame_count());
    printf("Time.smoothDeltaTime: %f\n", il2chad::unity::time::get_smooth_delta_time());
    // printf("Time.fixedTime: %f\n", il2chad::unity::time::get_fixed_time());

    // TimeScale setter test
    printf("Setting Time.timeScale to 0.5\n");
    il2chad::unity::time::set_time_scale(0.5f);
    printf("Time.timeScale after set: %f\n", il2chad::unity::time::get_time_scale());

    printf("Setting Time.timeScale back to 1.0\n");
    il2chad::unity::time::set_time_scale(1.0f);
    printf("Time.timeScale after set: %f\n", il2chad::unity::time::get_time_scale());

    printf("Screen size: %d/%d\n", il2chad::unity::screen::get_height(), il2chad::unity::screen::get_width());

    auto mouse_pos = il2chad::unity::input_legacy::get_mouse_position();
    printf("Mouse position: %f %f %f\n", mouse_pos.x, mouse_pos.y, mouse_pos.z);

    while (true) {
        auto horizontal = il2chad::unity::input_legacy::get_axis("Horizontal");
        auto vertical = il2chad::unity::input_legacy::get_axis("Vertical");

        printf("Axis Horizontal: %f\n", horizontal);
        printf("Axis Vertical: %f\n", vertical);

        Sleep(1000);
    }

    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
            DisableThreadLibraryCalls(hModule);
            CreateThread(nullptr, 0, ThreadProc, nullptr, 0, nullptr);
            break;
        case DLL_THREAD_ATTACH:
            break;
        case DLL_THREAD_DETACH:
            break;
        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}
