#pragma once
// MESSAGE ESC_HBCI_MONITOR PACKING

#define MAVLINK_MSG_ID_ESC_HBCI_MONITOR 515


typedef struct __mavlink_esc_hbci_monitor_t {
 uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
 float voltage_fl; /*< [V] Front left voltage*/
 float voltage_fr; /*< [V] Front right voltage*/
 float voltage_rl; /*< [V] Rear left voltage*/
 float voltage_rr; /*< [V] Rear right voltage*/
 float current_fl; /*< [A] Front left current*/
 float current_fr; /*< [A] Front right current*/
 float current_rl; /*< [A] Rear left current*/
 float current_rr; /*< [A] Rear right current*/
 int32_t rpm_fl; /*< [RPM] Front left RPM*/
 int32_t rpm_fr; /*< [RPM] Front right RPM*/
 int32_t rpm_rl; /*< [RPM] Rear left RPM*/
 int32_t rpm_rr; /*< [RPM] Rear right RPM*/
 int32_t motor_temper_fl; /*< [degC] Front left motor temperature*/
 int32_t motor_temper_fr; /*< [degC] Front right motor temperature*/
 int32_t motor_temper_rl; /*< [degC] Rear left motor temperature*/
 int32_t motor_temper_rr; /*< [degC] Rear right motor temperature*/
 int32_t esc_temper_fl; /*< [degC] Front left ESC temperature*/
 int32_t esc_temper_fr; /*< [degC] Front right ESC temperature*/
 int32_t esc_temper_rl; /*< [degC] Rear left ESC temperature*/
 int32_t esc_temper_rr; /*< [degC] Rear right ESC temperature*/
 float output_pwm_fl; /*< [%] Front left output PWM*/
 float output_pwm_fr; /*< [%] Front right output PWM*/
 float output_pwm_rl; /*< [%] Rear left output PWM*/
 float output_pwm_rr; /*< [%] Rear right output PWM*/
 float input_pwm_fl; /*< [%] Front left input PWM*/
 float input_pwm_fr; /*< [%] Front right input PWM*/
 float input_pwm_rl; /*< [%] Rear left input PWM*/
 float input_pwm_rr; /*< [%] Rear right input PWM*/
} mavlink_esc_hbci_monitor_t;

#define MAVLINK_MSG_ID_ESC_HBCI_MONITOR_LEN 116
#define MAVLINK_MSG_ID_ESC_HBCI_MONITOR_MIN_LEN 116
#define MAVLINK_MSG_ID_515_LEN 116
#define MAVLINK_MSG_ID_515_MIN_LEN 116

