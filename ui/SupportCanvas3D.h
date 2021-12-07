#ifndef SUPPORTCANVAS3D_H
#define SUPPORTCANVAS3D_H

#include <memory>

#include "GL/glew.h"
#include <QGLWidget>

#include "glm/glm.hpp"

class RGBA;
class OpenGLScene;
class SceneviewScene;

/**
 * @class  SupportCanvas3D
 *
 * The SupportCanvas3D class holds a single active OpenGLScene, and either
 * calls upon that scene to draw itself using OpenGL or draws the scene
 * by directly calling upon OpenGL (getting the scene-specific information
 * from the OpenGLScene object). The details of the implementation are left
 * to the student; neither way is better than the other.
 *
 * The SupportCanvas3D also contains a default camera which can be used in
 * case the loaded scene does not specify a camera.
 */

class SupportCanvas3D : public QGLWidget {
    Q_OBJECT
public:
    SupportCanvas3D(QGLFormat format, QWidget *parent);

    virtual ~SupportCanvas3D();

    // Copies pixels from the OpenGL render buffer into a standard bitmap image, using row-major
    // order and RGBA data format.
    void copyPixels(int width, int height, RGBA *data);

    // This function will be called by the UI when the settings have changed.
    virtual void settingsChanged();

protected:
    // Overridden from QGLWidget
    virtual void initializeGL() override;
    virtual void paintGL() override;

private:
    void initializeGlew();
    void initializeOpenGLSettings();
    std::unique_ptr<SceneviewScene> m_sceneviewScene;
};

#endif // SUPPORTCANVAS3D_H
