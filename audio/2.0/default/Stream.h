/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef HIDL_GENERATED_android_hardware_audio_V2_0_Stream_H_
#define HIDL_GENERATED_android_hardware_audio_V2_0_Stream_H_

#include <android/hardware/audio/2.0/IStream.h>
#include <hidl/Status.h>

#include <hidl/MQDescriptor.h>

#include "ParametersUtil.h"

namespace android {
namespace hardware {
namespace audio {
namespace V2_0 {
namespace implementation {

using ::android::hardware::audio::common::V2_0::AudioChannelMask;
using ::android::hardware::audio::common::V2_0::AudioDevice;
using ::android::hardware::audio::common::V2_0::AudioFormat;
using ::android::hardware::audio::V2_0::DeviceAddress;
using ::android::hardware::audio::V2_0::IStream;
using ::android::hardware::audio::V2_0::ParameterValue;
using ::android::hardware::audio::V2_0::Result;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::hardware::hidl_vec;
using ::android::hardware::hidl_string;
using ::android::sp;

struct Stream : public IStream, public ParametersUtil {
    explicit Stream(audio_stream_t* stream);

    // Methods from ::android::hardware::audio::V2_0::IStream follow.
    Return<uint64_t> getFrameSize()  override;
    Return<uint64_t> getFrameCount()  override;
    Return<uint64_t> getBufferSize()  override;
    Return<uint32_t> getSampleRate()  override;
    Return<void> getSupportedSampleRates(getSupportedSampleRates_cb _hidl_cb)  override;
    Return<Result> setSampleRate(uint32_t sampleRateHz)  override;
    Return<AudioChannelMask> getChannelMask()  override;
    Return<void> getSupportedChannelMasks(getSupportedChannelMasks_cb _hidl_cb)  override;
    Return<Result> setChannelMask(AudioChannelMask mask)  override;
    Return<AudioFormat> getFormat()  override;
    Return<void> getSupportedFormats(getSupportedFormats_cb _hidl_cb)  override;
    Return<Result> setFormat(AudioFormat format)  override;
    Return<void> getAudioProperties(getAudioProperties_cb _hidl_cb)  override;
    Return<Result> addEffect(uint64_t effectId)  override;
    Return<Result> removeEffect(uint64_t effectId)  override;
    Return<Result> standby()  override;
    Return<AudioDevice> getDevice()  override;
    Return<Result> setDevice(const DeviceAddress& address)  override;
    Return<Result> setConnectedState(const DeviceAddress& address, bool connected)  override;
    Return<Result> setHwAvSync(uint32_t hwAvSync)  override;
    Return<void> getParameters(
            const hidl_vec<hidl_string>& keys, getParameters_cb _hidl_cb)  override;
    Return<Result> setParameters(const hidl_vec<ParameterValue>& parameters)  override;
    Return<void> debugDump(const hidl_handle& fd)  override;

    // Utility methods for extending interfaces.
    Result analyzeStatus(const char* funcName, int status);

  private:
    audio_stream_t *mStream;

    virtual ~Stream();

    // Methods from ParametersUtil.
    char* halGetParameters(const char* keys) override;
    int halSetParameters(const char* keysAndValues) override;
};

}  // namespace implementation
}  // namespace V2_0
}  // namespace audio
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_android_hardware_audio_V2_0_Stream_H_