#define MAVLINK_MSG_ID_ESC_HBCI_MONITOR_CRC 205
#define MAVLINK_MSG_ID_515_CRC 205



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ESC_HBCI_MONITOR { \
    515, \
    "ESC_HBCI_MONITOR", \
    29, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_esc_hbci_monitor_t, time_boot_ms) }, \
         { "voltage_fl", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_esc_hbci_monitor_t, voltage_fl) }, \
         { "voltage_fr", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_esc_hbci_monitor_t, voltage_fr) }, \
         { "voltage_rl", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_esc_hbci_monitor_t, voltage_rl) }, \
         { "voltage_rr", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_esc_hbci_monitor_t, voltage_rr) }, \
         { "current_fl", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_esc_hbci_monitor_t, current_fl) }, \
         { "current_fr", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_esc_hbci_monitor_t, current_fr) }, \
         { "current_rl", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_esc_hbci_monitor_t, current_rl) }, \
         { "current_rr", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_esc_hbci_monitor_t, current_rr) }, \
         { "rpm_fl", NULL, MAVLINK_TYPE_INT32_T, 0, 36, offsetof(mavlink_esc_hbci_monitor_t, rpm_fl) }, \
         { "rpm_fr", NULL, MAVLINK_TYPE_INT32_T, 0, 40, offsetof(mavlink_esc_hbci_monitor_t, rpm_fr) }, \
         { "rpm_rl", NULL, MAVLINK_TYPE_INT32_T, 0, 44, offsetof(mavlink_esc_hbci_monitor_t, rpm_rl) }, \
         { "rpm_rr", NULL, MAVLINK_TYPE_INT32_T, 0, 48, offsetof(mavlink_esc_hbci_monitor_t, rpm_rr) }, \
         { "motor_temper_fl", NULL, MAVLINK_TYPE_INT32_T, 0, 52, offsetof(mavlink_esc_hbci_monitor_t, motor_temper_fl) }, \
         { "motor_temper_fr", NULL, MAVLINK_TYPE_INT32_T, 0, 56, offsetof(mavlink_esc_hbci_monitor_t, motor_temper_fr) }, \
         { "motor_temper_rl", NULL, MAVLINK_TYPE_INT32_T, 0, 60, offsetof(mavlink_esc_hbci_monitor_t, motor_temper_rl) }, \
         { "motor_temper_rr", NULL, MAVLINK_TYPE_INT32_T, 0, 64, offsetof(mavlink_esc_hbci_monitor_t, motor_temper_rr) }, \
         { "esc_temper_fl", NULL, MAVLINK_TYPE_INT32_T, 0, 68, offsetof(mavlink_esc_hbci_monitor_t, esc_temper_fl) }, \
         { "esc_temper_fr", NULL, MAVLINK_TYPE_INT32_T, 0, 72, offsetof(mavlink_esc_hbci_monitor_t, esc_temper_fr) }, \
         { "esc_temper_rl", NULL, MAVLINK_TYPE_INT32_T, 0, 76, offsetof(mavlink_esc_hbci_monitor_t, esc_temper_rl) }, \
         { "esc_temper_rr", NULL, MAVLINK_TYPE_INT32_T, 0, 80, offsetof(mavlink_esc_hbci_monitor_t, esc_temper_rr) }, \
         { "output_pwm_fl", NULL, MAVLINK_TYPE_FLOAT, 0, 84, offsetof(mavlink_esc_hbci_monitor_t, output_pwm_fl) }, \
         { "output_pwm_fr", NULL, MAVLINK_TYPE_FLOAT, 0, 88, offsetof(mavlink_esc_hbci_monitor_t, output_pwm_fr) }, \
         { "output_pwm_rl", NULL, MAVLINK_TYPE_FLOAT, 0, 92, offsetof(mavlink_esc_hbci_monitor_t, output_pwm_rl) }, \
         { "output_pwm_rr", NULL, MAVLINK_TYPE_FLOAT, 0, 96, offsetof(mavlink_esc_hbci_monitor_t, output_pwm_rr) }, \
         { "input_pwm_fl", NULL, MAVLINK_TYPE_FLOAT, 0, 100, offsetof(mavlink_esc_hbci_monitor_t, input_pwm_fl) }, \
         { "input_pwm_fr", NULL, MAVLINK_TYPE_FLOAT, 0, 104, offsetof(mavlink_esc_hbci_monitor_t, input_pwm_fr) }, \
         { "input_pwm_rl", NULL, MAVLINK_TYPE_FLOAT, 0, 108, offsetof(mavlink_esc_hbci_monitor_t, input_pwm_rl) }, \
         { "input_pwm_rr", NULL, MAVLINK_TYPE_FLOAT, 0, 112, offsetof(mavlink_esc_hbci_monitor_t, input_pwm_rr) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ESC_HBCI_MONITOR { \
    "ESC_HBCI_MONITOR", \
    29, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_esc_hbci_monitor_t, time_boot_ms) }, \
         { "voltage_fl", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_esc_hbci_monitor_t, voltage_fl) }, \
         { "voltage_fr", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_esc_hbci_monitor_t, voltage_fr) }, \
         { "voltage_rl", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_esc_hbci_monitor_t, voltage_rl) }, \
         { "voltage_rr", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_esc_hbci_monitor_t, voltage_rr) }, \
         { "current_fl", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_esc_hbci_monitor_t, current_fl) }, \
         { "current_fr", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_esc_hbci_monitor_t, current_fr) }, \
         { "current_rl", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_esc_hbci_monitor_t, current_rl) }, \
         { "current_rr", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_esc_hbci_monitor_t, current_rr) }, \
         { "rpm_fl", NULL, MAVLINK_TYPE_INT32_T, 0, 36, offsetof(mavlink_esc_hbci_monitor_t, rpm_fl) }, \
         { "rpm_fr", NULL, MAVLINK_TYPE_INT32_T, 0, 40, offsetof(mavlink_esc_hbci_monitor_t, rpm_fr) }, \
         { "rpm_rl", NULL, MAVLINK_TYPE_INT32_T, 0, 44, offsetof(mavlink_esc_hbci_monitor_t, rpm_rl) }, \
         { "rpm_rr", NULL, MAVLINK_TYPE_INT32_T, 0, 48, offsetof(mavlink_esc_hbci_monitor_t, rpm_rr) }, \
         { "motor_temper_fl", NULL, MAVLINK_TYPE_INT32_T, 0, 52, offsetof(mavlink_esc_hbci_monitor_t, motor_temper_fl) }, \
         { "motor_temper_fr", NULL, MAVLINK_TYPE_INT32_T, 0, 56, offsetof(mavlink_esc_hbci_monitor_t, motor_temper_fr) }, \
         { "motor_temper_rl", NULL, MAVLINK_TYPE_INT32_T, 0, 60, offsetof(mavlink_esc_hbci_monitor_t, motor_temper_rl) }, \
         { "motor_temper_rr", NULL, MAVLINK_TYPE_INT32_T, 0, 64, offsetof(mavlink_esc_hbci_monitor_t, motor_temper_rr) }, \
         { "esc_temper_fl", NULL, MAVLINK_TYPE_INT32_T, 0, 68, offsetof(mavlink_esc_hbci_monitor_t, esc_temper_fl) }, \
         { "esc_temper_fr", NULL, MAVLINK_TYPE_INT32_T, 0, 72, offsetof(mavlink_esc_hbci_monitor_t, esc_temper_fr) }, \
         { "esc_temper_rl", NULL, MAVLINK_TYPE_INT32_T, 0, 76, offsetof(mavlink_esc_hbci_monitor_t, esc_temper_rl) }, \
         { "esc_temper_rr", NULL, MAVLINK_TYPE_INT32_T, 0, 80, offsetof(mavlink_esc_hbci_monitor_t, esc_temper_rr) }, \
         { "output_pwm_fl", NULL, MAVLINK_TYPE_FLOAT, 0, 84, offsetof(mavlink_esc_hbci_monitor_t, output_pwm_fl) }, \
         { "output_pwm_fr", NULL, MAVLINK_TYPE_FLOAT, 0, 88, offsetof(mavlink_esc_hbci_monitor_t, output_pwm_fr) }, \
         { "output_pwm_rl", NULL, MAVLINK_TYPE_FLOAT, 0, 92, offsetof(mavlink_esc_hbci_monitor_t, output_pwm_rl) }, \
         { "output_pwm_rr", NULL, MAVLINK_TYPE_FLOAT, 0, 96, offsetof(mavlink_esc_hbci_monitor_t, output_pwm_rr) }, \
         { "input_pwm_fl", NULL, MAVLINK_TYPE_FLOAT, 0, 100, offsetof(mavlink_esc_hbci_monitor_t, input_pwm_fl) }, \
         { "input_pwm_fr", NULL, MAVLINK_TYPE_FLOAT, 0, 104, offsetof(mavlink_esc_hbci_monitor_t, input_pwm_fr) }, \
         { "input_pwm_rl", NULL, MAVLINK_TYPE_FLOAT, 0, 108, offsetof(mavlink_esc_hbci_monitor_t, input_pwm_rl) }, \
         { "input_pwm_rr", NULL, MAVLINK_TYPE_FLOAT, 0, 112, offsetof(mavlink_esc_hbci_monitor_t, input_pwm_rr) }, \
         } \
}
#endif

