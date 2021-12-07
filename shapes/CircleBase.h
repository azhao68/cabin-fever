#ifndef CIRCLEBASE_H
#define CIRCLEBASE_H
#include "OpenGLShape.h"
#include <glm/glm.hpp>
#include <memory>
#include <vector>
#include <list>

class CircleBase
{
public:
    CircleBase();
    CircleBase(int param1, int param2);
    virtual ~CircleBase();
    std::vector<float> makeBase(glm::mat4 transform);
    void tessellate(std::shared_ptr<std::vector<float>> face, float frac, std::vector<glm::vec3> edgeAndNormals);

protected:
    int m_param1;
    int m_param2;
};

#endif // CIRCLEBASE_H
