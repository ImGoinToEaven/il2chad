#pragma once
#include <cstdint>
#include "vector2f.hpp"
#include "vector3f.hpp"

namespace il2chad {
    // UnityEngine.CoreModule.dll
    namespace unity::camera {
        class camera;

        camera *get_main();
        vector3f world_to_screen_point(camera *camera, vector3f position, int32_t eye = 0);
        vector3f screen_to_world_point(camera *camera, vector3f position, int32_t eye = 0);
    }

    // UnityEngine.CoreModule.dll
    namespace unity::screen {
        int get_width();
        int get_height();
    }

    // UnityEngine.CoreModule.dll
    namespace unity::time {
        float get_time();
        float get_unscaled_time();
        float get_delta_time();
        float get_unscaled_delta_time();
        float get_fixed_delta_time();
        float get_time_scale();
        void set_time_scale(float scale);
        float get_realtime_since_startup();
        int get_frame_count();
        float get_smooth_delta_time();
        // float get_fixed_time(); Seems to be missing from my build at least. You can uncomment this if you need it.
    }

    // UnityEngine.CoreModule.dll
    namespace unity::physics {
        struct UnityEngine_Ray_o {
            vector3f origin;
            vector3f direction;
        };

        struct UnityEngine_RaycastHit_o {
            vector3f point;
            vector3f normal;
            uint32_t face_id;
            float distance;
            vector2f uv;
            int32_t collider;
        };

        bool raycast(vector3f origin, vector3f direction, UnityEngine_RaycastHit_o *hit, float maxDistance,
                     int layerMask = -1);

    }

    // UnityEngine.InputLegacyModule.dll
    namespace unity::input_legacy {
        vector3f get_mouse_position();
        float get_axis(const char *axis_name);
        float get_axis_raw(const char *axis_name);
    }
}