/**
 * @brief Pack a esc_hbci_monitor message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param voltage_fl [V] Front left voltage
 * @param voltage_fr [V] Front right voltage
 * @param voltage_rl [V] Rear left voltage
 * @param voltage_rr [V] Rear right voltage
 * @param current_fl [A] Front left current
 * @param current_fr [A] Front right current
 * @param current_rl [A] Rear left current
 * @param current_rr [A] Rear right current
 * @param rpm_fl [RPM] Front left RPM
 * @param rpm_fr [RPM] Front right RPM
 * @param rpm_rl [RPM] Rear left RPM
 * @param rpm_rr [RPM] Rear right RPM
 * @param motor_temper_fl [degC] Front left motor temperature
 * @param motor_temper_fr [degC] Front right motor temperature
 * @param motor_temper_rl [degC] Rear left motor temperature
 * @param motor_temper_rr [degC] Rear right motor temperature
 * @param esc_temper_fl [degC] Front left ESC temperature
 * @param esc_temper_fr [degC] Front right ESC temperature
 * @param esc_temper_rl [degC] Rear left ESC temperature
 * @param esc_temper_rr [degC] Rear right ESC temperature
 * @param output_pwm_fl [%] Front left output PWM
 * @param output_pwm_fr [%] Front right output PWM
 * @param output_pwm_rl [%] Rear left output PWM
 * @param output_pwm_rr [%] Rear right output PWM
 * @param input_pwm_fl [%] Front left input PWM
 * @param input_pwm_fr [%] Front right input PWM
 * @param input_pwm_rl [%] Rear left input PWM
 * @param input_pwm_rr [%] Rear right input PWM
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_esc_hbci_monitor_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, float voltage_fl, float voltage_fr, float voltage_rl, float voltage_rr, float current_fl, float current_fr, float current_rl, float current_rr, int32_t rpm_fl, int32_t rpm_fr, int32_t rpm_rl, int32_t rpm_rr, int32_t motor_temper_fl, int32_t motor_temper_fr, int32_t motor_temper_rl, int32_t motor_temper_rr, int32_t esc_temper_fl, int32_t esc_temper_fr, int32_t esc_temper_rl, int32_t esc_temper_rr, float output_pwm_fl, float output_pwm_fr, float output_pwm_rl, float output_pwm_rr, float input_pwm_fl, float input_pwm_fr, float input_pwm_rl, float input_pwm_rr)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESC_HBCI_MONITOR_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, voltage_fl);
    _mav_put_float(buf, 8, voltage_fr);
    _mav_put_float(buf, 12, voltage_rl);
    _mav_put_float(buf, 16, voltage_rr);
    _mav_put_float(buf, 20, current_fl);
    _mav_put_float(buf, 24, current_fr);
    _mav_put_float(buf, 28, current_rl);
    _mav_put_float(buf, 32, current_rr);
    _mav_put_int32_t(buf, 36, rpm_fl);
    _mav_put_int32_t(buf, 40, rpm_fr);
    _mav_put_int32_t(buf, 44, rpm_rl);
    _mav_put_int32_t(buf, 48, rpm_rr);
    _mav_put_int32_t(buf, 52, motor_temper_fl);
    _mav_put_int32_t(buf, 56, motor_temper_fr);
    _mav_put_int32_t(buf, 60, motor_temper_rl);
    _mav_put_int32_t(buf, 64, motor_temper_rr);
    _mav_put_int32_t(buf, 68, esc_temper_fl);
    _mav_put_int32_t(buf, 72, esc_temper_fr);
    _mav_put_int32_t(buf, 76, esc_temper_rl);
    _mav_put_int32_t(buf, 80, esc_temper_rr);
    _mav_put_float(buf, 84, output_pwm_fl);
    _mav_put_float(buf, 88, output_pwm_fr);
    _mav_put_float(buf, 92, output_pwm_rl);
    _mav_put_float(buf, 96, output_pwm_rr);
    _mav_put_float(buf, 100, input_pwm_fl);
    _mav_put_float(buf, 104, input_pwm_fr);
    _mav_put_float(buf, 108, input_pwm_rl);
    _mav_put_float(buf, 112, input_pwm_rr);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_LEN);
#else
    mavlink_esc_hbci_monitor_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.voltage_fl = voltage_fl;
    packet.voltage_fr = voltage_fr;
    packet.voltage_rl = voltage_rl;
    packet.voltage_rr = voltage_rr;
    packet.current_fl = current_fl;
    packet.current_fr = current_fr;
    packet.current_rl = current_rl;
    packet.current_rr = current_rr;
    packet.rpm_fl = rpm_fl;
    packet.rpm_fr = rpm_fr;
    packet.rpm_rl = rpm_rl;
    packet.rpm_rr = rpm_rr;
    packet.motor_temper_fl = motor_temper_fl;
    packet.motor_temper_fr = motor_temper_fr;
    packet.motor_temper_rl = motor_temper_rl;
    packet.motor_temper_rr = motor_temper_rr;
    packet.esc_temper_fl = esc_temper_fl;
    packet.esc_temper_fr = esc_temper_fr;
    packet.esc_temper_rl = esc_temper_rl;
    packet.esc_temper_rr = esc_temper_rr;
    packet.output_pwm_fl = output_pwm_fl;
    packet.output_pwm_fr = output_pwm_fr;
    packet.output_pwm_rl = output_pwm_rl;
    packet.output_pwm_rr = output_pwm_rr;
    packet.input_pwm_fl = input_pwm_fl;
    packet.input_pwm_fr = input_pwm_fr;
    packet.input_pwm_rl = input_pwm_rl;
    packet.input_pwm_rr = input_pwm_rr;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ESC_HBCI_MONITOR;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_MIN_LEN, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_LEN, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_CRC);
}

/**
 * @brief Pack a esc_hbci_monitor message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param voltage_fl [V] Front left voltage
 * @param voltage_fr [V] Front right voltage
 * @param voltage_rl [V] Rear left voltage
 * @param voltage_rr [V] Rear right voltage
 * @param current_fl [A] Front left current
 * @param current_fr [A] Front right current
 * @param current_rl [A] Rear left current
 * @param current_rr [A] Rear right current
 * @param rpm_fl [RPM] Front left RPM
 * @param rpm_fr [RPM] Front right RPM
 * @param rpm_rl [RPM] Rear left RPM
 * @param rpm_rr [RPM] Rear right RPM
 * @param motor_temper_fl [degC] Front left motor temperature
 * @param motor_temper_fr [degC] Front right motor temperature
 * @param motor_temper_rl [degC] Rear left motor temperature
 * @param motor_temper_rr [degC] Rear right motor temperature
 * @param esc_temper_fl [degC] Front left ESC temperature
 * @param esc_temper_fr [degC] Front right ESC temperature
 * @param esc_temper_rl [degC] Rear left ESC temperature
 * @param esc_temper_rr [degC] Rear right ESC temperature
 * @param output_pwm_fl [%] Front left output PWM
 * @param output_pwm_fr [%] Front right output PWM
 * @param output_pwm_rl [%] Rear left output PWM
 * @param output_pwm_rr [%] Rear right output PWM
 * @param input_pwm_fl [%] Front left input PWM
 * @param input_pwm_fr [%] Front right input PWM
 * @param input_pwm_rl [%] Rear left input PWM
 * @param input_pwm_rr [%] Rear right input PWM
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_esc_hbci_monitor_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t time_boot_ms, float voltage_fl, float voltage_fr, float voltage_rl, float voltage_rr, float current_fl, float current_fr, float current_rl, float current_rr, int32_t rpm_fl, int32_t rpm_fr, int32_t rpm_rl, int32_t rpm_rr, int32_t motor_temper_fl, int32_t motor_temper_fr, int32_t motor_temper_rl, int32_t motor_temper_rr, int32_t esc_temper_fl, int32_t esc_temper_fr, int32_t esc_temper_rl, int32_t esc_temper_rr, float output_pwm_fl, float output_pwm_fr, float output_pwm_rl, float output_pwm_rr, float input_pwm_fl, float input_pwm_fr, float input_pwm_rl, float input_pwm_rr)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESC_HBCI_MONITOR_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, voltage_fl);
    _mav_put_float(buf, 8, voltage_fr);
    _mav_put_float(buf, 12, voltage_rl);
    _mav_put_float(buf, 16, voltage_rr);
    _mav_put_float(buf, 20, current_fl);
    _mav_put_float(buf, 24, current_fr);
    _mav_put_float(buf, 28, current_rl);
    _mav_put_float(buf, 32, current_rr);
    _mav_put_int32_t(buf, 36, rpm_fl);
    _mav_put_int32_t(buf, 40, rpm_fr);
    _mav_put_int32_t(buf, 44, rpm_rl);
    _mav_put_int32_t(buf, 48, rpm_rr);
    _mav_put_int32_t(buf, 52, motor_temper_fl);
    _mav_put_int32_t(buf, 56, motor_temper_fr);
    _mav_put_int32_t(buf, 60, motor_temper_rl);
    _mav_put_int32_t(buf, 64, motor_temper_rr);
    _mav_put_int32_t(buf, 68, esc_temper_fl);
    _mav_put_int32_t(buf, 72, esc_temper_fr);
    _mav_put_int32_t(buf, 76, esc_temper_rl);
    _mav_put_int32_t(buf, 80, esc_temper_rr);
    _mav_put_float(buf, 84, output_pwm_fl);
    _mav_put_float(buf, 88, output_pwm_fr);
    _mav_put_float(buf, 92, output_pwm_rl);
    _mav_put_float(buf, 96, output_pwm_rr);
    _mav_put_float(buf, 100, input_pwm_fl);
    _mav_put_float(buf, 104, input_pwm_fr);
    _mav_put_float(buf, 108, input_pwm_rl);
    _mav_put_float(buf, 112, input_pwm_rr);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_LEN);
#else
    mavlink_esc_hbci_monitor_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.voltage_fl = voltage_fl;
    packet.voltage_fr = voltage_fr;
    packet.voltage_rl = voltage_rl;
    packet.voltage_rr = voltage_rr;
    packet.current_fl = current_fl;
    packet.current_fr = current_fr;
    packet.current_rl = current_rl;
    packet.current_rr = current_rr;
    packet.rpm_fl = rpm_fl;
    packet.rpm_fr = rpm_fr;
    packet.rpm_rl = rpm_rl;
    packet.rpm_rr = rpm_rr;
    packet.motor_temper_fl = motor_temper_fl;
    packet.motor_temper_fr = motor_temper_fr;
    packet.motor_temper_rl = motor_temper_rl;
    packet.motor_temper_rr = motor_temper_rr;
    packet.esc_temper_fl = esc_temper_fl;
    packet.esc_temper_fr = esc_temper_fr;
    packet.esc_temper_rl = esc_temper_rl;
    packet.esc_temper_rr = esc_temper_rr;
    packet.output_pwm_fl = output_pwm_fl;
    packet.output_pwm_fr = output_pwm_fr;
    packet.output_pwm_rl = output_pwm_rl;
    packet.output_pwm_rr = output_pwm_rr;
    packet.input_pwm_fl = input_pwm_fl;
    packet.input_pwm_fr = input_pwm_fr;
    packet.input_pwm_rl = input_pwm_rl;
    packet.input_pwm_rr = input_pwm_rr;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ESC_HBCI_MONITOR;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_MIN_LEN, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_LEN, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_MIN_LEN, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_LEN);
#endif
}

/**
 * @brief Pack a esc_hbci_monitor message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param voltage_fl [V] Front left voltage
 * @param voltage_fr [V] Front right voltage
 * @param voltage_rl [V] Rear left voltage
 * @param voltage_rr [V] Rear right voltage
 * @param current_fl [A] Front left current
 * @param current_fr [A] Front right current
 * @param current_rl [A] Rear left current
 * @param current_rr [A] Rear right current
 * @param rpm_fl [RPM] Front left RPM
 * @param rpm_fr [RPM] Front right RPM
 * @param rpm_rl [RPM] Rear left RPM
 * @param rpm_rr [RPM] Rear right RPM
 * @param motor_temper_fl [degC] Front left motor temperature
 * @param motor_temper_fr [degC] Front right motor temperature
 * @param motor_temper_rl [degC] Rear left motor temperature
 * @param motor_temper_rr [degC] Rear right motor temperature
 * @param esc_temper_fl [degC] Front left ESC temperature
 * @param esc_temper_fr [degC] Front right ESC temperature
 * @param esc_temper_rl [degC] Rear left ESC temperature
 * @param esc_temper_rr [degC] Rear right ESC temperature
 * @param output_pwm_fl [%] Front left output PWM
 * @param output_pwm_fr [%] Front right output PWM
 * @param output_pwm_rl [%] Rear left output PWM
 * @param output_pwm_rr [%] Rear right output PWM
 * @param input_pwm_fl [%] Front left input PWM
 * @param input_pwm_fr [%] Front right input PWM
 * @param input_pwm_rl [%] Rear left input PWM
 * @param input_pwm_rr [%] Rear right input PWM
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_esc_hbci_monitor_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,float voltage_fl,float voltage_fr,float voltage_rl,float voltage_rr,float current_fl,float current_fr,float current_rl,float current_rr,int32_t rpm_fl,int32_t rpm_fr,int32_t rpm_rl,int32_t rpm_rr,int32_t motor_temper_fl,int32_t motor_temper_fr,int32_t motor_temper_rl,int32_t motor_temper_rr,int32_t esc_temper_fl,int32_t esc_temper_fr,int32_t esc_temper_rl,int32_t esc_temper_rr,float output_pwm_fl,float output_pwm_fr,float output_pwm_rl,float output_pwm_rr,float input_pwm_fl,float input_pwm_fr,float input_pwm_rl,float input_pwm_rr)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESC_HBCI_MONITOR_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, voltage_fl);
    _mav_put_float(buf, 8, voltage_fr);
    _mav_put_float(buf, 12, voltage_rl);
    _mav_put_float(buf, 16, voltage_rr);
    _mav_put_float(buf, 20, current_fl);
    _mav_put_float(buf, 24, current_fr);
    _mav_put_float(buf, 28, current_rl);
    _mav_put_float(buf, 32, current_rr);
    _mav_put_int32_t(buf, 36, rpm_fl);
    _mav_put_int32_t(buf, 40, rpm_fr);
    _mav_put_int32_t(buf, 44, rpm_rl);
    _mav_put_int32_t(buf, 48, rpm_rr);
    _mav_put_int32_t(buf, 52, motor_temper_fl);
    _mav_put_int32_t(buf, 56, motor_temper_fr);
    _mav_put_int32_t(buf, 60, motor_temper_rl);
    _mav_put_int32_t(buf, 64, motor_temper_rr);
    _mav_put_int32_t(buf, 68, esc_temper_fl);
    _mav_put_int32_t(buf, 72, esc_temper_fr);
    _mav_put_int32_t(buf, 76, esc_temper_rl);
    _mav_put_int32_t(buf, 80, esc_temper_rr);
    _mav_put_float(buf, 84, output_pwm_fl);
    _mav_put_float(buf, 88, output_pwm_fr);
    _mav_put_float(buf, 92, output_pwm_rl);
    _mav_put_float(buf, 96, output_pwm_rr);
    _mav_put_float(buf, 100, input_pwm_fl);
    _mav_put_float(buf, 104, input_pwm_fr);
    _mav_put_float(buf, 108, input_pwm_rl);
    _mav_put_float(buf, 112, input_pwm_rr);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_LEN);
#else
    mavlink_esc_hbci_monitor_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.voltage_fl = voltage_fl;
    packet.voltage_fr = voltage_fr;
    packet.voltage_rl = voltage_rl;
    packet.voltage_rr = voltage_rr;
    packet.current_fl = current_fl;
    packet.current_fr = current_fr;
    packet.current_rl = current_rl;
    packet.current_rr = current_rr;
    packet.rpm_fl = rpm_fl;
    packet.rpm_fr = rpm_fr;
    packet.rpm_rl = rpm_rl;
    packet.rpm_rr = rpm_rr;
    packet.motor_temper_fl = motor_temper_fl;
    packet.motor_temper_fr = motor_temper_fr;
    packet.motor_temper_rl = motor_temper_rl;
    packet.motor_temper_rr = motor_temper_rr;
    packet.esc_temper_fl = esc_temper_fl;
    packet.esc_temper_fr = esc_temper_fr;
    packet.esc_temper_rl = esc_temper_rl;
    packet.esc_temper_rr = esc_temper_rr;
    packet.output_pwm_fl = output_pwm_fl;
    packet.output_pwm_fr = output_pwm_fr;
    packet.output_pwm_rl = output_pwm_rl;
    packet.output_pwm_rr = output_pwm_rr;
    packet.input_pwm_fl = input_pwm_fl;
    packet.input_pwm_fr = input_pwm_fr;
    packet.input_pwm_rl = input_pwm_rl;
    packet.input_pwm_rr = input_pwm_rr;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ESC_HBCI_MONITOR;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_MIN_LEN, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_LEN, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_CRC);
}

/**
 * @brief Encode a esc_hbci_monitor struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param esc_hbci_monitor C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_esc_hbci_monitor_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_esc_hbci_monitor_t* esc_hbci_monitor)
{
    return mavlink_msg_esc_hbci_monitor_pack(system_id, component_id, msg, esc_hbci_monitor->time_boot_ms, esc_hbci_monitor->voltage_fl, esc_hbci_monitor->voltage_fr, esc_hbci_monitor->voltage_rl, esc_hbci_monitor->voltage_rr, esc_hbci_monitor->current_fl, esc_hbci_monitor->current_fr, esc_hbci_monitor->current_rl, esc_hbci_monitor->current_rr, esc_hbci_monitor->rpm_fl, esc_hbci_monitor->rpm_fr, esc_hbci_monitor->rpm_rl, esc_hbci_monitor->rpm_rr, esc_hbci_monitor->motor_temper_fl, esc_hbci_monitor->motor_temper_fr, esc_hbci_monitor->motor_temper_rl, esc_hbci_monitor->motor_temper_rr, esc_hbci_monitor->esc_temper_fl, esc_hbci_monitor->esc_temper_fr, esc_hbci_monitor->esc_temper_rl, esc_hbci_monitor->esc_temper_rr, esc_hbci_monitor->output_pwm_fl, esc_hbci_monitor->output_pwm_fr, esc_hbci_monitor->output_pwm_rl, esc_hbci_monitor->output_pwm_rr, esc_hbci_monitor->input_pwm_fl, esc_hbci_monitor->input_pwm_fr, esc_hbci_monitor->input_pwm_rl, esc_hbci_monitor->input_pwm_rr);
}

/**
 * @brief Encode a esc_hbci_monitor struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param esc_hbci_monitor C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_esc_hbci_monitor_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_esc_hbci_monitor_t* esc_hbci_monitor)
{
    return mavlink_msg_esc_hbci_monitor_pack_chan(system_id, component_id, chan, msg, esc_hbci_monitor->time_boot_ms, esc_hbci_monitor->voltage_fl, esc_hbci_monitor->voltage_fr, esc_hbci_monitor->voltage_rl, esc_hbci_monitor->voltage_rr, esc_hbci_monitor->current_fl, esc_hbci_monitor->current_fr, esc_hbci_monitor->current_rl, esc_hbci_monitor->current_rr, esc_hbci_monitor->rpm_fl, esc_hbci_monitor->rpm_fr, esc_hbci_monitor->rpm_rl, esc_hbci_monitor->rpm_rr, esc_hbci_monitor->motor_temper_fl, esc_hbci_monitor->motor_temper_fr, esc_hbci_monitor->motor_temper_rl, esc_hbci_monitor->motor_temper_rr, esc_hbci_monitor->esc_temper_fl, esc_hbci_monitor->esc_temper_fr, esc_hbci_monitor->esc_temper_rl, esc_hbci_monitor->esc_temper_rr, esc_hbci_monitor->output_pwm_fl, esc_hbci_monitor->output_pwm_fr, esc_hbci_monitor->output_pwm_rl, esc_hbci_monitor->output_pwm_rr, esc_hbci_monitor->input_pwm_fl, esc_hbci_monitor->input_pwm_fr, esc_hbci_monitor->input_pwm_rl, esc_hbci_monitor->input_pwm_rr);
}

/**
 * @brief Encode a esc_hbci_monitor struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param esc_hbci_monitor C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_esc_hbci_monitor_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_esc_hbci_monitor_t* esc_hbci_monitor)
{
    return mavlink_msg_esc_hbci_monitor_pack_status(system_id, component_id, _status, msg,  esc_hbci_monitor->time_boot_ms, esc_hbci_monitor->voltage_fl, esc_hbci_monitor->voltage_fr, esc_hbci_monitor->voltage_rl, esc_hbci_monitor->voltage_rr, esc_hbci_monitor->current_fl, esc_hbci_monitor->current_fr, esc_hbci_monitor->current_rl, esc_hbci_monitor->current_rr, esc_hbci_monitor->rpm_fl, esc_hbci_monitor->rpm_fr, esc_hbci_monitor->rpm_rl, esc_hbci_monitor->rpm_rr, esc_hbci_monitor->motor_temper_fl, esc_hbci_monitor->motor_temper_fr, esc_hbci_monitor->motor_temper_rl, esc_hbci_monitor->motor_temper_rr, esc_hbci_monitor->esc_temper_fl, esc_hbci_monitor->esc_temper_fr, esc_hbci_monitor->esc_temper_rl, esc_hbci_monitor->esc_temper_rr, esc_hbci_monitor->output_pwm_fl, esc_hbci_monitor->output_pwm_fr, esc_hbci_monitor->output_pwm_rl, esc_hbci_monitor->output_pwm_rr, esc_hbci_monitor->input_pwm_fl, esc_hbci_monitor->input_pwm_fr, esc_hbci_monitor->input_pwm_rl, esc_hbci_monitor->input_pwm_rr);
}

/**
 * @brief Send a esc_hbci_monitor message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param voltage_fl [V] Front left voltage
 * @param voltage_fr [V] Front right voltage
 * @param voltage_rl [V] Rear left voltage
 * @param voltage_rr [V] Rear right voltage
 * @param current_fl [A] Front left current
 * @param current_fr [A] Front right current
 * @param current_rl [A] Rear left current
 * @param current_rr [A] Rear right current
 * @param rpm_fl [RPM] Front left RPM
 * @param rpm_fr [RPM] Front right RPM
 * @param rpm_rl [RPM] Rear left RPM
 * @param rpm_rr [RPM] Rear right RPM
 * @param motor_temper_fl [degC] Front left motor temperature
 * @param motor_temper_fr [degC] Front right motor temperature
 * @param motor_temper_rl [degC] Rear left motor temperature
 * @param motor_temper_rr [degC] Rear right motor temperature
 * @param esc_temper_fl [degC] Front left ESC temperature
 * @param esc_temper_fr [degC] Front right ESC temperature
 * @param esc_temper_rl [degC] Rear left ESC temperature
 * @param esc_temper_rr [degC] Rear right ESC temperature
 * @param output_pwm_fl [%] Front left output PWM
 * @param output_pwm_fr [%] Front right output PWM
 * @param output_pwm_rl [%] Rear left output PWM
 * @param output_pwm_rr [%] Rear right output PWM
 * @param input_pwm_fl [%] Front left input PWM
 * @param input_pwm_fr [%] Front right input PWM
 * @param input_pwm_rl [%] Rear left input PWM
 * @param input_pwm_rr [%] Rear right input PWM
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_esc_hbci_monitor_send(mavlink_channel_t chan, uint32_t time_boot_ms, float voltage_fl, float voltage_fr, float voltage_rl, float voltage_rr, float current_fl, float current_fr, float current_rl, float current_rr, int32_t rpm_fl, int32_t rpm_fr, int32_t rpm_rl, int32_t rpm_rr, int32_t motor_temper_fl, int32_t motor_temper_fr, int32_t motor_temper_rl, int32_t motor_temper_rr, int32_t esc_temper_fl, int32_t esc_temper_fr, int32_t esc_temper_rl, int32_t esc_temper_rr, float output_pwm_fl, float output_pwm_fr, float output_pwm_rl, float output_pwm_rr, float input_pwm_fl, float input_pwm_fr, float input_pwm_rl, float input_pwm_rr)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESC_HBCI_MONITOR_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, voltage_fl);
    _mav_put_float(buf, 8, voltage_fr);
    _mav_put_float(buf, 12, voltage_rl);
    _mav_put_float(buf, 16, voltage_rr);
    _mav_put_float(buf, 20, current_fl);
    _mav_put_float(buf, 24, current_fr);
    _mav_put_float(buf, 28, current_rl);
    _mav_put_float(buf, 32, current_rr);
    _mav_put_int32_t(buf, 36, rpm_fl);
    _mav_put_int32_t(buf, 40, rpm_fr);
    _mav_put_int32_t(buf, 44, rpm_rl);
    _mav_put_int32_t(buf, 48, rpm_rr);
    _mav_put_int32_t(buf, 52, motor_temper_fl);
    _mav_put_int32_t(buf, 56, motor_temper_fr);
    _mav_put_int32_t(buf, 60, motor_temper_rl);
    _mav_put_int32_t(buf, 64, motor_temper_rr);
    _mav_put_int32_t(buf, 68, esc_temper_fl);
    _mav_put_int32_t(buf, 72, esc_temper_fr);
    _mav_put_int32_t(buf, 76, esc_temper_rl);
    _mav_put_int32_t(buf, 80, esc_temper_rr);
    _mav_put_float(buf, 84, output_pwm_fl);
    _mav_put_float(buf, 88, output_pwm_fr);
    _mav_put_float(buf, 92, output_pwm_rl);
    _mav_put_float(buf, 96, output_pwm_rr);
    _mav_put_float(buf, 100, input_pwm_fl);
    _mav_put_float(buf, 104, input_pwm_fr);
    _mav_put_float(buf, 108, input_pwm_rl);
    _mav_put_float(buf, 112, input_pwm_rr);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_HBCI_MONITOR, buf, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_MIN_LEN, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_LEN, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_CRC);
#else
    mavlink_esc_hbci_monitor_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.voltage_fl = voltage_fl;
    packet.voltage_fr = voltage_fr;
    packet.voltage_rl = voltage_rl;
    packet.voltage_rr = voltage_rr;
    packet.current_fl = current_fl;
    packet.current_fr = current_fr;
    packet.current_rl = current_rl;
    packet.current_rr = current_rr;
    packet.rpm_fl = rpm_fl;
    packet.rpm_fr = rpm_fr;
    packet.rpm_rl = rpm_rl;
    packet.rpm_rr = rpm_rr;
    packet.motor_temper_fl = motor_temper_fl;
    packet.motor_temper_fr = motor_temper_fr;
    packet.motor_temper_rl = motor_temper_rl;
    packet.motor_temper_rr = motor_temper_rr;
    packet.esc_temper_fl = esc_temper_fl;
    packet.esc_temper_fr = esc_temper_fr;
    packet.esc_temper_rl = esc_temper_rl;
    packet.esc_temper_rr = esc_temper_rr;
    packet.output_pwm_fl = output_pwm_fl;
    packet.output_pwm_fr = output_pwm_fr;
    packet.output_pwm_rl = output_pwm_rl;
    packet.output_pwm_rr = output_pwm_rr;
    packet.input_pwm_fl = input_pwm_fl;
    packet.input_pwm_fr = input_pwm_fr;
    packet.input_pwm_rl = input_pwm_rl;
    packet.input_pwm_rr = input_pwm_rr;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_HBCI_MONITOR, (const char *)&packet, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_MIN_LEN, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_LEN, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_CRC);
#endif
}

/**
 * @brief Send a esc_hbci_monitor message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_esc_hbci_monitor_send_struct(mavlink_channel_t chan, const mavlink_esc_hbci_monitor_t* esc_hbci_monitor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_esc_hbci_monitor_send(chan, esc_hbci_monitor->time_boot_ms, esc_hbci_monitor->voltage_fl, esc_hbci_monitor->voltage_fr, esc_hbci_monitor->voltage_rl, esc_hbci_monitor->voltage_rr, esc_hbci_monitor->current_fl, esc_hbci_monitor->current_fr, esc_hbci_monitor->current_rl, esc_hbci_monitor->current_rr, esc_hbci_monitor->rpm_fl, esc_hbci_monitor->rpm_fr, esc_hbci_monitor->rpm_rl, esc_hbci_monitor->rpm_rr, esc_hbci_monitor->motor_temper_fl, esc_hbci_monitor->motor_temper_fr, esc_hbci_monitor->motor_temper_rl, esc_hbci_monitor->motor_temper_rr, esc_hbci_monitor->esc_temper_fl, esc_hbci_monitor->esc_temper_fr, esc_hbci_monitor->esc_temper_rl, esc_hbci_monitor->esc_temper_rr, esc_hbci_monitor->output_pwm_fl, esc_hbci_monitor->output_pwm_fr, esc_hbci_monitor->output_pwm_rl, esc_hbci_monitor->output_pwm_rr, esc_hbci_monitor->input_pwm_fl, esc_hbci_monitor->input_pwm_fr, esc_hbci_monitor->input_pwm_rl, esc_hbci_monitor->input_pwm_rr);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_HBCI_MONITOR, (const char *)esc_hbci_monitor, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_MIN_LEN, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_LEN, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_CRC);
#endif
}

#if MAVLINK_MSG_ID_ESC_HBCI_MONITOR_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_esc_hbci_monitor_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time_boot_ms, float voltage_fl, float voltage_fr, float voltage_rl, float voltage_rr, float current_fl, float current_fr, float current_rl, float current_rr, int32_t rpm_fl, int32_t rpm_fr, int32_t rpm_rl, int32_t rpm_rr, int32_t motor_temper_fl, int32_t motor_temper_fr, int32_t motor_temper_rl, int32_t motor_temper_rr, int32_t esc_temper_fl, int32_t esc_temper_fr, int32_t esc_temper_rl, int32_t esc_temper_rr, float output_pwm_fl, float output_pwm_fr, float output_pwm_rl, float output_pwm_rr, float input_pwm_fl, float input_pwm_fr, float input_pwm_rl, float input_pwm_rr)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, voltage_fl);
    _mav_put_float(buf, 8, voltage_fr);
    _mav_put_float(buf, 12, voltage_rl);
    _mav_put_float(buf, 16, voltage_rr);
    _mav_put_float(buf, 20, current_fl);
    _mav_put_float(buf, 24, current_fr);
    _mav_put_float(buf, 28, current_rl);
    _mav_put_float(buf, 32, current_rr);
    _mav_put_int32_t(buf, 36, rpm_fl);
    _mav_put_int32_t(buf, 40, rpm_fr);
    _mav_put_int32_t(buf, 44, rpm_rl);
    _mav_put_int32_t(buf, 48, rpm_rr);
    _mav_put_int32_t(buf, 52, motor_temper_fl);
    _mav_put_int32_t(buf, 56, motor_temper_fr);
    _mav_put_int32_t(buf, 60, motor_temper_rl);
    _mav_put_int32_t(buf, 64, motor_temper_rr);
    _mav_put_int32_t(buf, 68, esc_temper_fl);
    _mav_put_int32_t(buf, 72, esc_temper_fr);
    _mav_put_int32_t(buf, 76, esc_temper_rl);
    _mav_put_int32_t(buf, 80, esc_temper_rr);
    _mav_put_float(buf, 84, output_pwm_fl);
    _mav_put_float(buf, 88, output_pwm_fr);
    _mav_put_float(buf, 92, output_pwm_rl);
    _mav_put_float(buf, 96, output_pwm_rr);
    _mav_put_float(buf, 100, input_pwm_fl);
    _mav_put_float(buf, 104, input_pwm_fr);
    _mav_put_float(buf, 108, input_pwm_rl);
    _mav_put_float(buf, 112, input_pwm_rr);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_HBCI_MONITOR, buf, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_MIN_LEN, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_LEN, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_CRC);
#else
    mavlink_esc_hbci_monitor_t *packet = (mavlink_esc_hbci_monitor_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->voltage_fl = voltage_fl;
    packet->voltage_fr = voltage_fr;
    packet->voltage_rl = voltage_rl;
    packet->voltage_rr = voltage_rr;
    packet->current_fl = current_fl;
    packet->current_fr = current_fr;
    packet->current_rl = current_rl;
    packet->current_rr = current_rr;
    packet->rpm_fl = rpm_fl;
    packet->rpm_fr = rpm_fr;
    packet->rpm_rl = rpm_rl;
    packet->rpm_rr = rpm_rr;
    packet->motor_temper_fl = motor_temper_fl;
    packet->motor_temper_fr = motor_temper_fr;
    packet->motor_temper_rl = motor_temper_rl;
    packet->motor_temper_rr = motor_temper_rr;
    packet->esc_temper_fl = esc_temper_fl;
    packet->esc_temper_fr = esc_temper_fr;
    packet->esc_temper_rl = esc_temper_rl;
    packet->esc_temper_rr = esc_temper_rr;
    packet->output_pwm_fl = output_pwm_fl;
    packet->output_pwm_fr = output_pwm_fr;
    packet->output_pwm_rl = output_pwm_rl;
    packet->output_pwm_rr = output_pwm_rr;
    packet->input_pwm_fl = input_pwm_fl;
    packet->input_pwm_fr = input_pwm_fr;
    packet->input_pwm_rl = input_pwm_rl;
    packet->input_pwm_rr = input_pwm_rr;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_HBCI_MONITOR, (const char *)packet, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_MIN_LEN, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_LEN, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_CRC);
#endif
}
#endif

#endif

// MESSAGE ESC_HBCI_MONITOR UNPACKING


/**
 * @brief Get field time_boot_ms from esc_hbci_monitor message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint32_t mavlink_msg_esc_hbci_monitor_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field voltage_fl from esc_hbci_monitor message
 *
 * @return [V] Front left voltage
 */
