#pragma once
#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP
#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>

class Transform {
public:
    glm::vec3 position { 0.0f, 0.0f, 0.0f };
    glm::quat rotation { 1.0f, 0.0f, 0.0f, 0.0f }; // Identity quaternion
    glm::vec3 scale    { 1.0f, 1.0f, 1.0f };

    Transform() = default;

    glm::mat4 getMatrix() const {
        glm::mat4 translationMat = glm::translate(position);
        glm::mat4 rotationMat    = glm::toMat4(rotation);
        glm::mat4 scaleMat       = glm::scale(scale);
        return translationMat * rotationMat * scaleMat;
    }

    void setEulerRotation(const glm::vec3& eulerDegrees) {
        glm::vec3 radians = glm::radians(eulerDegrees);
        rotation = glm::quat(radians);
    }

    glm::vec3 getEulerRotation() const {
        return glm::degrees(glm::eulerAngles(rotation));
    }

    // Helpers
    void translate(const glm::vec3& delta) {
        position += delta;
    }

    void rotate(const glm::vec3& eulerDeltaDegrees) {
        glm::vec3 deltaRadians = glm::radians(eulerDeltaDegrees);
        rotation = glm::normalize(glm::quat(deltaRadians) * rotation);
    }
};
#endif
