#ifndef CUBE_H
#define CUBE_H

#include "OpenGLShape.h"

class Cube : public OpenGLShape
{
public:
    Cube();
    ~Cube();

    std::vector<float> getVertexData();

private:
//    std::vector<float> makeFace(glm::mat4 transform);
//    glm::vec3 getNormal(glm::vec3 v1, glm::vec3 v2);
    int m_param1 = 20;
    int m_param2 = 20;
};

#endif // CUBE_H