static inline float mavlink_msg_esc_hbci_monitor_get_voltage_fl(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field voltage_fr from esc_hbci_monitor message
 *
 * @return [V] Front right voltage
 */
static inline float mavlink_msg_esc_hbci_monitor_get_voltage_fr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field voltage_rl from esc_hbci_monitor message
 *
 * @return [V] Rear left voltage
 */
static inline float mavlink_msg_esc_hbci_monitor_get_voltage_rl(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field voltage_rr from esc_hbci_monitor message
 *
 * @return [V] Rear right voltage
 */
static inline float mavlink_msg_esc_hbci_monitor_get_voltage_rr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field current_fl from esc_hbci_monitor message
 *
 * @return [A] Front left current
 */
static inline float mavlink_msg_esc_hbci_monitor_get_current_fl(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field current_fr from esc_hbci_monitor message
 *
 * @return [A] Front right current
 */
static inline float mavlink_msg_esc_hbci_monitor_get_current_fr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field current_rl from esc_hbci_monitor message
 *
 * @return [A] Rear left current
 */
static inline float mavlink_msg_esc_hbci_monitor_get_current_rl(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field current_rr from esc_hbci_monitor message
 *
 * @return [A] Rear right current
 */
static inline float mavlink_msg_esc_hbci_monitor_get_current_rr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field rpm_fl from esc_hbci_monitor message
 *
 * @return [RPM] Front left RPM
 */
static inline int32_t mavlink_msg_esc_hbci_monitor_get_rpm_fl(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  36);
}

/**
 * @brief Get field rpm_fr from esc_hbci_monitor message
 *
 * @return [RPM] Front right RPM
 */
static inline int32_t mavlink_msg_esc_hbci_monitor_get_rpm_fr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  40);
}

/**
 * @brief Get field rpm_rl from esc_hbci_monitor message
 *
 * @return [RPM] Rear left RPM
 */
static inline int32_t mavlink_msg_esc_hbci_monitor_get_rpm_rl(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  44);
}

