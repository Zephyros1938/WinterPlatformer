#ifndef PHYSICS_OBJECT_HPP
#define PHYSICS_OBJECT_HPP

#include "Transform.hpp"
#include <glm/glm.hpp>

class PhysicsObject
{
public:
    Transform transform;

    glm::vec3 linearVelocity { 0.0f };
    glm::vec3 angularVelocity { 0.0f }; // Euler angles in degrees/sec or radians/sec

    float mass = 1.0f; // force-based physics

    PhysicsObject() = default;

    void update(float deltaTime) {
        // Linear motion
        transform.position += linearVelocity * deltaTime;

        // Angular motion
        glm::vec3 angularVelRadians = glm::radians(angularVelocity * deltaTime);
        glm::quat deltaRotation = glm::quat(angularVelRadians);
        transform.rotation = glm::normalize(deltaRotation * transform.rotation);
    }

    void applyImpulse(const glm::vec3& impulse) {
        if (mass > 0.0f) {
            linearVelocity += impulse / mass;
        }
    }

    void applyForce(const glm::vec3& force, float deltaTime) {
        if (mass > 0.0f) {
            glm::vec3 acceleration = force / mass;
            linearVelocity += acceleration * deltaTime;
        }
    }
};

#endif // PHYSICS_OBJECT_HPP
