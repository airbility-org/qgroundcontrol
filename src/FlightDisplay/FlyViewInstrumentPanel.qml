/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

import QtQuick

import QGroundControl
import QGroundControl.Controls

// FlyView에서 어떤 계기판을 표시할지 선택
SelectableControl { // QGC에서 정의한 커스텀 UI 컨트롤
    z:                      QGroundControl.zOrderWidgets
    selectionUIRightAnchor: true
    // 선택한 계기판 QML 파일의 경로를 나타내는 값
    selectedControl:        QGroundControl.settingsManager.flyViewSettings.instrumentQmlFile

    property var  missionController:    _missionController
    property real extraInset:           innerControl.extraInset
    property real extraValuesWidth:     innerControl.extraValuesWidth
}
