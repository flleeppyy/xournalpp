/*
 * Xournal++
 *
 * Helper functions to iterate over devices
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include <string>
#include <vector>

#include <gdk/gdk.h>
#include <gtk/gtk.h>

#include "control/settings/Settings.h"
#include "gui/inputdevices/InputEvents.h"

class InputDevice {
public:
    explicit InputDevice(GdkDevice* device);
    explicit InputDevice(std::string name, GdkInputSource source);
    ~InputDevice() = default;

public:
    std::string getType() const;
    std::string getName() const;
    GdkInputSource getSource() const;
    void updateType(GdkInputSource newSource);

    bool operator==(const InputDevice& inputDevice) const;

private:
    std::string name;
    GdkInputSource source;
};

namespace DeviceListHelper {
std::vector<InputDevice> getDeviceList(Settings* settings, bool ignoreTouchDevices = false);
InputDeviceClass getSourceMapping(GdkInputSource source, Settings* settings);
}  // namespace DeviceListHelper