/**
 * @brief Get field rpm_rr from esc_hbci_monitor message
 *
 * @return [RPM] Rear right RPM
 */
static inline int32_t mavlink_msg_esc_hbci_monitor_get_rpm_rr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  48);
}

/**
 * @brief Get field motor_temper_fl from esc_hbci_monitor message
 *
 * @return [degC] Front left motor temperature
 */
static inline int32_t mavlink_msg_esc_hbci_monitor_get_motor_temper_fl(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  52);
}

/**
 * @brief Get field motor_temper_fr from esc_hbci_monitor message
 *
 * @return [degC] Front right motor temperature
 */
static inline int32_t mavlink_msg_esc_hbci_monitor_get_motor_temper_fr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  56);
}

/**
 * @brief Get field motor_temper_rl from esc_hbci_monitor message
 *
 * @return [degC] Rear left motor temperature
 */
static inline int32_t mavlink_msg_esc_hbci_monitor_get_motor_temper_rl(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  60);
}

/**
 * @brief Get field motor_temper_rr from esc_hbci_monitor message
 *
 * @return [degC] Rear right motor temperature
 */
static inline int32_t mavlink_msg_esc_hbci_monitor_get_motor_temper_rr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  64);
}

/**
 * @brief Get field esc_temper_fl from esc_hbci_monitor message
 *
 * @return [degC] Front left ESC temperature
 */
