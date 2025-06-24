/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import QtQml

import QGroundControl.Templates as T
import QGroundControl.Controls
import QGroundControl.ScreenTools
import QGroundControl.Controllers
import QGroundControl.Palette
import QGroundControl.FlightMap
import QGroundControl

// HorizontalFactValueGrid 템플릿이 내부적으로 Fact 객체를 관리하는 데이터 모델을 가지고 있음
T.HorizontalFactValueGrid { 
    id:                     _root
    Layout.preferredWidth:  topLayout.width
    Layout.preferredHeight: topLayout.height

    property bool   settingsUnlocked:       false

    property real   _margins:               ScreenTools.defaultFontPixelWidth / 2
    property int    _rowMax:                2
    property real   _rowButtonWidth:        ScreenTools.minTouchPixels
    property real   _rowButtonHeight:       ScreenTools.minTouchPixels / 2
    property real   _editButtonSpacing:     2

    QGCPalette { id: qgcPal; colorGroupEnabled: enabled }

    ColumnLayout {
        id:         topLayout
        spacing:    ScreenTools.defaultFontPixelWidth

        RowLayout {
            spacing: parent.spacing
            RowLayout {
                id:         labelValueColumnLayout
                spacing:    ScreenTools.defaultFontPixelWidth * 1.25

                Repeater {
                    // 자신이 가지고 있는 columns라는 이름의 model 참조
                    model: _root.columns // Fact 객체들의 목록

                    GridLayout {
                        rows:           object.count
                        columns:        2
                        rowSpacing:     0
                        columnSpacing:  ScreenTools.defaultFontPixelWidth / 4
                        flow:           GridLayout.TopToBottom

                        // 각 열 내부에서 InstrumentValueLabel과 InstrumentValueValue가
                        // 한 쌍으로 표시됨
                        // InstrumentValueLabel : e.g. "roll"
                        // InstrumentValueValue : e.g. "12.3 deg"
                        Repeater {
                            id:     labelRepeater
                            model:  object // 상위 Repeater의 현재 항목

                            // Fact의 이름을 표시하는 QML 컴포넌트
                            // e.g. roll, pitch
                            InstrumentValueLabel {
                                Layout.fillHeight:      true
                                Layout.alignment:       Qt.AlignRight
                                // labelRepeater의 현재 항목
                                instrumentValueData:    object
                            }
                        }

                        Repeater {
                            id:     valueRepeater
                            model:  object // 상위 repeater의 현재 항목

                            property real   _index:     index
                            property real   maxWidth:   0
                            property var    lastCheck:  new Date().getTime()

                            function recalcWidth() {
                                var newMaxWidth = 0
                                for (var i=0; i<valueRepeater.count; i++) {
                                    newMaxWidth = Math.max(newMaxWidth, valueRepeater.itemAt(i).contentWidth)
                                }
                                maxWidth = Math.min(maxWidth, newMaxWidth)
                            }

                            // Fact의 실제 값을 표시하는 QML
                            InstrumentValueValue {
                                Layout.fillHeight:      true
                                Layout.alignment:       Qt.AlignLeft
                                Layout.preferredWidth:  valueRepeater.maxWidth
                                // valueRepeater의 현재 항목
                                instrumentValueData:    object

                                property real lastContentWidth

                                Component.onCompleted:  {
                                    valueRepeater.maxWidth = Math.max(valueRepeater.maxWidth, contentWidth)
                                    lastContentWidth = contentWidth
                                }

                                onContentWidthChanged: {
                                    valueRepeater.maxWidth = Math.max(valueRepeater.maxWidth, contentWidth)
                                    lastContentWidth = contentWidth
                                    var currentTime = new Date().getTime()
                                    if (currentTime - valueRepeater.lastCheck > 30 * 1000) {
                                        valueRepeater.lastCheck = currentTime
                                        valueRepeater.recalcWidth()
                                    }
                                }
                            }
                        }
                    }
                }
            }

            ColumnLayout {
                spacing: 1
                visible: settingsUnlocked

                QGCButton {
                    Layout.preferredWidth:  ScreenTools.minTouchPixels
                    Layout.fillHeight:      true
                    topPadding:             0                
                    bottomPadding:          0
                    leftPadding:            0
                    rightPadding:           0
                    text:                   qsTr("+")
                    enabled:                (_root.width + (2 * (_rowButtonWidth + _margins))) < screen.width
                    onClicked:              appendColumn()
                }

                QGCButton {
                    Layout.preferredWidth:  ScreenTools.minTouchPixels
                    Layout.fillHeight:      true
                    topPadding:             0                
                    bottomPadding:          0
                    leftPadding:            0
                    rightPadding:           0
                    text:                   qsTr("-")
                    enabled:                _root.columns.count > 1
                    onClicked:              deleteLastColumn()
                }
            }
        }

        RowLayout {
            Layout.fillWidth:   true
            spacing:            1
            visible:            settingsUnlocked

            QGCButton {
                Layout.fillWidth:       true
                Layout.preferredHeight: ScreenTools.minTouchPixels
                topPadding:             0                
                bottomPadding:          0
                leftPadding:            0
                rightPadding:           0
                text:                   qsTr("+")
                enabled:                (_root.height + (2 * (_rowButtonHeight + _margins))) < (screen.height - ScreenTools.toolbarHeight)
                onClicked:              appendRow()
            }

            QGCButton {
                Layout.fillWidth:       true
                Layout.preferredHeight: parent.height
                topPadding:             0                
                bottomPadding:          0
                leftPadding:            0
                rightPadding:           0
                text:                   qsTr("-")
                enabled:                _root.rowCount > 1
                onClicked:              deleteLastRow()
            }
        }
    }

    QGCMouseArea {
        x:          labelValueColumnLayout.x
        y:          labelValueColumnLayout.y
        width:      labelValueColumnLayout.width
        height:     labelValueColumnLayout.height
        visible:    settingsUnlocked
        cursorShape:Qt.PointingHandCursor

        property var mappedLabelValueColumnLayoutPosition: _root.mapFromItem(labelValueColumnLayout, labelValueColumnLayout.x, labelValueColumnLayout.y)

        onClicked: (mouse) => {
            var columnGridLayoutItem = labelValueColumnLayout.childAt(mouse.x, mouse.y)
            //console.log(mouse.x, mouse.y, columnGridLayoutItem)
            var mappedMouse = labelValueColumnLayout.mapToItem(columnGridLayoutItem, mouse.x, mouse.y)
            var labelOrDataItem = columnGridLayoutItem.childAt(mappedMouse.x, mappedMouse.y)
            console.log(mappedMouse.x, mappedMouse.y, labelOrDataItem, labelOrDataItem ? labelOrDataItem.instrumentValueData : "null", labelOrDataItem && labelOrDataItem.parent ? labelOrDataItem.parent.instrumentValueData : "null")

            // 클릭된 데이터의 속성 값을 팝업창에 넘겨줌
            if (labelOrDataItem && labelOrDataItem.instrumentValueData !== undefined) {
                valueEditDialog.createObject(mainWindow, { instrumentValueData: labelOrDataItem.instrumentValueData }).open()
            }
        }
    }

    Component {
        id: valueEditDialog
        // 각 항목 더블클릭 시 뜨게 되는 팝업 컴포넌트
        InstrumentValueEditDialog { }
    }
}
