#ifndef IMPLICITSHAPE_H
#define IMPLICITSHAPE_H
#include <glm/glm.hpp>
#include <vector>

/**
 * @class ImplicitShape
 *
 *  Students will implement this class as necessary in the Ray project.
 */
class ImplicitShape {

public:
    ImplicitShape();
    virtual ~ImplicitShape();

    float cube(glm::vec3 eye, glm::vec3 d);
    float cubeHelper(std::vector<float> face);
    float cylinder(glm::vec3 eye, glm::vec3 d);
    float cone(glm::vec3 eye, glm::vec3 d);
    float sphere(glm::vec3 eye, glm::vec3 d);

    glm::vec3 getNormal(glm::vec3 point, int type);

private:
    float m_epsilon = 0.0001;

};

#endif // IMPLICITSHAPE_H