static inline int32_t mavlink_msg_esc_hbci_monitor_get_esc_temper_fl(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  68);
}

/**
 * @brief Get field esc_temper_fr from esc_hbci_monitor message
 *
 * @return [degC] Front right ESC temperature
 */
static inline int32_t mavlink_msg_esc_hbci_monitor_get_esc_temper_fr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  72);
}

/**
 * @brief Get field esc_temper_rl from esc_hbci_monitor message
 *
 * @return [degC] Rear left ESC temperature
 */
static inline int32_t mavlink_msg_esc_hbci_monitor_get_esc_temper_rl(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  76);
}

/**
 * @brief Get field esc_temper_rr from esc_hbci_monitor message
 *
 * @return [degC] Rear right ESC temperature
 */
static inline int32_t mavlink_msg_esc_hbci_monitor_get_esc_temper_rr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  80);
}

/**
 * @brief Get field output_pwm_fl from esc_hbci_monitor message
 *
 * @return [%] Front left output PWM
 */
static inline float mavlink_msg_esc_hbci_monitor_get_output_pwm_fl(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  84);
}

/**
 * @brief Get field output_pwm_fr from esc_hbci_monitor message
 *
 * @return [%] Front right output PWM
 */
static inline float mavlink_msg_esc_hbci_monitor_get_output_pwm_fr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  88);
}

