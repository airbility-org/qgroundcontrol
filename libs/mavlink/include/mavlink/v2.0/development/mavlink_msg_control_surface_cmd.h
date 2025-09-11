#pragma once
// MESSAGE CONTROL_SURFACE_CMD PACKING

#define MAVLINK_MSG_ID_CONTROL_SURFACE_CMD 515


typedef struct __mavlink_control_surface_cmd_t {
 uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
 float left_aileron; /*< [deg] Left aileron command.*/
 float right_aileron; /*< [deg] Right aileron command.*/
 float left_ruddervator; /*< [deg] Left ruddervator command.*/
 float right_ruddervator; /*< [deg] Right ruddervator command.*/
} mavlink_control_surface_cmd_t;

#define MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_LEN 20
#define MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_MIN_LEN 20

#define MAVLINK_MSG_ID_515_LEN 20
#define MAVLINK_MSG_ID_515_MIN_LEN 20

#define MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_CRC 79
#define MAVLINK_MSG_ID_515_CRC 79




#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CONTROL_SURFACE_CMD { \
    515, \
    "CONTROL_SURFACE_CMD", \
    5, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_control_surface_cmd_t, time_boot_ms) }, \
         { "left_aileron", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_control_surface_cmd_t, left_aileron) }, \
         { "right_aileron", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_control_surface_cmd_t, right_aileron) }, \
         { "left_ruddervator", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_control_surface_cmd_t, left_ruddervator) }, \
         { "right_ruddervator", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_control_surface_cmd_t, right_ruddervator) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CONTROL_SURFACE_CMD { \
    "CONTROL_SURFACE_CMD", \
    5, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_control_surface_cmd_t, time_boot_ms) }, \
         { "left_aileron", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_control_surface_cmd_t, left_aileron) }, \
         { "right_aileron", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_control_surface_cmd_t, right_aileron) }, \
         { "left_ruddervator", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_control_surface_cmd_t, left_ruddervator) }, \
         { "right_ruddervator", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_control_surface_cmd_t, right_ruddervator) }, \
         } \
}
#endif

