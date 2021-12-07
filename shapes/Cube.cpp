#include "Cube.h"
#include <glm/glm.hpp>
#include "glm/gtx/transform.hpp"
#include <math.h>
#include <iostream>

// THIS IS A CUBE (I HOPE)

Cube::Cube()
{
    /**
     * You'll want to expand upon or refactor this code heavily to take advantage
     * of polymorphism, vector math/glm library, and utilize good software design
     */
    m_vertexData = getVertexData();
    initializeOpenGLShapeProperties();
}

Cube::~Cube()
{
}

//std::vector<float> Cube::makeFace(glm::mat4 transform) {

//    std::vector<glm::vec4> points;
//    std::vector<float> face;
//    float frac = 1.f/m_param1;

//    // make points (like a grid)
//    for (int i = m_param1; i >= 0; i--) { // y decreases (top bottom)
//        for (int j = 0; j < m_param1 + 1; j++) { // x increases (left right)
//            float x = j*frac - 0.5;
//            float y = i*frac - 0.5;
//            glm::vec4 v4(x, y, 0.f, 1.f);
//            points.push_back(transform * v4);
//        }
//    }

//    // tessellate (refactor)
//    for (int i = 0; i < points.size(); i++) {
//        if ((i - m_param1) % (m_param1 + 1) == 0) { // edge cases
//            continue; // if point on the right edge of square
//        } if (i > points.size() - (m_param1 + 2)) {
//            continue; // if point on bottom edge of square
//        }

//        // for each subsquare, insert 2 triangles
//        glm::vec4 curr = points[i];
//        glm::vec4 right = points[i+1];
//        glm::vec4 bottom = points[i + m_param1 + 1];
//        glm::vec4 bottomRight = points[i + m_param1 + 2];
//        glm::vec3 normal = getNormal(glm::vec3(right-bottom), (glm::vec3(curr-bottom)));

//        face.insert(std::end(face), {curr.x, curr.y, curr.z, normal.x, normal.y, normal.z});
//        face.insert(std::end(face), {bottom.x, bottom.y, bottom.z, normal.x, normal.y, normal.z});
//        face.insert(std::end(face), {right.x, right.y, right.z, normal.x, normal.y, normal.z});

//        face.insert(std::end(face), {bottom.x, bottom.y, bottom.z, normal.x, normal.y, normal.z});
//        face.insert(std::end(face), {bottomRight.x, bottomRight.y, bottomRight.z, normal.x, normal.y, normal.z});
//        face.insert(std::end(face), {right.x, right.y, right.z, normal.x, normal.y, normal.z});
//    }

//    return face;
//}

std::vector<float> Cube::getVertexData() {

//    std::vector<float> cube;
//    float pi = M_PI;

//    // transformation matrices
//    glm::mat4 front = glm::translate(glm::vec3(0.f,0.f,0.5f)) * glm::rotate(0.f, glm::vec3(0.f, 1.f, 0.f));
//    glm::mat4 back = glm::translate(glm::vec3(0.f,0.f,-0.5f)) * glm::rotate(pi, glm::vec3(0.f, 1.f, 0.f));
//    glm::mat4 left = glm::translate(glm::vec3(-0.5f,0.f,0.f)) * glm::rotate(-pi/2, glm::vec3(0.f, 1.f, 0.f));
//    glm::mat4 right = glm::translate(glm::vec3(0.5f,0.f,0.f)) * glm::rotate(pi/2, glm::vec3(0.f, 1.f, 0.f));
//    glm::mat4 top = glm::translate(glm::vec3(0.f,0.5f,0.f)) * glm::rotate(-pi/2, glm::vec3(1.f, 0.f, 0.f));
//    glm::mat4 bottom = glm::translate(glm::vec3(0.f,-0.5f,0.f)) * glm::rotate(pi/2, glm::vec3(1.f, 0.f, 0.f));
//    std::vector<glm::mat4> transformations({front, back, left, right, top, bottom});

//    // make faces
//    for (glm::mat4 &transformation : transformations) {
//        std::vector<float> face = makeFace(transformation);
//        cube.insert(std::end(cube), std::begin(face), std::end(face));
//    }
//    return cube;
    return std::vector<float>({0.5f, 0.5f, 0.5f,\
                               0.f, 0.f, 1.f, \
                               -0.5f, 0.5f, 0.5f,\
                               0.f, 0.f, 1.f, \
                               0.5f,-0.5f, 0.5f, \
                               0.f, 0.f, 1.f});
}

//glm::vec3 Cube::getNormal(glm::vec3 v1, glm::vec3 v2) {
//    glm::vec3 norm(glm::normalize(glm::cross(v1, v2)));
//    return norm;
//}