/**
 * @brief Get field output_pwm_rl from esc_hbci_monitor message
 *
 * @return [%] Rear left output PWM
 */
static inline float mavlink_msg_esc_hbci_monitor_get_output_pwm_rl(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  92);
}

/**
 * @brief Get field output_pwm_rr from esc_hbci_monitor message
 *
 * @return [%] Rear right output PWM
 */
static inline float mavlink_msg_esc_hbci_monitor_get_output_pwm_rr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  96);
}

/**
 * @brief Get field input_pwm_fl from esc_hbci_monitor message
 *
 * @return [%] Front left input PWM
 */
static inline float mavlink_msg_esc_hbci_monitor_get_input_pwm_fl(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  100);
}

/**
 * @brief Get field input_pwm_fr from esc_hbci_monitor message
 *
 * @return [%] Front right input PWM
 */
static inline float mavlink_msg_esc_hbci_monitor_get_input_pwm_fr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  104);
}

/**
 * @brief Get field input_pwm_rl from esc_hbci_monitor message
 *
 * @return [%] Rear left input PWM
 */
static inline float mavlink_msg_esc_hbci_monitor_get_input_pwm_rl(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  108);
}

/**
 * @brief Get field input_pwm_rr from esc_hbci_monitor message
 *
 * @return [%] Rear right input PWM
 */
