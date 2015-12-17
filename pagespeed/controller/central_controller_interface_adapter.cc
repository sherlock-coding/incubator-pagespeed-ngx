// Copyright 2015 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Author: cheesy@google.com (Steve Hill)

#include "pagespeed/controller/central_controller_interface_adapter.h"

namespace net_instaweb {

CentralControllerInterfaceAdapter::CentralControllerInterfaceAdapter(
    CentralControllerInterface* central_controller)
    : central_controller_(central_controller) {
}

CentralControllerInterfaceAdapter::~CentralControllerInterfaceAdapter() {
}

void CentralControllerInterfaceAdapter::ScheduleExpensiveOperation(
    ExpensiveOperationCallback* callback) {
  callback->SetCentralControllerInterface(central_controller_.get());
  central_controller_->ScheduleExpensiveOperation(callback);
}

void CentralControllerInterfaceAdapter::ScheduleRewrite(
    ScheduleRewriteCallback* callback) {
  callback->SetCentralControllerInterface(central_controller_.get());
  central_controller_->ScheduleRewrite(callback->key(), callback);
}

}  // namespace net_instaweb