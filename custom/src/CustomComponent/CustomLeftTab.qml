import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QGroundControl.Palette
import QGroundControl.ScreenTools

import "qrc:/custom/qml/CustomComponent"

Rectangle {
    id: leftTab
    property int currentTabIndex: 0
    property var contentLoader

    signal closeToggleRequested()

    width: ScreenTools.defaultFontPixelWidth * 25
    color: "#292929"
    anchors.left: parent.left
    anchors.bottom: parent.bottom

    ColumnLayout {
        anchors.fill: parent
        anchors.topMargin: ScreenTools.defaultFontPointSize * 1
        spacing: 0

        property int currentTabIndex: 0

        // 첫 번째 메뉴: Flight Status
        Label {
            id: firstMenu
            font.family: "Pretendard"
            font.weight: Font.DemiBold
            text: "Flight Status"
            color: "white"
            font.pixelSize: 20

            Layout.leftMargin: ScreenTools.defaultFontPointSize * 2.5
            Layout.topMargin: ScreenTools.defaultFontPointSize * 2
        }

        // 구분선
        Rectangle {
            width: parent.width
            height: 1 // 선의 두께
            color: "#848484"
            Layout.topMargin: ScreenTools.defaultFontPixelHeight
            Layout.bottomMargin: ScreenTools.defaultFontPointSize * 0.1
        }

        // 하위 버튼 1
        CustomLeftTabButton {
            labelText: "Propulsion / Power"
            iconSource: "qrc:/custom/icon/Propulsion_power_ico.svg"
            active: globals.isInCustomTabView && leftTab.currentTabIndex === 0
            onClicked: {
                leftTab.currentTabIndex = 0;
                if(globals.isInCustomTabView) {
                    contentLoader.source = customTabViewRoot.tabSources[leftTab.currentTabIndex];
                } else {
                    mainWindow.showCustomTabView(leftTab.currentTabIndex)
                }
            }
        }

        // 하위 버튼 2
        CustomLeftTabButton {
            labelText: "Control"
            iconSource: "qrc:/custom/icon/Control_ico.svg"
            active: globals.isInCustomTabView && leftTab.currentTabIndex === 1
            onClicked: {
                leftTab.currentTabIndex = 1;
                if(globals.isInCustomTabView) {
                    contentLoader.source = customTabViewRoot.tabSources[leftTab.currentTabIndex];
                } else {
                    mainWindow.showCustomTabView(leftTab.currentTabIndex)
                }
            }
        }

        // 두 번째 메뉴: Vehicle Configuration
        Label {
            font.family: "Pretendard"
            font.weight: Font.DemiBold
            text: "Vehicle\nConfiguration"
            color: "white"
            font.pixelSize: 20
            Layout.leftMargin: ScreenTools.defaultFontPointSize * 2.5
            Layout.topMargin: ScreenTools.defaultFontPointSize * 5
        }

        // 구분선
        Rectangle {
            width: parent.width
            height: 1
            color: "#6c6c6c"
            Layout.topMargin: ScreenTools.defaultFontPixelHeight
            Layout.bottomMargin: ScreenTools.defaultFontPointSize * 0.1
        }

        // 하위 버튼 3
        CustomLeftTabButton {
            labelText: "General"
            iconSource: "qrc:/custom/icon/General_ico.svg"
            active: globals.isInCustomTabView && leftTab.currentTabIndex === 2
            onClicked: {
                leftTab.currentTabIndex = 2;
                if(globals.isInCustomTabView) {
                    contentLoader.source = customTabViewRoot.tabSources[leftTab.currentTabIndex];
                } else {
                    mainWindow.showCustomTabView(leftTab.currentTabIndex)
                }
            }
        }

        // 하위 버튼 4
        CustomLeftTabButton {
            labelText: "Propulsion / Power"
            iconSource: "qrc:/custom/icon/Propulsion_power_ico.svg"
            active: globals.isInCustomTabView && leftTab.currentTabIndex === 3
            onClicked: {
                leftTab.currentTabIndex = 3;
                if(globals.isInCustomTabView) {
                    contentLoader.source = customTabViewRoot.tabSources[leftTab.currentTabIndex];
                } else {
                    mainWindow.showCustomTabView(leftTab.currentTabIndex)
                }
            }
        }

        // 하위 버튼 5
        CustomLeftTabButton {
            labelText: "Control"
            iconSource: "qrc:/custom/icon/Control_ico.svg"
            active: globals.isInCustomTabView && leftTab.currentTabIndex === 4
            onClicked: {
                leftTab.currentTabIndex = 4;
                if(globals.isInCustomTabView) {
                    contentLoader.source = customTabViewRoot.tabSources[leftTab.currentTabIndex];
                } else {
                    mainWindow.showCustomTabView(leftTab.currentTabIndex)
                }
            }
        }

        Item {
            Layout.fillHeight: true // 남는 세로 공간을 모두 차지
        }

        // CustomRoundButton과 그 마진을 포함하는 컨테이너
        Item {
            id: bottomContainer
            Layout.fillWidth: true
            // 버튼 높이를 기준으로 아이템 높이 설정
            Layout.preferredHeight: mainPageButton.implicitHeight
            Layout.bottomMargin: ScreenTools.defaultFontPointSize * 5

            CustomRoundButton {
                id: mainPageButton
                iconSource: "qrc:/custom/icon/Main_page_ico.svg"
                labelText: "Main"

                anchors.right: customToggleButton.left
                anchors.rightMargin: ScreenTools.defaultFontPixelWidth * 2
                anchors.verticalCenter: parent.verticalCenter
                visible: globals.isInCustomTabView
                
                onClicked: {
                    mainWindow.showFlyView()
                }
            }

            CustomToggleButton {
                id: customToggleButton
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                anchors.rightMargin: ScreenTools.defaultFontPointSize * 2
                isOpened: true

                onClicked: {
                    closeToggleRequested()
                }
            }
        }
    }
}

