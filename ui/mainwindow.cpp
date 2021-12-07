#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "view.h"
#include <QGLFormat>
#include "Databinding.h"
#include "Settings.h"
#include <QSettings>
#include <QFileDialog>
#include <QMessageBox>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    settings.loadSettingsOrDefaults();
    QGLFormat qglFormat;
    qglFormat.setVersion(4, 3);
    qglFormat.setProfile(QGLFormat::CoreProfile);
    qglFormat.setSampleBuffers(true);
    ui->setupUi(this);
    m_canvas3D = new SupportCanvas3D(qglFormat, this);
    QSettings qtSettings("cabin-fever", "cabin-fever");
    dataBind();
}

void MainWindow::dataBind() {
    // Snow dock
#define BIND(b) { \
    DataBinding *_b = (b); \
    m_bindings.push_back(_b); \
    assert(connect(_b, SIGNAL(dataChanged()), this, SLOT(settingsChanged()))); \
}
    BIND(FloatBinding::bindSliderAndTextbox(
        ui->snowRateSlider, ui->snowRateTextbox, settings.snowRate, 0.f, 50.f))
    BIND(FloatBinding::bindSliderAndTextbox(
        ui->snowSizeSlider, ui->snowSizeTextbox, settings.snowSize, 0.f, 50.f))
//    BIND(BoolBinding::bind(ui->brushAlphaBlendingCheckbox, settings.fixAlphaBlending))

#undef BIND

   // make sure the aspect ratio updates when m_canvas3D changes size
   // connect(m_canvas3D, SIGNAL(aspectRatioChanged()), this, SLOT(updateAspectRatio()));
}

MainWindow::~MainWindow()
{
    foreach (DataBinding *b, m_bindings)
        delete b;
    delete ui;
}

void MainWindow::settingsChanged() {
    std::cout << "settings changed" << std::endl;
}

void MainWindow::throwSnowball() {
    std::cout << "throw Snowball" << std::endl;
}
