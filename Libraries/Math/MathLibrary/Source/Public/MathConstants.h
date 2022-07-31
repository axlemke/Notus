#pragma once

constexpr unsigned long k_kilobyte = 1024;
constexpr unsigned long k_64kilobytes = 64 * k_kilobyte;
constexpr unsigned long k_megabyte = 1000 * k_kilobyte;
constexpr unsigned long k_gigabyte = 1000 * k_megabyte;
constexpr unsigned long k_terrabyte = 1000 * k_gigabyte;

constexpr float k_epsilon = 0.0000001f;

constexpr float k_pi = 3.141592653f;
constexpr float k_quaterPi = 0.25f * k_pi;
constexpr float k_halfPi = 0.5f * k_pi;
constexpr float k_twoPi = 2.0f * k_pi;

constexpr float k_tau = k_twoPi;
constexpr float k_inversePi = 1.0f / k_pi;

constexpr float k_goldenRatio = 1.618f;

constexpr unsigned int k_floatSignMask = 0x80000000;
constexpr unsigned int k_floatExponentMask = 0x7f800000;
constexpr unsigned int k_floatMantissaMask = 0x007fffff;
