#include "Cone.h"
#include <glm/glm.hpp>
#include "glm/gtx/transform.hpp"
#include <math.h>
#include <iostream>
#include "CircleBase.h"

Cone::Cone()
{
}

Cone::Cone(int param1, int param2) :
    m_param1(param1),
    m_param2(param2)
{
    validateParams();
    m_circleBase = std::make_unique<CircleBase>(m_param1, m_param2);
    m_vertexData = getVertexData();
    initializeOpenGLShapeProperties();
}

Cone::~Cone()
{
}

void Cone::validateParams() {
    if (m_param1 < 1) {
        m_param1 = 1;
    }
    if (m_param2 < 3) {
        m_param2 = 3;
    }
}

std::vector<float> Cone::makeFace() {

    std::shared_ptr<std::vector<float>> face = std::make_shared<std::vector<float>>();
    float theta =  (2.f * M_PI) / m_param2;
    float frac =  1.f / m_param1;

    glm::vec3 tip(0.f, 0.5f, 0.f);
    for (int i = 0; i < m_param2; i++) {

        // base coords
        glm::vec3 left(0.5f * cos(theta*(i+1)), -0.5f, 0.5f * sin(theta*(i+1)));
        glm::vec3 right(0.5f * cos(theta*(i)), -0.5f, 0.5f * sin(theta*(i)));
        glm::vec3 leftLeft(0.5f * cos(theta*(i+2)), -0.5f, 0.5f * sin(theta*(i+2)));
        glm::vec3 rightRight(0.5f * cos(theta*(i-1)), -0.5f, 0.5f * sin(theta*(i-1)));

        // lines
        glm::vec3 leftEdge(tip-left);
        glm::vec3 rightEdge(tip-right);

        // calc normals
        glm::vec3 leftNormal(getNormal((right-leftLeft), (tip-left)));
        glm::vec3 rightNormal(getNormal((rightRight-left), (tip-right)));

        // tessellate
        std::vector<glm::vec3> edgesAndNormals({left, right, leftEdge, rightEdge, leftNormal, rightNormal});
        m_circleBase->tessellate(face, frac, edgesAndNormals);
    }

    return *face;
}

std::vector<float> Cone::getVertexData() {

    std::vector<float> cone;
    std::vector<float> frontFace = makeFace(); // make faces
    glm::mat4 bottom = glm::rotate(0.f, glm::vec3(1.f, 0.f, 0.f));
    cone = m_circleBase->makeBase(bottom); // initialise as base
    cone.insert(std::end(cone), std::begin(frontFace), std::end(frontFace)); // add to vertex data

    return cone;
}

glm::vec3 Cone::getNormal(glm::vec3 v1, glm::vec3 v2) {
    glm::vec3 norm(glm::normalize(glm::cross(v1, v2)));
    return norm;
}
