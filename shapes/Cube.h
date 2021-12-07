#ifndef CUBE_H
#define CUBE_H

#include "OpenGLShape.h"

class Cube : public OpenGLShape
{
public:
    Cube();
    Cube(int param1, int param2);
    ~Cube();

    std::vector<float> getVertexData();

private:
    void validateParams();
    std::vector<float> makeFace(glm::mat4 transform);
    glm::vec3 getNormal(glm::vec3 v1, glm::vec3 v2);
    int m_param1;
    int m_param2;
};

#endif // CUBE_H