/**
 * @brief Pack a control_surface_cmd message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param left_aileron [deg] Left aileron command.
 * @param right_aileron [deg] Right aileron command.
 * @param left_ruddervator [deg] Left ruddervator command.
 * @param right_ruddervator [deg] Right ruddervator command.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_control_surface_cmd_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, float left_aileron, float right_aileron, float left_ruddervator, float right_ruddervator)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, left_aileron);
    _mav_put_float(buf, 8, right_aileron);
    _mav_put_float(buf, 12, left_ruddervator);
    _mav_put_float(buf, 16, right_ruddervator);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_LEN);
#else
    mavlink_control_surface_cmd_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.left_aileron = left_aileron;
    packet.right_aileron = right_aileron;
    packet.left_ruddervator = left_ruddervator;
    packet.right_ruddervator = right_ruddervator;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CONTROL_SURFACE_CMD;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_MIN_LEN, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_LEN, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_CRC);
}

/**
 * @brief Pack a control_surface_cmd message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param left_aileron [deg] Left aileron command.
 * @param right_aileron [deg] Right aileron command.
 * @param left_ruddervator [deg] Left ruddervator command.
 * @param right_ruddervator [deg] Right ruddervator command.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_control_surface_cmd_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,float left_aileron,float right_aileron,float left_ruddervator,float right_ruddervator)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, left_aileron);
    _mav_put_float(buf, 8, right_aileron);
    _mav_put_float(buf, 12, left_ruddervator);
    _mav_put_float(buf, 16, right_ruddervator);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_LEN);
#else
    mavlink_control_surface_cmd_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.left_aileron = left_aileron;
    packet.right_aileron = right_aileron;
    packet.left_ruddervator = left_ruddervator;
    packet.right_ruddervator = right_ruddervator;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CONTROL_SURFACE_CMD;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_MIN_LEN, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_LEN, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_CRC);
}

/**
 * @brief Encode a control_surface_cmd struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param control_surface_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_control_surface_cmd_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_control_surface_cmd_t* control_surface_cmd)
{
    return mavlink_msg_control_surface_cmd_pack(system_id, component_id, msg, control_surface_cmd->time_boot_ms, control_surface_cmd->left_aileron, control_surface_cmd->right_aileron, control_surface_cmd->left_ruddervator, control_surface_cmd->right_ruddervator);
}

/**
 * @brief Encode a control_surface_cmd struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param control_surface_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_control_surface_cmd_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_control_surface_cmd_t* control_surface_cmd)
{
    return mavlink_msg_control_surface_cmd_pack_chan(system_id, component_id, chan, msg, control_surface_cmd->time_boot_ms, control_surface_cmd->left_aileron, control_surface_cmd->right_aileron, control_surface_cmd->left_ruddervator, control_surface_cmd->right_ruddervator);
}

/**
 * @brief Send a control_surface_cmd message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param left_aileron [deg] Left aileron command.
 * @param right_aileron [deg] Right aileron command.
 * @param left_ruddervator [deg] Left ruddervator command.
 * @param right_ruddervator [deg] Right ruddervator command.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_control_surface_cmd_send(mavlink_channel_t chan, uint32_t time_boot_ms, float left_aileron, float right_aileron, float left_ruddervator, float right_ruddervator)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, left_aileron);
    _mav_put_float(buf, 8, right_aileron);
    _mav_put_float(buf, 12, left_ruddervator);
    _mav_put_float(buf, 16, right_ruddervator);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD, buf, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_MIN_LEN, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_LEN, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_CRC);
#else
    mavlink_control_surface_cmd_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.left_aileron = left_aileron;
    packet.right_aileron = right_aileron;
    packet.left_ruddervator = left_ruddervator;
    packet.right_ruddervator = right_ruddervator;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD, (const char *)&packet, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_MIN_LEN, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_LEN, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_CRC);
#endif
}

/**
 * @brief Send a control_surface_cmd message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_control_surface_cmd_send_struct(mavlink_channel_t chan, const mavlink_control_surface_cmd_t* control_surface_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_control_surface_cmd_send(chan, control_surface_cmd->time_boot_ms, control_surface_cmd->left_aileron, control_surface_cmd->right_aileron, control_surface_cmd->left_ruddervator, control_surface_cmd->right_ruddervator);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD, (const char *)control_surface_cmd, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_MIN_LEN, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_LEN, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_CRC);
#endif
}

#if MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_control_surface_cmd_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time_boot_ms, float left_aileron, float right_aileron, float left_ruddervator, float right_ruddervator)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, left_aileron);
    _mav_put_float(buf, 8, right_aileron);
    _mav_put_float(buf, 12, left_ruddervator);
    _mav_put_float(buf, 16, right_ruddervator);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD, buf, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_MIN_LEN, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_LEN, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_CRC);
#else
    mavlink_control_surface_cmd_t *packet = (mavlink_control_surface_cmd_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->left_aileron = left_aileron;
    packet->right_aileron = right_aileron;
    packet->left_ruddervator = left_ruddervator;
    packet->right_ruddervator = right_ruddervator;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD, (const char *)packet, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_MIN_LEN, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_LEN, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_CRC);
#endif
}
#endif

#endif

// MESSAGE CONTROL_SURFACE_CMD UNPACKING


/**
 * @brief Get field time_boot_ms from control_surface_cmd message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint32_t mavlink_msg_control_surface_cmd_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field left_aileron from control_surface_cmd message
 *
 * @return [deg] Left aileron command.
 */
static inline float mavlink_msg_control_surface_cmd_get_left_aileron(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field right_aileron from control_surface_cmd message
 *
 * @return [deg] Right aileron command.
 */
static inline float mavlink_msg_control_surface_cmd_get_right_aileron(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field left_ruddervator from control_surface_cmd message
 *
 * @return [deg] Left ruddervator command.
 */
static inline float mavlink_msg_control_surface_cmd_get_left_ruddervator(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field right_ruddervator from control_surface_cmd message
 *
 * @return [deg] Right ruddervator command.
 */
static inline float mavlink_msg_control_surface_cmd_get_right_ruddervator(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Decode a control_surface_cmd message into a struct
 *
 * @param msg The message to decode
 * @param control_surface_cmd C-struct to decode the message contents into
 */
static inline void mavlink_msg_control_surface_cmd_decode(const mavlink_message_t* msg, mavlink_control_surface_cmd_t* control_surface_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    control_surface_cmd->time_boot_ms = mavlink_msg_control_surface_cmd_get_time_boot_ms(msg);
    control_surface_cmd->left_aileron = mavlink_msg_control_surface_cmd_get_left_aileron(msg);
    control_surface_cmd->right_aileron = mavlink_msg_control_surface_cmd_get_right_aileron(msg);
    control_surface_cmd->left_ruddervator = mavlink_msg_control_surface_cmd_get_left_ruddervator(msg);
    control_surface_cmd->right_ruddervator = mavlink_msg_control_surface_cmd_get_right_ruddervator(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_LEN? msg->len : MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_LEN;
        memset(control_surface_cmd, 0, MAVLINK_MSG_ID_CONTROL_SURFACE_CMD_LEN);
    memcpy(control_surface_cmd, _MAV_PAYLOAD(msg), len);
#endif
}
