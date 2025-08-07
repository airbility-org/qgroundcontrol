import QtQuick

Item {
    id: _customScreenTools

    property real baseWidth: 1920
    property real baseHeight: 1200

    property real currentWidth
    property real currentHeight

    property real defaultWidthRatio: mainWindow.width / baseWidth
    property real defaultHeightRatio: mainWindow.height / baseHeight

    property real widthRatio: currentWidth / baseWidth
    property real heightRatio: currentHeight / baseHeight

    property real defaultFontSize1: 13
    property real defaultFontSize2: 20
    property real defaultFontSize3: 30
    property real defaultFontSize4: 40

    property real minTiltAngleFontPointSize: 30
    property real minTitlelFontPointSize: 20
    property real minMediumFontPointSize: 13
    property real minSmallFontPointSize: 10

    property real fontSize1: Math.max(10, defaultFontSize1 * defaultWidthRatio)
    property real fontSize2: Math.max(defaultFontSize1, defaultFontSize2 * defaultWidthRatio)
    property real fontSize3: Math.max(defaultFontSize1, defaultFontSize3 * defaultWidthRatio)
    property real fontSize4: Math.max(defaultFontSize1, defaultFontSize4 * defaultWidthRatio)
} 
