/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 6.0.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */

/*
 * SWGNoiseFigureSettings.h
 *
 * NoiseFigure
 */

#ifndef SWGNoiseFigureSettings_H_
#define SWGNoiseFigureSettings_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"
#include "export.h"

namespace SWGSDRangel {

class SWG_API SWGNoiseFigureSettings: public SWGObject {
public:
    SWGNoiseFigureSettings();
    SWGNoiseFigureSettings(QString* json);
    virtual ~SWGNoiseFigureSettings();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGNoiseFigureSettings* fromJson(QString &jsonString) override;

    qint64 getInputFrequencyOffset();
    void setInputFrequencyOffset(qint64 input_frequency_offset);

    qint32 getFftSize();
    void setFftSize(qint32 fft_size);

    qint32 getFftCount();
    void setFftCount(qint32 fft_count);

    qint32 getSweepSpec();
    void setSweepSpec(qint32 sweep_spec);

    float getStartValue();
    void setStartValue(float start_value);

    float getStopValue();
    void setStopValue(float stop_value);

    qint32 getSteps();
    void setSteps(qint32 steps);

    float getStep();
    void setStep(float step);

    QString* getList();
    void setList(QString* list);

    QString* getSetting();
    void setSetting(QString* setting);

    QString* getVisaDevice();
    void setVisaDevice(QString* visa_device);

    QString* getPowerOnScpi();
    void setPowerOnScpi(QString* power_on_scpi);

    QString* getPowerOffScpi();
    void setPowerOffScpi(QString* power_off_scpi);

    QString* getPowerOnCommand();
    void setPowerOnCommand(QString* power_on_command);

    QString* getPowerOffCommand();
    void setPowerOffCommand(QString* power_off_command);

    float getPowerDelay();
    void setPowerDelay(float power_delay);

    qint32 getRgbColor();
    void setRgbColor(qint32 rgb_color);

    QString* getTitle();
    void setTitle(QString* title);

    qint32 getStreamIndex();
    void setStreamIndex(qint32 stream_index);

    qint32 getUseReverseApi();
    void setUseReverseApi(qint32 use_reverse_api);

    QString* getReverseApiAddress();
    void setReverseApiAddress(QString* reverse_api_address);

    qint32 getReverseApiPort();
    void setReverseApiPort(qint32 reverse_api_port);

    qint32 getReverseApiDeviceIndex();
    void setReverseApiDeviceIndex(qint32 reverse_api_device_index);

    qint32 getReverseApiChannelIndex();
    void setReverseApiChannelIndex(qint32 reverse_api_channel_index);


    virtual bool isSet() override;

private:
    qint64 input_frequency_offset;
    bool m_input_frequency_offset_isSet;

    qint32 fft_size;
    bool m_fft_size_isSet;

    qint32 fft_count;
    bool m_fft_count_isSet;

    qint32 sweep_spec;
    bool m_sweep_spec_isSet;

    float start_value;
    bool m_start_value_isSet;

    float stop_value;
    bool m_stop_value_isSet;

    qint32 steps;
    bool m_steps_isSet;

    float step;
    bool m_step_isSet;

    QString* list;
    bool m_list_isSet;

    QString* setting;
    bool m_setting_isSet;

    QString* visa_device;
    bool m_visa_device_isSet;

    QString* power_on_scpi;
    bool m_power_on_scpi_isSet;

    QString* power_off_scpi;
    bool m_power_off_scpi_isSet;

    QString* power_on_command;
    bool m_power_on_command_isSet;

    QString* power_off_command;
    bool m_power_off_command_isSet;

    float power_delay;
    bool m_power_delay_isSet;

    qint32 rgb_color;
    bool m_rgb_color_isSet;

    QString* title;
    bool m_title_isSet;

    qint32 stream_index;
    bool m_stream_index_isSet;

    qint32 use_reverse_api;
    bool m_use_reverse_api_isSet;

    QString* reverse_api_address;
    bool m_reverse_api_address_isSet;

    qint32 reverse_api_port;
    bool m_reverse_api_port_isSet;

    qint32 reverse_api_device_index;
    bool m_reverse_api_device_index_isSet;

    qint32 reverse_api_channel_index;
    bool m_reverse_api_channel_index_isSet;

};

}

#endif /* SWGNoiseFigureSettings_H_ */
