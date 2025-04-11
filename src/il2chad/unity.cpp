#include <il2chad/unity.hpp>
#include <il2chad/il2cpp-api.hpp>
#include <il2chad/metadata.hpp>

#define UNITY_FN __fastcall

// Camera (UnityEngine.CoreModule.dll)
il2chad::unity::camera::camera *il2chad::unity::camera::get_main() {
    static auto get_main_ =
            reinterpret_cast<camera *(UNITY_FN *) ()>(metadata::get_method_address("UnityEngine", "Camera", "get_main"));
    return get_main_();
}

vector3f il2chad::unity::camera::world_to_screen_point(camera *camera, vector3f position, int32_t eye) {
    static auto world_to_screen_point_ =
            reinterpret_cast<vector3f(UNITY_FN *)(void *, vector3f, int32_t, const void *)>(
                    metadata::get_method_address("UnityEngine", "Camera", "WorldToScreenPoint", 1));
    return world_to_screen_point_(camera, position, eye, nullptr);
}

vector3f il2chad::unity::camera::screen_to_world_point(camera *camera, vector3f position, int32_t eye) {
    static auto screen_to_world_point_ =
            reinterpret_cast<vector3f(UNITY_FN *)(void *, vector3f, int32_t, const void *)>(
                    metadata::get_method_address("UnityEngine", "Camera", "ScreenToWorldPoint", 1));
    return screen_to_world_point_(camera, position, eye, nullptr);
}

// Screen (UnityEngine.CoreModule.dll)
int il2chad::unity::screen::get_width() {
    static auto get_width_ =
            reinterpret_cast<int(UNITY_FN *)()>(metadata::get_method_address("UnityEngine", "Screen", "get_width"));
    return get_width_();
}

int il2chad::unity::screen::get_height() {
    static auto get_height_ =
            reinterpret_cast<int(UNITY_FN *)()>(metadata::get_method_address("UnityEngine", "Screen", "get_height"));
    return get_height_();
}

// Time (UnityEngine.CoreModule.dll)
float il2chad::unity::time::get_time() {
    static auto get_time_ =
            reinterpret_cast<float(UNITY_FN *)()>(metadata::get_method_address("UnityEngine", "Time", "get_time"));
    return get_time_();
}

float il2chad::unity::time::get_unscaled_time() {
    static auto get_unscaled_time_ = reinterpret_cast<float(UNITY_FN *)()>(
            metadata::get_method_address("UnityEngine", "Time", "get_unscaledTime"));
    return get_unscaled_time_();
}

float il2chad::unity::time::get_delta_time() {
    static auto get_delta_time_ =
            reinterpret_cast<float(UNITY_FN *)()>(metadata::get_method_address("UnityEngine", "Time", "get_deltaTime"));
    return get_delta_time_();
}

float il2chad::unity::time::get_unscaled_delta_time() {
    static auto get_unscaled_delta_time_ = reinterpret_cast<float(UNITY_FN *)()>(
            metadata::get_method_address("UnityEngine", "Time", "get_unscaledDeltaTime"));
    return get_unscaled_delta_time_();
}

float il2chad::unity::time::get_fixed_delta_time() {
    static auto get_fixed_delta_time_ = reinterpret_cast<float(UNITY_FN *)()>(
            metadata::get_method_address("UnityEngine", "Time", "get_fixedDeltaTime"));
    return get_fixed_delta_time_();
}

float il2chad::unity::time::get_time_scale() {
    static auto get_time_scale_ =
            reinterpret_cast<float(UNITY_FN *)()>(metadata::get_method_address("UnityEngine", "Time", "get_timeScale"));
    return get_time_scale_();
}

void il2chad::unity::time::set_time_scale(float scale) {
    static auto set_time_scale_ = reinterpret_cast<void(UNITY_FN *)(float)>(
            metadata::get_method_address("UnityEngine", "Time", "set_timeScale"));
    set_time_scale_(scale);
}

float il2chad::unity::time::get_realtime_since_startup() {
    static auto get_realtime_since_startup_ = reinterpret_cast<float(UNITY_FN *)()>(
            metadata::get_method_address("UnityEngine", "Time", "get_realtimeSinceStartup"));
    return get_realtime_since_startup_();
}

int il2chad::unity::time::get_frame_count() {
    static auto get_frame_count_ =
            reinterpret_cast<int(UNITY_FN *)()>(metadata::get_method_address("UnityEngine", "Time", "get_frameCount"));
    return get_frame_count_();
}

float il2chad::unity::time::get_smooth_delta_time() {
    static auto get_smooth_delta_time_ = reinterpret_cast<float(UNITY_FN *)()>(
            metadata::get_method_address("UnityEngine", "Time", "get_smoothDeltaTime"));
    return get_smooth_delta_time_();
}

// Seems to be missing from my build at least. You can uncomment this if you need it.
// float il2chad::unity::time::get_fixed_time() {
//     static auto get_fixed_time_ =
//         reinterpret_cast<float(UNITY_FN*)()>(metadata::get_method_address("UnityEngine", "Time", "get_fixedTime"));
//     return get_fixed_time_();
// }

// InputLegacyModule (UnityEngine.InputLegacyModule.dll)
vector3f il2chad::unity::input_legacy::get_mouse_position() {
    static auto get_mouse_position_ = reinterpret_cast<vector3f(UNITY_FN *)()>(
            metadata::get_method_address("UnityEngine", "Input", "get_mousePosition"));
    return get_mouse_position_();
}

// todo these prly use system strings. might wanna let the user pass in a string object instead of a cstr so we don't
// have to convert every time
float il2chad::unity::input_legacy::get_axis(const char *axis_name) {
    static auto get_axis_ = reinterpret_cast<float(UNITY_FN *)(il2cpp::Il2CppString *)>(
            metadata::get_method_address("UnityEngine", "Input", "GetAxis"));
    return get_axis_(il2cpp::il2cpp_string_new(axis_name));
}

float il2chad::unity::input_legacy::get_axis_raw(const char *axis_name) {
    static auto get_axis_raw_ = reinterpret_cast<float(UNITY_FN *)(il2cpp::Il2CppString *)>(
            metadata::get_method_address("UnityEngine", "Input", "GetAxisRaw"));
    return get_axis_raw_(il2cpp::il2cpp_string_new(axis_name));
}

// Physics (UnityEngine.CoreModule.dll)
bool il2chad::unity::physics::raycast(vector3f origin, vector3f direction, UnityEngine_RaycastHit_o *hit,
                                      float maxDistance, int layerMask) {
    static auto raycast_ =
            reinterpret_cast<bool(UNITY_FN *)(vector3f, vector3f, UnityEngine_RaycastHit_o *, float, int)>(
                    metadata::get_method_address("UnityEngine", "Physics", "Raycast"));
    return raycast_(origin, direction, hit, maxDistance, layerMask);
}
