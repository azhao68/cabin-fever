#ifndef CONE_H
#define CONE_H

#include "OpenGLShape.h"
#include "CircleBase.h"

class Cone : public OpenGLShape
{
public:
    Cone();
    Cone(int param1, int param2);
    ~Cone();

    std::vector<float> getVertexData();

private:
    void validateParams();
    std::vector<float> makeFace();
    glm::vec3 getNormal(glm::vec3 v1, glm::vec3 v2);
    int m_param1;
    int m_param2;
    std::unique_ptr<CircleBase> m_circleBase;
};

#endif // CONE_H