static inline float mavlink_msg_esc_hbci_monitor_get_input_pwm_rr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  112);
}

/**
 * @brief Decode a esc_hbci_monitor message into a struct
 *
 * @param msg The message to decode
 * @param esc_hbci_monitor C-struct to decode the message contents into
 */
static inline void mavlink_msg_esc_hbci_monitor_decode(const mavlink_message_t* msg, mavlink_esc_hbci_monitor_t* esc_hbci_monitor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    esc_hbci_monitor->time_boot_ms = mavlink_msg_esc_hbci_monitor_get_time_boot_ms(msg);
    esc_hbci_monitor->voltage_fl = mavlink_msg_esc_hbci_monitor_get_voltage_fl(msg);
    esc_hbci_monitor->voltage_fr = mavlink_msg_esc_hbci_monitor_get_voltage_fr(msg);
    esc_hbci_monitor->voltage_rl = mavlink_msg_esc_hbci_monitor_get_voltage_rl(msg);
    esc_hbci_monitor->voltage_rr = mavlink_msg_esc_hbci_monitor_get_voltage_rr(msg);
    esc_hbci_monitor->current_fl = mavlink_msg_esc_hbci_monitor_get_current_fl(msg);
    esc_hbci_monitor->current_fr = mavlink_msg_esc_hbci_monitor_get_current_fr(msg);
    esc_hbci_monitor->current_rl = mavlink_msg_esc_hbci_monitor_get_current_rl(msg);
    esc_hbci_monitor->current_rr = mavlink_msg_esc_hbci_monitor_get_current_rr(msg);
    esc_hbci_monitor->rpm_fl = mavlink_msg_esc_hbci_monitor_get_rpm_fl(msg);
    esc_hbci_monitor->rpm_fr = mavlink_msg_esc_hbci_monitor_get_rpm_fr(msg);
    esc_hbci_monitor->rpm_rl = mavlink_msg_esc_hbci_monitor_get_rpm_rl(msg);
    esc_hbci_monitor->rpm_rr = mavlink_msg_esc_hbci_monitor_get_rpm_rr(msg);
    esc_hbci_monitor->motor_temper_fl = mavlink_msg_esc_hbci_monitor_get_motor_temper_fl(msg);
    esc_hbci_monitor->motor_temper_fr = mavlink_msg_esc_hbci_monitor_get_motor_temper_fr(msg);
    esc_hbci_monitor->motor_temper_rl = mavlink_msg_esc_hbci_monitor_get_motor_temper_rl(msg);
    esc_hbci_monitor->motor_temper_rr = mavlink_msg_esc_hbci_monitor_get_motor_temper_rr(msg);
    esc_hbci_monitor->esc_temper_fl = mavlink_msg_esc_hbci_monitor_get_esc_temper_fl(msg);
    esc_hbci_monitor->esc_temper_fr = mavlink_msg_esc_hbci_monitor_get_esc_temper_fr(msg);
    esc_hbci_monitor->esc_temper_rl = mavlink_msg_esc_hbci_monitor_get_esc_temper_rl(msg);
    esc_hbci_monitor->esc_temper_rr = mavlink_msg_esc_hbci_monitor_get_esc_temper_rr(msg);
    esc_hbci_monitor->output_pwm_fl = mavlink_msg_esc_hbci_monitor_get_output_pwm_fl(msg);
    esc_hbci_monitor->output_pwm_fr = mavlink_msg_esc_hbci_monitor_get_output_pwm_fr(msg);
    esc_hbci_monitor->output_pwm_rl = mavlink_msg_esc_hbci_monitor_get_output_pwm_rl(msg);
    esc_hbci_monitor->output_pwm_rr = mavlink_msg_esc_hbci_monitor_get_output_pwm_rr(msg);
    esc_hbci_monitor->input_pwm_fl = mavlink_msg_esc_hbci_monitor_get_input_pwm_fl(msg);
    esc_hbci_monitor->input_pwm_fr = mavlink_msg_esc_hbci_monitor_get_input_pwm_fr(msg);
    esc_hbci_monitor->input_pwm_rl = mavlink_msg_esc_hbci_monitor_get_input_pwm_rl(msg);
    esc_hbci_monitor->input_pwm_rr = mavlink_msg_esc_hbci_monitor_get_input_pwm_rr(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ESC_HBCI_MONITOR_LEN? msg->len : MAVLINK_MSG_ID_ESC_HBCI_MONITOR_LEN;
        memset(esc_hbci_monitor, 0, MAVLINK_MSG_ID_ESC_HBCI_MONITOR_LEN);
    memcpy(esc_hbci_monitor, _MAV_PAYLOAD(msg), len);
#endif
}
