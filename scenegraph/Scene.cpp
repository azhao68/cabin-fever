#include "Scene.h"
#include "glm/gtx/transform.hpp"
#include <iostream>
#include <queue>
#include "glm/gtx/transform.hpp"

Scene::Scene()
{ // anything needed here?
}

Scene::Scene(Scene &scene): // copy constructor: copies al of &scene's resources to this new obj
    m_global({ 1, 1, 1, 1}), // need to set the m_global to one when we duplicate a scene otherwise it will be double counted (squared)
    m_lights(scene.m_lights),
    m_primitives(scene.m_primitives),
    m_transformations(scene.m_transformations)
{
    m_global = scene.m_global;
}

Scene::~Scene()
{
    // Do not delete m_camera, it is owned by SupportCanvas3D
}

void Scene::makeScene(Scene *sceneToFill) {
    std::cout << "scene: make scene" << std::endl;
}

//void Scene::parse(Scene *sceneToFill, CS123ISceneParser *parser) {

//    // global data
//    CS123SceneGlobalData globalData; // make data object
//    parser->getGlobalData(globalData); // get data from parser
//    sceneToFill->setGlobal(globalData); // load data to input scene

//    // lights data (CS123SceneLightData is data for one light)
//    int numLights = parser->getNumLights();
//    for (int i = 0; i < numLights; i++) {
//        CS123SceneLightData lightData;
//        parser->getLightData(i, lightData);
//        sceneToFill->addLight(lightData);
//    }

//    // parse object data
//    CS123SceneNode *root = parser->getRootNode();
//    sceneToFill->dfs(sceneToFill, root);
//}

//void Scene::dfs(Scene *sceneToFill, CS123SceneNode *root) {

//    std::map<CS123SceneNode*, bool> visited; // key = node, value = visited
//    std::map<CS123SceneNode*, glm::mat4x4> transformations; // key = node, value = cumulative transformation matrix
//    std::map<CS123SceneNode*, CS123SceneNode*> parents; // key = node, value = parent
//    std::queue<CS123SceneNode*> queue;

//    queue.push(root); // add root
//    glm::mat4x4 identity(1.0f); // initialise identity matrix
//    transformations[root] = identity; // root has no transformations
//    parents[root] = root; // for transformation purposes

//    while (queue.size() != 0) {
//        CS123SceneNode* node = queue.front();
//        queue.pop();
//        if (!visited[node]) {
//            glm::mat4 objTrans(1.f); // object's transformation matrix (to world)
//            for (CS123SceneTransformation* t : node->transformations) {
//                switch (t->type) {
//                    case TRANSFORMATION_TRANSLATE: {
//                        objTrans = objTrans * glm::translate(t->translate);
//                        break;
//                    }
//                    case TRANSFORMATION_ROTATE: {
//                        objTrans = objTrans * glm::rotate(t->angle, t->rotate);
//                        break;
//                    }
//                    case TRANSFORMATION_SCALE: {
//                        objTrans = objTrans * glm::scale(t->scale);
//                        break;
//                    }
//                    default:
//                        break;
//                }
//            }

//            glm::mat4 cumulativeTrans = transformations[parents[node]] * objTrans; // multiply by parent transformations
//            transformations[node] = cumulativeTrans; // save final matrix in map
//            visited[node] = true;

//            if (node->children.size() == 0) { // if is leaf
//                const CS123ScenePrimitive p = *(node->primitives).front(); // assume every leaf has one primitive??
//                sceneToFill->addPrimitive(p, cumulativeTrans);
//            } else {
//                for (CS123SceneNode* child : node->children) {
//                    queue.push(child);
//                    parents[child] = node;
//                }
//            }
//        }
//    }
//}

void Scene::addPrimitive(const CS123ScenePrimitive &scenePrimitive, glm::mat4x4 &matrix) {
    m_primitives.push_back(scenePrimitive);
    m_transformations.push_back(matrix);
}

void Scene::addLight(const CS123SceneLightData &sceneLight) {
    m_lights.push_back(sceneLight);
}

void Scene::setGlobal(const CS123SceneGlobalData &global) {
    m_global = global;
}

