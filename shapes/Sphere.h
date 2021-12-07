#ifndef SPHERE_H
#define SPHERE_H

#include "OpenGLShape.h"

class Sphere : public OpenGLShape
{
public:
    Sphere();
    Sphere(int param1, int param2);
    ~Sphere();

    std::vector<float> getVertexData();

private:
    void validateParams();
    std::vector<float> makeFace();
    glm::vec3 getNormal(glm::vec3 v1, glm::vec3 v2);
    int m_param1;
    int m_param2;
};

#endif // SPHERE_H
