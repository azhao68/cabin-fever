#include "CircleBase.h"
#include <iostream>

CircleBase::CircleBase()
{
}

CircleBase::CircleBase(int param1, int param2) :
    m_param1(param1),
    m_param2(param2)
{
}

CircleBase::~CircleBase()
{
}

std::vector<float> CircleBase::makeBase(glm::mat4 transform) {



    std::vector<glm::vec4> points;
    std::vector<float> base;
    glm::vec4 center(transform * glm::vec4(0.f, -0.5f, 0.f, 1.f));
    glm::vec3 normal(transform * glm::vec4(0.f, -1.f, 0.f, 0.f));

    float theta =  (2 * M_PI) / m_param2;
    float frac =  1.f / m_param1;

    // starts from right (positive x) and goes counterclockwise
    for (int i = 0; i < m_param2; i++) {
        float x = 0.5f * cos(theta*i);
        float y = -0.5f;
        float z = 0.5f * sin(theta*i);
        glm::vec4 v4(x, y, z, 1.f);
        points.push_back(transform * v4);
    }

    // tessellate
    for (int i = 0; i < points.size(); i++) {
        glm::vec4 curr = points[i];
        glm::vec4 next;

        if (i == points.size() - 1) { // handle edge cases
            next = points[0];
        } else {
            next = points[i+1];
        }

        glm::vec3 left(center-curr);
        glm::vec3 right(center-next);

        // face endpoints
        for (int j = 0; j < m_param1; j++) {

            // outside in
            glm::vec3 leftTop(left * (frac * (j+1)) + glm::vec3(curr));
            glm::vec3 leftBottom(left * (frac * j) + glm::vec3(curr));
            glm::vec3 rightBottom(right * (frac * (j)) + glm::vec3(next));
            glm::vec3 rightTop(right * (frac * (j+1)) + glm::vec3(next));

            base.insert(std::end(base), {leftTop.x, leftTop.y, leftTop.z, normal.x, normal.y, normal.z});
            base.insert(std::end(base), {leftBottom.x, leftBottom.y, leftBottom.z, normal.x, normal.y, normal.z});
            base.insert(std::end(base), {rightTop.x, rightTop.y, rightTop.z, normal.x, normal.y, normal.z});

            base.insert(std::end(base), {rightTop.x, rightTop.y, rightTop.z, normal.x, normal.y, normal.z});
            base.insert(std::end(base), {leftBottom.x, leftBottom.y, leftBottom.z, normal.x, normal.y, normal.z});
            base.insert(std::end(base), {rightBottom.x, rightBottom.y, rightBottom.z, normal.x, normal.y, normal.z});
        }
    }

    return base;
}

void CircleBase::tessellate(std::shared_ptr<std::vector<float>> face, float frac, std::vector<glm::vec3> edgeAndNormals) {

    glm::vec3 left = edgeAndNormals[0];
    glm::vec3 right = edgeAndNormals[1];
    glm::vec3 leftEdge = edgeAndNormals[2];
    glm::vec3 rightEdge = edgeAndNormals[3];
    glm::vec3 leftNormal = edgeAndNormals[4];
    glm::vec3 rightNormal = edgeAndNormals[5];

    for (int j = 0; j < m_param1; j++) {

        // trapezoids of each face working from bottom up
        glm::vec3 leftTop(leftEdge * (frac * (j+1)) + left); // = right top at tip
        glm::vec3 leftBottom(leftEdge * (frac * j) + left);
        glm::vec3 rightBottom(rightEdge * (frac * (j)) + right);
        glm::vec3 rightTop(rightEdge * (frac * (j+1)) + right);

        face->insert(std::end(*face), {leftTop.x, leftTop.y, leftTop.z, leftNormal.x, leftNormal.y, leftNormal.z});
        face->insert(std::end(*face), {leftBottom.x, leftBottom.y, leftBottom.z, leftNormal.x, leftNormal.y, leftNormal.z});
        face->insert(std::end(*face), {rightTop.x, rightTop.y, rightTop.z, rightNormal.x, rightNormal.y, rightNormal.z});

        face->insert(std::end(*face), {rightTop.x, rightTop.y, rightTop.z, rightNormal.x, rightNormal.y, rightNormal.z});
        face->insert(std::end(*face), {leftBottom.x, leftBottom.y, leftBottom.z, leftNormal.x, leftNormal.y, leftNormal.z});
        face->insert(std::end(*face), {rightBottom.x, rightBottom.y, rightBottom.z, rightNormal.x, rightNormal.y, rightNormal.z});
    }
}
