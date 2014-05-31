/*
 * Copyright (c) 2000 - 2013 Samsung Electronics Co., Ltd. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
/*
 * setting-reset.h
 *
 *  Created on: Oct 10, 2013
 *      Author: min-hoyun
 */

#ifndef SETTING_RESET_H_
#define SETTING_RESET_H_

#include <Elementary.h>
#include <libintl.h>
#include <string.h>
#include <dd-deviced.h>

#define PREDEF_FACTORY_RESET "launchfr"

void _reset_popup_cb(void *data, Evas_Object *obj, void *event_info);


#endif /* SETTING_RESET_H_ */
