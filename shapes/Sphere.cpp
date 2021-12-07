#include "Sphere.h"
#include <glm/glm.hpp>
#include "glm/gtx/transform.hpp"
#include <math.h>
#include <iostream>
#include "CircleBase.h"

Sphere::Sphere()
{
}

Sphere::Sphere(int param1, int param2) :
    m_param1(param1),
    m_param2(param2)
{
    validateParams();
    m_vertexData = getVertexData();
    initializeOpenGLShapeProperties();
}

Sphere::~Sphere()
{
}

void Sphere::validateParams() {
    if (m_param1 < 2) {
        m_param1 = 2;
    }
    if (m_param2 < 3) {
        m_param2 = 3;
    }
}

std::vector<float> Sphere::makeFace() {

    std::vector<float> face;
    float r = 0.5f;
    float theta =  (2.f * M_PI) / m_param2;
    float phi =  M_PI / m_param1;

    std::vector<glm::vec3> points;
    for (int i = 0; i < m_param2; i++) {

        glm::mat4 transform = glm::rotate(theta*i, glm::vec3(0.f, 1.f, 0.f)) * glm::rotate((float)-M_PI_2, glm::vec3(0.f, 0.f, 1.f));

        // (x,y,z) = (r*cos(phi)*cos(theta), r*cos(phi)*sin(theta), r*sin(phi))
        for (int j = 0; j <= m_param1; j++) {
            float x = r * cos(phi*j);
            float y = r * sin(phi*j);
            float z = 0.f;
            glm::vec4 v4(transform * glm::vec4(x, y, z, 1.f));
            points.insert(std::end(points), glm::vec3(v4));
        }
    }

    for (int i = 0; i < points.size(); i++) {

        int faceLength = m_param1 + 1;
        if ((i - m_param1) % faceLength == 0) {
            continue; // skip if curr is a tip vertex
        }

        glm::vec3 curr = points[i];
        glm::vec3 top = points [i+1];
        glm::vec3 right; glm::vec3 topRight;

        if (i >= points.size() - faceLength) {
            right = points[i % faceLength];
            topRight = points[i % faceLength + 1];
        } else {
            right = points[i+faceLength];
            topRight = points[i+faceLength+1];
        }

        glm::vec3 currNormal(glm::normalize(curr));
        glm::vec3 topNormal(glm::normalize(top));
        glm::vec3 rightNormal(glm::normalize(right));
        glm::vec3 topRightNormal(glm::normalize(topRight));

        face.insert(std::end(face), {curr.x, curr.y, curr.z, currNormal.x, currNormal.y, currNormal.z});
        face.insert(std::end(face), {topRight.x, topRight.y, topRight.z, topRightNormal.x, topRightNormal.y, topRightNormal.z});
        face.insert(std::end(face), {top.x, top.y, top.z, topNormal.x, topNormal.y, topNormal.z});

        face.insert(std::end(face), {curr.x, curr.y, curr.z, currNormal.x, currNormal.y, currNormal.z});
        face.insert(std::end(face), {right.x, right.y, right.z, rightNormal.x, rightNormal.y, rightNormal.z});
        face.insert(std::end(face), {topRight.x, topRight.y, topRight.z, topRightNormal.x, topRightNormal.y, topRightNormal.z});
    }

    return face;
}

std::vector<float> Sphere::getVertexData() {
    std::vector<float> sphere = makeFace(); // make faces
    return sphere;
}

glm::vec3 Sphere::getNormal(glm::vec3 v1, glm::vec3 v2) {
    glm::vec3 norm(glm::normalize(glm::cross(v1, v2)));
    return norm;
}
