#include "ImplicitShape.h"
#include <iostream>
#include <algorithm>
#include "shapes/Cube.h"

ImplicitShape::ImplicitShape()
{
}

ImplicitShape::~ImplicitShape()
{
}

float ImplicitShape::cube(glm::vec3 eye, glm::vec3 d) {

    std::vector<float> x = {eye.x, d.x, eye.y, d.y, eye.z, d.z};
    std::vector<float> y = {eye.y, d.y, eye.z, d.z, eye.x, d.x};
    std::vector<float> z = {eye.z, d.z, eye.x, d.x, eye.y, d.y};
    std::vector<float> tVals = {cubeHelper(x), cubeHelper(y), cubeHelper(z)};
    std::vector<float> valid;
    for (int i = 0; i < 3; i++) {
        if (tVals[i] == -1.f) {
            continue;
        } else {
            if (fabsf(eye.x + tVals[i]*d.x) < 0.5f + m_epsilon &&
                    fabsf(eye.y + tVals[i]*d.y) < 0.5f + m_epsilon && fabsf(eye.z + tVals[i]*d.z) < 0.5f + m_epsilon)
                valid.push_back(tVals[i]);
        }
    }

    return valid.size() > 0 ? *std::min_element(valid.begin(), valid.end()) : -1.f;;
}

// gets min t for possible intersection at two parallel planes (eg. x = 0.5 or x = -0.5)
float ImplicitShape::cubeHelper(std::vector<float> face) {

    float t1 = (0.5f - face[0]) / face[1];
    float t2 = (-0.5f - face[0]) / face[1];
    std::vector<float> valid;

    // check that the other points are between -0.5 and 0.5
    float acceptedRange = 0.5f + m_epsilon;
    if ((fabsf(face[2] + t1*face[3]) <= acceptedRange) && (fabsf(face[4] + t1*face[5]) <= acceptedRange)) {
        if (t1 > 0) { valid.push_back(t1); } // add t1 if it is valid
    } if ((fabsf(face[2] + t2*face[3]) <= acceptedRange) && (fabsf(face[4] + t2*face[5]) <= acceptedRange)) {
        if (t2 > 0) { valid.push_back(t2); } // add t2 if it is valid
    }

    return valid.size() > 0 ? *std::min_element(valid.begin(), valid.end()) : -1.f;
}

float ImplicitShape::cone(glm::vec3 eye, glm::vec3 d) {

    float t1 = -1.f; // body1
    float t2 = -1.f; // body2
    float t3 = -1.f; // base
    std::vector<float> valid;

    // cone body
    float a = pow(d.x, 2) + pow(d.z, 2) - (0.25f * pow(d.y, 2));
    float b = (2.f * eye.x * d.x) + (2.f * eye.z * d.z) - (0.5f * eye.y * d.y) + (0.25f * d.y);
    float c = pow(eye.x, 2) + pow(eye.z, 2) - (0.25f * pow(eye.y, 2)) + (0.25f * eye.y) - 0.0625f;
    float discriminant = pow(b, 2) - (4.f * a * c);
    if (discriminant > -m_epsilon) {
        t1 = (-b + sqrt(discriminant)) / (2 * a);
        t2 = (-b - sqrt(discriminant)) / (2 * a);
    }

    // base
    t3 = (-0.5f - eye.y) / d.y;

    // validate
    if (fabsf(eye.y + (t1 * d.y)) > 0.5f + m_epsilon) { t1 = -1.f; }
    if (fabsf(eye.y + (t2 * d.y)) > 0.5f + m_epsilon) { t2 = -1.f; }
    if (pow(eye.x + (d.x * t3), 2) + pow(eye.z + (d.z * t3), 2) > 0.25f + m_epsilon) { t3 = -1.f; }
    for (float t : {t1, t2, t3}) {
        if (t > 0) {
            valid.push_back(t);
        }
    }

    return valid.size() > 0 ? *std::min_element(valid.begin(), valid.end()) : -1.f;
}

