// Copyright (c) 2015 The Chromium Embedded Framework Authors.
// Portions copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "libcef/browser/alloy/chrome_profile_alloy.h"

#include "components/variations/variations_client.h"
#include "components/variations/variations_http_header_provider.h"
#include "content/public/browser/resource_context.h"
#include "net/url_request/url_request_context.h"

namespace {

class CefVariationsClient : public variations::VariationsClient {
 public:
  explicit CefVariationsClient(content::BrowserContext* browser_context)
      : browser_context_(browser_context) {}

  ~CefVariationsClient() override = default;

  bool IsIncognito() const override {
    return browser_context_->IsOffTheRecord();
  }

  std::string GetVariationsHeader() const override {
    return variations::VariationsHttpHeaderProvider::GetInstance()
        ->GetClientDataHeader(false /* is_signed_in */);
  }

 private:
  content::BrowserContext* browser_context_;
};

}  // namespace

ChromeProfileAlloy::ChromeProfileAlloy() {}

ChromeProfileAlloy::~ChromeProfileAlloy() {}

bool ChromeProfileAlloy::IsOffTheRecord() {
  return false;
}

bool ChromeProfileAlloy::IsOffTheRecord() const {
  return false;
}

const Profile::OTRProfileID& ChromeProfileAlloy::GetOTRProfileID() const {
  NOTREACHED();
  static base::NoDestructor<Profile::OTRProfileID> otr_profile_id(
      "ProfileImp::NoOTRProfileID");
  return *otr_profile_id;
}

variations::VariationsClient* ChromeProfileAlloy::GetVariationsClient() {
  if (!variations_client_)
    variations_client_ = std::make_unique<CefVariationsClient>(this);
  return variations_client_.get();
}

scoped_refptr<base::SequencedTaskRunner> ChromeProfileAlloy::GetIOTaskRunner() {
  NOTREACHED();
  return scoped_refptr<base::SequencedTaskRunner>();
}

std::string ChromeProfileAlloy::GetProfileUserName() const {
  NOTREACHED();
  return std::string();
}

Profile::ProfileType ChromeProfileAlloy::GetProfileType() const {
  return REGULAR_PROFILE;
}

Profile* ChromeProfileAlloy::GetOffTheRecordProfile(
    const Profile::OTRProfileID& otr_profile_id) {
  NOTREACHED();
  return nullptr;
}

std::vector<Profile*> ChromeProfileAlloy::GetAllOffTheRecordProfiles() {
  NOTREACHED();
  return {};
}

void ChromeProfileAlloy::DestroyOffTheRecordProfile(Profile* otr_profile) {
  NOTREACHED();
}

bool ChromeProfileAlloy::HasOffTheRecordProfile(
    const Profile::OTRProfileID& otr_profile_id) {
  return false;
}

bool ChromeProfileAlloy::HasAnyOffTheRecordProfile() {
  return false;
}

Profile* ChromeProfileAlloy::GetOriginalProfile() {
  return this;
}

const Profile* ChromeProfileAlloy::GetOriginalProfile() const {
  return this;
}

bool ChromeProfileAlloy::IsSupervised() const {
  return false;
}

bool ChromeProfileAlloy::IsChild() const {
  return false;
}

bool ChromeProfileAlloy::IsLegacySupervised() const {
  return false;
}

ExtensionSpecialStoragePolicy*
ChromeProfileAlloy::GetExtensionSpecialStoragePolicy() {
  NOTREACHED();
  return nullptr;
}

PrefService* ChromeProfileAlloy::GetOffTheRecordPrefs() {
  NOTREACHED();
  return nullptr;
}

bool ChromeProfileAlloy::IsSameProfile(Profile* profile) {
  NOTREACHED();
  return false;
}

base::Time ChromeProfileAlloy::GetStartTime() const {
  NOTREACHED();
  return base::Time();
}

base::FilePath ChromeProfileAlloy::last_selected_directory() {
  NOTREACHED();
  return base::FilePath();
}

void ChromeProfileAlloy::set_last_selected_directory(
    const base::FilePath& path) {
  NOTREACHED();
}

GURL ChromeProfileAlloy::GetHomePage() {
  NOTREACHED();
  return GURL();
}

bool ChromeProfileAlloy::WasCreatedByVersionOrLater(
    const std::string& version) {
  NOTREACHED();
  return false;
}

void ChromeProfileAlloy::SetExitType(ExitType exit_type) {
  NOTREACHED();
}

Profile::ExitType ChromeProfileAlloy::GetLastSessionExitType() {
  NOTREACHED();
  return EXIT_NORMAL;
}

base::Time ChromeProfileAlloy::GetCreationTime() const {
  NOTREACHED();
  return base::Time();
}

void ChromeProfileAlloy::SetCreationTimeForTesting(base::Time creation_time) {
  NOTREACHED();
}
