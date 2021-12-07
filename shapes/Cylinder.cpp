#include "Cylinder.h"
#include <glm/glm.hpp>
#include "glm/gtx/transform.hpp"
#include <math.h>
#include <iostream>
#include "CircleBase.h"

Cylinder::Cylinder()
{
}

Cylinder::Cylinder(int param1, int param2) :
    m_param1(param1),
    m_param2(param2)
{
    validateParams();
    m_circleBase = std::make_unique<CircleBase>(m_param1, m_param2);
    m_vertexData = getVertexData();
    initializeOpenGLShapeProperties();
}

Cylinder::~Cylinder()
{
}

void Cylinder::validateParams() {
    if (m_param1 < 1) {
        m_param1 = 1;
    }
    if (m_param2 < 3) {
        m_param2 = 3;
    }
}

std::vector<float> Cylinder::makeFace() {

    std::shared_ptr<std::vector<float>> face = std::make_shared<std::vector<float>>();
    float theta =  (2.f * M_PI) / m_param2;
    float frac =  1.f / m_param1;

    for (int i = 0; i < m_param2; i++) {

        // base coords
        glm::vec3 left(0.5f * cos(theta*(i+1)), -0.5f, 0.5f * sin(theta*(i+1)));
        glm::vec3 right(0.5f * cos(theta*(i)), -0.5f, 0.5f * sin(theta*(i)));

        // lines
        glm::vec3 edge(0, 1.f, 0);

        // calc normals
        glm::vec3 leftNormal(glm::normalize(glm::vec3(0.5f * cos(theta*(i+1)), 0.f, 0.5f * sin(theta*(i+1)))));
        glm::vec3 rightNormal(glm::normalize(glm::vec3(0.5f * cos(theta*(i)), 0.f, 0.5f * sin(theta*(i)))));

        // tessellate
        std::vector<glm::vec3> edgesAndNormals({left, right, edge, edge, leftNormal, rightNormal});
        m_circleBase->tessellate(face, frac, edgesAndNormals);
    }

    return *face;
}

std::vector<float> Cylinder::getVertexData() {

    std::vector<float> cone;

    // make bases
    glm::mat4 top = glm::rotate((float)M_PI, glm::vec3(1.f, 0.f, 0.f));
    glm::mat4 bottom = glm::rotate(0.f, glm::vec3(1.f, 0.f, 0.f));
    std::vector<float> topBase = m_circleBase->makeBase(top);
    std::vector<float> bottomBase = m_circleBase->makeBase(bottom);
    cone.insert(std::end(cone), std::begin(topBase), std::end(topBase));
    cone.insert(std::end(cone), std::begin(bottomBase), std::end(bottomBase));

    std::vector<float> frontFace = makeFace(); // make faces
    cone.insert(std::end(cone), std::begin(frontFace), std::end(frontFace)); // add to vertex data

    return cone;
}

glm::vec3 Cylinder::getNormal(glm::vec3 v1, glm::vec3 v2) {
    glm::vec3 norm(glm::normalize(glm::cross(v1, v2)));
    return norm;
}
