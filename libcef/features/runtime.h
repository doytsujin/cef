// Copyright 2020 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#ifndef CEF_LIBCEF_FEATURES_RUNTIME_H_
#define CEF_LIBCEF_FEATURES_RUNTIME_H_
#pragma once

#include "cef/libcef/features/features.h"

namespace cef {

#if BUILDFLAG(ENABLE_CEF)

inline bool IsCefBuildEnabled() {
  return true;
}

// True if CEF was initialized with the Alloy runtime.
bool IsAlloyRuntimeEnabled();

// True if CEF was initialized with the Chrome runtime.
bool IsChromeRuntimeEnabled();

#else

inline bool IsCefBuildEnabled() {
  return false;
}
inline bool IsAlloyRuntimeEnabled() {
  return false;
}
inline bool IsChromeRuntimeEnabled() {
  return false;
}

#endif

}  // namespace cef

#endif  // CEF_LIBCEF_FEATURES_RUNTIME_H_
