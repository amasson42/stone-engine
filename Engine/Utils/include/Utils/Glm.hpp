// Copyright 2024 Stone-Engine

#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <string>

namespace glm {
float &value_at(mat3 &m, int r, int c);
float &value_at(mat4 &m, int r, int c);
} // namespace glm
