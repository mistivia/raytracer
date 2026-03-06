#include "vecmath.h"

#include <math.h>
#include <stdio.h>

namespace raytracer {

float vec3f_dot(vec3<float> lhs, vec3<float> rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

vec3<float> vec3f_neg(vec3<float> v) {
    return (vec3<float>){-v.x, -v.y, -v.z};
}

vec3<float> vec3f_normalize(vec3<float> vec) {
    float len = sqrt(vec3f_dot(vec, vec));
    return (vec3<float>){vec.x/len, vec.y/len, vec.z/len};
}

vec3<float> vec3f_mul(float a, vec3<float> v) {
    return (vec3<float>){v.x * a, v.y * a, v.z * a};
}

color icolor(int32_t rgb) {
    int r = (rgb >> 16) & 0xff;
    int g = (rgb >> 8) & 0xff;
    int b = rgb & 0xff;
    return (color){.r = r/(float)255.0, .g = g/(float)255.0, .b = b/(float)255.0};
}

void vec3f_show(const char *name, vec3<float> v) {
    printf("%s(%f,%f,%f)\n", name, v.x, v.y, v.z);
}

color pixel_avg4(color pixels[4]) {
    float r = 0,g = 0,b = 0;
    for (int i = 0; i < 4; i++) {
        r += pixels[i].r; 
        g += pixels[i].g; 
        b += pixels[i].b; 
    }
    return (color) {r/(float)4.0, g/(float)4.0, b/(float)4.0};
}

} // namespace raytracer