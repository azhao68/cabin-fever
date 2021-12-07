#ifndef CYLINDER_H
#define CYLINDER_H

#include "OpenGLShape.h"
#include "CircleBase.h"

class Cylinder : public OpenGLShape
{
public:
    Cylinder();
    Cylinder(int param1, int param2);
    ~Cylinder();

    std::vector<float> getVertexData();

private:
    void validateParams();
    std::vector<float> makeBase(glm::mat4 transform);
    std::vector<float> makeFace();
    glm::vec3 getNormal(glm::vec3 v1, glm::vec3 v2);
    int m_param1;
    int m_param2;
    std::unique_ptr<CircleBase> m_circleBase;
};

#endif // CYLINDER_H
