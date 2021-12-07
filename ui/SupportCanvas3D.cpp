#include "SupportCanvas3D.h"

#include <QFileDialog>
#include <QMouseEvent>
#include <QMessageBox>
#include <QApplication>

#include "lib/RGBA.h"
#include "scenegraph/SceneviewScene.h"
#include "Settings.h"
#include <iostream>
#include "gl/GLDebug.h"

SupportCanvas3D::SupportCanvas3D(QGLFormat format, QWidget *parent) :
    QGLWidget(format, parent),
    m_sceneviewScene(std::make_unique<SceneviewScene>())
{
}

SupportCanvas3D::~SupportCanvas3D()
{
}

void SupportCanvas3D::initializeGL() {
    initializeGlew();
    initializeOpenGLSettings();
    settingsChanged();

}

void SupportCanvas3D::initializeGlew() {
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    glGetError(); // Clear errors after call to glewInit
    if (GLEW_OK != err) {
      // Problem: glewInit failed, something is seriously wrong.
      fprintf(stderr, "Error initializing glew: %s\n", glewGetErrorString(err));
    }
}

void SupportCanvas3D::initializeOpenGLSettings() {
    // Enable depth testing, so that objects are occluded based on depth instead of drawing order.
    glEnable(GL_DEPTH_TEST);

    // Move the polygons back a bit so lines are still drawn even though they are coplanar with the
    // polygons they came from, which will be drawn before them.
    glEnable(GL_POLYGON_OFFSET_LINE);
    glPolygonOffset(-1, -1);

    // Enable back-face culling, meaning only the front side of every face is rendered.
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    // Specify that the front face is represented by vertices in counterclockwise order (this is
    // the default).
    glFrontFace(GL_CCW);
}

void SupportCanvas3D::paintGL() {
    float ratio = static_cast<QGuiApplication *>(QCoreApplication::instance())->devicePixelRatio();
    glViewport(0, 0, width() * ratio, height() * ratio);
    m_sceneviewScene->render(this);
}

void SupportCanvas3D::settingsChanged() {
    if (m_sceneviewScene != nullptr) {
        // Just calling this function so that the scene is always updated.
        m_sceneviewScene->settingsChanged();
    }
    update(); /* repaint the scene */
}


void SupportCanvas3D::copyPixels(int width, int height, RGBA *data) {
    glReadPixels(0, 0, width, height, GL_BGRA, GL_UNSIGNED_BYTE, data);
    std::cout << "copied " << width << "x" << height << std::endl;

    // Flip the image and since OpenGL uses an origin in the lower left and we an origin in the
    // upper left.
    for (int y = 0; y < (height + 1) / 2; y++)
        for (int x = 0; x < width; x++)
            std::swap(data[x + y * width], data[x + (height - y - 1) * width]);
}

