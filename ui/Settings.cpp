/*!

 Settings.h
 CS123 Support Code

 @author  Evan Wallace (edwallac)
 @date    9/1/2010

 This file contains various settings and enumerations that you will need to
 use in the various assignments. The settings are bound to the GUI via static
 data bindings.

**/

#include "Settings.h"
#include <QFile>
#include <QSettings>

Settings settings;


/**
 * Loads the application settings, or, if no saved settings are available, loads default values for
 * the settings. You can change the defaults here.
 */
void Settings::loadSettingsOrDefaults() {
    // Set the default values below
    QSettings s("cabin-fever", "cabin-fever");

    // Brush
    snowRate = s.value("snowRate", 1).toDouble();
    snowSize = s.value("snowSize", 1).toDouble();

}

void Settings::saveSettings() {
    QSettings s("cabin-fever", "cabin-fever");

    s.setValue("snowRate", snowRate);
    s.setValue("snowSize", snowSize);


    //s.setValue("currentTab", currentTab);
}