float ImplicitShape::cylinder(glm::vec3 eye, glm::vec3 d) {

    float t1 = -1.f; // body1
    float t2 = -1.f; // body2
    float t3 = -1.f; // base (top)
    float t4 = -1.f; // base (bottom)
    std::vector<float> valid;

    // cylinder body
    float a = pow(d.x, 2) + pow(d.z, 2);
    float b = 2.f * ((eye.x * d.x) + (eye.z * d.z));
    float c = pow(eye.x, 2) + pow(eye.z, 2) - 0.25f;
    float discriminant = pow(b, 2) - (4.f * a * c);
    if (discriminant >= 0) {
        t1 = (-b + sqrt(discriminant)) / (2 * a);
        t2 = (-b - sqrt(discriminant)) / (2 * a);
    }

    // base
    t3 = (0.5f - eye.y) / d.y;
    t4 = (-0.5f - eye.y) / d.y;

    // validate
    if (fabsf(eye.y + (t1 * d.y)) > 0.5f) { t1 = -1.f; }
    if (fabsf(eye.y + (t2 * d.y)) > 0.5f) { t2 = -1.f; }
    if (pow(eye.x + (d.x * t3), 2) + pow(eye.z + (d.z * t3), 2) > 0.25f) { t3 = -1.f; }
    if (pow(eye.x + (d.x * t4), 2) + pow(eye.z + (d.z * t4), 2) > 0.25f) { t4 = -1.f; }
    for (float t : {t1, t2, t3, t4}) {
        if (t > 0) {  valid.push_back(t); }
    }

    return valid.size() > 0 ? *std::min_element(valid.begin(), valid.end()) : -1.f;
}

float ImplicitShape::sphere(glm::vec3 eye, glm::vec3 d) {

    float t1 = -1.f;
    float t2 = -1.f;

    float a = pow(d.x, 2) + pow(d.y, 2) + pow(d.z, 2);
    float b = 2 * ((eye.x * d.x) + (eye.y * d.y) + (eye.z * d.z));
    float c = pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2) - 0.25f;

    float discriminant = pow(b, 2) - (4.f * a * c);
    if (discriminant >= 0) {
        t1 = (-b + sqrt(discriminant)) / (2 * a);
        t2 = (-b - sqrt(discriminant)) / (2 * a);
    }

    std::vector<float> valid;
    for (float t : {t1, t2}) {
        if (t > 0) {  valid.push_back(t); }
    }

    return valid.size() > 0 ? *std::min_element(valid.begin(), valid.end()) : -1.f;
}

glm::vec3 ImplicitShape::getNormal(glm::vec3 point, int type) {
    switch (type) {
        case 0: // cube
            if (fabsf(point.y - 0.5f) < m_epsilon) {
                return {0.f, 1.f, 0.f};
            } else if (fabsf(point.y + 0.5f) < m_epsilon) {
                return {0.f, -1.f, 0.f};
            } else if (fabsf(point.x - 0.5f) < m_epsilon) {
                return {1.f, 0.f, 0.f};
            } else if (fabsf(point.x + 0.5f) < m_epsilon) {
                return {-1.f, 0.f, 0.f};
            } else if (point.z == 0.5f) {
                return {0.f, 0.f, 1.f};
            } else if (point.z == -0.5) {
                return {0.f, 0.f, -1.f};
            }
            break;
        case 1: {// cone
            if (fabsf(point.y + 0.5f) < m_epsilon) {
                return {0.f, -1.f, 0.f};
            }
            glm::vec2 pxz = glm::normalize(point.xz());
            return {pxz[0], 0.5f, pxz[1]};
            break;
    }
        case 2: // cylinder
            if (fabsf(point.y + 0.5f) < m_epsilon) {
                return {0.f, -1.f, 0.f};
            } if (fabsf(point.y - 0.5f) < m_epsilon) {
                return {0.f, 1.f, 0.f};
            }
            return {point.x, 0.f, point.z};
            break;
        case 4: // sphere
            return point;
            break;
        default:
            break;
    }
    return {0.f, 0.f, 0.f};
}
