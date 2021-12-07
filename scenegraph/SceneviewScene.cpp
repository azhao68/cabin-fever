#include "scenegraph/SceneviewScene.h"
#include "GL/glew.h"
#include <QGLWidget>
#include <iostream>
#include "lib/ResourceLoader.h"
#include "Settings.h"
#include "SupportCanvas3D.h"
#include "gl/shaders/CS123Shader.h"
using namespace CS123::GL;

// Utilize a flyweight pattern (storing objects that are used repeatedly) to reduce the number of objects you need to store
SceneviewScene::SceneviewScene()
//    m_cube(new Cube(1, 1)),
//    m_cone(new Cone(20, 20)),
//    m_cylinder(new Cylinder(20, 20)),
//    m_sphere(new Sphere(20, 20))
{
    // TODO: [SCENEVIEW] Set up anything you need for your Sceneview scene here...
//    loadPhongShader();
}

SceneviewScene::~SceneviewScene()
{
}

//void SceneviewScene::loadPhongShader() {
//    std::string vertexSource = ResourceLoader::loadResourceFileToString(":/shaders/default.vert");
//    std::string fragmentSource = ResourceLoader::loadResourceFileToString(":/shaders/default.frag");
//    m_phongShader = std::make_unique<CS123Shader>(vertexSource, fragmentSource);
//}

void SceneviewScene::render(SupportCanvas3D *context) {
    setClearColor();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    m_phongShader->bind();
//    setGlobalData();
//    setLights();
//    renderGeometry();
//    glBindTexture(GL_TEXTURE_2D, 0);
//    m_phongShader->unbind();

}

//// implement setGlobalData() to set coefficient values in the shader
//void SceneviewScene::setGlobalData(){
//    // [TODO] pass global data to shader.vert using m_phongShader
//    m_phongShader->setUniform("ka", m_global.ka);
//    m_phongShader->setUniform("kd", m_global.kd);
//    m_phongShader->setUniform("ks", m_global.ks);
//}

//void SceneviewScene::setSceneUniforms(SupportCanvas3D *context) {
//    m_phongShader->setUniform("useLighting", true);
//    m_phongShader->setUniform("useArrowOffsets", false);
//    m_phongShader->setUniform("isShapeScene", false);
//    m_phongShader->setUniform("p" , glm::mat4(0.f));
//    m_phongShader->setUniform("v", glm::mat4(0.f));
//}

//void SceneviewScene::setMatrixUniforms(CS123Shader *shader, SupportCanvas3D *context) {
//    shader->setUniform("p", glm::mat4(0.f));
//    shader->setUniform("v", glm::mat4(0.f));
//}

//void SceneviewScene::setLights()
//{
//    // TODO: [SCENEVIEW] Fill this in...
//    //
//    // Set up the lighting for your scene using m_phongShader.
//    // The lighting information will most likely be stored in CS123SceneLightData structures.
//    for (CS123SceneLightData &light : m_lights) {
//        m_phongShader->setLight(light);
//    }
//}

//void SceneviewScene::renderGeometry() {
//    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//    for (int i = 0; i < m_primitives.size(); i++) {
//        CS123ScenePrimitive prim = m_primitives[i];

//        m_phongShader->applyMaterial(prim.material);
//        m_phongShader->setUniform("m", m_transformations[i]);
//        switch (prim.type) {
//            case PrimitiveType::PRIMITIVE_CUBE: {
//                m_cube->draw();
//                break;
//            }
//            case PrimitiveType::PRIMITIVE_CONE: {
//                m_cone->draw();
//                break;
//            }
//            case PrimitiveType::PRIMITIVE_CYLINDER: {
//                m_cylinder->draw();
//                break;
//            }
//            case PrimitiveType::PRIMITIVE_SPHERE: {
//                m_sphere->draw();
//                break;
//            }
//            default:
//                break;
//        }
//    }
//}

void SceneviewScene::settingsChanged() {
    // TODO: [SCENEVIEW] Fill this in if applicable.
    std::cout << "sceneview scene: settings changed" << std::endl;
}

