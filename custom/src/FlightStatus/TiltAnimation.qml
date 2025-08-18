import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs
import Qt5Compat.GraphicalEffects
import QtQuick.Shapes

import QGroundControl
import QGroundControl.Controls
import QGroundControl.Palette
import QGroundControl.MultiVehicleManager
import QGroundControl.ScreenTools
import QGroundControl.Controllers

Item {
    id: tiltAnim

    property int lineWidth: 3
    property real angle: 0
    property real defaultRadius: width * 0.5 - lineWidth // 기준 반지름
    //property int angleIncrement: 5

    readonly property real progress: Math.abs(angle) / 90
    readonly property bool isAngleNegative: angle < 0
    readonly property bool isAngleOutlier: angle >= 100 || angle <= -100
    
    onAngleChanged: {
        ellipseCanvas.requestPaint()
    }

    /**
    Timer {
        interval: 100
        running: true
        repeat: true
        onTriggered: {
            tiltAnim.angle += tiltAnim.angleIncrement
        
            // 각도가 90도를 넘어가면 감소 방향으로 전환
            if (tiltAnim.angle >= 90) {
                tiltAnim.angleIncrement = -5
            } 
            // 각도가 -90도보다 작아지면 증가 방향으로 전환
            else if (tiltAnim.angle <= -90) {
                tiltAnim.angleIncrement = 5
            }
        }
    }
    **/

    function getColorByAngle() {
        if(isAngleOutlier) {
            return qgcPal.warningText
        } else if(isAngleNegative) {
            return customPal.lightGray
        } else {
            return qgcPal.text
        }
    }

    Canvas {
        id: ellipseCanvas
        anchors.fill: parent
        renderTarget: Canvas.Image

        onPaint: {
            var ctx = getContext("2d")
            ctx.clearRect(0, 0, width, height)

            var centerX = width / 2
            var centerY = height / 2
            var adjustedAngle

            if (tiltAnim.isAngleOutlier) {
                if (tiltAnim.isAngleNegative) {
                    adjustedAngle = -90
                } else {
                    adjustedAngle = 90
                }
            } else {
                adjustedAngle = tiltAnim.angle
            }

            // 타원의 가로/세로 반지름 계산 (코사인, 사인 기반으로 찌그러짐 표현)
            var rad = Math.abs(adjustedAngle) * Math.PI / 180
            var ratio = Math.cos(rad)

            var radiusX = tiltAnim.defaultRadius
            var radiusY = tiltAnim.defaultRadius * ratio

            var yOffset = tiltAnim.defaultRadius * tiltAnim.progress

            // 1. 선 (막대)
            ctx.beginPath()
            ctx.moveTo(centerX, lineWidth)
            ctx.lineTo(centerX, height - lineWidth)
            ctx.strokeStyle = tiltAnim.getColorByAngle()
            ctx.lineWidth = lineWidth
            ctx.stroke()

            // 2. 타원
            ctx.beginPath()
            //ctx.lineWidth = 1
            if (tiltAnim.isAngleNegative) {
                ctx.ellipse(centerX - tiltAnim.defaultRadius, height - Math.abs(radiusY) * 2 - lineWidth, radiusX * 2, Math.abs(radiusY) * 2, 0, 0, 2 * Math.PI)
            } else {
                ctx.ellipse(centerX - tiltAnim.defaultRadius, lineWidth, radiusX * 2, Math.abs(radiusY) * 2, 0, 0, 2 * Math.PI)
            }

            ctx.fillStyle = tiltAnim.getColorByAngle()
            ctx.fill()
            ctx.strokeStyle = tiltAnim.getColorByAngle()
            ctx.stroke()
        }
    }
}