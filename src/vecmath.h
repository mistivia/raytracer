#pragma once

#include <stdint.h>

namespace raytracer {

template<typename T>
struct vec2 {
    T x;
    T y;
};

template<typename T>
struct vec3 {
    T x;
    T y;
    T z;

    vec3<T> operator+(vec3<T> rhs);
    vec3<T> operator-(vec3<T> rhs);
    T dot(vec3<T> rhs);
    vec3<T> mul(T v);
    vec3<T> normalize();
    vec3<T> neg();
};

struct color {
    float r;
    float g;
    float b;
};

float vec3f_dot(vec3<float> lhs, vec3<float> rhs);
vec3<float> vec3f_neg(vec3<float> v);
vec3<float> vec3f_normalize(vec3<float> vec);
vec3<float> vec3f_mul(float a, vec3<float> v);

color icolor(int32_t rgb);
color pixel_avg4(color pixels[4]);


// ========== impl =============


template<typename T>
vec3<T> vec3<T>::operator+(vec3<T> rhs) {
    vec3<T> &lhs = *this;
    return (vec3<T>){
        .x = lhs.x + rhs.x,
        .y = lhs.y + rhs.y,
        .z = lhs.z + rhs.z,
    };
}

template<typename T>
vec3<T> vec3<T>::operator-(vec3<T> rhs) {
    vec3<T> &lhs = *this;
    return (vec3<T>){
        .x = lhs.x - rhs.x,
        .y = lhs.y - rhs.y,
        .z = lhs.z - rhs.z,
    };
}

} // namespace raytracer