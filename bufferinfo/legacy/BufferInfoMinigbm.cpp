/*
 * Copyright (C) 2018 The Android Open Source Project
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

#define LOG_TAG "hwc-bufferinfo-minigbm"

#include "BufferInfoMinigbm.h"

#include <log/log.h>
#include <xf86drm.h>
#include <xf86drmMode.h>

#include "cros_gralloc_handle.h"

namespace android {

LEGACY_BUFFER_INFO_GETTER(BufferInfoMinigbm);

int BufferInfoMinigbm::ConvertBoInfo(buffer_handle_t handle, hwc_drm_bo_t *bo) {
  cros_gralloc_handle *gr_handle = (cros_gralloc_handle *)handle;
  if (!gr_handle)
    return -EINVAL;

  bo->width = gr_handle->width;
  bo->height = gr_handle->height;
  bo->hal_format = gr_handle->droid_format;
  bo->format = gr_handle->format;
  bo->usage = gr_handle->usage;
  bo->prime_fds[0] = gr_handle->fds[0];
  bo->pitches[0] = gr_handle->strides[0];
  bo->offsets[0] = gr_handle->offsets[0];

  return 0;
}

}  // namespace android
